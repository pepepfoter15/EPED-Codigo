//
// Ejemplo.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

public class Ejemplo {
    public static void main(String[] args) {
        URL google = new URL("https://www.google.com");
        URL github = new URL("https://www.github.com");

        // Crear una pila y realizar operaciones
        Pila pila = new Pila();
        imprimirEstado(pila);
        pila.apilar(google);
        imprimirEstado(pila);
        pila.apilar(github);
        imprimirEstado(pila);

        // Ver que la pila no está vacía y mostrar el elemento superior
        while (!pila.estaVacia()) {
            pila.desapilar();
            imprimirEstado(pila);
        }
    }
    
    // Método auxiliar para imprimir el estado de la pila
    private static void imprimirEstado(Pila pila) {
        if (!pila.estaVacia()) {
            System.out.println("La pila tiene " + pila.longitud() + " elemento(s).");
            System.out.println("Cima de la pila: " + pila.obtenerCima().getUrl());
        } else {
            System.out.println("La pila está vacía. No hay cima.");
        }

        System.out.println();
    }

}