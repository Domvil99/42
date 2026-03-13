# Quick Reference: Cierre de proyectos 42

## Protocolo de cierre

### Cierre total (validación completa, cierre completo, etc.)
- Validar funcionamiento según el .txt
- Verificar memoria y estabilidad
- Ejecutar Norminette
- git add, commit, push
- Actualizar .md y README
- Evidencia de cierre en README y tracking

### Cierre express (auditoría express)
- Solo tras cierre total reciente
- Revisión rápida, mínima batería
- Actualizar README y tracking

## Norminette
 - Siempre después de validar funcionamiento

## Git workflow
 - Mensajes de commit funcionales

## Regla de oro: preservación de proyectos en /C
- Ningún proyecto en `42/C/` puede perder funcionamiento tras su cierre.
- Cada directorio es autónomo: debe compilar y funcionar por separado.
- Prohibido modificar fuentes de un proyecto cerrado sin solicitud explícita.

## Limpieza post-cierre
- Eliminar temporales y binarios fuera del proyecto.
- `make fclean` dentro del proyecto.
- Verificar `git status` limpio en ambos repos.
- Registrar limpieza en `project-history.md`.
- `git add`, `commit`, `push` final.

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
│   │   ├── libft/
│   │   ├── ft_printf/
│   │   ├── push_swap/
│   │   ├── push_swap_mandatory/
│   │   └── currentLibft/
│   ├── PDFs/
│   │   ├── 2026-03-08_primera_libft.txt
│   │   ├── 2026-03-10_ft_printf.txt
│   │   └── 2026-03-12_get_next_line_actualizado.txt
│   ├── testsLibf/
│   │   └── README.md
│   ├── tests_ft_printf/
│   │   └── README.md
│   ├── tests_currentLibft/
│   │   └── README.md
│   ├── tests_push_swap/
│   │   └── README.md
│   ├── tests_push_swap_mandatory/
│   │   └── README.md
│   └── tests_<project_name>/
│       └── README.md
├── .github/
│   ├── QUICK_REFERENCE.md
│   ├── chat-handoff.md
│   ├── copilot-instructions.md
│   ├── deferred-tasks.md
│   ├── instructions/
│   │   ├── c-coding.instructions.md
│   │   └── config-guide.instructions.md
│   ├── libft-functions.md
│   ├── libft-progress.md
│   ├── libft-reference.md
│   ├── ft_printf-functions.md
│   ├── ft_printf-progress.md
│   ├── ft_printf-reference.md
│   ├── push_swap-functions.md
│   ├── push_swap-progress.md
│   ├── push_swap-reference.md
│   ├── projects-index.md
│   ├── project-history.md
│   ├── reports/
│   ├── currentLibft/
│   │   └── integration-manifest.md
│   ├── metodos_de_estudio/
│   │   ├── global-dictionary.md
│   │   ├── libft/
│   │   │   └── libft.md
│   │   │   └── dictionary.md
│   │   ├── ft_printf/
│   │   │   └── ft_printf.md
│   │   │   └── dictionary.md
│   │   ├── get_next_line/
│   │   │   └── get_next_line.md
│   │   │   └── dictionary.md
│   │   ├── currentLibft/
│   │   │   └── currentLibft.md
│   │   │   └── dictionary.md
│   │   ├── push_swap/
│   │   │   └── push_swap.md
│   │   │   └── implementation.md
│   │   │   └── validation.md
│   │   │   └── defense.md
│   │   │   └── case-studies.md
│   │   │   └── dictionary.md
│   │   └── overview.md
│   └── workflow-rules.md
├── .tools/
└── .vscode/
```

## Chat Map

- Chat1: administración de flujo, coordinación, reglas y tracking.
- Chat2: implementación/refactor/debug de C.
- Chat3: gestión de pendientes (`to-do`), prioridades y backlog.
- Chat4: métodos de estudio, repaso técnico y reportes de aprendizaje.

Regla rápida:
- Si es código C ejecutable -> Chat2.
- Si es organización de pendientes -> Chat3.
- Si es explicación/repaso/estudio -> Chat4.

## Git Layout (Dual Repo)

- Delivery repo root (projects to submit): `42/C/`
- Workspace repo root (docs/tooling/tracking): `Raiz/`
- Daily rule:
    - If you are coding a deliverable project (`libft` and next ones), run
        `git add`, `git commit`, `git push` inside `42/C/`.
    - If you are updating workflow/docs/tooling (`.github`, `.vscode`, `42/PDFs`,
        `42/testsLibf`, `42/tests_currentLibft`, `42/tests_ft_printf`,
        `42/tests_<project_name>`), run
        git in `Raiz/`.

Quick root check before commit:

```bash
git rev-parse --show-toplevel
```

Commit message guardrail:
- Do not use commit messages about user changes or metadata changes.
- Avoid references to username, date, or email updates in commit titles/bodies.
- Prefer functional messages (example: `sync(currentLibft): align ft_printf integration headers`).

## Canonical Root Path (Default)

- Primary Linux path (use by default):
    - `/home/domvil99/empresa/42/newLibft/Raiz`
- Windows/WSL equivalent (reference only):
    - `\\wsl.localhost\Ubuntu\home\domvil99\empresa\42\newLibft\Raiz`
- Rule:
    - Normalize all incoming paths to the Linux path before running commands.
    - Do not operate from another root unless it is verified and explicitly requested.

Quick verification:

```bash
pwd
realpath /home/domvil99/empresa/42/newLibft/Raiz
```

## Tracking Files You Must Keep Updated

### End of Work Block (mandatory)
- Before switching to a new topic/project, update pending snapshot file in:
    - `.github/reports/workblock-pending-status.md`
- Keep only still-pending items; delete lines for completed tasks.
- Split the snapshot by repo:
    - `Repo entrega C (42/C/)`
    - `Repo workspace Raiz`

### When `42/C/libft` changes
- `.github/libft-functions.md`
- `.github/libft-progress.md`
- `.github/libft-reference.md`

### When `42/C/ft_printf` changes
- `.github/ft_printf-functions.md`
- `.github/ft_printf-progress.md`
- `.github/ft_printf-reference.md`
- Note (2026-03-11): ft_printf tracking is in closure state.
  Post-closure updates should be logged first in `.github/project-history.md`.

### When `42/C/push_swap` changes
- `.github/push_swap-functions.md`
- `.github/push_swap-progress.md`
- `.github/push_swap-reference.md`
- `.github/metodos_de_estudio/push_swap/push_swap.md` (si hay cambios de arquitectura
    o estrategia)

### currentLibft Integration Rule
- `42/C/currentLibft` must keep a single parent `libft` at:
    - `42/C/currentLibft/libft`
- Integrated child projects (example: `ft_printf`) live under:
    - `42/C/currentLibft/libft/<project>`
- Do not keep a nested child `libft` inside integrated projects.
- Keep equivalent headers synchronized across mirrors and preserve legacy
    `Created` timestamps for original libft files.
- Coexistence note:
    - `42/C/ft_printf` (standalone deliverable project) can coexist with
      `42/C/currentLibft/libft/ft_printf` (integrated copy) without being a
      structural violation.
- Forbidden paths inside `currentLibft`:
    - `42/C/currentLibft/ft_printf`
    - `42/C/currentLibft/libft/ft_printf/libft`

### New Project Bootstrap (using currentLibft base)
- For a new project (example `push_swap`):
    1. Create `42/C/push_swap/`.
    2. Copy base library from `42/C/currentLibft/libft` to
       `42/C/push_swap/libft`.
    3. Keep project deliverable files in root of `42/C/push_swap/`
       (`*.c`, `*.h`, `Makefile` of the project itself).
    4. Keep integrated child projects only under that local `libft/` when
       truly required by project architecture.

### When a new project is added under `42/C/`
- `.github/projects-index.md`
- `.github/project-history.md`

### When a support directory is added under `42/` (outside `42/C/`)
- `.github/projects-index.md`
- `.github/project-history.md`
- `.github/QUICK_REFERENCE.md`

### When `.github/metodos_de_estudio/` changes
- `.github/project-history.md`
- `.github/QUICK_REFERENCE.md`

Mandatory study dictionary policy:
- Keep one global dictionary at `.github/metodos_de_estudio/global-dictionary.md`.
- Keep one project dictionary at
    `.github/metodos_de_estudio/<project>/dictionary.md`.
- Dictionary format baseline: technical glossary + mini examples.

### When a new instruction `.txt` is received
- Save into `42/PDFs/`
- Transcribe full content (no summary, no omission of normative details)
- Preserve section semantics: title, summary, index, chapters,
  requirements, bonus, delivery/evaluation
- Log it in `.github/project-history.md`
- Apply relevant spec changes in tracking files

## Tracking 30s Checklist

1. Identify change type: `project`, `support-dir`, or `spec-txt`.
2. Update only required files:
- `project` (`42/C/...`): `.github/projects-index.md`, `.github/project-history.md`
- `support-dir` (`42/...` outside `42/C/`): `.github/projects-index.md`,
    `.github/project-history.md`, `.github/QUICK_REFERENCE.md`
- `spec-txt` (`42/PDFs/...`): save with `YYYY-MM-DD_<topic>.txt` and log in
    `.github/project-history.md`; transcribe complete content preserving
    section semantics
3. Run quick route check in docs:
```bash
rg -n "42/PDFs|42/C/libft|42/C/ft_printf" .github
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

