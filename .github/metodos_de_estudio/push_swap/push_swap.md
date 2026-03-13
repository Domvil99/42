# push_swap Study Report

## 1. Vision del Proyecto

`push_swap` es un proyecto de algoritmia aplicada con restricciones severas.
No basta con ordenar: hay que ordenar con un lenguaje de operaciones limitado,
minimizando movimientos y manteniendo robustez de parsing, memoria y errores.

Objetivo real de aprendizaje:

- Modelar datos en estructuras simples y fiables (stacks enlazados).
- Diseñar estrategia algorítmica por escala de entrada.
- Defender complejidad y decisiones técnicas ante evaluación oral.
- Implementar flujo de validación profesional: spec -> memoria -> norma.

## 2. Subject y Reglas Obligatorias

Fuente canónica usada para este informe:
`42/PDFs/2026-03-13_push_swap_actualizado.txt`.

### 2.1 Programas esperados

- Mandatory: `push_swap`.
- Bonus: `checker`.

### 2.2 Operaciones permitidas

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

### 2.3 Restricciones críticas

- Sin variables globales.
- Compilación con `-Wall -Wextra -Werror`.
- Manejo de errores obligatorio (`Error\n` en stderr para entradas inválidas).
- Entrada vacía: no imprimir nada y salir limpio.

### 2.4 Benchmarks de evaluación (referencia del subject)

- 100 números: objetivo alto < 700 operaciones.
- 500 números: objetivo alto <= 5500 operaciones.

## 3. Arquitectura Mental Recomendada

### 3.1 Pipeline completo

1. Parseo de entrada.
2. Validación (sintaxis numérica, rango int, duplicados).
3. Construcción de stack `a`.
4. Normalización por índices (ranking).
5. Selección de estrategia según tamaño.
6. Emisión de instrucciones.
7. Liberación total de memoria.

### 3.2 Invariantes de seguridad

- `a` y `b` siempre son listas enlazadas válidas.
- Ninguna operación debe romper punteros aun en casos de tamaño 0/1.
- El parser no acepta tokens ambiguos o fuera de rango int.
- Toda reserva tiene ruta de liberación.

## 4. Estrategias de Ordenación por Tamaño

### 4.1 n <= 1

No hacer nada.

### 4.2 n == 2

Un `sa` si están invertidos.

### 4.3 n == 3

Resolver con tabla corta de casos (comparando índices).

### 4.4 4 <= n <= 5

- Extraer mínimos a `b`.
- Ordenar 3 en `a`.
- Reintegrar con `pa`.

### 4.5 n > 5

Radix binario sobre `index` normalizado:

- Recorrer bits de menor a mayor.
- Bit 0 -> `pb`.
- Bit 1 -> `ra`.
- Vaciar `b` con `pa` al final de cada bit.

## 5. Complejidad y Justificación

### 5.1 Parsing y validación

- Sintaxis/rango: O(n * k) donde `k` es longitud media de token.
- Duplicados en implementación actual: O(n^2).

### 5.2 Sort small

- Coste constante (n <= 5).

### 5.3 Sort radix

- O(n * bits).
- Como `bits ~= log2(n)`, el coste es O(n log n) en términos de pasos de bit.

## 6. Makefile: Guía Completa

### 6.1 De un Makefile básico (estilo libft1) a push_swap

Estructura mínima heredada:

- Variables (`NAME`, `CC`, `CFLAGS`, `RM`).
- Reglas estándar (`all`, `clean`, `fclean`, `re`).
- Regla de objetos (`%.o: %.c`).

Adaptación para push_swap:

- Añadir lista de fuentes del proyecto (`SRC`).
- Añadir dependencia con `libft/libft.a`.
- Enlazar objetos + libft para generar ejecutable final.

### 6.2 Adaptación para funcionar en current/base evolutiva

Principio operativo:

- Mantener `libft` como submódulo compilable con `make -C libft`.
- Evitar rutas absolutas.
- Mantener regla de no relink: recompilar solo cuando cambian dependencias.

### 6.3 Explicación de reglas

#### `NAME`

Nombre del binario final (`push_swap`).

#### `all`

Objetivo por defecto. Debe construir `$(NAME)`.

#### `clean`

Elimina objetos locales y ejecuta `make clean -C libft`.

#### `fclean`

Incluye `clean` + elimina binario final + `make fclean -C libft`.

#### `re`

Atajo de reconstrucción total (`fclean` + `all`).

#### Reglas de compilación

- `%.o: %.c push_swap.h` compila cada fuente con cabecera como dependencia.

#### Reglas de dependencias

- `$(NAME)` depende de `$(OBJ)` y `$(LIBFT)`.
- `$(LIBFT)` dispara compilación de libft.

#### Regla bonus

Actualmente no existe en el Makefile del proyecto.
Para cumplir bonus de subject, se recomienda agregar:

- `BONUS_NAME = checker`
- `bonus: $(BONUS_NAME)`
- Fuentes específicas de checker y enlace contra libft.

## 7. Errores Frecuentes y Prevención

1. Aceptar tokens inválidos (`--1`, `1a`, `+`).
2. No detectar overflow int.
3. Duplicados silenciosos.
4. Operaciones que escriben instrucción aunque no cambien estado esperado.
5. Leaks en rutas de fallo de parseo.
6. Olvidar validar rendimiento en 100/500.

## 8. Ruta para Rehacer push_swap desde Cero

1. Diseñar `t_node` y helpers de lista.
2. Implementar operaciones primitivas (sin print y luego con print flag).
3. Implementar parser robusto + errores.
4. Construir stack e índice normalizado.
5. Implementar sort para 2/3/5.
6. Implementar radix para grandes.
7. Montar Makefile y tests manuales.
8. Validar contra checker y benchmarks.
9. Cerrar memoria y Norminette.

## 9. Plan de Estudio por Etapas

### Etapa A: Fundamentos

- Entender cada operación sobre ejemplos de 3 elementos.

### Etapa B: Parsing y robustez

- Practicar entradas válidas/invalidas y rutas de error.

### Etapa C: Algoritmos

- Trazar a mano `sort_three`, `sort_five`, `sort_radix`.

### Etapa D: Defensa técnica

- Responder preguntas de complejidad, decisiones y edge cases.

## 10. Integración con Chat2 y Chat4

- Chat2: documentar cada módulo implementado en paralelo (incremental).
- Chat4: convertir avances en material pedagógico ampliable.
- Este archivo es núcleo; los anexos contienen profundidad por tema.

## 11. Mapa de Anexos

- `implementation.md`: arquitectura y código real.
- `validation.md`: pruebas funcionales, memoria y rendimiento.
- `defense.md`: banco de preguntas para evaluación.
- `case-studies.md`: trazas paso a paso.
- `dictionary.md`: glosario técnico.

## Change Log

- 2026-03-13: versión inicial integral para estudio en paralelo a implementación.
