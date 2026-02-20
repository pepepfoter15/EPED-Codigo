//
// Main.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

import java.util.Scanner;

public class Main {
    // Programa principal para probar la funcionalidad de la lista enlazada con libros
    public static void main(String[] args) {
        Lista lista = new Lista();
        Scanner scanner = new Scanner(System.in);
        int opcion = -1;

        while (true) {
            System.out.println("\n--- MENU ---");
            System.out.println("1) Insertar al principio");
            System.out.println("2) Insertar al final");
            System.out.println("3) Insertar despues de posicion (0-based)");
            System.out.println("4) Eliminar principio");
            System.out.println("5) Eliminar ultimo");
            System.out.println("6) Eliminar elemento en posicion (0-based)");
            System.out.println("7) Recorrer / Mostrar lista");
            System.out.println("0) Salir");
            System.out.print("Elija opcion (0-7): ");

            try {
                opcion = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Opción no válida. Ingrese un número.");
                continue;
            }

            if (opcion == 0) break;

            switch (opcion) {
                case 1: {
                    Libro lib = new Libro();
                    Libro.leerLibro(lib, scanner);
                    lista.insertarPrincipio(lib);
                    System.out.printf("Insertado al principio. Total: %d%n", lista.contar());
                    break;
                }
                case 2: {
                    Libro lib = new Libro();
                    Libro.leerLibro(lib, scanner);
                    lista.insertarFinal(lib);
                    System.out.printf("Insertado al final. Total: %d%n", lista.contar());
                    break;
                }
                case 3: {
                    System.out.print("Posicion after (0-based): ");
                    try {
                        int pos = Integer.parseInt(scanner.nextLine());
                        if (pos < 0) {
                            System.out.println("Posicion invalida");
                            break;
                        }
                        Libro lib = new Libro();
                        Libro.leerLibro(lib, scanner);
                        lista.insertarDespues(pos, lib);
                        System.out.printf("Insertado despues de %d. Total: %d%n", pos, lista.contar());
                    } catch (NumberFormatException e) {
                        System.out.println("Posicion invalida");
                    }
                    break;
                }
                case 4:
                    lista.eliminarPrincipio();
                    System.out.printf("Eliminado principio. Total: %d%n", lista.contar());
                    break;
                case 5:
                    lista.eliminarUltimo();
                    System.out.printf("Eliminado ultimo. Total: %d%n", lista.contar());
                    break;
                case 6: {
                    System.out.print("Posicion a eliminar (0-based): ");
                    try {
                        int pos = Integer.parseInt(scanner.nextLine());
                        if (pos < 0 || pos >= lista.contar()) {
                            System.out.println("Posicion invalida");
                            break;
                        }
                        lista.eliminarElemento(pos);
                        System.out.printf("Eliminado posicion %d. Total: %d%n", pos, lista.contar());
                    } catch (NumberFormatException e) {
                        System.out.println("Posicion invalida");
                    }
                    break;
                }
                case 7:
                    lista.imprimirLista();
                    break;
                default:
                    System.out.println("Opcion no valida.");
            }
        }

        // Liberar recursos (Scanner se cierra automáticamente, pero es buena práctica hacerlo explícitamente)
        scanner.close();

        System.out.printf("Saliendo. Total registros finales: %d%n", lista.contar());
    }
}