# Build integrado currentLibft
cd 42/C/currentLibft && make && make bonus
```

## ✅ Validación Rápida de Norminette

```bash
# Definir raíz del workspace (repo Raiz)
WORKSPACE_ROOT="/home/domvil99/empresa/42/newLibft/Raiz"

# Usar siempre la versión local del workspace
NORMI="$WORKSPACE_ROOT/.tools/norminette-venv/bin/python3 -m norminette"

# Validar un archivo
$NORMI ft_strlen.c

# Validar todos los archivos .c
$NORMI *.c

# Validar header
$NORMI libft.h
```

## VS Code: Norminette Automation

- Task de correccion automatica por archivo activo:
    - `Normi Autofix: Active File`
- Task de chequeo rapido (sin excepciones):
    - `Normi Check: Active File`
- Task de barrido completo en `ft_printf` (sin excepciones):
    - `Normi Check: ft_printf All`
- Task de barrido completo para cualquier proyecto `42/C/<project>`:
    - `Normi Check: Project All`
- Atajo dedicado sin colision con shortcuts comunes:
    - `Ctrl+Alt+Shift+N`, luego `Ctrl+Alt+Shift+F`
- Atajo de chequeo rapido:
    - `Ctrl+Alt+Shift+N`, luego `Ctrl+Alt+Shift+C`
- Atajo de barrido completo `ft_printf`:
    - `Ctrl+Alt+Shift+N`, luego `Ctrl+Alt+Shift+A`
- Atajo de barrido completo por proyecto:
    - `Ctrl+Alt+Shift+N`, luego `Ctrl+Alt+Shift+P`

Flujo recomendado por archivo:
1. Editar el `.c` o `.h`.
2. Ejecutar atajo de autofix.
3. Si quedan errores, ejecutar atajo de check para ver solo accionables.

Si un atajo no responde:
1. Ejecutar `Tasks: Run Task` y lanzar la tarea equivalente.
2. Verificar que el keybinding tambien exista en `Keyboard Shortcuts (JSON)`
    de usuario.

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

## Orden Obligatorio de Revisión

Para este y todos los proyectos:
1. Validar comportamiento segun la especificacion `.txt`.
2. Validar memoria y estabilidad.
3. Ejecutar Norminette al final como cierre.

Regla practica:
- Si la funcionalidad no esta en verde, no empezar limpieza masiva de estilo.

## 📋 Checklist antes de Commit

- [ ] Verifiqué la raíz git (`git rev-parse --show-toplevel`)
- [ ] Si es entrega, estoy en repo `42/C/`
- [ ] Si es docs/tooling, estoy en repo `Raiz/`
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
    # Entrega (desde 42/C/)
    git add .
    git commit -m "feat: add ft_strlen with 42 norm"
    git push

    # Workspace docs/tooling (desde Raiz/)
    git add .github .vscode 42/PDFs 42/testsLibf 42/tests_currentLibft 42/tests_push_swap
    git commit -m "docs: update tracking and workflow"
    git push
   ```
