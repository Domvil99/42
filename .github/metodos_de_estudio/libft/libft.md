# libft Study Report

## 1. Vision del Proyecto

`libft` es la base tecnica de casi todo el track de C en 42. El objetivo no es
solo reimplementar funciones de libc, sino demostrar dominio de:

- punteros y aritmetica de memoria,
- contratos de funciones (entradas/salidas y casos borde),
- modularidad y diseño de API propia,
- estabilidad bajo compilacion estricta (`-Wall -Wextra -Werror`),
- disciplina de validacion (funcionalidad -> memoria -> norma).

Si `libft` es robusta, acelera y estabiliza proyectos posteriores como
`ft_printf`, `get_next_line`, `push_swap`, etc.

## 2. Objetivos Tecnicos Reales

Mas alla del enunciado, este proyecto te entrena en:

1. Separar comportamiento esperado vs implementacion interna.
2. Evitar undefined behavior en memoria.
3. Diseñar funciones reutilizables con naming y contratos consistentes.
4. Detectar diferencias sutiles con libc sin depender de magia negra.
5. Construir una libreria estandar propia mantenible en el tiempo.

## 3. Arquitectura Mental Recomendada

Piensa `libft` en bloques funcionales:

- Bloque A: checks de caracteres (`ft_is*`, `ft_to*`).
- Bloque B: memoria (`ft_mem*`, `ft_bzero`, `ft_calloc`).
- Bloque C: strings basicas (`ft_strlen`, `ft_strchr`, `ft_strncmp`, etc.).
- Bloque D: strings de construccion (`ft_substr`, `ft_strjoin`, `ft_split`,
  `ft_strtrim`, `ft_itoa`).
- Bloque E: salida a fd (`ft_putchar_fd`, etc.).
- Bloque F bonus: listas enlazadas (`t_list`, `ft_lst*`).

Esta separacion ayuda a depurar por familias y evitar cambios caoticos.

## 4. Funciones Criticas y Riesgos Tipicos

### 4.1 Memoria

- `ft_memcpy`: no soporta overlap. Si hay overlap, se usa `ft_memmove`.
- `ft_memmove`: requiere direccion de copia correcta (forward/backward).
- `ft_calloc`: overflow en `nmemb * size` es error critico.
- `ft_bzero`: no debe escribir fuera del buffer, incluso para `n=0`.

### 4.2 Strings

- `ft_strlen`: usar tipo correcto (`size_t`) para evitar overflow de int.
- `ft_strlcpy` / `ft_strlcat`: valor de retorno importa tanto como la copia.
- `ft_substr`: si `start` >= `len(s)`, devolver string vacio valido.
- `ft_split`: principal fuente de leaks si falla una reserva intermedia.
- `ft_itoa`: manejar `INT_MIN` sin desbordar en negacion.

### 4.3 Listas bonus

- `ft_lstclear`: liberar contenido + nodos de forma segura.
- `ft_lstmap`: si falla crear un nodo, limpiar todo lo creado.
- `ft_lstdelone`: contrato claro entre `del(content)` y `free(node)`.

## 5. Estrategia de Implementacion (Orden Productivo)

1. Implementar funciones simples y puras primero (`ft_is*`, `ft_to*`).
2. Continuar con memoria (`ft_mem*`) y utilidades base (`ft_strlen`).
3. Construir funciones de string complejas reutilizando base validada.
4. Cerrar con `ft_split` y `ft_itoa` (normalmente las mas delicadas).
5. Implementar bonus de listas cuando mandatory este estable.

Regla oro: no escalar complejidad si la base aun falla tests.

## 6. Validacion Profesional

### 6.1 Funcionalidad

- Comparar contra libc cuando aplique.
- Cubrir casos borde:
  - entradas vacias,
  - n=0,
  - punteros null segun contrato,
  - valores extremos (`INT_MIN`, `INT_MAX`).

### 6.2 Memoria

- Ejecutar sanitizers (`ASAN/UBSAN`) o valgrind.
- Confirmar:
  - 0 leaks,
  - 0 invalid read/write,
  - 0 invalid free,
  - rutas de error limpian recursos.

### 6.3 Norminette

- Ejecutar al final de cierre por lote completo.
- Corregir sin romper semantica.
- Evitar refactors masivos de estilo antes de estabilizar funcionalidad.

## 7. Anti-Patrones Frecuentes

1. Declarar victoria con tests felices y sin casos borde.
2. Corregir solo norma sin validar memory safety.
3. Mezclar responsabilidades en funciones largas e ilegibles.
4. No manejar error de `malloc` en rutas intermedias.
5. Asumir que "si compila, funciona".

## 8. Checklist de Defensa Tecnica (Oral/Revision)

Debes poder explicar con seguridad:

1. Diferencia exacta entre `memcpy` y `memmove`.
2. Por que `strlcpy/strlcat` retornan lo que retornan.
3. Como preveniste leaks en `ft_split`.
4. Como trataste `INT_MIN` en `ft_itoa`.
5. Como garantizas no romper API en evoluciones futuras.
6. Orden de validacion aplicado y evidencia de cada etapa.

## 9. Repaso Activo

### Preguntas rapidas

1. Que pasa si `nmemb * size` desborda en `ft_calloc`?
2. Que debe devolver `ft_substr` si `start` esta fuera de rango?
3. Cuando `ft_memcpy` es incorrecto aunque no crashee?
4. Cual es el fallo clasico de `ft_lstmap`?

### Mini retos

1. Reescribe `ft_split` en pseudocodigo con cleanup completo en cada error.
2. Dibuja memoria paso a paso de un `memmove` con overlap inverso.
3. Argumenta por que `ft_strlcat` puede truncar y aun asi estar correcta.

## 10. Evolucion Continua

Este documento no es estatico. Debe crecer cada vez que:

- se detecte un bug real durante un proyecto futuro,
- cambie la interpretacion de una spec,
- aparezca una mejor explicacion pedagogica,
- se aprenda una tecnica de depuracion mas efectiva.

## Change Log

- 2026-03-12: version inicial completa para proyecto `libft` validado y
  cerrado con baseline corregida de spec.
