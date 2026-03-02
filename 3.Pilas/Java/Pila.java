//
// Pila.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

public interface Pila {
    // Métodos de la pila
    void apilar(URL url);
    void desapilar();
    URL obtenerCima();
    boolean estaVacia();
    int longitud();
}
