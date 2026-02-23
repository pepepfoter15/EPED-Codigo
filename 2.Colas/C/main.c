// main.c
// EstructurasC - Colas de Pedidos
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "pedido.h"

// Función para contar los pedidos en la cola
int contarPedidos(Cola* cola) {
    int contador = 0;
    NodoPedido* actual = cola->cabeza;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// Función para imprimir todos los pedidos de la cola
void imprimirCola(Cola* cola) {
    if (cola == NULL || cola->cabeza == NULL) {
        printf("\n*** La cola está vacía ***\n");
        return;
    }
    printf("\n=== CONTENIDO DE LA COLA ===\n");
    NodoPedido* actual = cola->cabeza;
    int contador = 1;
    while (actual != NULL) {
        printf("\nPedido #%d:\n", contador);
        imprimirPedido(actual->pedido);
        actual = actual->siguiente;
        contador++;
    }
    printf("\nTotal de pedidos en cola: %d\n", contador - 1);
    printf("============================\n");
}

int main(void) {
    Cola* cola = crearCola();
    if (cola == NULL) {
        fprintf(stderr, "Error al crear la cola.\n");
        return 1;
    }
    char line[128];
    int opcion = -1;
    while (1) {
        printf("\n========== MENU - COLA DE PEDIDOS ==========\n");
        printf("1) Agregar pedido a la cola (encolar)\n");
        printf("2) Quitar pedido de la cola (desencolar)\n");
        printf("3) Consultar pedido en cabeza\n");
        printf("4) Mostrar todos los pedidos\n");
        printf("5) Contar pedidos en la cola\n");
        printf("0) Salir\n");
        printf("============================================\n");
        printf("Elija opcion (0-5): ");
        if (!fgets(line, sizeof(line), stdin)) break;
        opcion = (int)strtol(line, NULL, 10);
        if (opcion == 0) {
            printf("\nSaliendo del programa...\n");
            break;
        }
        switch (opcion) {
            case 1: {
                printf("\n--- Crear Nuevo Pedido ---\n");
                Pedido* pedido = crearPedido();
                if (pedido != NULL) {
                    encolar(cola, pedido);
                    printf("\n✓ Pedido encolado correctamente. Total: %d pedidos\n", contarPedidos(cola));
                }
                break;
            }
            case 2: {
                if (cola->cabeza == NULL) {
                    printf("\n✗ Error: La cola está vacía, no hay pedidos para eliminar.\n");
                } else {
                    printf("\n--- Desencolar Pedido ---\n");
                    Pedido* pedido = Consultar(cola);
                    if (pedido != NULL) {
                        printf("Eliminando pedido del cliente: %d\n", pedido->id_cliente);
                    }
                    Eliminar(cola);
                    destruirPedido(pedido);
                    printf("✓ Pedido desencola correctamente. Total: %d pedidos\n", contarPedidos(cola));
                }
                break;
            }
            case 3: {
                printf("\n--- Consultar Pedido en Cabeza ---\n");
                Pedido* pedido = Consultar(cola);
                if (pedido == NULL) {
                    printf("✗ La cola está vacía, no hay pedidos.\n");
                } else {
                    printf("\nPedido en cabeza:\n");
                    imprimirPedido(pedido);
                }
                break;
            }
            case 4: {
                imprimirCola(cola);
                break;
            }
            case 5: {
                int total = contarPedidos(cola);
                printf("\n Total de pedidos en la cola: %d\n", total);
                break;
            }
        }
    }
    /* Liberar memoria restante */
    NodoPedido* actual = cola->cabeza;
    while (actual != NULL) {
        NodoPedido* temp = actual;
        actual = actual->siguiente;
        destruirPedido(temp->pedido);
    }
    destruirCola(cola);
    printf("\nSaliendo. Total registros finales: %d\n", contarPedidos(cola));
    return 0;
}
