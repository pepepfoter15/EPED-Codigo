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

/* función auxiliar para leer un libro desde stdin */
static void leerLibro(Libro *lib) {
    printf("Ingrese el titulo del libro: ");
    if (!fgets(lib->titulo, sizeof lib->titulo, stdin)) lib->titulo[0] = '\0';
    lib->titulo[strcspn(lib->titulo, "\n")] = '\0';

    printf("Ingrese el autor del libro: ");
    if (!fgets(lib->autor, sizeof lib->autor, stdin)) lib->autor[0] = '\0';
    lib->autor[strcspn(lib->autor, "\n")] = '\0';

    printf("Ingrese el ISBN del libro: ");
    if (!fgets(lib->isbn, sizeof lib->isbn, stdin)) lib->isbn[0] = '\0';
    lib->isbn[strcspn(lib->isbn, "\n")] = '\0';
}

/* imprimir todos los libros usando obtener() */
static void imprimirLista(Lista *lst) {
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