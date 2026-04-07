# 02 - Build y Makefile

## Como funciona el Makefile principal

El Makefile define:
- compilador y flags,
- nombres de ejecutables mandatory y bonus,
- fuentes comunes y especificas,
- reglas para compilar, limpiar y recompilar.

Flujo normal de ejecucion:
1. make
2. construye libft si no esta al dia
3. compila objetos comunes + server/client
4. enlaza ejecutables server y client

Flujo bonus:
1. make bonus
2. reutiliza objetos comunes
3. compila objetos bonus
4. enlaza server_bonus y client_bonus

## Que es relink

Relink es volver a enlazar ejecutables sin necesidad real, aunque no haya
cambios en dependencias.

## Como detectar relink

1. Ejecuta make dos veces seguidas.
2. Si en la segunda ejecucion vuelve a enlazar binarios sin cambios, hay relink.
3. Repite para make bonus y para make -C libft.

Ejemplo de verificacion:
- primera vez: compila y enlaza.
- segunda vez: deberia responder que no hay nada por hacer.

## Como evitar relink

1. Declarar dependencias correctas de cada target.
2. Mantener lista de objetos separada por ejecutable.
3. Evitar comandos de link dentro de reglas que se disparan siempre.
4. Mantener timestamps consistentes (no tocar binarios manualmente).

## Makefiles internos (libft)

Se aplica la misma logica:
- si libft no cambia, make -C libft no debe recompilar ni relinkar.

## Change Log

- 2026-04-05: respuestas de Makefile y relink.
