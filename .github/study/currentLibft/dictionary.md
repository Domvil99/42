# currentLibft Dictionary

Glosario tecnico para estudiar la base integradora `currentLibft`.

## Entradas

### Parent libft
- Definicion: libreria base unica en `42/C/currentLibft/libft`.
- Mini ejemplo: no crear otra `libft` paralela al mismo nivel.

### Integrated child module
- Definicion: proyecto incorporado bajo `libft/<project_name>`.
- Mini ejemplo: `42/C/currentLibft/libft/ft_printf`.

### Forbidden nested libft
- Definicion: `libft` adicional dentro de un modulo hijo integrado.
- Mini ejemplo: ruta invalida `.../libft/ft_printf/libft`.

### Coexistence model
- Definicion: convivencia valida entre standalone e integrado.
- Mini ejemplo: `42/C/ft_printf` y `42/C/currentLibft/libft/ft_printf`.

### Integration manifest
- Definicion: indice consolidado de modulos, conteos y entry points.
- Mini ejemplo: actualizar `.github/tracking/projects/currentLibft/integration-manifest.md`.

### Bootstrap base
- Definicion: plantilla oficial para arrancar un proyecto nuevo.
- Mini ejemplo: copiar `42/C/currentLibft/libft` a `42/C/<new>/libft`.

### Structural invariant
- Definicion: regla que no debe romperse en ningun ciclo de cambios.
- Mini ejemplo: mantener una sola `libft` padre en currentLibft.

### Sync without regression
- Definicion: alinear base comun sin romper proyectos cerrados.
- Mini ejemplo: tras sync, compilar standalone + integrado para verificar.

### Integrated API surface
- Definicion: conjunto de entry points y helpers expuestos por modulos hijos.
- Mini ejemplo: `ft_printf` y `get_next_line` disponibles desde currentLibft.

### Compile-all policy
- Definicion: estrategia donde `make` puede preparar mandatory y bonus para
	dejar la base lista para consumo en otros proyectos.
- Mini ejemplo: en una libft integrada, `make` + `make bonus` garantizan
	cobertura total antes de linkar el proyecto principal.

### Header contract
- Definicion: combinacion de headers publicos que define el uso correcto de la
	libreria integrada.
- Mini ejemplo: `libft.h`, `libft_bonus.h`, `ft_printf.h`,
	`get_next_line.h`.
