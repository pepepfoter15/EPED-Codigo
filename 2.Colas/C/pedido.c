//
// pedido.c
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"

LineaPedido crearLineaPedido() {
    LineaPedido linea;
    char buffer[128];
    printf("  ID Producto: ");
    fgets(buffer, sizeof(buffer), stdin);
    linea.id_producto = (int)strtol(buffer, NULL, 10);
    printf("  Cantidad: ");
    fgets(buffer, sizeof(buffer), stdin);
    linea.cantidad = (int)strtol(buffer, NULL, 10);
    printf("  Precio Unitario: ");
    fgets(buffer, sizeof(buffer), stdin);
    linea.precio_unitario = (float)strtof(buffer, NULL);
    return linea;
}

Pedido* crearPedido() {
    Pedido* pedido = (Pedido*)malloc(sizeof(Pedido));
    if (pedido == NULL) {
        fprintf(stderr, "Error al asignar memoria para el pedido.\n");
        return NULL;
    }
    char buffer[128];
    int num_lineas;
    printf("ID Cliente: ");
    fgets(buffer, sizeof(buffer), stdin);
    pedido->id_cliente = (int)strtol(buffer, NULL, 10);
    printf("Número de líneas de pedido: ");
    fgets(buffer, sizeof(buffer), stdin);
    num_lineas = (int)strtol(buffer, NULL, 10);
    pedido->lista_productos = NULL;
    for (int i = 0; i < num_lineas; i++) {
        printf("\nLínea %d:\n", i + 1);
        LineaPedido linea = crearLineaPedido();
        NodoLineaPedido* nuevoNodo = (NodoLineaPedido*)malloc(sizeof(NodoLineaPedido));
        if (nuevoNodo == NULL) {
            fprintf(stderr, "Error al asignar memoria para la línea de pedido.\n");
            return NULL;
        }
        nuevoNodo->linea = linea;
        nuevoNodo->siguiente = NULL;
        if (pedido->lista_productos == NULL) {
            pedido->lista_productos = nuevoNodo;
        } else {
            nuevoNodo->siguiente = pedido->lista_productos;
            pedido->lista_productos = nuevoNodo;
        }
    }
    return pedido;
}

void imprimirLineaPedido(LineaPedido* linea) {
    printf("    - Producto: %d, Cantidad: %d, Precio: %.2f€\n", linea->id_producto, linea->cantidad, linea->precio_unitario);
}

void imprimirPedido(Pedido* pedido) {
    if (pedido == NULL) {
        printf("Pedido NULL\n");
        return;
    }
    printf("  ID Cliente: %d\n", pedido->id_cliente);
    printf("  Productos:\n");
    NodoLineaPedido* actual = pedido->lista_productos;
    float total = 0.0;
    while (actual != NULL) {
        imprimirLineaPedido(&actual->linea);
        total += actual->linea.cantidad * actual->linea.precio_unitario;
        actual = actual->siguiente;
    }
    printf("  Total: %.2f€\n", total);
}

void destruirPedido(Pedido* pedido) {
    if (pedido == NULL) return;
    NodoLineaPedido* actual = pedido->lista_productos;
    while (actual != NULL) {
        NodoLineaPedido* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(pedido);
}
