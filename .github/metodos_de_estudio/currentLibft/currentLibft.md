# currentLibft Study Report

## 1. Vision del Proyecto

`currentLibft` es la base canonica evolutiva para nuevos proyectos en `42/C/`.
Su objetivo no es reemplazar entregables cerrables, sino concentrar una
biblioteca reutilizable y extensible con modulos integrados.

## 2. Objetivos Tecnicos Reales

- Mantener una sola libreria padre en `42/C/currentLibft/libft`.
- Integrar modulos aprobados bajo `libft/<project_name>`.
- Preservar compatibilidad de headers y comportamiento base.
- Evitar regresiones al sincronizar con proyectos cerrados.

## 3. Arquitectura Mental Recomendada

- Capa base: funciones `libft` nucleares.
- Capa integrada: modulos como `ft_printf` y `get_next_line`.
- Capa de gobernanza: manifiestos, tracking y reglas de cierre.

## 4. Riesgos Tipicos

- Duplicar `libft` dentro de un modulo integrado.
- Romper autonomia de proyectos cerrados por sincronizacion agresiva.
- Mover rutas fuera del patron canonicamente definido.

## 5. Estrategia de Integracion Segura

1. Cerrar primero el proyecto standalone.
2. Integrar despues en `currentLibft` respetando arquitectura.
3. Revalidar build y pruebas del bloque integrado.
4. Registrar cambios en tracking y manifiestos.

## 6. Validacion Profesional

- Scope: rutas y estructura permitida.
- Funcional: comportamiento segun subject actualizado.
- Estabilidad: pruebas con sanitizers cuando aplique.
- Norma: Norminette como gate final de cierre.

## 7. Repaso Activo

- Por que `currentLibft` no reemplaza los entregables standalone.
- Que invariantes estructurales nunca deben romperse.
- Como detectar regresiones tras integrar un modulo nuevo.
