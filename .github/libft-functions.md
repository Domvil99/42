# Funciones Implementadas en Libft

## Estado
- Cierre tecnico completado el 2026-03-09.
- Cobertura total: 43/43 funciones implementadas y compilables.
- Base oficial activa: `42/C/currentLibft/libft`.
- `42/C/libft` se mantiene como referencia historica.
- Validacion vigente sin excepciones para `INVALID_HEADER`.

## 📚 Parte 1 - Libc Functions (23 funciones)

### Character Classification
- `int ft_isalpha(int c)` - Verifica si es letra (a-z, A-Z) ✅
- `int ft_isdigit(int c)` - Verifica si es dígito (0-9) ✅
- `int ft_isalnum(int c)` - Verifica si es alfanumérico ✅
- `int ft_isascii(int c)` - Verifica si es ASCII (0-127) ✅
- `int ft_isprint(int c)` - Verifica si es imprimible ✅

### String Operations
- `size_t ft_strlen(const char *s)` - Longitud de string ✅
- `char *ft_strchr(const char *s, int c)` - Busca carácter en string ✅
- `char *ft_strrchr(const char *s, int c)` - Busca último carácter ✅
- `int ft_strncmp(const char *s1, const char *s2, size_t n)` - Compara strings (n chars) ✅
- `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` - Busca substring ✅

### Memory Operations
- `void *ft_memset(void *b, int c, size_t len)` - Llena memoria con byte ✅
- `void ft_bzero(void *s, size_t n)` - Pone n bytes a 0 ✅
- `void *ft_memcpy(void *dst, const void *src, size_t n)` - Copia memoria ✅
- `void *ft_memmove(void *dst, const void *src, size_t len)` - Copia memoria (overlap safe) ✅
- `int ft_memcmp(const void *s1, const void *s2, size_t n)` - Compara memoria ✅
- `void *ft_memchr(const void *s, int c, size_t n)` - Busca byte en memoria ✅

### String Copy/Concat
- `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` - Copia string segura ✅
- `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` - Concatena string segura ✅

### Character Conversion
- `int ft_toupper(int c)` - Convierte a mayúscula ✅
- `int ft_tolower(int c)` - Convierte a minúscula ✅

### Number Conversion
- `int ft_atoi(const char *str)` - String a entero ✅

### Memory Allocation
- `void *ft_calloc(size_t count, size_t size)` - Asigna e inicializa memoria ✅
- `char *ft_strdup(const char *s)` - Duplica string (con malloc) ✅

## 📚 Parte 2 - Additional Functions (11 funciones)

### String Manipulation
- `char *ft_substr(char const *s, unsigned int start, size_t len)` - Extrae substring ✅
- `char *ft_strjoin(char const *s1, char const *s2)` - Une dos strings ✅
- `char *ft_strtrim(char const *s1, char const *set)` - Recorta caracteres de bordes ✅
- `char **ft_split(char const *s, char c)` - Divide string por delimitador ✅
- `char *ft_itoa(int n)` - Entero a string ✅
- `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` - Aplica función a cada char ✅
- `void ft_striteri(char *s, void (*f)(unsigned int, char*))` - Itera con índice ✅

### File Descriptor Output
- `void ft_putchar_fd(char c, int fd)` - Escribe carácter a file descriptor ✅
- `void ft_putstr_fd(char *s, int fd)` - Escribe string a file descriptor ✅
- `void ft_putendl_fd(char *s, int fd)` - Escribe string con newline a fd ✅
- `void ft_putnbr_fd(int n, int fd)` - Escribe número a file descriptor ✅

## 📚 Bonus - Linked Lists (9 funciones)

### List Creation and Manipulation
- `t_list *ft_lstnew(void *content)` - Crea nuevo nodo lista ✅
- `void ft_lstadd_front(t_list **lst, t_list *new)` - Añade nodo al inicio ✅
- `int ft_lstsize(t_list *lst)` - Retorna tamaño de lista ✅
- `t_list *ft_lstlast(t_list *lst)` - Retorna último nodo ✅
- `void ft_lstadd_back(t_list **lst, t_list *new)` - Añade nodo al final ✅

### List Deletion and Iteration
- `void ft_lstdelone(t_list *lst, void (*del)(void*))` - Borra un nodo ✅
- `void ft_lstclear(t_list **lst, void (*del)(void*))` - Borra toda la lista ✅
- `void ft_lstiter(t_list *lst, void (*f)(void*))` - Itera y aplica función ✅
- `t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))` - Mapea lista ✅

## ✅ Estado de Revisión
- Inventario funcional completo: 43/43 funciones implementadas.
- Inventario canónico sincronizado con `42/C/currentLibft/libft` (43/43).
- Estructura de prueba interna normalizada: un `main` comentado por archivo `ft_*.c`.
- Migracion de pruebas (2026-03-10):
	- `main` de validacion mantenidos comentados en `42/C/libft/*.c` (histórico).
	- Casos extraidos a `42/testsLibf/test_<funcion>.c` (43 archivos).
	- Validacion de compilacion por test contra `libft.a` completada (43/43).
- Revalidación reciente completada tras ajustes manuales en archivos de
	memoria y bonus de listas, manteniendo 43/43 operativas.
- Auditoría integral adicional (2026-03-09) basada en
	`42/PDFs/2026-03-08_primera_libft.txt`:
	- compilación obligatoria + bonus OK,
	- sin errores no-header en Norminette,
	- verificación de 43/43 archivos `*.c` con una sola firma
	  `int main(void)` para pruebas internas.
- Revisión específica de headers/Makefile:
	- separación efectiva de API bonus en `libft_bonus.h`.
	- `*_bonus.c` acoplados a `libft_bonus.h`.
	- regla `bonus` optimizada para evitar relink innecesario.

## Estado operativo actual (2026-03-11)

- Tanda de limpieza interna de `42/C/libft` cerrada en commit:
	- `bfe932d` (`libft: clean legacy commented test blocks and normalize eof`).
- Naturaleza del delta aplicado:
	- limpieza de bloques de prueba comentados y ajuste menor de finales de archivo.
- Impacto validado:
	- mantenimiento/estilo interno, sin cambio funcional de la libreria.
- Actualizacion de headers en Makefile (bloque actual):
	- `42/C/libft/Makefile`
	- `42/C/ft_printf/libft/Makefile`
	- `42/C/currentLibft/libft/Makefile`
	- objetivo: consistencia de mirror + politica de timestamps humanos.

## Corrección headers libft1 (2026-03-12)
- `42/C/libft/libft.h` actualizado para incluir:
	- `typedef struct s_list ... t_list;`
	- prototipos `ft_lstnew` a `ft_lstmap`.
- `42/C/libft/libft_bonus.h` convertido en wrapper compatible sin duplicar
	declaraciones.
- Validación de cierre del cambio:
	- build obligatorio y bonus ✅
	- tests `42/testsLibf` ✅
	- Norminette final (`*.c`, `*.h`) ✅