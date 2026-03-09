---
name: quick-reference
description: "Quick reference guide for C development in libft project with common commands, shortcuts, and validation tips."
---

# 📖 Quick Reference: Libft C Development

## Workspace Map (Current)

```text
Raiz/
├── 42/
│   ├── C/
│   │   └── libft/
│   ├── PDFs/
│   └── testsLibf/
├── .github/
│   ├── QUICK_REFERENCE.md
│   ├── libft-functions.md
│   ├── libft-progress.md
│   ├── libft-reference.md
│   ├── projects-index.md
│   ├── project-history.md
│   └── workflow-rules.md
└── .vscode/
```

## Tracking Files You Must Keep Updated

### When `42/C/libft` changes
- `.github/libft-functions.md`
- `.github/libft-progress.md`
- `.github/libft-reference.md`

### When a new project is added under `42/C/`
- `.github/projects-index.md`
- `.github/project-history.md`

### When a support directory is added under `42/` (outside `42/C/`)
- `.github/projects-index.md`
- `.github/project-history.md`
- `.github/QUICK_REFERENCE.md`

### When a new instruction `.txt` is received
- Save into `42/PDFs/`
- Log it in `.github/project-history.md`
- Apply relevant spec changes in tracking files

## Tracking 30s Checklist

1. Identify change type: `project`, `support-dir`, or `spec-txt`.
2. Update only required files:
- `project` (`42/C/...`): `.github/projects-index.md`, `.github/project-history.md`
- `support-dir` (`42/...` outside `42/C/`): `.github/projects-index.md`,
    `.github/project-history.md`, `.github/QUICK_REFERENCE.md`
- `spec-txt` (`42/PDFs/...`): save with `YYYY-MM-DD_<topic>.txt` and log in
    `.github/project-history.md`
3. Run quick route check in docs:
```bash
rg -n "C/PDFs|C/libft" .github
```

## Tracking Copy/Paste Template

Add this block into `.github/project-history.md`:

```md
## YYYY-MM-DD

- Change type: project | support-dir | spec-txt
- Paths changed:
    - `path/one`
    - `path/two`
- Tracking docs updated:
    - `.github/projects-index.md`
    - `.github/project-history.md`
    - `.github/QUICK_REFERENCE.md`
- Notes:
    - short summary
```

## 🔨 Comandos Básicos de Compilación

```bash
# Compilar librería completa (obligatorio: -Wall -Wextra -Werror)
make

# Compilar limpiar
make clean

# Limpieza total
make fclean

# Recompilar todo
make re

# Compilar con flags OBLIGATORIOS del proyecto
gcc -Wall -Wextra -Werror -c ft_atoi.c

# Compilar y enlazar
gcc -Wall -Wextra -Werror ft_atoi.c -o program
```

## ✅ Validación Rápida de Norminette

```bash
# Usar siempre la versión local del proyecto
NORMI="/home/domvil99/empresa/42/newLibft/Raiz/.tools/norminette-venv/bin/python3 -m norminette"

# Validar un archivo
$NORMI ft_strlen.c

# Validar todos los archivos .c
$NORMI *.c

# Validar header
$NORMI libft.h
```

## 🐛 Debugging con lldb

```bash
# Compilar con debugger
gcc -g -Wall -Wextra -Werror -c ft_atoi.c

# Iniciar lldb
lldb ./program

# Comandos básicos en lldb
break main           # Breakpoint en main
step                 # Paso siguiente (entra en funciones)
next                 # Paso siguiente (sin entrar)
continue             # Continuar ejecución
print variable       # Ver valor de variable
backtrace           # Ver stack
quit                # Salir
```

## 🔍 Validación de Memoria

```bash
# Compilar para valgrind
gcc -g -Wall -Wextra -Werror -c ft_atoi.c

# Buscar memory leaks
valgrind --leak-check=full ./program

# Perfiles detallados
valgrind --leak-check=full --show-leak-kinds=all ./program
```

## 📋 Checklist antes de Commit

- [ ] Código pasa Norminette (`$NORMI *.c`)
- [ ] Compila sin warnings (`gcc -Wall -Wextra -Werror`)
- [ ] Sin memory leaks (`valgrind`)
- [ ] Funciona en edge cases (NULL, vacío, etc.)
- [ ] Header actualizado con proto funciones
- [ ] Tests locales pasan
- [ ] Comentarios claros en código complejo

## 🎯 Mejores Prácticas por Tipo de Función

### String Functions
```c
// Siempre validar strings
if (!s)
    return (NULL);

// Longitud máxima
size_t  ft_strlen(const char *s);

// Copia segura
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

### Memory Functions
```c
// Alocar y validar
void    *ptr = malloc(size);
if (!ptr)
    return (NULL);

// Liberar correctamente
if (ptr)
    free(ptr);
```

### Utility Functions
```c
// Funciones tipo to_X
int     ft_toupper(int c);
int     ft_tolower(int c);

// Funciones tipo is_X
int     ft_isalpha(int c);
int     ft_isdigit(int c);
```

## 📊 Estructura Típica de Función

```c
// Nombre consistente (ft_)
// Tipo de retorno claro
// Parámetros validados
t_type  ft_function(t_param param1, t_param param2)
{
    // Validación de entrada
    if (!param1)
        return (ERROR_VALUE);
    
    // Inicialización de variables
    t_var   var;
    
    // Lógica principal
    // Máximo 25 líneas
    
    // Retorno explícito
    return (result);
}
```

## 🎯 Archivos Bonus
Los bonus deben estar en archivos separados con sufijo `_bonus`:
- `ft_lstnew_bonus.c`, `ft_lstadd_front_bonus.c`, etc.
- Header: `libft_bonus.h` (incluye prototipos de bonus)
- Compilación: `make bonus` (regla en Makefile)

## 🔗 Integración en Makefile

```makefile
NAME    = libft.a
SRCS    = ft_strlen.c ft_atoi.c ...
OBJS    = $(SRCS:.c=.o)
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

## 🆘 Errores Comunes

| Error | Causa | Solución |
|-------|-------|----------|
| `undefined reference to 'ft_strlen'` | Función no compilada | Añade .c al Makefile |
| `line too long` | Norminette | Divide línea con `\` o refactoriza |
| `segmentation fault` | Acceso memoria inválida | Valida punteros con NULL |
| `memory leak` | malloc sin free | Libra memoria antes de return |
| `implicit declaration` | Falta prototipo en header | Añade a libft.h |

## 💡 Tips Productividad

1. **Snippets personalizados**: Crea snippets para funciones frecuentes
2. **Live Coding**: Usa autocomplete de Copilot (Ctrl+Space)
3. **Format on Save**: Clang-format automático tras guardar
4. **Git Workflow**:
   ```bash
   git add .
   git commit -m "feat: add ft_strlen with 42 norm"
   git push
   ```
5. **Norminette Hook**: Ejecuta norminette antes de commit para evitar errores

---

**Versión**: 1.0 | **Actualizado**: Marzo 2026
