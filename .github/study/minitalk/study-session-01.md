# Sesion 01 - Inicio Guiado de minitalk

Objetivo: entender el proyecto completo sin asumir conocimientos previos de IPC.
Duracion sugerida: 60-75 minutos.

## Material

1. `minitalk.md`
2. `implementation.md`
3. `dictionary.md`
4. `validation.md`
5. `defense.md`

## Bloques

### Bloque A (15 min) - Modelo mental

1. Que es una senal en Linux.
2. Como representar 1 y 0 con SIGUSR1/SIGUSR2.
3. Como enviar un byte en 8 pasos.

Resultado esperado:

- explicar el recorrido completo de un caracter desde cliente a servidor.

Respuestas guia (Bloque A):

1. Que es una senal en Linux
- Es una notificacion asincrona que el sistema (o otro proceso) envia a un
	proceso para avisar un evento.
- En minitalk, no se usa para "matar" procesos, se usa como canal de datos.

2. Como representar 1 y 0 con SIGUSR1/SIGUSR2
- Convencion usada en el proyecto:
	- `SIGUSR1` representa bit `1`.
	- `SIGUSR2` representa bit `0`.
- Cada bit del caracter se transforma en una de estas dos senales.

3. Como enviar un byte en 8 pasos
- Un caracter (byte) tiene 8 bits.
- El cliente recorre del bit 7 al bit 0 (MSB -> LSB).
- Por cada bit:
	- si vale 1 envia `SIGUSR1`,
	- si vale 0 envia `SIGUSR2`.
- El servidor recibe 8 senales, reconstruye el byte y escribe el caracter.

Recorrido completo de 1 caracter (resumen):

1. Cliente toma un caracter.
2. Lo divide en 8 bits.
3. Envia 8 senales al PID del servidor.
4. Servidor acumula bit a bit en `current_char`.
5. Al llegar al bit 8, imprime el caracter.
6. Si el byte es `\0`, imprime salto de linea y cierra mensaje.

### Bloque B (15 min) - Flujo real de codigo

1. Leer `client.c` y `signals_utils.c`.
2. Identificar donde se valida PID.
3. Identificar donde se manda `\0` final.

Resultado esperado:

- saber seguir el flujo desde `main` hasta envio bit a bit.

Respuestas guia (Bloque B):

1. Flujo desde `main` en cliente
- `main` llama a `validate_args`.
- `validate_args` llama a `mt_parse_pid` para validar el PID del servidor.
- Si todo esta bien, `main` llama a `mt_send_message(server_pid, argv[2])`.

2. Donde se valida PID
- Se valida en `parse_utils.c`, funcion `mt_parse_pid`.
- Revisa que:
	- el string no este vacio,
	- todos los caracteres sean digitos,
	- no haya overflow (`INT_MAX`),
	- el PID final sea mayor que 0.

3. Donde se manda `\0` final
- En `signals_utils.c`, dentro de `mt_send_message`.
- Despues de enviar todos los caracteres del mensaje, se llama a
	`mt_send_char(server_pid, '\0')`.

Resumen rapido del Bloque B:

1. cliente valida args,
2. cliente valida PID,
3. cliente envia mensaje caracter por caracter,
4. cliente envia byte nulo para cerrar.

### Bloque C (15 min) - Recepcion y estado

1. Leer `server.c`.
2. Entender `current_char`, `bit_index`, `active_client`.
3. Entender cuando se imprime caracter y cuando se imprime nueva linea.

Resultado esperado:

- explicar por que el estado debe persistir entre senales.

Respuestas guia (Bloque C):

1. Que significa cada campo de estado
- `current_char`: byte en construccion.
- `bit_index`: cuantos bits del byte actual ya llegaron (0..7).
- `active_client`: PID del cliente que se esta atendiendo.

2. Cuando se imprime un caracter
- Cada vez que `bit_index` llega a 8, el byte esta completo.
- Si `current_char` no es `\0`, el servidor imprime ese caracter.

3. Cuando se imprime nueva linea
- Cuando el byte reconstruido es `\0`.
- Eso marca fin de string y el servidor imprime `\n`.

4. Por que el estado debe persistir
- El handler recibe una senal por vez (un solo bit por evento).
- Para reconstruir un byte completo, el servidor necesita recordar lo recibido
	antes.
- Sin estado persistente, cada senal se procesaria aislada y el byte no se
	podria formar.

### Bloque D (10 min) - Bonus con ACK

1. Leer `client_bonus.c`, `utils_bonus.c`, `server_bonus.c`.
2. Entender por que ACK evita perdida de bits.

Resultado esperado:

- comparar mandatory vs bonus en una frase tecnica clara.

Respuestas guia (Bloque D):

1. Mandatory (sin ACK)
- Cliente envia bits con un delay fijo (`usleep`).
- No espera confirmacion del servidor.
- Es simple, pero bajo carga puede perder bits.

2. Bonus (con ACK)
- Cliente envia 1 bit y se bloquea en espera de ACK.
- Servidor responde con `SIGUSR1` tras recibir/procesar ese bit.
- Cliente solo envia el siguiente bit cuando llega el ACK.

3. Frase tecnica esperada para comparar
- Mandatory depende de temporizacion; bonus agrega sincronizacion explicita
	bit a bit, reduciendo drasticamente perdida de senales.

### Bloque E (5 min) - Cierre

Escribir 3 lineas:

1. concepto mas claro,
2. duda pendiente,
3. proximo paso.

Modelo de cierre (Bloque E):

1. Concepto mas claro:
- Ahora entiendo que un caracter se envia como 8 senales y que `SIGUSR1`
	y `SIGUSR2` representan bits.

2. Duda pendiente:
- Quiero practicar mejor como el servidor arma `current_char` bit a bit.

3. Proximo paso:
- Releer `server.c` y simular en papel el envio de una letra (por ejemplo `A`).

## Mini checklist final

- [ ] entiendo byte -> 8 senales
- [ ] entiendo por que se envia `\0`
- [ ] entiendo riesgo sin ACK
- [ ] entiendo como bonus sincroniza envio

## Change Log

- 2026-04-05: sesion inicial de estudio para `minitalk`.
- 2026-04-05: agregadas respuestas guia completas para bloques A-E.
