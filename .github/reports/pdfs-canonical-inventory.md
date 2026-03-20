# PDFs Canonical Inventory

Purpose: definir una referencia canonica por proyecto en `42/PDFs/` y
evitar confusion entre versiones historicas y versiones vigentes.

## Canonical Set (2026-03-13)

| Project | Canonical spec | Legacy files kept | Status | Notes |
|---|---|---|---|---|
| libft | `42/PDFs/2026-03-12_libft_v16_6.txt` | (none) | OK | Canonical v16.6 vigente.
| ft_printf | `42/PDFs/2026-03-12_ft_printf.txt` | (none) | OK | Canonical vigente.
| get_next_line | `42/PDFs/2026-03-12_get_next_line.txt` | (none) | OK | Canonical vigente.
| push_swap | `42/PDFs/2026-03-13_push_swap_actualizado.txt` | `42/PDFs/2026-03-13_push_swap.txt` | DONE | Source recibido 2026-03-13. Traduccion validada por el usuario.

## Operational Rule

1. Cada proyecto debe tener una unica referencia canonica activa.
2. Archivos legacy no se usan como base de validacion, solo historial.
3. Ninguna traduccion nueva se cierra sin source oficial disponible y
   revision de usuario (`REVIEW_PENDING` -> `DONE`).

## Next Action (push_swap)

1. Continuar con ACK de Chat2 en H-009 o H-011 segun prioridad de ejecucion.
2. Mantener `2026-03-13_push_swap_actualizado.txt` como referencia canónica vigente.
3. Registrar cualquier futura revision en project-history antes de reemplazar el canonical.