# currentLibft Progress

## Current Status

Proyecto: `42/C/currentLibft`
Estado: in-progress (base evolutiva)

## Integrated Modules

- libft base (43 funciones): completed
- ft_printf child: integrated and completed
- get_next_line child: integrated and completed

Cobertura funcional registrada (2026-04-05):
- libft base: 43/43
- ft_printf: mandatory + bonus disponibles en modulo integrado
- get_next_line: mandatory + bonus disponibles en modulo integrado

## Integration Gates

1. Build gate:
   - `make` en `42/C/currentLibft`.
   - `make bonus` en `42/C/currentLibft`.
2. Parity gate:
   - base libft sincronizada con `42/C/libft`.
3. Style gate:
   - norminette sobre archivos impactados al cerrar cambios.
4. Documentation gate:
   - tracking y manifest de currentLibft sincronizados con codigo real.

## Operational Notes

- currentLibft no reemplaza entregables standalone; los complementa como base
  reusable para nuevos proyectos.
- Integraciones nuevas deben registrarse en:
  - `.github/tracking/projects/currentLibft/integration-manifest.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`

## Change Log

- 2026-04-05: progreso actualizado con cobertura integrada detallada.
- 2026-03-20: tracking inicial de progreso creado.
