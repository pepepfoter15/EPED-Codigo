//
// Trabajo.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

// Clase Trabajo que representa un trabajo a imprimir
public class Trabajo {
    // Atributos del trabajo
    private String titulo;
    private String autor;
    private boolean impreso;

    // Constructor de la clase
    public Trabajo(String titulo, String autor) {
        this.titulo = titulo;
        this.autor = autor;
        this.impreso = false;
    }
    
    // Métodos getters y setters
    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public boolean isImpreso() {
        return impreso;
    }

    public void setImpreso(boolean impreso) {
        this.impreso = impreso;
    }

    // Método para imprimir el trabajo
    @Override
    public String toString() {
        return "Trabajo{" +
                "nombre='" + nombre + '\'' +
                ", duracion=" + duracion +
                '}';
    }
}