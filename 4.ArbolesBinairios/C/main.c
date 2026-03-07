//
// main.c
// EstructurasC
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo para el árbol binario
typedef struct Nodo {
    int valor;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
    struct Nodo* padre;
} Nodo;

// Definición del tipo de dato para el árbol binario
typedef Nodo ArbolBinario;

// Función para crear un nuevo nodo con el valor dado
Nodo* crearNodo(int valor, Nodo* padre) {
    Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));
    if (nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo.\n");
        return NULL;
    }
    nodo->valor = valor;
    // Inicializar los punteros izquierdo y derecho como NULL
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->padre = padre; // Establecer el puntero al nodo padre
    return nodo;
}

// Función para destruir un nodo y liberar su memoria
void destruirNodo(Nodo* nodo) {
    nodo->izquierdo = NULL; // Desconectar el nodo del árbol
    nodo->derecho = NULL; // Desconectar el nodo del árbol  
    free(nodo); // Liberar la memoria del nodo actual
}

// Función para insertar un valor en el árbol binario
static void InsertarConPadre(Nodo** arbol, Nodo* padre, int valor) {
    if (*arbol == NULL) {
        *arbol = crearNodo(valor, padre); // Si el árbol está vacío, crear un nuevo nodo
    } else {
        int valorActual = (*arbol)->valor; // Obtener el valor del nodo actual
        if (valor < valorActual) {
            InsertarConPadre(&((*arbol)->izquierdo), *arbol, valor); // Insertar en el subárbol izquierdo
        } else {
            InsertarConPadre(&((*arbol)->derecho), *arbol, valor); // Insertar en el subárbol derecho
        }
    }
}

// Función pública para insertar un valor en el árbol binario, sin necesidad de proporcionar el nodo padre
void Insertar(Nodo** arbol, int valor) {
    InsertarConPadre(arbol, NULL, valor); // Llamar a la función de inserción con el nodo padre inicial como NULL
}

// Función para verificar si un valor existe en el árbol binario
int Existe(Nodo* arbol, int valor) {
    if (arbol == NULL) {
        return 0; // El valor no existe en el árbol
    }
    if (arbol->valor == valor) {
        return 1; // El valor existe en el árbol
    }
    if (valor < arbol->valor) {
        return Existe(arbol->izquierdo, valor); // Buscar en el subárbol izquierdo
    } else {
        return Existe(arbol->derecho, valor); // Buscar en el subárbol derecho
    }
}

// Funcion de utilidad para determinar la existencia de un valor en el árbol y mostrar un mensaje
void DeterminarExistencia(Nodo* arbol, int valor) {
    if (Existe(arbol, valor)) {
        printf("El valor %d existe en el árbol.\n", valor);
    } else {
        printf("El valor %d no existe en el árbol.\n", valor);
    }
}

// Función para obtener un nodo con el valor dado en el árbol binario
Nodo* Obtener (Nodo* arbol, int valor) {
    if (arbol == NULL) {
        return NULL; // El valor no existe en el árbol
    }
    if (arbol->valor == valor) {
        return arbol; // El valor existe en el árbol, retornar el nodo
    }
    if (valor < arbol->valor) {
        return Obtener(arbol->izquierdo, valor); // Buscar en el subárbol izquierdo
    } else {
        return Obtener(arbol->derecho, valor); // Buscar en el subárbol derecho
    }
}

// Función para reemplazar un nodo en el árbol binario
static void ReemplazarNodo(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre){
        // Procedemos a colocar en el padre de árbol el nuevo nodo como hijo nuevo
        if (arbol->padre == arbol->padre->izquierdo) {
            arbol->padre->izquierdo = nuevoNodo; // El nuevo nodo se convierte en el hijo izquierdo del padre
        } else if (arbol->padre == arbol->padre->derecho) {
            arbol->padre->derecho = nuevoNodo; // El nuevo nodo se convierte en el hijo derecho del padre
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre; // El nuevo nodo apunta al padre del nodo actual
    }
}

// Función para buscar el nodo mínimo en un subárbol dado
static Nodo* BuscarMinimo(Nodo* arbol) {
    if (arbol == NULL) {
        return NULL; // El subárbol está vacío, retornar NULL
    }
    while (arbol->izquierdo) {
        return BuscarMinimo(arbol->izquierdo); // Seguir buscando en el subárbol izquierdo hasta encontrar el nodo mínimo
    }
    return arbol; // Retornar el nodo mínimo encontrado
}

// Función para eliminar un nodo del árbol binario
static void EliminarNodo(Nodo* NodoEliminar){
    if (NodoEliminar->izquierdo && NodoEliminar->derecho) {
        // Tratar de eliminar un nodo con dos hijos
        Nodo* nodoMinimo = BuscarMinimo(NodoEliminar->derecho); // Buscar el nodo mínimo en el subárbol derecho
        NodoEliminar->valor = nodoMinimo->valor; // Reemplazar el valor del nodo a eliminar con el valor del nodo mínimo encontrado
        EliminarNodo(nodoMinimo); // Eliminar el nodo mínimo encontrado
    } else if (NodoEliminar->izquierdo){
        // Tratar de eliminar un nodo con un hijo izquierdo
        ReemplazarNodo(NodoEliminar, NodoEliminar->izquierdo); // Reemplazar el nodo a eliminar por su hijo izquierdo
        destruirNodo(NodoEliminar); // Destruir el nodo a eliminar
    } else if (NodoEliminar->derecho) {
        // Tratar de eliminar un nodo con un hijo derecho
        ReemplazarNodo(NodoEliminar, NodoEliminar->derecho); // Reemplazar el nodo a eliminar por su hijo derecho
        destruirNodo(NodoEliminar); // Destruir el nodo a eliminar
    } else {
        // Tratar de eliminar un nodo sin hijos (nodo hoja)
        ReemplazarNodo(NodoEliminar, NULL); // Reemplazar el nodo a eliminar por NULL
        destruirNodo(NodoEliminar); // Destruir el nodo a eliminar
    }
}

