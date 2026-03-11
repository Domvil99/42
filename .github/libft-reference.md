# Referencia Rápida: Funciones Disponibles

Estado: cierre tecnico completado (2026-03-09), obligatorio y bonus
implementados, validado con compilacion `-Wall -Wextra -Werror`.

Uso recomendado: base estable para los siguientes proyectos de `42/C/`.
Nota temporal: pendiente correccion de headers Norminette (`INVALID_HEADER`).

## 🔤 String Functions (Obligatorio Validado)
| Función | Descripción | Uso |
|---------|------------|-----|
| ft_strlen | Longitud de string | Verificar tamaño |
| ft_strchr | Busca carácter en string | Encontrar posición |
| ft_strrchr | Busca último carácter | Encontrar última ocurrencia |
| ft_strncmp | Compara strings (n chars) | Comparar parcialmente |
| ft_strnstr | Busca substring | Encontrar subcadena |
| ft_strlcpy | Copia string segura | Copiar con límite |
| ft_strlcat | Concatena string segura | Unir con límite |
| ft_toupper | Convierte a mayúscula | Cambiar caso |
| ft_tolower | Convierte a minúscula | Cambiar caso |
| ft_substr | Extrae substring | Partir string |
| ft_strjoin | Une dos strings | Concatenar |
| ft_strtrim | Recorta caracteres | Limpiar bordes |
| ft_split | Divide string por delimitador | Separar palabras |
| ft_itoa | Entero a string | Convertir número |
| ft_strmapi | Aplica función a cada char | Transformar string |
| ft_striteri | Itera con función | Procesar con índice |

## 🧠 Memory Functions (Obligatorio Validado)
| Función | Descripción | Uso |
|---------|------------|-----|
| ft_memset | Llena memoria con byte | Inicializar bloques |
| ft_bzero | Pone n bytes a 0 | Limpiar memoria |
| ft_memcpy | Copia memoria | Copiar datos |
| ft_memmove | Copia memoria (overlap safe) | Copiar seguro |
| ft_memcmp | Compara memoria | Comparar bloques |
| ft_memchr | Busca byte en memoria | Encontrar byte |
| ft_calloc | Asigna e inicializa memoria | Reservar inicializado |
| ft_strdup | Duplica string | Copiar string |

## 🔗 List Functions (Bonus Implementado)
| Función | Descripción | Uso |
|---------|------------|-----|
| ft_lstnew | Crea nuevo nodo | Iniciar lista |
| ft_lstadd_front | Añade al inicio | Insertar principio |
| ft_lstsize | Tamaño de lista | Contar elementos |
| ft_lstlast | Último nodo | Acceder final |
| ft_lstadd_back | Añade al final | Insertar final |
| ft_lstdelone | Borra un nodo | Eliminar uno |
| ft_lstclear | Borra toda lista | Limpiar lista |
| ft_lstiter | Itera lista | Procesar elementos |
| ft_lstmap | Mapea lista | Transformar lista |

## ❌ Funciones Prohibidas 42 School
- printf, malloc (en algunas funciones), strcpy, strcat

## 🧪 Notas de Revisión
- Todos los `main` de prueba quedaron comentados.
- Migracion aplicada (2026-03-10): cada `main` de `42/C/libft/*.c` tiene
	su espejo descomentado en `42/testsLibf/test_<funcion>.c`.
- Validacion actual: `make` + `make bonus` en `42/C/libft` y compilacion
	de 43/43 tests contra `libft.a`.
- Se agregó `main` de prueba comentado en `ft_bzero.c`.
- Se corrigieron errores críticos detectados durante la revisión por lote.
- Se agregó regla `bonus` en `Makefile` para integrar `_bonus.o` en `libft.a`.
- Se ejecutó nuevo ciclo de validación final con compilación completa
	(`make clean && make && make bonus`) y limpieza de estilo no-header.
- Se confirmó estabilidad tras cambios recientes en `ft_memcpy.c`,
	`ft_lstdelone_bonus.c` y `ft_lstmap_bonus.c` con compilación completa
	y revisión de Norminette (excepto política temporal de header).
- Auditoría integral (2026-03-09) alineada al `.txt` oficial:
	- `make` y `make bonus` correctos.
	- sin errores de Norminette fuera de `INVALID_HEADER`.
	- 43/43 `*.c` con un único `int main(void)` para prueba interna
	  (en bloque comentado).
- Ajuste de arquitectura `.h` + `Makefile`:
	- `libft.h` expone solo API obligatoria/parte 2.
	- `libft_bonus.h` concentra `t_list` y API `ft_lst*`.
	- `bonus` en `Makefile` sin relink innecesario en ejecuciones repetidas.

## Estado actual de trabajo (2026-03-11)
- Lote pendiente detectado en `42/C/libft/*.c`:
  - limpieza de comentarios de pruebas legacy y ajustes menores de formato.
- No se detectan cambios pendientes de API en cabeceras publicas.
- Referencia de uso se mantiene vigente para proyectos siguientes.