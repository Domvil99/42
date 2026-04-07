# 05 - Bonus y Unicode

## Como implementar ACK (server confirma cada senal)

Idea:
1. cliente envia 1 bit,
2. servidor procesa ese bit,
3. servidor responde ACK con SIGUSR1,
4. cliente espera ACK antes de enviar el siguiente bit.

En el proyecto actual:
- client_bonus usa una flag global de ACK.
- server_bonus envia kill(info->si_pid, SIGUSR1) tras cada bit.
- bonus_utils bloquea con pause() hasta recibir ACK.

## Como probar esta funcionalidad

1. Ejecutar server_bonus.
2. Ejecutar client_bonus con mensaje largo.
3. Verificar que no se corrompen caracteres.
4. Repetir con varios mensajes y clientes consecutivos.

## Que son caracteres Unicode

Unicode es un estandar global para representar texto de muchos idiomas.

En C y terminales modernas, normalmente se transmiten como bytes UTF-8.

## Como se implementan aqui

No hay una capa especial de parser Unicode.
El proyecto envia y recibe bytes; por eso, si la cadena de entrada esta en UTF-8,
los bytes se transmiten y reconstruyen en orden.

## Como funciona el soporte en el proyecto

- mandatory: envia bytes con delay fijo.
- bonus: envia bytes con ACK por bit.
- si no hay perdida de bits, los bytes UTF-8 se preservan.

## Change Log

- 2026-04-05: bonus y unicode.
