//
// Lista.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

public class Lista {

    // Instanciar la cabeza de la lista
    private Nodo cabeza;
    private int longitud;

    // Constructor per defecto
    public Lista() {
        this.cabeza = null;
        this.longitud = 0;
    }

    // Crear la clase nodo con un valor infinito para poder ir almacenando los libros
    private class Nodo{
        public Libro libro;
        public Nodo siguiente = null;

        public Nodo(Libro libro) {
            this.libro = libro;
        }

    }

    // Función para insertar libro al principio
    public void insertarPrincipio(Libro libro) {
        Nodo nodo = new Nodo(libro);
        nodo.siguiente = cabeza;
        cabeza = nodo; // La cabeza ahora apunta al nuevo nodo
        longitud++; // Incrementar la longitud de la lista
    }

    // Función para insertar al final
    public void insertarFinal(Libro libro) {
        
        Nodo nodo = new Nodo(libro);

        if (cabeza == null) { // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
            cabeza = nodo;
        } else {
            Nodo puntero = cabeza;
            while (puntero.siguiente != null) { // Recorremos la lista hasta el final
                puntero = puntero.siguiente;
            }
            puntero.siguiente = nodo; // El último nodo ahora apunta al nuevo nodo
        }
        longitud++; // Incrementar la longitud de la lista
    }

    // Función para insertar en medio
    public void insertarDespues(int n, Libro libro) { // n es el libro en la posición de la lista
        Nodo nodo = new Nodo(libro);
        if (cabeza == null) {
            cabeza = nodo;
        } else {
            Nodo puntero = cabeza;
            int posicion = 0; // Inicializamos la posición O un contador a 0
            while (posicion < n && puntero.siguiente != null) { // Recorremos la lista hasta llegar a la posición n
                puntero = puntero.siguiente;
                posicion++;
            }
            nodo.siguiente = puntero.siguiente; // Apuntamos al siguiente de n desde el puntero
            puntero.siguiente = nodo; // Apunta desde el nodo al nuevo valor insertado que apunta a siguiente del nodo.
        }
        longitud++; // Incrementar la longitud de la lista
    }

    // Recorrer la lista
    public Libro obtener(int n) {
        if (cabeza == null) {
            return null; // Si la lista está vacía, devuelve null
        } else {
            Nodo puntero = cabeza;
            int posicion = 0;
            while (posicion < n && puntero.siguiente != null) {
                puntero = puntero.siguiente;
                posicion++;
            }
            if (posicion != n) { // No tenemos suficientes libros ya que n > numero de libros de la lista
                return null;
            } else {
                return puntero.libro; // Mostrar el libro n que tienes
            }
        }
    }

    // Contar cuantos libros o la longitud de la lista
    public int contar() {
        return longitud;
    }

    // Ver si la lista está vacía
    public boolean estaVacia() {
        return cabeza == null;
    }

    // Eliminar la cabecera de la lista
    public void eliminarPrincipio() {
        if (cabeza != null) { // Si la lista no está vacía
            Nodo primer = cabeza;
            cabeza = cabeza.siguiente; // Ponemos el segundo elemento de la lista como la cabecera
            // En Java, el recolector de basura (Garbage Collector) se encarga de liberar la memoria pero es buena práctica desconectar el nodo eliminado para facilitar la recolección de basura
            primer.siguiente = null; // Desconectamos el nodo eliminado de la lista para facilitar la recolección de basura
            longitud--; // Reducimos en 1 la longitud de la lista
        }
    }

    // Eliminar último de la lista
    public void eliminarUltimo() {
        if (cabeza != null) {
            if (cabeza.siguiente != null) { // Para lista de más de 1 elemento
                Nodo puntero = cabeza;
                while (puntero.siguiente.siguiente != null) {
                    puntero = puntero.siguiente;
                }
                puntero.siguiente = null; // El siguiente del penúltimo ahora es null
                longitud--;
            } else { // Para lista de solo un elemento
                cabeza = null;
                longitud--;
            }
        }
    }

    // Eliminar un elemento n de la lista
    public void eliminarElemento(int n) { // Eliminar un nodo cualquiera llamado n
        if (cabeza != null) {
            if (n == 0) { // Caso especial cuando el nodo es igual a 0 o más bien, quiere eliminar la cabecera
                Nodo primer = cabeza;
                cabeza = cabeza.siguiente;
                primer.siguiente = null; // Desconectamos el nodo eliminado de la lista para facilitar la recolección de basura
                longitud--;
            } else if (n < longitud) { // Caso que n > 0 y puedes recorrerlo sin problemas
                Nodo puntero = cabeza;
                int posicion = 0;
                while (posicion < (n - 1)) { // Nos posicionamos en el anterior que queremos eliminar
                    puntero = puntero.siguiente;
                    posicion++;
                }
                // Cuando ya se ha recorrido, pasa a la eliminación del nodo comentado
                Nodo nodoAEliminar = puntero.siguiente;
                puntero.siguiente = nodoAEliminar.siguiente;
                nodoAEliminar.siguiente = null; // Desconectamos el nodo eliminado de la lista para facilitar la recolección de basura
                longitud--;
            }
        }
    }

    // Imprimir todos los libros de la lista
    public void imprimirLista() {
        int n = contar();
        if (n == 0) {
            System.out.println("La lista está vacía.");
            return;
        }
        for (int i = 0; i < n; i++) {
            Libro l = obtener(i);
            if (l != null) {
                System.out.printf("[%d] Titulo: %s | Autor: %s | ISBN: %s%n", i, l.getTitulo(), l.getAutor(), l.getIsbn());
            }
        }
    }
}
