# Algoritmo de Dijsktra

## Condicionales

Se aplica a grafos conexos.
Los pesos deben ser positivos.

## Algoritmo

1. Inicializar un arreglo de distancias con infinito, excepto la distancia del nodo inicial que es 0.
2. Relajar vecinos del nodo inicial.
3. Seleccionar el nodo con la distancia mínima.
4. Relajar vecinos del nodo seleccionado.
5. Repetir hasta que todos los nodos hayan sido seleccionados.

## Problema del camino mas corto hacia S

Invertir direccion de las aristas y aplicar el algoritmo de Dijkstra desde S.

## Problema del camino mas corto con varias fuentes

<!-- 1. agregar arista falso que este conectado a todas las fuentes con peso 0.
2. aplicar el algoritmo de Dijkstra.
3. eliminar la arista falso. -->
