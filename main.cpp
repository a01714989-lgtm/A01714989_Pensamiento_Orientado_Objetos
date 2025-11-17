#include <iostream>
using namespace std;

//A01714989 Leonardo Márquez Caballero
// Clase 1: Productos
class Productos {
    private:
        string nombre;
        double precio;
        int unidades;
        string categoria;

    public:
        // Constructor
        Productos(string nm, double precio_1, int unidades_1, string categoria_1) {
            nombre = nm;
            precio = precio_1;
            unidades = unidades_1;
            categoria = categoria_1;
        }

        // Método 1: Aumento de precio (20%)
        void aumento_precio() {
            precio = precio + (precio * 0.2);
            cout << "Precio aumentado en 20%. Nuevo precio: $" << precio << endl;
        }

        // Método 2: Restar unidades
        void resta_unidades() {
            if (unidades > 0) {
                unidades--;
                cout << "Unidad vendida. Quedan " << unidades << " unidades" << endl;
            } else {
                cout << "No hay unidades disponibles" << endl;
            }
        }

        // Método 3: Mostrar información
        void mostrar_info() {
            cout << "\n--- Información del Producto ---" << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: $" << precio << endl;
            cout << "Unidades disponibles: " << unidades << endl;
            cout << "Categoría: " << categoria << endl;
        }

        // Método para obtener unidades
        int obtener_unidades() {
            return unidades;
        }

        // Método para obtener precio
        double obtener_precio() {
            return precio;
        }
};

// Clase 2: Empleados
class Empleados {
    private:
        string nombre;
        int id;
        double salario;
        int ventas_realizadas;

    public:
        // Constructor
        Empleados(string nm, int id_1, double salario_1) {
            nombre = nm;
            id = id_1;
            salario = salario_1;
            ventas_realizadas = 0;
        }

        // Método 1: Registrar venta
        void registrar_venta() {
            ventas_realizadas++;
            cout << nombre << " ha registrado una venta. Total de ventas: " << ventas_realizadas << endl;
        }

        // Método 2: Calcular comisión (5% del salario por cada 10 ventas)
        void calcular_comision() {
            double comision = (ventas_realizadas / 10) * (salario * 0.05);
            cout << "Comisión ganada: $" << comision << endl;
            cout << "Salario total: $" << (salario + comision) << endl;
        }

        // Método 3: Mostrar información
        void mostrar_info() {
            cout << "\n--- Información del Empleado ---" << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "ID: " << id << endl;
            cout << "Salario base: $" << salario << endl;
            cout << "Ventas realizadas: " << ventas_realizadas << endl;
        }
};

// Clase 3: Clientes
class Clientes {
    private:
        string nombre;
        string telefono;
        double puntos_fidelidad;
        int compras_totales;

    public:
        // Constructor
        Clientes(string nm, string telefono_1) {
            nombre = nm;
            telefono = telefono_1;
            puntos_fidelidad = 0.0;
            compras_totales = 0;
        }

        // Método 1: Registrar compra y acumular puntos (10% del valor de compra)
        void registrar_compra(double valor_compra) {
            compras_totales++;
            puntos_fidelidad += valor_compra * 0.1;
            cout << nombre << " ha realizado una compra de $" << valor_compra << endl;
            cout << "Puntos ganados: " << (valor_compra * 0.1) << endl;
            cout << "Puntos totales: " << puntos_fidelidad << endl;
        }

        // Método 2: Canjear puntos (cada 100 puntos = $10 de descuento)
        void canjear_puntos() {
            if (puntos_fidelidad >= 100) {
                double descuento = (int)(puntos_fidelidad / 100) * 10;
                puntos_fidelidad -= ((int)(puntos_fidelidad / 100)) * 100;
                cout << "¡Descuento canjeado! $" << descuento << endl;
                cout << "Puntos restantes: " << puntos_fidelidad << endl;
            } else {
                cout << "No tienes suficientes puntos para canjear (necesitas 100)" << endl;
            }
        }

        // Método 3: Mostrar información
        void mostrar_info() {
            cout << "\n--- Información del Cliente ---" << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Teléfono: " << telefono << endl;
            cout << "Puntos de fidelidad: " << puntos_fidelidad << endl;
            cout << "Compras totales: " << compras_totales << endl;
        }
};

int main() {
    cout << "========================================" << endl;
    cout << "  SISTEMA DE GESTIÓN TIENDA DEPARTAMENTAL" << endl;
    cout << "========================================" << endl;

    // Crear objeto de la clase Productos
    Productos producto_1("Laptop Dell", 15000.0, 10, "Electrónica");
    producto_1.mostrar_info();
    producto_1.aumento_precio();
    producto_1.resta_unidades();
    producto_1.resta_unidades();
    producto_1.mostrar_info();

    // Crear objeto de la clase Empleados
    Empleados empleado_1("Carlos Rodríguez", 1001, 8000.0);
    empleado_1.mostrar_info();
    
    for (int i = 0; i < 11; i++) {
        empleado_1.registrar_venta();
    }
    
    empleado_1.calcular_comision();
    empleado_1.mostrar_info();

    // Crear objeto de la clase Clientes
    Clientes cliente_1("María González", "555-1234");
    cliente_1.mostrar_info();
    cliente_1.registrar_compra(500.0);
    cliente_1.registrar_compra(750.0);
    cliente_1.registrar_compra(300.0);
    cliente_1.canjear_puntos();
    cliente_1.mostrar_info();

    return 0;
}