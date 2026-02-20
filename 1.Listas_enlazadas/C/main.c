//
// main.c
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "libro.h"

// Función del programa principal para probar la funcionalidad de la lista enlazada con libros
int main(void) {
    Lista lista;
    lista.cabeza = NULL;
    lista.longitud = 0;

    char line[128];
    int opcion = -1;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1) Insertar al principio\n");
        printf("2) Insertar al final\n");
        printf("3) Insertar despues de posicion (0-based)\n");
        printf("4) Eliminar principio\n");
        printf("5) Eliminar ultimo\n");
        printf("6) Eliminar elemento en posicion (0-based)\n");
        printf("7) Recorrer / Mostrar lista\n");
        printf("0) Salir\n");
        printf("Elija opcion (0-7): ");
        if (!fgets(line, sizeof line, stdin)) break;
        opcion = (int)strtol(line, NULL, 10);

        if (opcion == 0) break;

        switch (opcion) {
            case 1: {
                Libro lib;
                leerLibro(&lib);
                insertarPrincipio(&lista, &lib);
                printf("Insertado al principio. Total: %d\n", contar(&lista));
                break;
            }
            case 2: {
                Libro lib;
                leerLibro(&lib);
                insertarFinal(&lista, &lib);
                printf("Insertado al final. Total: %d\n", contar(&lista));
                break;
            }
            case 3: {
                printf("Posicion after (0-based): ");
                if (!fgets(line, sizeof line, stdin)) break;
                int pos = (int)strtol(line, NULL, 10);
                if (pos < 0) { printf("Posicion invalida\n"); break; }
                Libro lib;
                leerLibro(&lib);
                insertarDespues(pos, &lista, &lib);
                printf("Insertado despues de %d. Total: %d\n", pos, contar(&lista));
                break;
            }
            case 4:
                eliminarPrincipio(&lista);
                printf("Eliminado principio. Total: %d\n", contar(&lista));
                break;
            case 5:
                eliminarUltimo(&lista);
                printf("Eliminado ultimo. Total: %d\n", contar(&lista));
                break;
            case 6: {
                printf("Posicion a eliminar (0-based): ");
                if (!fgets(line, sizeof line, stdin)) break;
                int pos = (int)strtol(line, NULL, 10);
                if (pos < 0 || pos >= contar(&lista)) { printf("Posicion invalida\n"); break; }
                eliminarElemento(pos, &lista);
                printf("Eliminado posicion %d. Total: %d\n", pos, contar(&lista));
                break;
            }
            case 7:
                imprimirLista(&lista);
                break;
            default:
                printf("Opcion no valida.\n");
        }
    }

    /* liberar memoria restante */
    while (!estaVacia(&lista)) eliminarPrincipio(&lista);

    printf("Saliendo. Total registros finales: %d\n", contar(&lista));
    return 0;
}