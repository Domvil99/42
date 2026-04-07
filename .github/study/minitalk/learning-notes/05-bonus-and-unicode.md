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

Explicacion ampliada:

1. El proyecto no "entiende" letras Unicode a nivel semantico.
	Lo que hace realmente es transportar bytes en orden.

2. UTF-8 codifica muchos caracteres en varios bytes.
	Ejemplo:
	- una letra ASCII normal suele ocupar 1 byte,
	- caracteres como `ñ`, `€` o algunos simbolos pueden ocupar 2, 3 o mas bytes.

3. Si todos los bytes llegan en el orden correcto, el terminal reconstruye el
	caracter Unicode sin problema.
	Por eso decimos que minitalk "soporta Unicode" por transporte de bytes.

4. Mandatory:
	- envia cada bit con un `usleep` fijo,
	- no espera confirmacion entre bits,
	- funciona bien en muchos casos, pero bajo carga puede perder senales.

5. Cuando se pierde un bit de un byte UTF-8:
	- ese byte puede corromperse,
	- y como un caracter Unicode puede depender de varios bytes, se puede ver
	  simbolo roto, caracter extrano o secuencia invalida.

6. Bonus con ACK:
	- cada bit enviado queda confirmado por el servidor,
	- el cliente no avanza hasta recibir ACK,
	- reduce mucho el riesgo de perder bits,
	- por eso es el modo mas robusto para mensajes con UTF-8.

7. Conclusion practica:
	- mandatory puede mostrar Unicode correctamente si no hay perdida de bits,
	- bonus es la opcion recomendada para estabilidad real,
	- la clave no es "parser Unicode", sino integridad del flujo de bytes.

## Por que bonus tiene mayor estabilidad real

La diferencia real es la sincronizacion del envio.

Mandatory:

1. El cliente envia bits con `usleep` fijo.
2. No sabe si el servidor ya proceso el bit anterior.
3. Depende del timing del sistema.
4. Bajo carga, puede haber perdida de senales y bytes corruptos.

Bonus:

1. El cliente envia 1 bit.
2. El servidor confirma ese bit con ACK (`SIGUSR1`).
3. El cliente no envia el siguiente bit hasta recibir ACK.
4. El flujo queda sincronizado bit a bit.

Resumen corto:

- mandatory depende de temporizacion,
- bonus depende de confirmacion real de recepcion,
- por eso bonus es mas estable para mensajes largos y UTF-8.

## Change Log

- 2026-04-05: bonus y unicode.
- 2026-04-07: ampliada explicacion de soporte UTF-8 en mandatory vs bonus.
- 2026-04-07: agregada comparativa explicita de estabilidad mandatory vs bonus.
