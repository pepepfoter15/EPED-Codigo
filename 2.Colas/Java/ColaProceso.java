//
// ColaProceso.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

public interface ColaProceso {
    // Método para agregar un trabajo a la cola
    void encolar(Trabajo trabajo);

    // Método para eliminar un trabajo de la cola
    void eliminar();

    // Método para obtener el trabajo al frente de la cola sin eliminarlo
    Trabajo obtener();
}