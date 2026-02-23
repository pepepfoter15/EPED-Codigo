//
// MiColaProceso.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

public class MiColaProceso implements ColaProceso {
    // Clase nodo para representar cada nodo de la cola
    private class NodoProceso {
        Trabajo trabajo;
        NodoProceso siguiente;

        // Constructor del NodoProceso que recibe un trabajo y inicializa el siguiente nodo a null
        public NodoProceso(Trabajo trabajo) {
            this.trabajo = trabajo;
            this.siguiente = null;
        }
    }

    private NodoProceso cabeza; // Nodo que representa el frente de la cola
    private NodoProceso final;    // Nodo que representa el fin de la cola

    // Función que encola un trabajo en la cola, o que también dicho, que inserta al final de la cola un nuevo trabajo
    @Override
    public void encolar(Trabajo trabajo) {
        // Crear un nuevo nodo con el trabajo a encolar
        NodoProceso nuevoNodo = new NodoProceso(trabajo);
        // Si la cola está vacía, el nuevo nodo será tanto la cabeza como el final de la cola
        if (cabeza == null) {
            cabeza = nuevoNodo;
        } else {
            final.siguiente = nuevoNodo;
        }
        // El nuevo nodo se convierte en el nuevo final de la cola en ambos casos
        final = nuevoNodo;
    }

    // Función que elimina el trabajo de la cabeza de la cola
    @Override
    public void eliminar() {
        // Si la cola no está vacía, se mueve la cabeza al siguiente nodo
        if (cabeza != null) {
            // Mover la cabeza al siguiente nodo y elimina la cabecera antigua y la actuazliza a la nueva cabecera
            NodoProceso eliminar = cabeza;
            cabeza = cabeza.siguiente;
            eliminar.siguiente = null; // Eliminar la referencia al nodo eliminado para ayudar al recolector de basura
            // Si después de eliminar el nodo la cabeza es null, significa que la cola está vacía, por lo que también se debe actualizar el final a null
            if (cabeza == null) {
                final = null;
            }
        } else {
            System.out.println("La cola está vacía. No se puede eliminar ningún trabajo.");
        }
    }

    // Función que obtiene el trabajo al frente de la cola sin eliminarlo
    @Override
    public Trabajo obtener() {
        if (cabeza != null) {
            return cabeza.trabajo;
        } else {
            System.out.println("La cola está vacía. No hay trabajos para obtener.");
            return null;
        }
    }
}
