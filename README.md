# A01714989_Pensamiento_Orientado_Objetos

El objetivo del poryecto es desarrollar un sistema de gestión básico para una tienda departamental que permita organizar y contabilizar las operaciones principales del negocio mediante programación orientada a objetos en C++. El sistema administra tres aspectos fundamentales: el inventario de productos (control de precios y stock), el desempeño de empleados (registro de ventas y cálculo de comisiones), y la fidelización de clientes (programa de puntos y recompensas).

# Funciones

Clase Productos:

- aumento_precio(), Incrementa el precio del producto en un 20%
- resta_unidades(), Disminuye en 1 la cantidad disponible en inventario
- mostrar_info(), Despliega todos los datos del producto (nombre, precio, unidades, categoría)

Clase Empleados:

- registrar_venta(), Contabiliza una venta realizada por el empleado
- calcular_comision(), Calcula y muestra la comisión ganada (5% del salario por cada 10 ventas)
- mostrar_info(), Despliega los datos del empleado (nombre, ID, salario, ventas)

Clase Clientes:

- registrar_compra(), Registra una compra y acumula puntos de fidelidad (10% del valor)
- canjear_puntos(), Convierte puntos acumulados en descuentos (100 puntos = $10)
- mostrar_info(), Despliega los datos del cliente (nombre, teléfono, puntos, compras totales)

# Usos

Este programa C++ se ejecuta desde la terminal tras compilarlo con g++. Al iniciar, automáticamente demuestra sus funcionalidades creando objetos de ejemplo (producto, empleado, cliente) y llamando a sus métodos. Para usarlo en un escenario real, es necesario modificar la función main() para crear múltiples objetos según las necesidades de la tienda, lo que permite gestionar el inventario de productos, hacer seguimiento de ventas de empleados y administrar los puntos de fidelidad de los clientes.

# Ejecución

Compilar todos los archivos juntos usando un compilador de C++

- Windows "g++ main.cpp -o main.exe" 

- macOS "g++ main.cpp -o main.o"

Ejecutar el programa resultante:

- Windows "./main.exe" 

- MacOS "./main.o"

- Linux: - ./main

En mac:
- main.exe
