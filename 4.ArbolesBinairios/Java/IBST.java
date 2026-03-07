//
// IBST.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

package bst;

public interface IBST<T extends Comparable> {
    // Método para insertar un nuevo empleado en el árbol binario de búsqueda
    void insertar(T empleado);
    // Método para ver si existe un empleado con un ID específico en el árbol binario de búsqueda
    boolean existe(int id);
    // Método para obtener un empleado con un ID específico del árbol binario de búsqueda
    T obtener(int id);
    // Método para determinar si el nodo es una hoja (no tiene hijos)
    boolean esHoja();
    boolean esVacio();
    // Métodos para recorrer el árbol en preorden, inorden y postorden
    void preorden();
    void inorden();
    void postorden();
    // Método para eliminar un empleado con un ID específico del árbol binario de búsqueda
    void eliminar(int id);
}