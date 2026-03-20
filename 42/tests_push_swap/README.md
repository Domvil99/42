# tests_push_swap

Manual test harness directory for standalone push_swap validation.

Status: in-progress (2026-03-19).

Validation order:
1. Scope/spec alignment with 42/PDFs/2026-03-13_push_swap_actualizado.txt
2. Functional behavior (parsing, operations, sorting output)
3. Memory and stability
4. Norminette as final closing step

Closure evidence summary:
1. Build and relink checks in 42/C/push_swap.
2. Functional smoke tests and benchmark samples.
3. Memory/stability checks with Valgrind or sanitizers.
4. Norminette closeout in project sources.
