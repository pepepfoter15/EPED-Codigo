# Listas Enlazadas - Implementación en C y Java

## Resumen

Implementación de lista enlazada que gestiona una colección de libros. Comparación entre C (gestión manual de memoria) y Java (gestión automática).

## Estructura de Archivos

### C/
- lista.h: Definición de estructuras (Nodo, Lista)
- lista.c: Implementación de operaciones
- libro.h: Definición de estructura Libro
- libro.c: Funciones auxiliares
- main.c: Programa principal

### Java/
- Libro.java: Clase que representa un Libro
- Lista.java: Clase que implementa la lista enlazada
- Main.java: Programa principal

## Diferencias de Implementación

### En C - Gestión Manual de Memoria
```c
Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));  // Asignar memoria
nodo->siguiente = NULL;                     // Usar operador ->
free(nodo);                                 // Liberar (OBLIGATORIO)
```

**Puntos importantes:**
- Debes usar `malloc()` para crear nodos dinámicamente
- Usa operador `->` para acceder a campos de punteros
- SIEMPRE debes liberar memoria con `free()` para evitar memory leaks
- Gestiona manualmente la variable `longitud`

### En Java - Gestión Automática
```java
Nodo nodo = new Nodo(libro);    // Crear objeto automáticamente
nodo.siguiente = null;          // Usar operador .
// GC libera automáticamente cuando no hay referencias
```

**Puntos importantes:**
- El operador `new` crea objetos en memoria dinámicamente
- Usa operador `.` para acceder a atributos
- El Garbage Collector libera memoria automáticamente
- Las referencias null se manejan automáticamente

## Comparación Técnica

| Aspecto | C | Java |
|---------|---|------|
| Memoria | Manual (malloc/free) | Automática (GC) |
| Punteros | Explícitos (*->) | Implícitos (referencias) |
| Nulo | NULL | null |
| Tipos | struct | class |
| Compilación | gcc | javac |

## Compilación y Ejecución

**C:**
```bash
gcc -o listas_enlazadas main.c lista.c libro.c
./listas_enlazadas
```

**Java:**
```bash
javac *.java
java Main
```

## Complejidad de Operaciones

| Operación | Complejidad |
|-----------|-------------|
| Insertar al principio | O(1) |
| Insertar al final | O(n) |
| Eliminar al principio | O(1) |
| Eliminar al final | O(n) |
| Obtener elemento en posición n | O(n) |
| Contar elementos | O(1) |

## Consideraciones del Código

**En C:**
- La función `crearNodo()` copia los strings del libro usando `strncpy()` para evitar buffer overflows
- La eliminación de nodos incluye desconexiones explícitas antes de liberar
- El campo `longitud` en Lista debe actualizarse en cada operación

**En Java:**
- La clase Nodo está definida como una clase interna privada de Lista
- Los métodos constructores deben inicializar correctamente los atributos
- La clase Libro tiene constructores por defecto y con parámetros para flexibilidad
- Los getters y setters permiten acceso controlado a los datos

---

**Copyright (c) 2026 José Carlos Rodríguez Cañas**