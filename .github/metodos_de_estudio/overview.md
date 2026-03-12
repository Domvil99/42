# Study Methods Overview

Este directorio centraliza el material de estudio de proyectos validados y
cerrados con estado optimo.

## Scope

- Cada proyecto cerrado en `42/C/` puede tener su carpeta propia.
- Nombres de carpetas y archivos: en ingles.
- Contenido explicativo: en español, manteniendo terminos tecnicos del proyecto.
- Estructura evolutiva: se pueden agregar uno o varios archivos por proyecto.

## Current Projects

- `libft`
- `ft_printf`

## Mandatory Structure Rules

1. Carpeta por proyecto: `.github/metodos_de_estudio/<project>/`.
2. Archivo nucleo por proyecto: `<project>.md`.
3. Si crece el contenido, se permiten archivos complementarios:
   - `overview.md`
   - `implementation.md`
   - `validation.md`
   - `defense.md`
4. Cada actualizacion de estudio debe registrar:
   - fecha,
   - motivo (revalidacion, correccion de spec, mejora didactica),
   - secciones impactadas.

## Update Workflow

1. Confirmar proyecto validado y cerrado.
2. Crear/actualizar carpeta y archivo nucleo.
3. Ajustar contenido con foco de aprendizaje real:
   - fundamentos,
   - arquitectura,
   - errores tipicos,
   - estrategia de validacion,
   - preguntas de repaso.
4. Sincronizar tracking en `.github/project-history.md` y, si aplica,
   `.github/QUICK_REFERENCE.md`.

## Study Quality Baseline

Para considerar un reporte como "completo", debe incluir:

- Contexto del subject y objetivos.
- Mapa de funciones/modulos y responsabilidades.
- Casos borde y razonamiento de implementacion.
- Errores frecuentes y como evitarlos.
- Validacion funcional, memoria y norma.
- Checklist de defensa tecnica.
- Bloque de repaso activo (preguntas y mini retos).

## Change Log

- 2026-03-12: inicializacion de `metodos_de_estudio` con base para `libft` y
  `ft_printf`.
