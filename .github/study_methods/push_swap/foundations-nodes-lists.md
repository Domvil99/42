# Fundamentos - Nodos y Listas Enlazadas

Este documento explica la base minima para entender estructuras de datos en C
sin depender de algoritmos avanzados.

## 1) Estructura, nodo y lista: diferencias

1. Estructura (`struct`): el molde que define campos.
2. Nodo: una instancia real de ese molde.
3. Lista enlazada: varios nodos conectados por punteros.

Analogía:
- Estructura: formato de ficha de persona.
- Nodo: una ficha concreta de una persona.
- Lista: muchas fichas conectadas en cadena.

## 2) Ejemplo mental con tres nodos

Imagina tres nodos con valores 4, 9 y 2:

- Nodo A: value=4, next -> Nodo B
- Nodo B: value=9, next -> Nodo C
- Nodo C: value=2, next -> NULL

Representacion:

A(4) -> B(9) -> C(2) -> NULL

`NULL` significa fin de lista.

## 3) Que es un puntero en este contexto

Un puntero guarda una direccion de memoria.

- `next` no guarda el siguiente valor,
- `next` guarda donde vive el siguiente nodo.

Por eso, cuando cambias punteros, cambias la forma de la lista.

## 4) Head o top

Toda lista necesita un punto de inicio.

- `head` o `top`: puntero al primer nodo.
- Si `head == NULL`, la lista esta vacia.

En push_swap:
- `a` y `b` son listas enlazadas.
- El primer nodo es la cima del stack.

## 5) Operaciones basicas de lista

1. Recorrer:
- empiezas en `head`,
- sigues con `next` hasta `NULL`.

2. Insertar al inicio:
- el nuevo nodo apunta al viejo `head`,
- `head` pasa a ser el nuevo nodo.

3. Eliminar inicio:
- guardas el nodo actual,
- `head` avanza a `head->next`,
- liberas el nodo guardado.

## 6) Relacion directa con push_swap

- `pb`: saca el nodo de arriba de `a` y lo pone arriba de `b`.
- `pa`: saca el nodo de arriba de `b` y lo pone arriba de `a`.
- `sa`: intercambia los dos primeros nodos de `a`.
- `ra`: mueve el primer nodo de `a` al final.
- `rra`: mueve el ultimo nodo de `a` al inicio.

Todo esto son cambios de enlaces, no ordenacion magica.

## 7) Errores tipicos al empezar

1. Confundir estructura con lista.
2. Olvidar que `next` es direccion, no valor.
3. Perder referencia al `head` durante cambios.
4. No controlar `NULL` en listas vacias o de un nodo.
5. Hacer `free` incorrecto y romper memoria.

## 8) Checklist minimo de comprension

Puedes avanzar cuando respondas si mirar apuntes:

1. Que diferencia hay entre struct y nodo.
2. Que indica `next == NULL`.
3. Como insertas un nodo al inicio.
4. Que representa `head`.
5. Por que `pb` cambia dos listas a la vez.

## Change Log

- 2026-03-16: version inicial para base de estudio de nodos y listas.
