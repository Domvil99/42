# Project History

Purpose: chronological log of important decisions, imports, and structure changes.

## 2026-03-08

- Created base tracking docs:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
- Reorganized workspace structure:
  - moved `libft` to `C/libft`
  - created `42/PDFs`
- Saved official reference text as:
  - `42/PDFs/2026-03-08_primera_libft.txt`
- Corrected official function counts from the PDF:
  - Part 1: 23
  - Part 2: 11
  - Bonus: 9
  - Total: 43
- Standardized workspace automation rules:
  - updated `.github/copilot-instructions.md`
  - updated `.github/instructions/config-guide.instructions.md`
  - updated `.github/instructions/c-coding.instructions.md`
  - added global tracking for multi-project growth
- Renamed and reorganized directories:
  - root workspace directory kept as `Raiz/`
  - `C/` renamed to `42/`
  - `projects/` renamed to `C/`
  - `libft` moved to `42/C/libft`
  - imported specs path set to `42/PDFs/`

## 2026-03-09

- Adopted dual repository model:
  - delivery repo root: `42/C/`
  - workspace repo root: `Raiz/`
- Initialized git in `42/C/` for deliverable projects (default commit/push flow).
- Initialized git in `Raiz/` for tracking/docs/tooling.
- Added workspace `.gitignore` to keep repo separation:
  - ignore `42/C/` from `Raiz` repo
  - ignore local venv caches under `.tools/`
