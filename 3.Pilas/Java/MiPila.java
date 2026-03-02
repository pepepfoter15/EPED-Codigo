//
// MiPila.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

public class MiPila implements Pila {

    // Atributos de la pila
    private class Nodo {
        public URL url;
        public Nodo siguiente = null;

        public Nodo(URL url) {
            this.url = url;
        }
    }

    // Declaración de la cima de la pila como nulo para indicar que la pila está vacía
    private Nodo cima = null;

    private int longitud = 0; // Variable para llevar la cuenta de la longitud de la pila

    // Implementación de los métodos de la pila

    @Override
    // Método para apilar un URL en la pila
    public void apilar(URL url) {
        Nodo nuevoNodo = new Nodo(url);
        nuevoNodo.siguiente = cima;
        cima = nuevoNodo;
        longitud++; // Incrementar la longitud al apilar un nuevo elemento
    }

    @Override
    // Método para desapilar un URL de la pila
    public void desapilar() {
        if (!estaVacia()) {
            Nodo nodoAEliminar = cima;
            cima = cima.siguiente;
            nodoAEliminar.siguiente = null; // Ayuda al recolector de basura
            longitud--; // Decrementar la longitud al desapilar un elemento
        } else {
            System.out.println("La pila está vacía. No se puede desapilar.");
        }
    }

    @Override
    // Método para obtener el URL en la cima de la pila sin modificarla
    public URL obtenerCima() {
        if (!estaVacia()) {
            return cima.url;
        } else {
            System.out.println("La pila está vacía. No hay cima.");
            return null;
        }
    }

    @Override
    public boolean estaVacia() {
        return cima == null; // La pila está vacía si la cima es nula
    }

    @Override
    public int longitud() {
        return longitud;
    }
}