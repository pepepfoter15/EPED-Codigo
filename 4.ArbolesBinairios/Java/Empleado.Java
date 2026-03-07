//
// Empleado.java
// EstructurasJava
//
// Creado por José Carlos Rodríguez Cañas
// Copyright (c) 2026 José Carlos Rodríguez Cañas
//

package bst;
import java.util.Objects;

public class Empleado implemenyts Comparable<Empleado> {
    private int id;
    private String nombre;
    private String puesto;
    private String despacho;

    // Constructor para inicializar los atributos del empleado
    public Empleado(int id, String nombre, String puesto, String despacho) {
        this.id = id;
        this.nombre = nombre;
        this.puesto = puesto;
        this.despacho = despacho;
    }

    // Métodos getter para acceder a los atributos del empleado
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getPuesto() {
        return puesto;
    }

    public void setPuesto(String puesto) {
        this.puesto = puesto;
    }

    public String getDespacho() {
        return despacho;
    }
    
    public void setDespacho(String despacho) {
        this.despacho = despacho;
    }

    @Override
    public string toString() {
        return "Empleado{" +
                "id=" + id +
                ", nombre='" + nombre + '\'' +
                ", puesto='" + puesto + '\'' +
                ", despacho='" + despacho + '\'' +
                '}';
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, nombre, puesto, despacho);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Empleado empleado = (Empleado) obj;
        return id == empleado.id &&
                Objects.equals(nombre, empleado.nombre) &&
                Objects.equals(puesto, empleado.puesto) &&
                Objects.equals(despacho, empleado.despacho);   
    }

    // Implementación del método compareTo para comparar empleados por su ID
    @Override
    public int compareTo(Empleado empleado) {
        if (this.id < empleado.id) {
            return -1; // El empleado actual es menor que el empleado pasado como argumento
        } else if (this.id > empleado.id) {
            return 1; // El empleado actual es mayor que el empleado pasado como argumento
        } else {
            return 0; // Ambos empleados son iguales en términos de ID
        }
    }
}