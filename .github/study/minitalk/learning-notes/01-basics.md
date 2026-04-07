# 01 - Conceptos Basicos

## Que hace el ejecutable client y que hace server

- server:
  - arranca primero,
  - imprime su PID,
  - espera senales,
  - reconstruye bytes recibidos,
  - imprime el mensaje.
- client:
  - recibe PID del server + string,
  - valida argumentos,
  - envia la string bit a bit al server.

## Que es un servidor

En este proyecto, un servidor es el proceso que se queda escuchando
peticiones de clientes y procesa mensajes entrantes.

## Que es un PID

PID (Process ID) es el identificador numerico unico de un proceso activo.
El cliente necesita el PID del servidor para enviarle senales.

## Que es una variable global

Una variable global vive durante toda la ejecucion del programa y se puede
usar desde funciones del mismo archivo.

En minitalk, su uso esta justificado por el contexto asincrono de senales:
- server.c usa estado global para reconstruir bytes entre llamadas al handler.
- client_bonus.c usa flag global de ACK para sincronizar envio bit a bit.

El subject permite una variable global por programa (cliente y servidor),
siempre que se justifique.

## Buenas practicas basicas para este proyecto

1. Validar argumentos antes de iniciar logica de envio.
2. Validar PID y rangos numericos.
3. Comprobar retorno de llamadas criticas (`sigaction`, `kill`).
4. Mantener handlers simples.
5. Separar parseo, envio y recepcion en archivos distintos.

## Change Log

- 2026-04-05: respuestas basicas iniciales.
