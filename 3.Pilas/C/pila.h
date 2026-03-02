//
// pila.h
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#ifndef pila_h
#define pila_h

#include <stdio.h>

/* A partir de ahora puedo hacer cosas como:
    URL Google = "https://www.google.com";
    URL GitHub = "https://www.github.com";
*/

// Definición de tipos
typedef char* URL;

typedef struct Nodo {
    URL url;
    struct Nodo* siguiente; // Apunta al siguiente nodo en la pila
} Nodo; 

typedef struct Pila {
    Nodo* cima; // Apunta al nodo superior de la pila
    int longitud; // Almacena la cantidad de elementos en la pila
} Pila;

// Funciones para manejar los nodos
Nodo* crearNodo(URL url);
void DestruirNodo(Nodo* nodo);

// Funciones para la creación y destrucción de la pila
Pila crearPila();
void destruirPila(Pila* pila);

// Funciones para el manejo de la pila
void Apilar(Pila* pila, URL url);
void Desapilar(Pila* pila);
URL Cima(Pila* pila);
int Longitud(Pila* pila);
int EsVacia(Pila* pila);

#endif
