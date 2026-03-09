# Referencia Rápida: Funciones Disponibles

Estado: obligatorio y bonus implementados, validado con compilacion
`-Wall -Wextra -Werror`.

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
- Se agregó `main` de prueba comentado en `ft_bzero.c`.
- Se corrigieron errores críticos detectados durante la revisión por lote.
- Se agregó regla `bonus` en `Makefile` para integrar `_bonus.o` en `libft.a`.