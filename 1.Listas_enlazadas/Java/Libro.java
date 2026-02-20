//
// Libro.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

import java.util.Scanner;

// Clase para representar un libro con título, autor e ISBN 
public class Libro {

    private String titulo;
    private String autor;
    private String isbn;

    // Constructor por defecto
    public Libro() {
        this.titulo = "";
        this.autor = "";
        this.isbn = "";
    }

    // Constructor con parámetros
    public Libro(String titulo, String autor, String isbn) {
        this.titulo = titulo;
        this.autor = autor;
        this.isbn = isbn;
    }

    // Métodos Getter y Setter
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

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    // Función auxiliar para leer un libro desde stdin
    public static void leerLibro(Libro lib, Scanner scanner) {
        System.out.print("Ingrese el titulo del libro: ");
        lib.setTitulo(scanner.nextLine());

        System.out.print("Ingrese el autor del libro: ");
        lib.setAutor(scanner.nextLine());

        System.out.print("Ingrese el ISBN del libro: ");
        lib.setIsbn(scanner.nextLine());
    }
}