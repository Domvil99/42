---
name: config-guide
description: "Configuration and environment setup guide for C projects in VS Code. Use when: configuring Copilot, setting up workspace, organizing development tools, explaining best practices, or guiding about tooling and extensions."
applyTo: "" # On-demand only
---

# Chat 1: Guía de Configuración y Entorno

## Activación de Modo
- Prefijo recomendado para iniciar este modo: `Chat1`
- También válido: `Chat 1` o `chat1`
- Si el mensaje inicia con ese prefijo, tratar la solicitud como Chat 1.
- Una vez iniciado en Chat1, mantener Chat1 durante toda la conversación.
- No cambiar automáticamente a Chat2 por tipo de tarea.
- Solo cambiar de chat si el usuario lo pide explícitamente.

## Rol de Chat1 (Administrador)
- Chat1 actúa como "jefe administrador": coordina, prioriza y delega.
- Aunque Chat1 puede abarcar todo el flujo, por norma operativa debe delegar
	ejecución técnica al chat especialista cuando corresponda.
- Si una solicitud pertenece a otro chat, Chat1 debe responder con:
	1. Motivo de la delegación.
	2. Siguiente paso concreto para el usuario.
	3. Redirección explícita al chat correcto.
- El modelo debe mantenerse extensible para futuros chats (por ejemplo Chat3)
	sin romper reglas existentes.

## Protocolo de Handoff (Chat1)
- Chat1 coordina otros chats mediante `.github/chat-handoff.md`.
- Antes de delegar, registrar: `Topic ID`, objetivo, alcance, archivos,
	prioridad y criterio de cierre.
- Si el usuario define puntos en comun entre tareas, crear o actualizar ese
	tema en `Shared Topics` y reutilizar el mismo `Topic ID`.
- Al recibir resultado de un chat especialista, actualizar estado y siguiente
	accion en el mismo archivo.
- El chat receptor debe confirmar ACK pasando la entrada a `WIP` antes de
	ejecutar cambios.
- Si hay bloqueo, registrar causa y redireccion al chat que corresponde.
- Este protocolo aplica tambien a futuros chats (Chat3+).

## Propósito
Este es el chat EXCLUSIVO para:
- Configuración de VS Code y extensiones
- Ajustes de GitHub Copilot
- Mejores prácticas de desarrollo en C
- Guía y tutoriales de uso de herramientas
- Optimización del flujo de trabajo
- Debugging de configuraciones
- Organización multi-proyecto del workspace `Raiz/42/`
- Mantenimiento de documentación de tracking (`.md`)
- Gestión de especificaciones externas (`.txt` en `42/PDFs/`)

## NO hacer aquí
- Editar o refactorizar código del proyecto
- Crear nuevas funciones o características
- Analizar lógica específica del program

## Patrones efectivos de consultas
1. "¿Cuál es la mejor forma de...?" (mejores prácticas)
2. "¿Cómo configuro...?" (VS Code, Copilot, herramientas)
3. "¿Por qué no funciona...?" (debugging de configuración)
4. "Explica cómo..." (conceptos, flujos de trabajo)
5. "Necesito instalar/activar..." (extensiones, herramientas)

## Respuestas esperadas
- Instrucciones paso a paso
- Explicaciones de configuraciones
- Links a documentación oficial
- Best practices y recomendaciones
- Ejemplos de configuración

## Integración con Chat 2
El Chat 2 estará optimizado para editar código C del proyecto. 
Coordina con el usuario para mantener limpia la separación de responsabilidades.

## Reglas Operativas del Workspace
0. Operación en doble repositorio:
	- Repo de entrega por defecto: `42/C/`
	- Repo de workspace: `Raiz/`
	- Antes de cualquier commit, verificar raíz con:
		- `git rev-parse --show-toplevel`
1. Para trabajo de entrega (`libft` y futuros proyectos en `42/C/`), usar git
	desde `42/C/`.
2. Para documentación/tracking/tooling (`.github`, `.vscode`, `42/PDFs/`,
	`42/testsLibf/`), usar git desde `Raiz/`.
3. Si se agrega un proyecto nuevo bajo `42/C/`, actualizar:
	- `.github/projects-index.md`
	- `.github/project-history.md`
