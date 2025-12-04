#include <iostream>
#include <vector>
using namespace std;

//A01714989 Leonardo Márquez Caballero

// ============================================
// HERENCIA: Clase base Persona
// ============================================
class Persona {
    protected:
        string nombre;
        
    public:
        Persona(string nm) : nombre(nm) {}
        
        virtual void mostrar_info() {
            cout << "Nombre: " << nombre << endl;
        }
        
        string obtener_nombre() {
            return nombre;
        }
};

// ============================================
// Clase Productos (sin cambios en variables)
// ============================================
class Productos {
    private:
        string nombre;
        double precio;
        int unidades;
        string categoria;

    public:
        Productos(string nm, double precio_1, int unidades_1, string categoria_1) {
            nombre = nm;
            precio = precio_1;
            unidades = unidades_1;
            categoria = categoria_1;
        }

        void aumento_precio() {
            precio = precio + (precio * 0.2);
            cout << "Precio aumentado en 20%. Nuevo precio: $" << precio << endl;
        }

        void resta_unidades() {
            if (unidades > 0) {
                unidades--;
                cout << "Unidad vendida. Quedan " << unidades << " unidades" << endl;
            } else {
                cout << "No hay unidades disponibles" << endl;
            }
        }

        void mostrar_info() {
            cout << "\n--- Información del Producto ---" << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: $" << precio << endl;
            cout << "Unidades disponibles: " << unidades << endl;
            cout << "Categoría: " << categoria << endl;
        }

        int obtener_unidades() {
            return unidades;
        }

        double obtener_precio() {
            return precio;
        }
        
        string obtener_nombre() {
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
        void agregar_venta(string producto) {
            ventas.push_back(producto);
        }
        
        void mostrar_historial() {
            cout << "Historial de ventas:" << endl;
            for (int i = 0; i < ventas.size(); i++) {
                cout << "  - " << ventas[i] << endl;
            }
        }
        
        int obtener_total_ventas() {
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
        int ventas_realizadas;
        HistorialVentas historial; // COMPOSICIÓN

    public:
        Empleados(string nm, int id_1, double salario_1) 
            : Persona(nm), id(id_1), salario(salario_1), ventas_realizadas(0) {}

        void registrar_venta() {
            ventas_realizadas++;
            cout << nombre << " ha registrado una venta. Total de ventas: " << ventas_realizadas << endl;
        }
        
        void registrar_venta_producto(string producto) {
            ventas_realizadas++;
            historial.agregar_venta(producto);
            cout << nombre << " ha vendido: " << producto << endl;
        }

        void calcular_comision() {
            double comision = (ventas_realizadas / 10) * (salario * 0.05);
            cout << "Comisión ganada: $" << comision << endl;
            cout << "Salario total: $" << (salario + comision) << endl;
        }

        void mostrar_info() override {
            cout << "\n--- Información del Empleado ---" << endl;
            Persona::mostrar_info();
            cout << "ID: " << id << endl;
            cout << "Salario base: $" << salario << endl;
            cout << "Ventas realizadas: " << ventas_realizadas << endl;
            historial.mostrar_historial();
        }
};

// ============================================
// HERENCIA: Clientes hereda de Persona
// AGREGACIÓN: Clientes tiene referencia a Empleados
// ============================================
class Clientes : public Persona {
    private:
        string telefono;
        double puntos_fidelidad;
        int compras_totales;
        Empleados* empleado_asignado; // AGREGACIÓN (puntero)

    public:
        Clientes(string nm, string telefono_1) 
            : Persona(nm), telefono(telefono_1), puntos_fidelidad(0.0), 
              compras_totales(0), empleado_asignado(nullptr) {}

        // AGREGACIÓN: Asignar empleado que atiende al cliente
        void asignar_empleado(Empleados* emp) {
            empleado_asignado = emp;
            cout << "Empleado " << emp->obtener_nombre() << " asignado a cliente " << nombre << endl;
        }

        void registrar_compra(double valor_compra) {
            compras_totales++;
            puntos_fidelidad += valor_compra * 0.1;
            cout << nombre << " ha realizado una compra de $" << valor_compra << endl;
            cout << "Puntos ganados: " << (valor_compra * 0.1) << endl;
            cout << "Puntos totales: " << puntos_fidelidad << endl;
            
            // Si hay empleado asignado, registrar su venta
            if (empleado_asignado != nullptr) {
                empleado_asignado->registrar_venta();
            }
        }
        
        void registrar_compra_con_producto(double valor_compra, string producto) {
            compras_totales++;
            puntos_fidelidad += valor_compra * 0.1;
            cout << nombre << " ha comprado: " << producto << " ($" << valor_compra << ")" << endl;
            
            if (empleado_asignado != nullptr) {
                empleado_asignado->registrar_venta_producto(producto);
            }
        }

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

        void mostrar_info() override {
            cout << "\n--- Información del Cliente ---" << endl;
            Persona::mostrar_info();
            cout << "Teléfono: " << telefono << endl;
            cout << "Puntos de fidelidad: " << puntos_fidelidad << endl;
            cout << "Compras totales: " << compras_totales << endl;
            if (empleado_asignado != nullptr) {
                cout << "Atendido por: " << empleado_asignado->obtener_nombre() << endl;
            }
        }
};

int main() {
    cout << "========================================" << endl;
    cout << "  SISTEMA DE GESTIÓN TIENDA DEPARTAMENTAL" << endl;
    cout << "  (Con Herencia, Composición y Agregación)" << endl;
    cout << "========================================" << endl;

    // Crear producto
    Productos producto_1("Laptop Dell", 15000.0, 10, "Electrónica");
    producto_1.mostrar_info();
    producto_1.aumento_precio();
    producto_1.resta_unidades();
    producto_1.resta_unidades();
    producto_1.mostrar_info();

    cout << "\n========================================" << endl;
    cout << "  DEMOSTRACIÓN DE HERENCIA Y COMPOSICIÓN" << endl;
    cout << "========================================" << endl;

    // Crear empleado (hereda de Persona y compone HistorialVentas)
    Empleados empleado_1("Carlos Rodríguez", 1001, 8000.0);
    empleado_1.mostrar_info();
    
    // Registrar ventas con historial
    empleado_1.registrar_venta_producto("Laptop Dell");
    empleado_1.registrar_venta_producto("Mouse Logitech");
    empleado_1.registrar_venta_producto("Teclado Mecánico");
    
    for (int i = 0; i < 8; i++) {
        empleado_1.registrar_venta();
    }
    
    empleado_1.calcular_comision();
    empleado_1.mostrar_info();

    cout << "\n========================================" << endl;
    cout << "  DEMOSTRACIÓN DE AGREGACIÓN" << endl;
    cout << "========================================" << endl;

    // Crear cliente (hereda de Persona)
    Clientes cliente_1("María González", "555-1234");
    cliente_1.mostrar_info();
    
    // AGREGACIÓN: Asignar empleado al cliente
    cliente_1.asignar_empleado(&empleado_1);
    
    // Registrar compras (esto también registra ventas del empleado)
    cliente_1.registrar_compra_con_producto(500.0, "Tablet Samsung");
    cliente_1.registrar_compra(750.0);
    cliente_1.registrar_compra(300.0);
    cliente_1.canjear_puntos();
    cliente_1.mostrar_info();
    
    cout << "\n--- Estado final del empleado ---" << endl;
    empleado_1.mostrar_info();

    return 0;
}