//
// Ejemplo.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

package bst;

public class Ejemplo {

    public static void main(String[] args) {
        Empleado empleado1 = new Empleado(20,"Pepito Perez", "Ventas", "A-252");
        Empleado empleado2 = new Empleado(44,"Ana López", "Recursos Humanos", "B-363");
        Empleado empleado3 = new Empleado(18,"Carlos García", "Ventas", "C-474"); 
        Empleado empleado4 = new Empleado(33,"Juan Martínez", "Contabilidad", "D-585");
        Empleado empleado5 = new Empleado(64,"María González", "Marketing", "E-696");
        Empleado empleado6 = new Empleado(55,"Carlos Rodríguez", "Informática", "F-707"); 

        // Crear un nuevo árbol binario de búsqueda e insertar los empleados en el árbol bst
        BST bst = new BST();
        Array.asList(empleado1, empleado2, empleado3, empleado4, empleado5, empleado6).forEach(bst::insertar);

        // Recorrer el árbol en preorden, inorden y postorden para mostrar la información de los empleados
        System.out.println("Recorrido en preorden:");
        bst.preorden();
        System.out.println("Recorrido en inorden:");
        bst.inorden();
        System.out.println("Recorrido en postorden:");
        bst.postorden();
    }

    /**
     * Función para localizar un empleado por su ID en el árbol binario de búsqueda y mostrar su información
     * @param bst el árbol binario de búsqueda
     * @param id el ID del empleado a localizar
     * 
    private static void localizar(BST bst, int id) {
        if (bst.existe(id)) {
            Empleado empleado = bst.obtener(id);
            System.out.println("Empleado encontrado: " + empleado);
        } else {
            System.out.println("Empleado con ID " + id + " no encontrado en el árbol.");
        }
    }
    */
}