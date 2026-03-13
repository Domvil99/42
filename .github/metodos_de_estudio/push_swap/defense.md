# push_swap Defense Guide

## 1. Preguntas Técnicas Clave y Respuestas

### 1.1 ¿Por qué usar dos stacks y no un array ordenado directo?

Porque el subject limita las operaciones a un lenguaje de stack. El problema
no es ordenar con cualquier método, sino ordenar dentro del conjunto de
operaciones permitidas.

### 1.2 ¿Por qué normalizar a índices?

Permite trabajar con valores compactos [0..n-1], simplificando radix por bits
y evitando problemas de signo y magnitud de enteros grandes.

### 1.3 ¿Cómo justificas radix para n grande?

Tiene coste O(n * bits). Para entradas de 100 y 500 suele ofrecer buen
compromiso entre simplicidad de implementación y rendimiento en número de
movimientos.

### 1.4 ¿Cómo garantizas ausencia de duplicados?

Tras parsear, se compara cada elemento con los restantes (`has_duplicates`).
Si existe repetido, el programa emite `Error` y aborta.

### 1.5 ¿Qué haces en errores de parseo?

Se corta flujo temprano y se imprime `Error\n` en stderr. Además, se liberan
recursos reservados en la ruta de fallo correspondiente.

## 2. Defensa de diseño actual

### 2.1 Ventajas

- Código modular por responsabilidad.
- Operaciones primitivas claras.
- Estrategia híbrida por tamaño.
- Cleanup explícito en `main`.

### 2.2 Limitaciones honestas

- Detección de duplicados O(n^2).
- El bonus (`checker`) exige validación continua para mantener paridad con mandatory.
- `push_swap_mandatory` no incluye regla `bonus` por decisión de alcance.

## 3. Preguntas de evaluador para practicar

1. ¿Qué pasa si recibes `""`, `"   "`, `+`, `--1`?
2. ¿Cuál es la diferencia semántica entre `ra` y `rra`?
3. ¿Por qué en `sort_five` eliges rotación por distancia al tope?
4. ¿Qué garantiza que `b` quede vacía al final de radix?
5. ¿Cómo comprobarías que no hay relink innecesario?

## 4. Mini guion para explicación oral (2-3 minutos)

1. Describir restricciones del subject.
2. Explicar arquitectura modular.
3. Explicar normalización por índices.
4. Explicar small sort y radix según tamaño.
5. Cerrar con validación, memoria y norma.

## 5. Anti-patrones en defensa

1. Decir "funciona en mi máquina" sin evidencia.
2. No saber justificar complejidad.
3. No distinguir mandatory de bonus.
4. Ignorar casos inválidos de entrada.
5. Confundir salida esperada de push_swap con checker.

## Change Log

- 2026-03-13: banco inicial de defensa técnica para evaluación 42.
- 2026-03-13: actualización de limitaciones según estado real (bonus activo en push_swap y split mandatory-only).
