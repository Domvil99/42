# Study Overview

Este directorio centraliza el material de estudio de proyectos validados y
cerrados con estado optimo.

Excepcion operativa activa:

- `push_swap` puede documentarse en paralelo a su implementacion cuando Chat1
   lo autoriza explicitamente por prioridad de estudio.

## Scope

- Cada proyecto validado en `42/C/` (cerrado o en desarrollo con estudio
   documentado) puede tener su carpeta propia.
- Nombres de carpetas y archivos: en ingles.
- Contenido explicativo: en español, manteniendo terminos tecnicos del proyecto.
- Estructura evolutiva: se pueden agregar uno o varios archivos por proyecto.

## Current Projects

- `libft` (closed)
- `ft_printf` (closed)
- `get_next_line` (closed)
- `currentLibft` (in-progress)
- `push_swap` (in-progress)

## Mandatory Structure Rules

1. Carpeta por proyecto: `.github/study/<project>/`.
2. Archivo nucleo por proyecto: `<project>.md`.
3. Diccionario por proyecto obligatorio: `dictionary.md`.
4. Diccionario global obligatorio: `.github/study/global-dictionary.md`.
5. Si crece el contenido, se permiten archivos complementarios:
   - `overview.md`
   - `foundations-nodes-lists.md`
   - `implementation.md`
   - `validation.md`
   - `defense.md`
   - `study-session-01.md`
6. Cada actualizacion de estudio debe registrar:
   - fecha,
   - motivo (revalidacion, correccion de spec, mejora didactica),
   - secciones impactadas.

## Update Workflow

1. Confirmar proyecto validado y cerrado.
2. Crear/actualizar carpeta y archivo nucleo.
3. Crear/actualizar `dictionary.md` del proyecto con glosario + mini ejemplos.
4. Ajustar contenido con foco de aprendizaje real:
   - fundamentos,
   - arquitectura,
   - errores tipicos,
   - estrategia de validacion,
   - preguntas de repaso.
5. Sincronizar tracking en `.github/project-history.md` y, si aplica,
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

- 2026-03-12: inicializacion de `study_methods` con base para `libft` y
  `ft_printf`.
- 2026-03-12: agregado reporte inicial para `get_next_line`.
- 2026-03-12: incorporada regla de diccionario global y diccionario por
   proyecto; agregado scope de `currentLibft`.
- 2026-03-13: agregado `push_swap` en modo de estudio paralelo con handoff
   formal de sincronizacion Chat1 -> Chat2/Chat4.
- 2026-03-14: agregado modulo dedicado `push_swap` con paquete
   completo de estudio (reporte, implementacion, validacion, defensa,
   casos y diccionario).
- 2026-03-15: agregada sesion guiada `study-session-01.md` para inicio
   inmediato de estudio en `push_swap`.
- 2026-03-16: agregado soporte de arranque desde base cero con archivo
   `foundations-nodes-lists.md` para proyectos con listas enlazadas.
