# ft_printf Study Report

## 1. Vision del Proyecto

`ft_printf` valida que puedes diseñar una salida formateada variadica sin usar
el `printf` original ni su buffer interno. Este proyecto mide:

- dominio de `stdarg` (`va_list`, `va_start`, `va_arg`, `va_end`),
- parseo incremental de formato,
- conversion y representacion de tipos,
- control de longitud escrita (valor de retorno),
- robustez frente a casos borde y combinaciones de flags.

Es uno de los proyectos donde se nota si tu base de `libft` es realmente
estable.

## 2. Objetivos Tecnicos Reales

1. Parsear texto y especificadores sin perder sincronizacion de indice.
2. Mapear conversion -> handler con responsabilidades claras.
3. Mantener exactitud de salida y retorno total.
4. Evitar leaks en rutas con strings dinamicos intermedios.
5. Separar mandatory y bonus sin mezclar APIs ni headers.

## 3. Arquitectura Recomendada

Una arquitectura mantenible suele tener:

- Dispatcher principal (`ft_printf*`) que recorre `format`.
- Parser de especificador (flags, width, precision, type).
- Handlers por conversion (`c`, `s`, `p`, `d/i`, `u`, `x/X`, `%`).
- Utilidades de escritura/padding/conversion.
- Bonus separado (`*_bonus.c`, `*_bonus.h`) con compile flag dedicado.

Clave: cada handler debe enfocarse en una conversion y devolver caracteres
escritos o error.

## 4. Mandatory: Conversiones y Casos Criticos

### `%c`
- Escribe un caracter exacto.
- Retorno incrementa en 1 (o width si hay padding en bonus).

### `%s`
- Manejar `NULL` de forma compatible (normalmente `(null)`).
- Precision puede truncar.

### `%p`
- Formato hexadecimal con prefijo `0x`.
- Para puntero nulo, contraste con comportamiento esperado local (`(nil)` en
  glibc).

### `%d` / `%i`
- Signo correcto.
- Caso `0` con precision 0: salida vacia para el numero, pero siguen aplicando
  width/flags.

### `%u`
- Sin signo; no hereda logica de signo de `%d`.

### `%x` / `%X`
- Base 16 en minusculas/mayusculas.
- En bonus, `#` agrega prefijo solo cuando valor != 0.

### `%%`
- Debe imprimir `%` literal.

## 5. Bonus: Flags y Prioridades de Reglas

Flags comunes: `-`, `0`, `.`, width, `#`, `+`, espacio.

Reglas practicas de precedencia:

1. Precision suele anular padding con `0` en enteros.
2. `-` implica alineacion izquierda; padding a la derecha.
3. `+` tiene prioridad sobre espacio para positivos.
4. `#` depende de conversion y valor (por ejemplo `x/X` con valor no cero).
5. Width siempre se cumple, incluso si el contenido numerico queda vacio por
   precision 0 y valor 0.

## 6. Problemas Tipicos y Soluciones

1. **Indice de parseo desfasado**
- Sintoma: se salta caracteres tras una conversion.
- Solucion: definir claramente quien avanza el indice (parser o dispatcher,
  pero no ambos en conflicto).

2. **Retorno incorrecto**
- Sintoma: salida visible correcta pero total de caracteres no coincide.
- Solucion: cada write suma exactamente lo escrito; validar con matrices.

3. **Leaks en conversion numerica**
- Sintoma: rutas con precision/width generan strings temporales sin liberar.
- Solucion: ownership explicito y cleanup centralizado por handler.

4. **Comportamientos bonus inconsistentes**
- Sintoma: combinaciones `0`, `-`, `.`, width no coinciden con `printf`.
- Solucion: pruebas por matriz de combinaciones, no solo casos aislados.

## 7. Estrategia de Validacion

### 7.1 Funcionalidad

- Comparar salida contra `printf` real.
- Verificar retorno total.
- Usar matrices mandatory y bonus con casos borde.

### 7.2 Memoria/Estabilidad

- Ejecutar ASAN/UBSAN o valgrind sobre matrices completas.
- Confirmar cero errores runtime y cero leaks.

### 7.3 Build y estructura

- `make` y `make bonus` deben compilar limpio.
- No relink innecesario cuando no hay cambios.
- Separacion de archivos mandatory/bonus coherente con headers.

### 7.4 Norminette

- Cerrar al final, cuando funcionalidad y memoria esten estables.

## 8. Checklist de Defensa Tecnica

Debes poder defender:

1. Como funciona tu parser y que estado produce.
2. Como se aplica el orden de precedencia de flags.
3. Como aseguras el return total correcto.
4. Como manejas `%p` y `NULL`.
5. Que validaciones ejecutaste y con que evidencia.
6. Como separaste mandatory y bonus en compilacion y headers.

## 9. Repaso Activo

### Preguntas rapidas

1. Por que precision 0 con valor 0 no imprime digitos en enteros?
2. En que casos `0` padding debe ignorarse?
3. Como calculas width restante cuando hay signo/prefijo?
4. Que diferencia hay entre formatear `x` y `p`?

### Mini retos

1. Simula a mano `%08.3d` con `42` y explica cada paso.
2. Diseña una tabla de precedencia de flags para enteros.
3. Traza el retorno acumulado de una llamada con 5 conversiones mixtas.

## 10. Evolucion Continua

Actualizar este reporte cuando:

- se detecten diferencias nuevas contra `printf`,
- cambie la baseline de spec,
- se incorporen mejoras de arquitectura,
- aparezcan nuevos casos borde durante proyectos posteriores.

## Change Log

- 2026-03-12: version inicial completa para `ft_printf` validado y cerrado
  tras revalidacion con baseline corregida.
