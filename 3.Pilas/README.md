# Pilas - Implementación en C y Java

## Resumen

Implementación de estructura de datos Pila (LIFO - Last In First Out) que gestiona elementos basados en una política de último en entrar, primero en salir. Comparación entre C (gestión manual de memoria) y Java (gestión automática).

## Estructura de Archivos

### C/
- pila.h: Definición de estructuras (Nodo, Pila)
- pila.c: Implementación de operaciones de pila

### Java/
- Pila.java: Interfaz o clase base de pila
- MiPila.java: Implementación concreta de la pila
- Ejemplo.java: Programa de ejemplo con pruebas
- URL.java: Clase auxiliar para exemplificar uso de pilas (p.ej., validación de paréntesis, conversión, etc.)

## Diferencias de Implementación

### En C - Gestión Manual de Memoria
```c
Pila *pila = (Pila*)malloc(sizeof(Pila));  // Crear pila
pila->tope = NULL;                         // Inicializar tope
apilar(pila, elemento);                    // Apilar elemento
desapilar(pila);                           // Desapilar
free(pila);                                // Liberar (OBLIGATORIO)
```

**Puntos importantes:**
- Debes usar `malloc()` para crear la estructura de la pila
- La pila mantiene un puntero al `tope` (el último elemento insertado)
- SIEMPRE debes liberar memoria con `free()` para evitar memory leaks
- Las operaciones de apilar y desapilar modifican el puntero del tope
- Gestiona manualmente el tamaño/longitud de la pila

### En Java - Gestión Automática
```java
Pila pila = new MiPila();                  // Crear pila
pila.apilar(elemento);                     // Apilar elemento
pila.desapilar();                          // Desapilar
pila.cima();                               // Obtener elemento en cima
// GC libera automáticamente cuando no hay referencias
```

**Puntos importantes:**
- El operador `new` crea objetos en memoria automáticamente
- Usa intérfaces o clases heredadas para abstracción
- El Garbage Collector libera memoria automáticamente
- Las referencias null se manejan automáticamente

## Comparación Técnica

| Aspecto | C | Java |
|---------|---|------|
| Asignación | `malloc()` | `new` |
| Liberación | `free()` (manual) | Garbage Collector (automático) |
| Acceso | `puntero->campo` | `objeto.atributo` |
| Punteros | Explícitos `*` | Implícitos (referencias) |
| Errores | Posibles memory leaks | Evitados por GC |
| Rendimiento | Más rápido | Más lento por GC |
| Seguridad | Menor | Mayor |

## Características de una Pila

- **LIFO (Last In, First Out):** El último elemento insertado es el primero en salir
- **Operación apilar:** Agrega un elemento al tope
- **Operación desapilar:** Elimina y retorna el elemento del tope
- **Cima:** Obtiene el elemento superior sin eliminarlo
- **Vacía:** Verifica si la pila está vacía

## Aplicaciones Prácticas

- Evaluación de expresiones (notación postfija)
- Validación de paréntesis/corchetes
- Deshacer/Rehacer (Undo/Redo)
- Conversión entre sistemas de numeración
- Algoritmos de búsqueda en profundidad (DFS)
- Navegación histórica (back button)
