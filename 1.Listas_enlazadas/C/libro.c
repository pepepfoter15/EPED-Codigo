//
// libro.c
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#include <stdio.h>
#include <string.h>
#include "libro.h"

// Función auxiliar para leer un libro desde stdin
void leerLibro(Libro *lib) {
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
