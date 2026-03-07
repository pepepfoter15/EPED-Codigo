//
// BST.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

package bst;

public class BST implements IBST<Empleado> {

    // Atributos del nodo del árbol binario de búsqueda    
    private Empleado valor;
    private BST izquierdo, derecho;
    protected BST padre;

    // Funcion para saber si el nodo es una hoja (no tiene hijos) o si el nodo está vacío
    @Override
    public boolean esHoja() {
        return valor != null && izquierdo == null && derecho == null;
    }

    @Override
    public boolean esVacio() {
        return valor == null;
    }

    // Función para insertar un nuevo empleado en el árbol binario de búsqueda
    @Override
    private void insertarimpl(Empleado empleado, BST padre) {
        if (valor == null){
            this.valor = empleado;
            this.padre = padre;
        } else {
            // Comparar el ID del empleado a insertar con el ID del empleado en el nodo actual para determinar si se debe insertar en el subárbol izquierdo o derecho
            if (empleado.compareTo(valor) < 0) {
                if (izquierdo == null) {
                    izquierdo = new BST();
                }
                izquierdo.insertar(empleado, this);
            } else if (empleado.compareTo(valor) > 0) {
                if (derecho == null) {
                    derecho = new BST();
                }
                derecho.insertar(empleado);
            // Si el empleado a insertar tiene el mismo ID que el empleado en el nodo actual, no se permiten duplicados, por lo que no se inserta el nuevo empleado
            } else {
                // El empleado ya existe en el árbol, no se permiten duplicados o se puede hacer tambien con un throw 
                //System.out.println("El empleado con ID " + empleado.getId() + " ya existe en el árbol.");
                throw new RuntimeException("El empleado con ID " + empleado.getId() + " ya existe en el árbol.");
            }
        }
    }

    // Método para insertar un nuevo empleado en el árbol binario de búsqueda de manera simplificada
    @Override
    public void insertar(Empleado empleado) {
        insertarimpl(empleado, null);
    }

    // Función para ver si existe un empleado con un ID específico en el árbol binario de búsqueda
    @Override
    public boolean existe(int id) {
        if (valor != null) {
            if (id == valor.getId()) {
                return true;
            } else if (id < valor.getId() && izquierdo != null) {
                return izquierdo.existe(id);
            } else if (id > valor.getId() && derecho != null) {
                return derecho.existe(id);
            } else {
                return false;
            }
        } else {
            return false
        }
    }

    // Función para obtener un empleado con un ID específico del árbol binario de búsqueda
    @Override
    public Empleado obtener(int id) {
        if (valor != null) {
            if (id == valor.getId()) {
                return valor;
            } else if (id < valor.getId()) {
                return izquierdo.obtener(id);
            } else if (id > valor.getId()) {
                return derecho.obtener(id);
            }
        } else {
            return null;
        }
    }

    // Métodos para recorrer el árbol en preorden, inorden y postorden
    @Override
    public void preorden() {
        if (valor != null) {
            System.out.println(valor);
            if (izquierdo != null) {
                izquierdo.preorden();
            }
            if (derecho != null) {
                derecho.preorden();
            }
        }
    }

    @Override
    public void inorden() {
        if (valor != null) {
            if (izquierdo != null) {
                izquierdo.inorden();
            }
            System.out.println(valor);
            if (derecho != null) {
                derecho.inorden();
            }
        }
    }   

    @Override
    public void postorden() {
        if (valor != null) {
            if (izquierdo != null) {
                izquierdo.postorden();
            }
            if (derecho != null) {
                derecho.postorden();
            }
            System.out.println(valor);
        }
    }   

    // Función para encontrar el nodo con el valor mínimo en el subárbol derecho (sucesor) para eliminar un nodo con dos hijos
    private BST minimo() {
        if (izquierdo != null && izquierdo.esVacio() == false) {
            return izquierdo.minimo();
        } else {
            return this;
        }
    }

    // Función para eliminar un empleado con un ID específico del árbol binario de búsqueda
    private void eliminarimpl(int id) {
        if (izquierdo != null && derecho != null) {
            // Eliminar con 2 hijos 
            BST sucesor = derecho.minimo();
            this.valor = sucesor.valor;
            derecho.eliminar(sucesor.valor.getId());
        } else if (izquierdo != null || derecho != null) {
            // Eliminar con 1 hijo
            BST hijo = (izquierdo != null) ? izquierdo : derecho;
            this.valor = hijo.valor;
            this.izquierdo = hijo.izquierdo;
            this.derecho = hijo.derecho;
        } else {
            // Eliminar con 0 hijos
            if (padre != null) {
                if (padre.izquierdo == this) {
                    padre.izquierdo = null;
                } else if (padre.derecho == this) {
                    padre.derecho = null;
                }
            } else {
                valor = null; // Si el nodo a eliminar es la raíz y no tiene hijos, simplemente se establece su valor a null
            }
        }
    }

    // Método para eliminar un empleado con un ID específico del árbol binario de búsqueda
    @Override
    public void eliminar(int id) {
        if (valor != null) {
            if (id == valor.getId()) {
                eliminarimpl(id);
            } else if (id < valor.getId() && izquierdo != null) {
                izquierdo.eliminar(id);
            } else if (id > valor.getId() && derecho != null) {
                derecho.eliminar(id);
            }
        }
    }

}