- Updated docs to reflect dual git operation:
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/projects-index.md`

- Added deferred task backlog and trigger rule:
  - created `.github/deferred-tasks.md`
  - added rule for phrase `guardalo para despues` in:
    - `.github/workflow-rules.md`
    - `.github/instructions/config-guide.instructions.md`
  - corrected Norminette tip to reference `$NORMI` in:
    - `.github/QUICK_REFERENCE.md`

- Updated deferred task policy:
  - if item is not `super importante`, keep it deferred and do not mention it
    unless the user explicitly asks for the pending list.

- Added tests support directory:
  - `42/testsLibf/` (manual test programs for libft)
- Route consistency review completed after structure changes under `42/`.
- Updated tracking docs to match current paths:
  - `.github/projects-index.md`
  - `.github/libft-progress.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/instructions/config-guide.instructions.md`
- Added fast tracking operations docs:
  - added `Tracking 30s Checklist` and copy/paste template in
    `.github/QUICK_REFERENCE.md`
  - added `30-Second Ops Checklist` and history template in
    `.github/workflow-rules.md`
  - linked checklist usage from
    `.github/instructions/config-guide.instructions.md`

- Full review and implementation update for `42/C/libft`:
  - cleaned duplicated or malformed commented test blocks in:
    - `42/C/libft/ft_strtrim.c`
    - `42/C/libft/ft_calloc.c`
    - `42/C/libft/ft_striteri.c`
    - `42/C/libft/ft_split.c`
    - `42/C/libft/ft_itoa.c`
    - `42/C/libft/ft_substr.c`
    - `42/C/libft/ft_strjoin.c`
  - implemented all bonus list functions:
    - `42/C/libft/ft_lstnew_bonus.c`
    - `42/C/libft/ft_lstadd_front_bonus.c`
    - `42/C/libft/ft_lstsize_bonus.c`
    - `42/C/libft/ft_lstlast_bonus.c`
    - `42/C/libft/ft_lstadd_back_bonus.c`
    - `42/C/libft/ft_lstdelone_bonus.c`
    - `42/C/libft/ft_lstclear_bonus.c`
    - `42/C/libft/ft_lstiter_bonus.c`
    - `42/C/libft/ft_lstmap_bonus.c`
  - updated `42/C/libft/Makefile` adding `bonus` rule and bonus objects.
  - updated bonus declarations in:
    - `42/C/libft/libft.h`
    - `42/C/libft/libft_bonus.h`
  - verified build with:
    - `make clean && make && make bonus`

- Follow-up cleanup pass on `42/C/libft`:
  - normalized duplicate commented test mains in:
    - `42/C/libft/ft_atoi.c`
    - `42/C/libft/ft_putchar_fd.c`
    - `42/C/libft/ft_putendl_fd.c`
    - `42/C/libft/ft_putnbr_fd.c`
    - `42/C/libft/ft_putstr_fd.c`
    - `42/C/libft/ft_strdup.c`
    - `42/C/libft/ft_strlcat.c`
    - `42/C/libft/ft_strlcpy.c`
    - `42/C/libft/ft_strnstr.c`
    - `42/C/libft/ft_strrchr.c`
    - `42/C/libft/ft_toupper.c`
  - kept one commented `main` per `ft_*.c` file.
  - re-verified `make` and `make bonus`.

- Added canonical workspace root rule to prevent path conflicts:
  - validated Linux root path:
    - `/home/domvil99/empresa/42/newLibft/Raiz`
  - documented Windows/WSL equivalent:
    - `\\wsl.localhost\Ubuntu\home\domvil99\empresa\42\newLibft\Raiz`
  - updated:
    - `.github/workflow-rules.md`
    - `.github/QUICK_REFERENCE.md`

- Added deferred super-important checklist for future directory rename affecting
  canonical path segment `empresa/42/newLibft/Raiz`:
  - recorded exact file/line targets in:
    - `.github/deferred-tasks.md`

- Final estilo/validación pass en `42/C/libft` (sin tocar política de header):
  - corregidos errores no-header de Norminette en archivos núcleo,
    incluyendo `ft_atoi.c`, `ft_itoa.c`, `ft_memchr.c`, `ft_memcmp.c`,
    `ft_memcpy.c`, `ft_memmove.c`, `ft_memset.c`, `ft_putendl_fd.c`,
    `ft_putnbr_fd.c`, `ft_putstr_fd.c`, `ft_split.c`, `ft_striteri.c`,
    `ft_strrchr.c`, `ft_strtrim.c`, `ft_toupper.c` y `libft.h`.
  - revalidado flujo solicitado por el usuario:
    - paso 2: `norminette` con foco en errores no-header
    - paso 1: `make clean && make && make bonus` ✅

- Revalidación posterior a cambios recientes en `42/C/libft`:
  - revisados archivos modificados:
    - `42/C/libft/ft_memcpy.c`
    - `42/C/libft/ft_lstdelone_bonus.c`
    - `42/C/libft/ft_lstmap_bonus.c`
  - resultado de control de calidad:
    - `norminette` sin errores adicionales fuera de `INVALID_HEADER`
    - `make clean && make && make bonus` ✅

- Auditoría completa de cumplimiento contra la especificación:
  - referencia usada:
    - `42/PDFs/2026-03-08_primera_libft.txt`
  - verificaciones ejecutadas en `42/C/libft`:
    - `make fclean && make && make bonus` ✅
    - `norminette *.c *.h` revisado con exclusión temporal de
      `INVALID_HEADER` por decisión del usuario
    - control de `main` por archivo: 43/43 archivos `*.c` con una sola
      ocurrencia de `int main(void)`
  - resultado:
    - librería funcional y compilable conforme al flujo pedido,
      pendiente únicamente de cabeceras Norminette por política temporal.

- Hardening de cumplimiento en `Makefile` y headers de `libft`:
  - archivos actualizados:
    - `42/C/libft/.gitignore`
    - `42/C/libft/Makefile`
    - `42/C/libft/libft.h`
    - `42/C/libft/libft_bonus.h`
    - `42/C/libft/ft_lstnew_bonus.c`
    - `42/C/libft/ft_lstadd_front_bonus.c`
    - `42/C/libft/ft_lstsize_bonus.c`
    - `42/C/libft/ft_lstlast_bonus.c`
    - `42/C/libft/ft_lstadd_back_bonus.c`
    - `42/C/libft/ft_lstdelone_bonus.c`
    - `42/C/libft/ft_lstclear_bonus.c`
    - `42/C/libft/ft_lstiter_bonus.c`
    - `42/C/libft/ft_lstmap_bonus.c`
  - cambios clave:
    - separación de API bonus desde `libft.h` hacia `libft_bonus.h`.
    - `*_bonus.c` usando `#include "libft_bonus.h"`.
    - regla `bonus` con marcador `.bonus` para evitar relink innecesario.
  - verificación final:
    - `make fclean && make && make bonus` ✅
    - `make bonus` repetido sin reconstrucción innecesaria ✅
    - compilación externa con `libft.h` + `libft_bonus.h` (`OK_HEADER_FLOW`) ✅

## Log Rules

1. Add one dated block per relevant change set.
2. Log structural changes first, then function/spec changes.
3. Reference exact file paths for every important edit.