5. **Norminette Hook**: Ejecuta `$NORMI` antes de commit para evitar errores

---

**Versión**: 1.0 | **Actualizado**: Marzo 2026

### New Project Test Checklist
- Create `42/tests_<project_name>/`
- Add `README.md` with compile/run commands
- Register in `.github/projects-index.md`
- Log in `.github/project-history.md`
- Re-run `42/tests_currentLibft/` before integrating into libft

## Inter-Chat Handoff (Chat1 <-> Chat2+)

- Archivo puente oficial: `.github/chat-handoff.md`
- Uso rapido:
1. Chat1 crea entrada con `ID`, `Topic`, `From -> To`, `Task`, `Files`,
     `Status` y criterio de cierre.
2. Chat receptor confirma ACK cambiando a `WIP` antes de ejecutar.
3. Chat especialista actualiza estado en la misma fila (`WIP/BLOCKED/DONE`).
4. Si la tarea no corresponde al chat, marcar `BLOCKED` y redireccionar.
5. Cerrar tarea moviendo o reflejando resultado en `Closed Handoffs`.
- Tema comun:
    - Si el usuario define puntos en comun, registrarlos en `Shared Topics` y
        reutilizar el mismo `Topic ID` en todos los handoffs relacionados.
- Regla clave: no existe canal directo entre chats; el handoff file es la
    fuente canonica de continuidad.
- Reporte esencial de comunicacion:
    - `.github/reports/inter-chat-essential.md`
    - usarlo para registrar fricciones, mejoras validadas y solicitudes de
        Chat2/futuros chats.