// Función para eliminar un nodo con el valor dado en el árbol binario
void Eliminar(Nodo* arbol, int valor) {
    if (arbol == NULL) {
        return; // El valor no existe en el árbol, salir de la función
    } else if (valor < arbol->valor) {
        Eliminar(arbol->izquierdo, valor); // Buscar en el subárbol izquierdo
    } else if (valor > arbol->valor) {
        Eliminar(arbol->derecho, valor); // Buscar en el subárbol derecho
    } else {
        // El nodo a eliminar se encuentra aquí
        EliminarNodo(arbol); // Llamar a la función para eliminar el nodo
    }
}

// Función para recorrer el árbol en preorden (raíz, izquierda, derecha)
void Preorden(Nodo* arbol) {
    if (arbol == NULL) {
        printf(" - "); // El árbol está vacío, mostrar mensaje
    } else {    
        printf("( %d ", arbol->valor); // Visitar el nodo actual
        Preorden(arbol->izquierdo); // Recorrer el subárbol izquierdo
        Preorden(arbol->derecho); // Recorrer el subárbol derecho
        printf(")"); // Cerrar el paréntesis para indicar el final del nodo
    }
}

// Función para recorrer el árbol en inorden (izquierda, raíz, derecha)
void Inorden(Nodo* arbol) {
    if (arbol == NULL) {
        printf(" - "); // El árbol está vacío, mostrar mensaje
    } else {
        printf("( "); // Abrir un paréntesis para indicar el inicio del nodo
        Inorden(arbol->izquierdo); // Recorrer el subárbol izquierdo
        printf("%d ", arbol->valor); // Visitar el nodo actual
        
        // Mejora para ver cual es el padre del nodo que se va a insertar en el árbol
        /*if (arbol->padre == NULL) {
            printf(" %d {//}", arbol->valor, arbol->padre->valor); // Agregar un espacio entre el subárbol izquierdo y el nodo actual
        } else {
            printf(" %d {%d}", arbol->valor, arbol->padre->valor); // Visitar el nodo actual
        
        }*/

        Inorden(arbol->derecho); // Recorrer el subárbol derecho
        printf(" )"); // Cerrar el paréntesis para indicar el final del nodo
    }
}

// Función para recorrer el árbol en postorden (izquierda, derecha, raíz)
void Postorden(Nodo* arbol) {
    if (arbol == NULL) {    
        printf(" - "); // El árbol está vacío, mostrar mensaje
    } else {
        printf("( "); // Abrir un paréntesis para indicar el inicio del nodo
        Postorden(arbol->izquierdo); // Recorrer el subárbol izquierdo
        Postorden(arbol->derecho); // Recorrer el subárbol derecho
        printf("%d )", arbol->valor); // Visitar el nodo actual y cerrar el paréntesis para indicar el final del nodo
    }
}

int main(int argc, char **argv) {
    Nodo *arbol = NULL; // Inicializar el árbol como NULL
    // Insertar valores en el árbol binario
    Insertar(&arbol, 5);        // Preorden(arbol); printf("\n"); Postorden(arbol); printf("\n"); Inorden(arbol); printf("\n");
    Insertar(&arbol, 10);       // Preorden(arbol); printf("\n"); Postorden(arbol); printf("\n"); Inorden(arbol); printf("\n");
    Insertar(&arbol, 4);        // Preorden(arbol); printf("\n"); Postorden(arbol); printf("\n"); Inorden(arbol); printf("\n");
    Insertar(&arbol, 9);        // Preorden(arbol); printf("\n"); Postorden(arbol); printf("\n"); Inorden(arbol); printf("\n");
    Insertar(&arbol, 15);       // Preorden(arbol); printf("\n"); Postorden(arbol); printf("\n"); Inorden(arbol); printf("\n");
    Insertar(&arbol, 20);       // Preorden(arbol); printf("\n"); Postorden(arbol); printf("\n"); Inorden(arbol); printf("\n");
    Insertar(&arbol, 2);       // Preorden(arbol); printf("\n"); Postorden(arbol); printf("\n"); Inorden(arbol); printf("\n");

    Eliminar(arbol, 4);
    Eliminar(arbol, 15);
    Eliminar(arbol, 5);
    /*
    DeterminarExistencia(arbol, 10); // Verificar si el valor 10 existe en el árbol
    DeterminarExistencia(arbol, 7); // Verificar si el valor 7 existe en el árbol (y no existe y se muestra el mensaje correspondiente)
    DeterminarExistencia(arbol, 4); // Verificar si el valor 4 existe en el árbol
    */

    return 0;
}