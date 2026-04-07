# 04 - Comunicacion Cliente-Servidor y Senales UNIX

## Como se lanza un servidor

1. Ir al directorio del proyecto.
2. Ejecutar ./server (mandatory) o ./server_bonus (bonus).

## Donde se ve su PID

El PID se imprime en stdout al iniciar el servidor.
Ese numero es el que usa el cliente como primer argumento.

## Que string debe mandarse

La string que quieras enviar como segundo argumento del cliente.
Ejemplo: ./client 12345 "Hola 42"

## Como se cumple envio y visualizacion de string

1. Cliente recorre string caracter por caracter.
2. Cada caracter se envia como 8 senales (bits).
3. Servidor reconstruye byte a byte.
4. Servidor imprime cada caracter reconstruido.
5. Al recibir byte nulo (\0), imprime salto de linea.

## Como probar clientes consecutivos sin reiniciar servidor

1. Inicia servidor una sola vez.
2. Envia un mensaje desde cliente A.
3. Envia otro mensaje desde cliente B.
4. Verifica que ambos se imprimen sin reiniciar el servidor.

## Que es UNIX

UNIX es una familia de sistemas operativos multitarea y multiusuario.
Linux sigue muchos principios y APIs POSIX de UNIX.

## Que son las senales UNIX

Son notificaciones asincronas enviadas a procesos para indicar eventos.

## Que son SIGUSR1 y SIGUSR2

Son senales de usuario definidas por el sistema.
No las inventa el programador; sus nombres y numeros existen en el SO.

En minitalk se usan como protocolo de bits:
- SIGUSR1 = bit 1
- SIGUSR2 = bit 0

## Tipos de senales y para que se usan

Ejemplos comunes:
- SIGINT: interrupcion (Ctrl+C).
- SIGTERM: solicitud de finalizacion.
- SIGKILL: finalizacion forzada.
- SIGUSR1/SIGUSR2: uso personalizado de aplicacion.

## Change Log

- 2026-04-05: comunicacion y senales.
