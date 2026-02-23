//
// pedido.h
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#ifndef pedido_h
#define pedido_h

#include <stdio.h>

// Definición de estructuras para el pedido
typedef struct LineaPedido {
    int id_producto;
    int cantidad;
    float precio_unitario;
} LineaPedido;

// Nodo para la lista enlazada de líneas de pedido
typedef struct NodoLineaPedido {
    LineaPedido linea;
    struct NodoLineaPedido *siguiente;
} NodoLineaPedido;

// Estructura para el pedido
typedef struct Pedido {
    int id_cliente;
    NodoLineaPedido *lista_productos;
} Pedido;   

// Prototipos de funciones auxiliares
LineaPedido crearLineaPedido();
Pedido* crearPedido();
void imprimirLineaPedido(LineaPedido* linea);
void imprimirPedido(Pedido* pedido);
void destruirPedido(Pedido* pedido);

#endif /* pedido_h */