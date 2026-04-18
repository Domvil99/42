# 03 - Errores y Memoria

## Errores tipicos en fractol

1. segfault por puntero MLX no inicializado,
2. segfault al escribir fuera del buffer de imagen,
3. cierre abrupto por no validar argumentos,
4. fugas por no destruir imagen/ventana.

## Como prevenir segfault en render

1. validar app y punteros antes de render,
2. respetar limites width/height,
3. calcular offset de pixel con cuidado,
4. evitar casts peligrosos sin control.

## Recursos a liberar en salida

- imagen MLX,
- ventana MLX,
- display/contexto (segun API usada),
- memoria propia dinamica.

## Senales de problema de memoria

- cierre con errores al salir,
- valgrind reporta definitely lost,
- comportamiento distinto entre runs iguales.

## Estrategia de debug

1. reproducir con caso minimo,
2. aislar modulo (parse/init/render/events),
3. comprobar invariantes de view,
4. pasar valgrind en escenarios cortos.

## Change Log

- 2026-04-16: respuestas iniciales de errores y memoria.
