# Sesion 01 - Inicio Guiado de push_swap

## Objetivo de la sesion

Construir una base solida para entender push_swap desde cero, incluso si aun
no dominas estructuras, punteros o listas enlazadas.

Al terminar deberias poder:

- explicar que es un nodo y que es una lista enlazada,
- entender como se representa un stack con nodos,
- seguir el flujo general de `push_swap` sin perderte,
- identificar donde mirar cuando aparece una funcion nueva.

Duracion objetivo: 75 minutos (rango 60-90).

## Material a abrir

1. `.github/study_methods/push_swap/push_swap.md`
2. `.github/study_methods/push_swap/dictionary.md`
3. `.github/study_methods/push_swap/implementation.md`
4. `.github/study_methods/push_swap/case-studies.md`
5. `.github/study_methods/push_swap/validation.md`
6. `.github/study_methods/push_swap/defense.md`

## Flujo de sesion (75 min)

### Bloque 0 - Fundamentos (20 min)

Objetivo: fijar conceptos minimos antes de tocar algoritmos.

1. Diferenciar: estructura, nodo, puntero, lista enlazada y stack.
2. Dibujar en papel 3 nodos enlazados con `next`.
3. Identificar donde esta el inicio de la lista (`top` o `head`).

Checkpoint:
- si aun confundes estructura con lista, repite este bloque 5 minutos mas.

### Bloque A - Mapa de arquitectura (15 min)

Leer secciones 1-6 de `push_swap.md` y memorizar este mapa:

1. leer argumentos (`argc/argv`)
2. parsear numeros (`parse_numbers`)
3. validar formato/rango/duplicados
4. construir stack `a`
5. asignar indices normalizados
6. elegir algoritmo por tamano (`sort_dispatch`)
7. imprimir instrucciones
8. liberar memoria total

Checkpoint:
- si no puedes decir los pasos en orden, repetir 5 minutos.

### Bloque B - Trazas manuales (15 min)

Usar `case-studies.md` y resolver en papel:

1. caso n=2 (ordenado e invertido)
2. caso n=3 (al menos 2 permutaciones)
3. caso n=5 con extraccion minima y reintegracion

Checkpoint:
- justificar por que usas cada operacion.

### Bloque C - Estrategia y complejidad (10 min)

Con `push_swap.md` + `implementation.md` responder:

1. por que se normaliza a indices,
2. por que hay estrategias por tamano,
3. donde aparece O(n^2),
4. cuando conviene chunk frente a radix.

Checkpoint:
- respuestas cortas y concretas (3-5 lineas cada una).

### Bloque D - Validacion (10 min)

Con `validation.md` preparar checklist minimo:

1. casos validos funcionales,
2. casos invalidos de parsing,
3. memoria (sin leaks),
4. conteo de operaciones para 100 y 500.

Checkpoint:
- incluir comportamiento esperado para error (`Error`).

### Bloque E - Mini defensa oral (5 min)

Con `defense.md`, practicar:

1. 3 preguntas cortas (30-45 segundos),
2. 1 pregunta profunda (2 minutos).

## Recordatorio rapido (al cierre)

1. En push_swap no ordenas un array directo, reordenas nodos.
2. `a` y `b` son listas enlazadas tratadas como stacks.
3. Si controlas `top` y `next`, entiendes las operaciones.

## Entregable de la sesion

Escribe una nota breve con:

1. un concepto ya dominado,
2. una duda activa,
3. una accion concreta para la sesion 02.

## Vista previa de sesion 02

Si esta sesion queda estable, la sesion 02 se centra en:

- lectura de `implementation.md` archivo por archivo,
- flujo de navegacion con `rg` para seguir llamadas,
- defensa de operaciones (`sa`, `pb`, `ra`) con ejemplos.
