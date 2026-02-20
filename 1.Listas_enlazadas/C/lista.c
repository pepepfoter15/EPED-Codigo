//
// lista.c
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#include "lista.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // Para utilizar malloc y sus funciones de memoria dinámicas nos hace falta esta librería.
#include <stdio.h>

// Función para crear un nodo
Nodo* crearNodo(Libro* libro){

    Nodo *nodo = (Nodo* )malloc(sizeof(Nodo));

    if (!nodo) return NULL;

    /* Copiar cadenas de forma portable y asegurar terminador nulo */
    strncpy(nodo->libro.titulo, libro->titulo, sizeof(nodo->libro.titulo) - 1);
    nodo->libro.titulo[sizeof(nodo->libro.titulo) - 1] = '\0';

    strncpy(nodo->libro.autor, libro->autor, sizeof(nodo->libro.autor) - 1);
    nodo->libro.autor[sizeof(nodo->libro.autor) - 1] = '\0';

    strncpy(nodo->libro.isbn, libro->isbn, sizeof(nodo->libro.isbn) - 1);
    nodo->libro.isbn[sizeof(nodo->libro.isbn) - 1] = '\0';

    nodo->siguiente = NULL;
    return nodo;
}

// Función para imprimir todos los libros usando obtener()
void imprimirLista(Lista *lst) {
    int n = contar(lst);
    if (n == 0) {
        printf("La lista está vacía.\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        Libro *l = obtener(i, lst);
        if (l)
            printf("[%d] Titulo: %s | Autor: %s | ISBN: %s\n", i, l->titulo, l->autor, l->isbn);
    }
}

// Función para destruir un nodo que no queramos en memoria 
void destruirNodo(Nodo* nodo){
    free(nodo);
}

// Función para insertar al principio
void insertarPrincipio(Lista* lista, Libro* libro){
    Nodo* nodo = crearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++; // Incrementar la longitud de la lista
}

// Función para insertar al final
void insertarFinal(Lista* lista, Libro* libro){
    Nodo* nodo = crearNodo(libro);
    if(lista->cabeza == NULL) // Si la cabeza de la lista esta vacía
        lista->cabeza = nodo;
    else{
        Nodo* puntero = lista->cabeza;

        while(puntero->siguiente) // Avanzar hasta el final
            puntero = puntero->siguiente;

        puntero->siguiente = nodo;
    }
    lista->longitud++; // Incrementar la longitud de la lista
}

// Función para insertar en medio
void insertarDespues(int n, Lista* lista, Libro* libro){ // n es el libro en la posición de la lista
    Nodo* nodo = crearNodo(libro);
    if(lista->cabeza == NULL)
        lista->cabeza = nodo;
    else{
        Nodo* puntero = lista->cabeza;
        int posicion = 0; // Inicializamos la posición a 0
        while(posicion < n && puntero->siguiente){ // Recorremos la lista hasta llegar a la posición n
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente; // Apuntamos al siguiente de n desde el puntero
        puntero->siguiente = nodo; // Apunta desde el nodo al nuevo valor insertado que apunta a siguiente del nodo.
    }
    lista->longitud++;// Incrementar la longitud de la lista
}

// Ejemplo => 3 -> 4 | 3 -> 4 <- 5 (5 es el valor nuevo que quiero insertar) | 3 -> 5 -> 4 (este paso es la linea 68)

// Recorrer la lista
Libro* obtener(int n, Lista* lista){
    if(lista->cabeza == NULL)
        return NULL; // Si la lista esta vacía, te devuelve NULL porque no tiene nada la lista.
    else{
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        if(posicion != n) // No tenemos suficientes libros ya que n > numero de libros de la lista
            return NULL;
        else
            return &puntero->libro; // Mostrar el libro n que tienes
    }
}

// Contar cuantos libros o la longuitd de la lista
int contar(Lista* lista){
    return lista->longitud;
}

// Ver si la lista esta vacía con un valor booleano si devuelve NULL
bool estaVacia(Lista* lista){
    return lista->cabeza == NULL;
}

// Eliminar la cabecera de la lista
void eliminarPrincipio(Lista* lista){
    if(lista->cabeza){ // Si la lista no esta vacía 
        Nodo* eliminado = lista->cabeza; // Obtenemos el valor de la cabecera que queremos eliminar
        lista->cabeza = lista->cabeza->siguiente; // Ponemos el segundo elemento de la lista como la cabecera
        destruirNodo(eliminado); // Eliminamos la cabecera
        lista->longitud--; // Reducimos en 1 la longitud de la lista
    }
}

// Eliminar último de la lista
void eliminarUltimo(Lista* lista){
    if(lista->cabeza){
        if(lista->cabeza->siguiente){ // Para lista de más de 1 elemento
            Nodo* puntero = lista->cabeza;
            while(puntero->siguiente->siguiente)
                puntero = puntero->siguiente;
            Nodo* eliminado = puntero->siguiente; // Apunta al ultimo ya que sale de la condición while para el mismo
            puntero->siguiente = NULL;
            destruirNodo(eliminado);
            lista->longitud--;
        }

    } else{ // Para lista de solo un elemento
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = NULL;
        destruirNodo(eliminado);
        lista->longitud--;
    }
}

// Eliminar un elemento de la lista
void eliminarElemento(int n, Lista *lista){ // Eliminar un nodo cualquiera llamado n
    if(lista->cabeza){
        if(n == 0){ // Caso especial cuando el nodo es igual a 0 o más bien, quiere eliminar la cabecera
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            destruirNodo(eliminado);
            lista->longitud--;
        } else if(n < lista->longitud){ // Caso que n > 0 y puedes recorrerlo sin problemas
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while(posicion < (n - 1)){ // Nos posicionamos en el anterior que queremos eliminar
                puntero = puntero->siguiente;
                posicion++;
            }
            // Cuando ya se ha recorrido, pasa a la eliminación del nodo comentado
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            destruirNodo(eliminado);
            lista->longitud--;
        }
    }
}