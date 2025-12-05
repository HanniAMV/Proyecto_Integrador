#Proyecto Integrador - Sistema Básico de Gestión de Productos

## Descripción del Proyecto

Este proyecto es un Sistema Básico de Gestión de Productos desarrollado en C++ para una pequeña tienda que necesita gestionar su inventario. Fue desarrollado como parte de la experiencia educativa (EE) Metodología de la Programación.

El sistema permite al dueño de la tienda realizar las siguientes funciones:
* Registrar productos.
* Mostrar la lista de productos.
* Ordenar productos por precio, nombre o cantidad utilizando métodos de ordenamiento básicos.
* Buscar un producto por nombre.
* Actualizar información de un producto seleccionado (precio o cantidad).
* Generar un pequeño reporte final.

El programa debe compilar sin errores y ejecutarse en consola, mostrando mensajes claros para el usuario.

## Métodos y Estructuras Utilizadas
El sistema gestiona los productos utilizando un arreglo unidimensional con un máximo de 100 productos.

### Estructura Producto
Cada producto se define usando la siguiente estructura Struct Producto:

struct Producto {
    string nombre; // Campo obligatorio
    float precio; // Campo obligatorio
    int cantidad; // Campo obligatorio
};

### Funciones Implementadas
El comportamiento del programa está modularizado en funciones mínimas, incluyendo:

Funciones utilizadas

registrarProductos () Captura de datos para varios productos.
mostrarProductos () Imprime en formato tabular los productos registrados.
ordenarProductosBurbuja () Ordenamiento usando método burbuja.
ordenarProductosSeleccion () Ordenamiento usando método por selección.
ordenarProductosInsercion () Ordenamiento usando método por inserción.
buscarProducto () Búsqueda por nombre (lineal).
actualizarProducto () Permite modificar el precio o cantidad de un producto.

### Estructuras de Control Requeridas
El código utiliza de manera explícita:
* Estructuras selectivas: if, switch.
* Estructuras repetitivas: while, for, do-while.
* Operadores aritméticos, lógicos y relacionales.

## Flujo de Trabajo

1. El programa inicia y muestra el menú principal.
2. El usuario selecciona una operación.
3. Según la opción, se llama a la función correspondiente.
4. El menú se muestra nuevamente hasta que el usuario selecciona la opción Salir.

## Datos del Estudiante
Nombre: Hannia Monserrat Valencia Medina
Matrícula: S24016696
Experiencia Educativa: Metodología de la Programación
Fecha: 03/12/2025
