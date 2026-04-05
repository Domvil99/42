# push_swap Reference

## 1. Deliverable Scope

Mandatory:

- `push_swap` binary.
- `Makefile`, `*.h`, `*.c`.

Bonus:

- `checker` binary.
- Implementación bonus en archivos `*_bonus.c` y `*_bonus.h`.

## 2. Input/Output Contract

### Input

Lista de enteros por argumentos.

### Output

Secuencia de operaciones válidas separadas por `\n`.

### Error Output

`Error\n` en stderr para entrada inválida.

## 3. Allowed Operations

- Swap: `sa`, `sb`, `ss`
- Push: `pa`, `pb`
- Rotate: `ra`, `rb`, `rr`
- Reverse rotate: `rra`, `rrb`, `rrr`

## 4. Data Model

- Stack `a`: contiene datos iniciales.
- Stack `b`: auxiliar vacía al inicio.
- Nodo: valor original + índice normalizado.

## 5. Algorithm Policy by Size

- `n <= 1`: no-op.
- `n == 2`: swap condicional.
- `n == 3`: casos específicos.
- `n <= 5`: extracción de mínimos.
- `n <= 500`: chunk sort.
- `n > 500`: radix por bits.

## 6. Complexity Snapshot

- Parse + validación: O(n * k) + duplicados O(n^2).
- Índices (actual): O(n^2).
- Radix: O(n * log n) en práctica por número de bits.

## 7. Makefile Reference

### Variables

- `NAME = push_swap`
- `CC = cc`
- `CFLAGS = -Wall -Wextra -Werror`
- `SRC`, `OBJ`, `LIBFT`

### Rules

- `all`: compila `$(NAME)`.
- `bonus`: compila `checker`.
- `$(NAME)`: link de objetos + `libft`.
- `checker`: link de objetos core + bonus + `libft`.
- `$(LIBFT)`: `make -C libft`.
- `clean`: limpia `.o` local + libft.
- `fclean`: limpia binario + limpieza total libft.
- `re`: reconstrucción total.

Detalle de política actual de `push_swap/libft`:

- `all` de la libft local fuerza orden interno `mandatory -> bonus` y deja
	`libft.a` listo para link.
- Además dispara build bonus de módulos hijos (`ft_printf`, `get_next_line`)
	para mantener cobertura completa del baseline integrado.

## 8. Validation Commands

```bash
make
make bonus
./push_swap 2 1
ARG="3 2 5 1 4" && ./push_swap $ARG | wc -l
printf "sa\n" | ./checker 2 1
valgrind --leak-check=full ./push_swap 3 2 1
norminette *.c *.h
```

## 9. Common Failure Patterns

1. Overflow no detectado.
2. Duplicados no detectados.
3. Secuencia que no deja `b` vacía.
4. Operaciones fuera del set permitido.
5. Faltas de limpieza en rutas de error.

## 10. Parallel Study Maintenance

Para continuidad con Chat4:

- Actualizar este archivo cuando cambie arquitectura o validación.
- Registrar cambios en `project-history.md`.
- Sincronizar con `push_swap-functions.md` y `push_swap-progress.md`.

## Change Log

- 2026-04-05: añadida referencia de separación mandatory/bonus (`make` vs
	`make bonus`) y contrato funcional de `checker`.
- 2026-04-05: actualizado flujo Makefile de `push_swap/libft` con orden
	explícito `mandatory -> bonus` y compilación de módulos hijos al final.
- 2026-03-13: referencia inicial para uso técnico y revisión rápida.
