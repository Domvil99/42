# minitalk Study Report

Nota de estado (2026-04-05): proyecto `minitalk` marcado como terminado por el usuario.
Este reporte sirve para estudio tecnico y preparacion de defensa.

## 1. Vision del proyecto

`minitalk` implementa comunicacion entre dos procesos (cliente y servidor)
usando solo senales UNIX (`SIGUSR1` y `SIGUSR2`).

Objetivo pedagogico:

- entender IPC basico con senales,
- codificar bits sobre eventos asincronos,
- construir un protocolo robusto de envio/recepcion,
- defender decisiones de sincronizacion (delay vs ACK).

## 2. Subject y reglas clave

Referencia canonica:

- `42/PDFs/2026-04-05_minitalk.txt`

Reglas tecnicas que gobiernan el proyecto:

- Ejecutables obligatorios: `client` y `server`.
- Solo senales `SIGUSR1` y `SIGUSR2` para comunicar.
- Servidor imprime PID al iniciar.
- Cliente recibe `PID + mensaje` y lo transmite al servidor.
- Debe evitarse crashes, leaks y errores de norma.
- Bonus: ACK por senal y soporte de mensajes Unicode (flujo byte a byte).

## 3. Arquitectura mental completa

Pipeline mandatory:

1. `server` inicia, imprime PID y espera senales.
2. `client` valida argumentos y PID destino.
3. `client` envia cada caracter en 8 bits (MSB -> LSB).
4. `server` reconstruye bits hasta completar 1 byte.
5. `server` imprime caracter cuando completa byte.
6. `server` imprime salto de linea al recibir `\0`.
7. proceso continua para siguientes clientes sin reiniciar.

Pipeline bonus (con ACK):

1. cliente envia un bit,
2. servidor confirma con `SIGUSR1`,
3. cliente solo avanza cuando recibe ACK,
4. se repite para cada bit.

## 4. Contrato de entrada y salida

Entrada cliente:

- `./client <server_pid> "mensaje"`

Salida servidor:

- muestra mensaje recibido en stdout,
- nueva linea al final del string (`\0`).

Errores esperados:

- PID invalido,
- argumentos invalidos,
- fallo de `kill` o setup de handlers.

## 5. Riesgo tecnico principal

En mandatory, Linux no encola senales iguales pendientes.
Sin sincronizacion por ACK, pueden perderse bits si el emisor es muy rapido.
La mitigacion minima suele ser `usleep` por bit; la robusta es bonus con ACK.

## 6. Mapa de archivos clave

- `client.c`: validacion de args y envio de mensaje.
- `server.c`: handler de senales y reconstruccion de bytes.
- `signals_utils.c`: envio bit a bit (mandatory).
- `parse_utils.c`: parseo de PID y salida de errores.
- `client_bonus.c`: espera ACK por bit.
- `server_bonus.c`: envia ACK por cada bit recibido.
- `bonus_utils.c`: envio sincronizado con flag ACK.

## 7. Ruta de lectura recomendada

1. `minitalk.md` (este archivo)
2. `implementation.md`
3. `validation.md`
4. `defense.md`
5. `dictionary.md`
6. `study-session-01.md`

## 8. Checklist de comprension

Puedes considerar la base dominada cuando puedes:

- explicar como un byte se convierte en 8 senales,
- justificar por que se usa estado global en handlers,
- diferenciar mandatory sin ACK vs bonus con ACK,
- describir riesgos de perdida de senales,
- explicar por que el servidor no debe reiniciarse entre clientes.

## Change Log

- 2026-04-05: creacion inicial del reporte de estudio para `minitalk`.