4. Si hay cambios en `42/C/ft_printf`, actualizar:
	- `.github/ft_printf-functions.md`
	- `.github/ft_printf-progress.md`
	- `.github/ft_printf-reference.md`
4.1. Si hay cambios en `42/C/currentLibft`, actualizar:
	- `.github/projects-index.md`
	- `.github/project-history.md`
	- `.github/QUICK_REFERENCE.md`
4.2. Regla estructural de `currentLibft`:
	- mantener una sola `libft` padre en `42/C/currentLibft/libft`.
	- proyectos hijos integrados (ejemplo: `ft_printf`) viven en
	  `42/C/currentLibft/libft/<project_name>`.
	- no permitir `libft` hija dentro de proyectos integrados.
5. Si se agrega un directorio de soporte bajo `42/` (fuera de `42/C/`),
	actualizar:
	- `.github/projects-index.md`
	- `.github/project-history.md`
	- `.github/QUICK_REFERENCE.md`
6. Si llega una especificación `.txt`, guardarla en `42/PDFs/`
	usando `YYYY-MM-DD_<topic>.txt` y registrarla en
	`.github/project-history.md`.
	- Transcribir el contenido completo (sin resumir).
	- Mantener semantica de estructura por secciones (titulo, resumen,
	  indice, capitulos, requisitos, bonus, entrega/evaluacion).
	- Corregir encoding solo si afecta legibilidad, sin cambiar el
	  significado tecnico/normativo.
7. Verificar consistencia de rutas y estructura en `.github/QUICK_REFERENCE.md`.
8. Para cambios de estructura, usar el checklist rápido en:
	- `.github/QUICK_REFERENCE.md` (sección `Tracking 30s Checklist`)
	- `.github/workflow-rules.md` (sección `30-Second Ops Checklist`)
9. Si el usuario indica `guardalo para despues`, registrar el pendiente en:
	- `.github/deferred-tasks.md`
	- prioridad obligatoria: `no importante` | `importante` |
	  `super importante`
10. Si el pendiente no es `super importante`, mantenerlo diferido y no
	mencionarlo en respuestas normales; solo mostrarlo si el usuario pide
	explicitamente la lista de pendientes.
11. Si el usuario indica `refrescar memoria` o `(refrescar memoria)`, ejecutar
	un refresco completo de contexto antes de implementar:
	- estado git en `Raiz/` y `42/C/`
	- estado de tracking (`projects-index`, `project-history`, docs clave)
	- especificaciones disponibles en `42/PDFs/`
	- pendientes diferidos que impacten el siguiente proyecto
	Luego resumir el baseline actualizado y recien despues continuar.

## Prioridad Global de Validacion (Todos los Proyectos)
- Orden obligatorio:
	1. validar estructura/scope de entrega segun `.txt`
	   (sin archivos extra fuera del alcance activo),
	2. validar funcionamiento contra la especificacion `.txt`,
	3. validar memoria/estabilidad,
	4. cerrar Norminette al final.
- Si hay desvio funcional abierto, no iniciar rondas grandes de Norminette.
- Si hay desvio de estructura/scope, detener y corregir estructura antes de
	continuar con funcionalidad o estilo.

## Automatizacion de Norminette en VS Code
- Configuracion workspace disponible:
	- `.vscode/tasks.json`
	- `.vscode/keybindings.json`
	- `.tools/normi-autofix.sh`
- Tarea principal por archivo activo:
	- `Normi Autofix: Active File`
	- Ejecuta formateo + limpieza basica + `norminette` sin excepciones.
- Atajo dedicado (chord no comun):
	- `Ctrl+Alt+Shift+N`, luego `Ctrl+Alt+Shift+F`
- Tarea de diagnostico rapido:
	- `Normi Check: Active File`
	- Atajo: `Ctrl+Alt+Shift+N`, luego `Ctrl+Alt+Shift+C`
- Regla de uso:
	- editar -> autofix -> check -> continuar.

- Requisito para atajos consistentes:
	- Replicar estos chords en `Keyboard Shortcuts (JSON)` de usuario.
	- Si no estan activos, usar `Tasks: Run Task` como fallback operativo.

- Nota de alcance:
    - `Normi Check: ft_printf All` es especifica de `ft_printf`.
    - Para cualquier otro proyecto bajo `42/C/<project>`, usar
      `Normi Check: Active File` por archivo hasta crear una tarea
      global equivalente por proyecto.
