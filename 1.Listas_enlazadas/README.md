# Listas Enlazadas - Comparación C vs Java

Este directorio contiene una implementación de listas enlazadas en ambos lenguajes C y Java, permitiendo entender cómo funcionan los punteros en C y cómo se traducen a referencias en Java.

## Estructura de Archivos

### C/
- **lista.h**: Definición de estructuras (Nodo, Lista) y declaración de funciones
- **lista.c**: Implementación de operaciones de lista enlazada
- **libro.h**: Definición de estructura Libro
- **libro.c**: Funciones auxiliares para Libro
- **main.c**: Programa principal con menú interactivo

### Java/
- **Nodo.java**: Clase equivalente a `struct Nodo` en C
- **Libro.java**: Clase equivalente a `struct Libro` en C
- **Lista.java**: Clase con los métodos equivalentes de lista.c
- **Main.java**: Programa principal equivalente a main.c

## Conceptos Clave: Punteros en C vs Referencias en Java

### En C (Gestión Manual de Memoria)
```c
// Creación dinámica de nodo
Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));  // Asignar memoria
nodo->siguiente = NULL;                     // Acceso mediante puntero
free(nodo);                                 // Liberar memoria manualmente
```

### En Java (Gestión Automática de Memoria)
```java
// Creación de nodo
Nodo nodo = new Nodo(libro);  // Crear objeto (nueva referencia)
nodo.setSiguiente(null);       // Acceso mediante referencia
// No necesitas liberar memoria - el Garbage Collector lo hace
```

## Diferencias Importantes

| Característica | C | Java |
|---|---|---|
| **Memoria** | Manual (malloc/free) | Automática (GC) |
| **Punteros** | Explícitos (`*`, `->`) | Implícitos (referencias) |
| **Acceso a campos** | `ptr->campo` | `obj.getField()` |
| **Null** | `NULL` | `null` |
| **Tipos** | `struct` | `class` |
| **Métodos** | Funciones externas | Métodos de clase |

## Cómo Compilar y Ejecutar

### C
```bash
cd C/
gcc -o listas_enlazadas main.c lista.c libro.c
./listas_enlazadas
```

### Java
```bash
cd Java/
javac *.java
java Main
```

## Funcionalidades

Ambas implementaciones proporcionan:

1. **Inserción**
   - Al principio: O(1)
   - Al final: O(n)
   - Después de posición `n`: O(n)

2. **Eliminación**
   - Principio: O(1)
   - Último: O(n)
   - Elemento en posición: O(n)

3. **Búsqueda**
   - Obtener elemento en posición `n`: O(n)
   - Contar elementos: O(1)
   - Verificar si está vacía: O(1)

4. **Visualización**
   - Imprimir todos los elementos

## Notas Sobre Punteros

En C, los punteros son fundamentales:
- Representan direcciones de memoria
- Permiten acceso indirecto a datos
- Requieren gestión manual de memoria
- Más control pero más responsabilidad

En Java, las referencias abstraen los punteros:
- Son similares conceptualmente pero transparentes
- El compilador y JVM manejan la dirección internamente
- No hay acceso directo a memoria
- Más seguro, menos control
