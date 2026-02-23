//
// cola.h
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#ifndef cola_h
#define cola_h

#include <stdio.h>
#include "pedido.h"

// Nodo para la cola de pedidos que contiene un pedido y un puntero al siguiente nodo
typedef struct NodoPedido {
    Pedido* pedido;
    struct NodoPedido *siguiente;
} NodoPedido;

// Estructura para la cola de pedidos en la cabeza y el final de la cola
typedef struct Cola {
    NodoPedido *cabeza;
    NodoPedido *final;
} Cola;

// Como crear un nodo de pedido y destruirlo
NodoPedido* crearNodoPedido(Pedido* pedido);
void DestruirNodoPedido(NodoPedido* nodo);

// Funciones para crear y destruir la cola de pedidos
Cola* crearCola();
void destruirCola(Cola* cola);

// Funciones para encolar, desencolar y consultar los pedidos
void encolar(Cola* cola, Pedido* pedido);
Pedido* Consultar(Cola* cola);
void Eliminar(Cola* cola);

// Si queremos despachar un pedido, tenemos que conultar y eliminar el pedido de la cola
// Pedido* DespacharPedido(Cola* cola);
// En mi caso no lo voy a implementar, pero se puede hacer con las funciones de consultar y eliminar

#endif /* cola_h */