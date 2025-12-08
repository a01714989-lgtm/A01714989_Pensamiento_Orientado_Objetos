#include <iostream>
#include <vector>
using namespace std;

/*
 * Programa: Sistema de Gestión de Tienda Departamental
 * Descripción: Sistema que gestiona productos, empleados y clientes
 *              demostrando herencia, composición y agregación.
 * Autor: A01714989 Leonardo Márquez Caballero
 * Fecha: Diciembre 2025
 */

// ============================================
// HERENCIA: Clase base Persona
// ============================================
class Persona {
    protected:
        string nombre;
        
    public:
        /*
         * Constructor de Persona
         * Parámetro nm: nombre de la persona
         */
        Persona(string nm) : nombre(nm) {}
        
        /*
         * Muestra la información básica de la persona
         */
        virtual void mostrarInfo() {
            cout << "Nombre: " << nombre << endl;
        }
        
        /*
         * Obtiene el nombre de la persona
         * Retorna: string con el nombre
         */
        string obtenerNombre() {
            return nombre;
        }
};

// ============================================
// Clase Productos
// ============================================
class Productos {
    private:
        string nombre;
        double precio;
        int unidades;
        string categoria;

    public:
        /*
         * Constructor de Productos
         * Parámetro nm: nombre del producto
         * Parámetro precioInicial: precio inicial del producto
         * Parámetro unidadesIniciales: cantidad inicial de unidades
         * Parámetro categoriaInicial: categoría del producto
         */
        Productos(string nm, double precioInicial, int unidadesIniciales, 
            string categoriaInicial) {
            nombre = nm;
            precio = precioInicial;
            unidades = unidadesIniciales;
            categoria = categoriaInicial;
        }

        /*
         * Aumenta el precio del producto en un 20%
         */
        void aumentoPrecio() {
            precio = precio + (precio * 0.2);
            cout << "Precio aumentado en 20%. Nuevo precio: $" << precio 
            << endl;
        }

        /*
         * Resta una unidad del inventario cuando se vende
         */
        void restaUnidades() {
            if (unidades > 0) {
                unidades--;
                cout << "Unidad vendida. Quedan " << unidades 
                << " unidades" << endl;
            } else {
                cout << "No hay unidades disponibles" << endl;
            }
        }

        /*
         * Muestra toda la información del producto
         */
        void mostrarInfo() {
            cout << "\n--- Información del Producto ---" << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: $" << precio << endl;
            cout << "Unidades disponibles: " << unidades << endl;
            cout << "Categoría: " << categoria << endl;
        }

        /*
         * Obtiene las unidades disponibles
         * Retorna: número de unidades disponibles
         */
        int obtenerUnidades() {
            return unidades;
        }

        /*
         * Obtiene el precio del producto
         * Retorna: precio del producto
         */
        double obtenerPrecio() {
            return precio;
        }
        
        /*
         * Obtiene el nombre del producto
         * Retorna: nombre del producto
         */
        string obtenerNombre() {
            return nombre;
        }
};

// ============================================
// COMPOSICIÓN: Clase Historial de Ventas
// ============================================
class HistorialVentas {
    private:
        vector<string> ventas;
        
    public:
        /*
         * Agrega una venta al historial
         * Parámetro producto: nombre del producto vendido
         */
        void agregarVenta(string producto) {
            ventas.push_back(producto);
        }
        
        /*
         * Muestra todas las ventas registradas
         */
        void mostrarHistorial() {
            cout << "Historial de ventas:" << endl;
            for (int i = 0; i < ventas.size(); i++) {
                cout << "  - " << ventas[i] << endl;
            }
        }
        
        /*
         * Obtiene el total de ventas realizadas
         * Retorna: número total de ventas
         */
        int obtenerTotalVentas() {
            return ventas.size();
        }
};

// ============================================
// HERENCIA: Empleados hereda de Persona
// COMPOSICIÓN: Empleados contiene HistorialVentas
// ============================================
class Empleados : public Persona {
    private:
        int id;
        double salario;
        int ventasRealizadas;
        HistorialVentas historial;

    public:
        /*
         * Constructor de Empleados
         * Parámetro nm: nombre del empleado
         * Parámetro idEmpleado: identificador del empleado
         * Parámetro salarioBase: salario base del empleado
         */
        Empleados(string nm, int idEmpleado, double salarioBase) 
            : Persona(nm), id(idEmpleado), salario(salarioBase), 
            ventasRealizadas(0) {}

        /*
         * Registra una venta realizada por el empleado
         */
        void registrarVenta() {
            ventasRealizadas++;
            cout << nombre << " ha registrado una venta. Total de ventas: " 
            << ventasRealizadas << endl;
        }
        
        /*
         * Registra una venta de un producto específico
         * Parámetro producto: nombre del producto vendido
         */
        void registrarVentaProducto(string producto) {
            ventasRealizadas++;
            historial.agregarVenta(producto);
            cout << nombre << " ha vendido: " << producto << endl;
        }

        /*
         * Calcula la comisión del empleado basada en ventas
         */
        void calcularComision() {
            double comision = (ventasRealizadas / 10) * (salario * 0.05);
            cout << "Comisión ganada: $" << comision << endl;
            cout << "Salario total: $" << (salario + comision) << endl;
        }

