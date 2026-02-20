//
// lista.h
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdbool.h>
#include "libro.h" // Incluir archivo libro.h

// Estructura nodo para utilizarla para almacenar un libro y un puntero.
typedef struct Nodo{
    Libro libro;
    struct Nodo *siguiente;
} Nodo;

// Estructura lista que guarda el puntero a la cabeza de esta lista.
typedef struct Lista{
    Nodo* cabeza ;
    int longitud;
} Lista;

// Creación y destrucción de nodos
Nodo* crearNodo(Libro* libro);
void destruirNodo(Nodo* nodo);

// Funciones de varios tipos de inserción
void insertarPrincipio(Lista* lista, Libro* libro);
void insertarFinal(Lista* lista, Libro* libro);
void insertarDespues(int n, Lista* lista, Libro* libro);

// Recorrer, contar y ver si la longitud de la lista está vacía
Libro* obtener(int n, Lista* lista);
int contar(Lista* lista);
bool estaVacia(Lista* lista);

// Funciones para la eliminación de valores de una lista de varios tipos
void eliminarPrincipio(Lista* lista);
void eliminarUltimo(Lista* lista);
void eliminarElemento(int n, Lista *lista);

#endif /* lista_h */