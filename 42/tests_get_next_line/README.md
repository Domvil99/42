# tests_get_next_line

Manual test harness directory for standalone get_next_line validation.

Status: completed (2026-03-12).

Validation order:
1. Scope/spec alignment with 42/PDFs/2026-03-12_get_next_line.txt
2. Functional behavior
3. Memory and stability
4. Norminette as final closing step

Closure evidence summary:
1. Mandatory compilation with -Wall -Wextra -Werror: OK.
2. Bonus compilation with -Wall -Wextra -Werror: OK.
3. Norminette full scan (*.c, *.h): OK.
4. Functional mandatory tests with BUFFER_SIZE=1, 42, 9999: OK.
5. Functional bonus multi-fd tests with BUFFER_SIZE=42 and 1: OK.
6. Memory/stability checks using -fsanitize=address,undefined: no runtime issues observed.