        /*
         * Muestra toda la información del empleado
         */
        void mostrarInfo() override {
            cout << "\n--- Información del Empleado ---" << endl;
            Persona::mostrarInfo();
            cout << "ID: " << id << endl;
            cout << "Salario base: $" << salario << endl;
            cout << "Ventas realizadas: " << ventasRealizadas << endl;
            historial.mostrarHistorial();
        }
};

// ============================================
// HERENCIA: Clientes hereda de Persona
// AGREGACIÓN: Clientes tiene referencia a Empleados
// ============================================
class Clientes : public Persona {
    private:
        string telefono;
        double puntosFidelidad;
        int comprasTotales;
        Empleados* empleadoAsignado;

    public:
        /*
         * Constructor de Clientes
         * Parámetro nm: nombre del cliente
         * Parámetro telefonoContacto: teléfono del cliente
         */
        Clientes(string nm, string telefonoContacto) 
            : Persona(nm), telefono(telefonoContacto), puntosFidelidad(0.0), 
            comprasTotales(0), empleadoAsignado(nullptr) {}

        /*
         * Asigna un empleado para atender al cliente
         * Parámetro emp: puntero al empleado asignado
         */
        void asignarEmpleado(Empleados* emp) {
            empleadoAsignado = emp;
            cout << "Empleado " << emp->obtenerNombre() 
            << " asignado a cliente " << nombre << endl;
        }

        /*
         * Registra una compra realizada por el cliente
         * Parámetro valorCompra: valor total de la compra
         */
        void registrarCompra(double valorCompra) {
            comprasTotales++;
            puntosFidelidad += valorCompra * 0.1;
            cout << nombre << " ha realizado una compra de $" 
            << valorCompra << endl;
            cout << "Puntos ganados: " << (valorCompra * 0.1) << endl;
            cout << "Puntos totales: " << puntosFidelidad << endl;
            
            if (empleadoAsignado != nullptr) {
                empleadoAsignado->registrarVenta();
            }
        }
        
        /*
         * Registra una compra de un producto específico
         * Parámetro valorCompra: valor de la compra
         * Parámetro producto: nombre del producto comprado
         */
        void registrarCompraConProducto(double valorCompra, string producto) {
            comprasTotales++;
            puntosFidelidad += valorCompra * 0.1;
            cout << nombre << " ha comprado: " << producto << " ($" 
            << valorCompra << ")" << endl;
            
            if (empleadoAsignado != nullptr) {
                empleadoAsignado->registrarVentaProducto(producto);
            }
        }

        /*
         * Canjea puntos de fidelidad por descuentos
         */
        void canjearPuntos() {
            if (puntosFidelidad >= 100.0) {
                double descuento = (int)(puntosFidelidad / 100.0) * 10.0;
                puntosFidelidad -= ((int)(puntosFidelidad / 100.0)) * 100.0;
                cout << "¡Descuento canjeado! $" << descuento << endl;
                cout << "Puntos restantes: " << puntosFidelidad << endl;
            } else {
                cout << "No tienes suficientes puntos para canjear (100)" 
                << endl;
            }
        }

        /*
         * Muestra toda la información del cliente
         */
        void mostrarInfo() override {
            cout << "\n--- Información del Cliente ---" << endl;
            Persona::mostrarInfo();
            cout << "Teléfono: " << telefono << endl;
            cout << "Puntos de fidelidad: " << puntosFidelidad << endl;
            cout << "Compras totales: " << comprasTotales << endl;
            if (empleadoAsignado != nullptr) {
                cout << "Atendido por: " 
                << empleadoAsignado->obtenerNombre() << endl;
            }
        }
};

int main() {
    cout << "========================================" << endl;
    cout << "  SISTEMA DE GESTIÓN TIENDA DEPARTAMENTAL" << endl;
    cout << "  (Con Herencia, Composición y Agregación)" << endl;
    cout << "========================================" << endl;

    Productos producto1("Laptop Dell", 15000.0, 10, "Electrónica");
    producto1.mostrarInfo();
    producto1.aumentoPrecio();
    producto1.restaUnidades();
    producto1.restaUnidades();
    producto1.mostrarInfo();

    cout << "\n========================================" << endl;
    cout << "  DEMOSTRACIÓN DE HERENCIA Y COMPOSICIÓN" << endl;
    cout << "========================================" << endl;

    Empleados empleado1("Carlos Rodríguez", 1001, 8000.0);
    empleado1.mostrarInfo();
    
    empleado1.registrarVentaProducto("Laptop Dell");
    empleado1.registrarVentaProducto("Mouse Logitech");
    empleado1.registrarVentaProducto("Teclado Mecánico");
    
    for (int i = 0; i < 8; i++) {
        empleado1.registrarVenta();
    }
    
    empleado1.calcularComision();
    empleado1.mostrarInfo();

    cout << "\n========================================" << endl;
    cout << "  DEMOSTRACIÓN DE AGREGACIÓN" << endl;
    cout << "========================================" << endl;

    Clientes cliente1("María González", "555-1234");
    cliente1.mostrarInfo();
    
    cliente1.asignarEmpleado(&empleado1);
    
    cliente1.registrarCompraConProducto(500.0, "Tablet Samsung");
    cliente1.registrarCompra(750.0);
    cliente1.registrarCompra(300.0);
    cliente1.canjearPuntos();
    cliente1.mostrarInfo();
    
    cout << "\n--- Estado final del empleado ---" << endl;
    empleado1.mostrarInfo();

    return 0;
}