//
// cola.c
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#include <stdio.h>
#include <stdlib.h>

#include "cola.h"
#include "pedido.h"

// Función para crear un nodo de pedido y avisar si el nodo es nulo que no se permite asignar esta memmoria para el nodo pedido
NodoPedido* crearNodoPedido(Pedido* pedido) {
    NodoPedido* nodo = (NodoPedido*)malloc(sizeof(NodoPedido));
    if (nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo de pedido.\n");
        return NULL;
    }
    nodo->pedido = pedido;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para destruir un nodo de pedido y liberar la memoria asignada para el nodo
void DestruirNodoPedido(NodoPedido* nodo) {
    if (nodo == NULL) {
        fprintf(stderr, "Error al destruir nodo de pedido: nodo es NULL.\n");
        return;
    }
    nodo->pedido = NULL;
    nodo->siguiente = NULL;
    free(nodo);
}

// Función para crear una cola de pedidos y asignar memoria para la cola, inicializando la cabeza y el final a NULL
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    if (cola == NULL) {
        fprintf(stderr, "Error al asignar memoria para la cola.\n");
        return NULL;
    }
    cola->cabeza = NULL;
    cola->final = NULL;
    return cola;
}

// Función para destruir cola de pedidos y liberar la memoria asignada para la cola.
void destruirCola(Cola* cola) {
    if (cola == NULL) {
        fprintf(stderr, "Error al destruir cola: cola es NULL.\n");
        return;
    }
    while (cola->cabeza) {
        Eliminar(cola);
    }
    free(cola);
}

// Función para enconlar un pedido en la cola 
void encolar(Cola* cola, Pedido* pedido) {
    if (cola == NULL || pedido == NULL) {
        fprintf(stderr, "Error al encolar: cola o pedido es NULL.\n");
        return;
    }
    NodoPedido* nodo = crearNodoPedido(pedido);
    if (!cola->cabeza) {
        cola->cabeza = nodo;
        cola->final = nodo;
    } else {
        cola->final->siguiente = nodo;
        cola->final = nodo;
    }
}

// Consultar el pedido en la cabeza de la cola y devolverlo, o NULL si la cola está vacía o es nula
Pedido* Consultar(Cola* cola) {
    if (cola->cabeza) {
        return cola->cabeza->pedido;
    } else {
        return NULL;
    }
}

// Función para eliminar el pedido en la cabeza de la cola y actualizar la cabeza al siguiente nodo, o avisar si la cola es nula o está vacía
void Eliminar(Cola* cola) {
    if (cola == NULL || cola->cabeza == NULL) {
        fprintf(stderr, "Error al eliminar: cola es NULL o está vacía.\n");
        return;
    }
    NodoPedido* eliminado = cola->cabeza;
    cola->cabeza = eliminado->siguiente;
    DestruirNodoPedido(eliminado);
    if (cola->cabeza) {
        cola->final = NULL;
    }
}

// Función para despachar un pedido, que consulta el pedido en la cabeza de la cola y luego lo elimina de la cola, devolviendo el pedido despachado o NULL si la cola está vacía o es nula
/* Pedido* DespacharPedido(Cola* cola) {
	if (cola == NULL || cola->cabeza == NULL) {
		fprintf(stderr, "Error al despachar pedido: cola es NULL o está vacía.\n");
		return NULL;
	}
	Pedido* pedido_despachado = Consultar(cola);
	Eliminar(cola);
	return pedido_despachado;
} */