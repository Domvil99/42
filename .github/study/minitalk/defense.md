# minitalk Defense Guide

Banco corto de preguntas para defensa tecnica.

## 1. Preguntas base

1. Como codificas un caracter usando solo SIGUSR1 y SIGUSR2?
2. Por que necesitas estado persistente en el servidor?
3. Como detectas fin de mensaje?
4. Que diferencia tecnica hay entre mandatory y bonus?
5. Que riesgo existe si envias senales demasiado rapido?

## 2. Respuestas objetivo (resumen)

1. Cada caracter se envia en 8 bits; cada bit se mapea a una senal.
2. El handler recibe una senal por vez; sin estado no puedes reconstruir byte.
3. Se envia byte `\0`; al recibirlo, el servidor cierra con salto de linea.
4. Bonus agrega ACK bit a bit; mandatory depende de delay temporal.
5. Linux no encola senales iguales pendientes; puedes perder bits.

## 3. Preguntas de profundidad

1. Por que usar `sigaction` y no solo `signal`?
2. Para que sirve `volatile sig_atomic_t` en cliente bonus?
3. Como justificas variable global en este proyecto?
4. Como soportas multiples clientes consecutivos?

## 4. Errores tipicos de defensa

1. Decir que `next signal` siempre llega: falso en mandatory bajo carga.
2. Confundir PID del servidor con PID del cliente emisor.
3. No explicar por que el orden de bits importa (MSB -> LSB).
4. Decir que Unicode requiere logica especial cuando en realidad se envian bytes.

## 5. Mini simulacion oral

Formato:

- 3 preguntas cortas de 30 segundos,
- 2 preguntas profundas de 2 minutos.

Criterio:

- precision tecnica,
- orden del discurso,
- ejemplos concretos sobre tu codigo.

## Change Log

- 2026-04-05: guia inicial de defensa para `minitalk`.
