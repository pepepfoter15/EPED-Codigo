//
// pila.c
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#include <pila.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para crear un nuevo nodo con la URL dada
Nodo* crearNodo(URL url) {
    Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));
    if (nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo.\n");
        return NULL;
    }
    nodo->url = url;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para destruir un nodo y liberar su memoria
void DestruirNodo(Nodo* nodo) {
    nodo -> siguiente = NULL; // Desconectar el nodo de la pila
    free(nodo);
}

// Función para crear una nueva pila
Pila crearPila() {
    Pila* pila = (Pila *)malloc(sizeof(Pila));
    pila->cima = NULL; // Inicializar la cima de la pila como NULL
    pila->longitud = 0; // Inicializar la longitud de la pila como 0
    return *pila;
}

// Función para destruir una pila y liberar su memoria
void destruirPila(Pila* pila) {
    while (pila->cima != NULL) {
        Desapilar(pila); // Desapilar todos los nodos de la pila
    }
    free(pila); // Liberar la memoria de la pila
}



// Función para apilar una URL en la pila
void Apilar(Pila* pila, URL url) {
    Nodo* nuevoNodo = crearNodo(url);
    if (nuevoNodo == NULL) {
        return; // No se pudo crear el nodo, salir de la función
    }
    nuevoNodo->siguiente = pila->cima; // El nuevo nodo apunta a la cima actual
    pila->cima = nuevoNodo; // La cima de la pila ahora es el nuevo nodo
    pila->longitud++; // Incrementar la longitud de la pila
}

// Función para desapilar la URL superior de la pila
void Desapilar(Pila* pila) {
    if (pila->cima == NULL) {
        fprintf(stderr, "Error: La pila está vacía. No se puede desapilar.\n");
        return; // La pila está vacía, salir de la función
    }
    Nodo* nodoAEliminar = pila->cima; // Guardar el nodo a eliminar
    pila->cima = pila->cima->siguiente; // La cima de la pila ahora es el siguiente nodo
    DestruirNodo(nodoAEliminar); // Liberar la memoria del nodo eliminado
    pila->longitud--; // Decrementar la longitud de la pila
}

// Función para obtener la URL en la cima de la pila
URL Cima(Pila* pila) {
    if (pila->cima == NULL) {
        fprintf(stderr, "Error: La pila está vacía. No hay cima.\n");
        return NULL; // La pila está vacía, no hay cima
    }
    return pila->cima->url; // Devolver la URL en la cima de la pila
}

// Función para obtener la longitud de la pila
int Longitud(Pila* pila) {
    return pila->longitud; // Devolver la longitud de la pila
}

// Función para verificar si la pila está vacía
int EsVacia(Pila* pila) {
    return pila->longitud == 0; // La pila está vacía si su longitud es 0
}