# 06 - Reflexion Final

## Cual fue la parte mas dificil del proyecto

Generalmente, lo mas dificil en minitalk es:
- pensar en bits y sincronizacion en lugar de strings directas,
- entender que las senales son asincronas,
- manejar riesgo de perdida de senales en mandatory.

## Por donde se empezo a construir

Ruta recomendada de construccion:
1. servidor minimo que imprime PID,
2. cliente minimo que envia una sola senal,
3. reconstruccion de 1 byte en servidor,
4. envio de string + byte nulo,
5. validacion de errores,
6. bonus con ACK.

## Idea central para empezar

Transformar cada caracter en 8 bits y mapear cada bit a una senal UNIX.
Esa es la idea madre de todo minitalk.

## Si alguien tiene cero conocimiento, por donde empezar

1. aprender procesos y PID,
2. aprender que es una senal y como usar sigaction,
3. practicar manipulacion de bits basica,
4. entender strings en C y byte nulo (\0),
5. recien despues montar cliente/servidor completo.

## Sugerencia de estudio inicial

Primero entender mandatory bien.
Luego estudiar bonus (ACK) como mejora de robustez.

## Change Log

- 2026-04-05: reflexion inicial y ruta para principiantes.
