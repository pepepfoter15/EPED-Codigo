//
// libro.h
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#ifndef libro_h
#define libro_h

#include <stdio.h>

typedef struct Libro {
    char titulo[50];
    char autor[50];
    char isbn[50];
} Libro;

// Leer un libro desde stdin
void leerLibro(Libro *lib);

#endif /* libro_h */