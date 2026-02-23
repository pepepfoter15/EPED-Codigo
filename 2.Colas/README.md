# Colas - Implementación en C y Java

## Resumen

Implementación de estructura de datos Cola (FIFO - First In First Out) que gestiona procesos o tareas. Comparación entre C (gestión manual de memoria) y Java (gestión automática).

## Estructura de Archivos

### C/
- cola.h: Definición de estructuras (Nodo, Cola)
- cola.c: Implementación de operaciones de cola
- pedido.h: Definición de estructura Pedido/Trabajo
- pedido.c: Funciones auxiliares
- main.c: Programa principal

### Java/
- Trabajo.java: Clase que representa un Trabajo/Pedido
- ColaProceso.java: Interfaz o clase abstracta de cola
- MiColaProceso.java: Implementación concreta de la cola

## Diferencias de Implementación

### En C - Gestión Manual de Memoria
```c
Cola *cola = (Cola*)malloc(sizeof(Cola));  // Crear cola
cola->inicio = NULL;                       // Inicializar punteros
cola->final = NULL;
encolar(cola, elemento);                   // Encolar elemento
desencolar(cola);                          // Desencolar
free(cola);                                // Liberar (OBLIGATORIO)
```

**Puntos importantes:**
- Debes usar `malloc()` para crear la estructura de la cola
- La cola mantiene punteros a `inicio` y `final` para eficiencia
- SIEMPRE debes liberar memoria con `free()` para evitar memory leaks
- Las operaciones de encolar y desencolar modifican los punteros
- Gestiona manualmente el tamaño/longitud de la cola

### En Java - Gestión Automática
```java
ColaProceso cola = new MiColaProceso();     // Crear cola
cola.encolar(trabajo);                      // Encolar trabajo
cola.desencolar();                          // Desencolar
// GC libera automáticamente cuando no hay referencias
```

**Puntos importantes:**
- El operador `new` crea objetos en memoria automáticamente
- Usa intérfaces o clases heredadas para abstracción
- El Garbage Collector libera memoria automáticamente
- Las operaciones se expresan con métodos claros

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
gcc -o colas main.c cola.c pedido.c
./colas
```

**Java:**
```bash
javac *.java
java Main
```

## Principales Funciones

### Encolar (Enqueue)
Añade un elemento al final de la cola.
- **C:** `void encolar(Cola *cola, Pedido pedido);`
- **Java:** `void encolar(Trabajo trabajo);`
- **Complejidad:** O(1)

### Desencolar (Dequeue)
Elimina y devuelve el elemento del principio de la cola.
- **C:** `Pedido desencolar(Cola *cola);`
- **Java:** `Trabajo desencolar();`
- **Complejidad:** O(1)

### Consultar (Peek/Frente)
Obtiene el elemento del frente sin eliminarlo.
- **C:** `Pedido consultar(Cola *cola);`
- **Java:** `Trabajo consultar();` o `Trabajo frente();`
- **Complejidad:** O(1)

## Complejidad de Operaciones

### ¿Qué significa la complejidad?

- **O(1)** = Tiempo **CONSTANTE** - La operación tarda **siempre lo mismo**, sin importar cuántos elementos haya
- **O(n)** = Tiempo **LINEAL** - La operación tarda **más cuanto más elementos haya**

### Tabla de Complejidad

| Operación | Complejidad | Explicación |
|-----------|-------------|-------------|
| **Encolar** | O(1) | Solo añade un elemento al final. **Siempre tarda lo mismo**, tenga 1 o 1.000.000 elementos |
| **Desencolar** | O(1) | Solo quita el primer elemento. **Siempre tarda lo mismo**, sin recorrer la cola |
| **Consultar frente** | O(1) | Solo accede al primer elemento. **Tiempo instantáneo**, sin buscar |
| **Consultar tamaño** | O(1) | Solo lee una variable guardada. **Instantáneo** |
| **Comprobar si está vacía** | O(1) | Solo verifica si hay elementos. **Instantáneo** |

### Ejemplo Práctico

```
Cola con 5 elementos:  [1] → [2] → [3] → [4] → [5]

encolar(6):           [1] → [2] → [3] → [4] → [5] → [6]
Tiempo: ~0.001 ms

Cola con 1.000.000 elementos:
encolar(x):           [1] → [2] → ... → [999.999] → [1.000.000] → [x]
Tiempo: ~0.001 ms (¡IGUAL! Por eso es O(1))
```

La razón es que la cola solo necesita cambiar el puntero `final`, sin recorrer nada.

## Consideraciones del Código

**En C:**
- La estructura Cola mantiene dos punteros (`inicio` y `final`) para optimizar encolar/desencolar
- El campo `longitud` en Cola debe actualizarse en cada operación
- La función `desencolar()` debe verificar si la cola está vacía
- Debes gestionar cuidadosamente los punteros `inicio` y `final` al insertar/eliminar

**En Java:**
- La clase Nodo generalmente está como clase interna privada
- Implementar métodos como `estaVacia()` para verificar estado
- Los métodos pueden lanzar excepciones cuando se intenta desencolar de una cola vacía
- El patrón FIFO se mantiene mediante la gestión de referencias de inicio y final

---

**Copyright (c) 2026 José Carlos Rodríguez Cañas**
