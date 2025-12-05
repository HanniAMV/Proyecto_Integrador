#include <iostream>

#include <string>

using namespace std;



//primero defini mi constante max que puede almacenar hasta 100 productos

const int MAX_PRODUCTOS = 100;



//defino mi estructura producto

struct Producto {

    string nombre;

    double precio;

    int cantidad;

};



//defino el arreglo productos para guardar los datos

Producto productos[MAX_PRODUCTOS];

//numproductos me sirve a mi para saber la cantidad de productos guardados

int numProductos = 0;



//defino funciones que usare

void registrarProductos();

void mostrarProductos();

void ordenarProductosBurbuja();

void ordenarProductosSeleccion();

void ordenarProductosInsercion();

void buscarProducto();

void actualizarProducto();

void generarReporteFinal();



//Esta es la funcion principal del programa

//declaramos un bucle do-while hasta que el cliente use la opcion 7

int main() {

    int opcion;



    do {

        cout << "\n------ Sistema Basico De Gestion De Productos -------\n";

        cout << "1. Registrar productos\n";

        cout << "2. Mostrar productos\n";

        cout << "3. Ordenar productos\n";

        cout << "4. Buscar producto\n";

        cout << "5. Actualizar producto\n";

        cout << "6. Generar reporte final\n";

        cout << "7. Salir\n";

        cout << "Seleccione una opcion: ";

        cin >> opcion;

//Uso un switch para ejecutar la funcion que el cliente seleccione

        switch(opcion) {

            case 1: registrarProductos(); break; //llamo funcion para ingresar datos

            case 2: mostrarProductos(); break; //llamo funcion para ver lista

            case 3: {

                int tipo;

                cout << "\nSeleccione un metodo de ordenamiento:\n";

                cout << "1. Burbuja\n2. Seleccion\n3. Insercion\nOpción: ";

                cin >> tipo;



                if (tipo == 1) ordenarProductosBurbuja();

                else if (tipo == 2) ordenarProductosSeleccion();

                else if (tipo == 3) ordenarProductosInsercion();

                break;

            }

            case 4: buscarProducto(); break;

            case 5: actualizarProducto(); break;

            case 6: generarReporteFinal(); break;

            case 7: cout << "\nSaliendo...\n"; break;

        }



    } while (opcion != 7);



//se sigue en el bucle si la opcion no es 7



    return 0;

}





// Seccion donde voy a generar los productos que el usuario introduzca



void registrarProductos() {

    int cantidad;

    cout << "\n¿Cuantos productos desea registrar? :";

    cin >> cantidad;

//bucle for que repetira la cantidad de veces que el cliente indique

    for (int i = 0; i < cantidad; i++) {



        cout << "\nProducto " << (numProductos + 1) << ":\n";



        cout << "Nombre: ";

        cin >> productos[numProductos].nombre;



        cout << "Precio: ";

        cin >> productos[numProductos].precio;

        while (productos[numProductos].precio <= 0) {

            cout << "El precio debe ser mayor que 0, intente de nuevo porfavor: ";

            cin >> productos[numProductos].precio;

        }



        cout << "Cantidad: ";

        cin >> productos[numProductos].cantidad;

        while (productos[numProductos].cantidad < 0) {

            cout << "La cantidad no puede ser negativa, intente de nuevo porfavor: ";

            cin >> productos[numProductos].cantidad;

        }

//incremento el contador de los productos ya que se almacenan y se actualiza

        numProductos++;

    }



    cout << "\nProductos registrados exitosamente!\n";

}



//funcion para mostrar los productos que se registraron

void mostrarProductos() {

    //la condicion es verificar si se tiene productos

    if (numProductos == 0) {

        cout << "\nNo hay productos registrados\n";

        return;

    }



    cout << "\n------ LISTA DE PRODUCTOS ---------\n";

    cout << "Nombre        Precio        Cantidad\n";

    cout << "-------------------------------------\n";



    for (int i = 0; i < numProductos; i++) {

        cout << productos[i].nombre << "        "

             << productos[i].precio << "        "

             << productos[i].cantidad << endl;

    }

}



//Empiezo con mis metodos de ordenamiento para los productos

//de menor a mayor

void ordenarProductosBurbuja() {

    for (int i = 0; i < numProductos - 1; i++) {

        for (int j = 0; j < numProductos - i - 1; j++) {

            if (productos[j].precio > productos[j+1].precio) {

                Producto temp = productos[j];

                productos[j] = productos[j+1];

                productos[j+1] = temp;

            }

        }

    }



    cout << "\nProductos ordenados por precio (ascendente)\n";

}



void ordenarProductosSeleccion() {

    for (int i = 0; i < numProductos - 1; i++) {

        int min = i;



        for (int j = i + 1; j < numProductos; j++) {

            if (productos[j].precio < productos[min].precio)

                min = j;

        }



        if (min != i) {

            Producto temp = productos[i];

            productos[i] = productos[min];

            productos[min] = temp;

        }

    }



    cout << "\nProductos ordenados por precio (ascendente)\n";

}



void ordenarProductosInsercion() {

    for (int i = 1; i < numProductos; i++) {

        Producto actual = productos[i];

        int j = i - 1;



        while (j >= 0 && productos[j].precio > actual.precio) {

            productos[j + 1] = productos[j];

            j--;

        }



        productos[j + 1] = actual;

    }



    cout << "\nProductos ordenados por precio (ascendente)\n";

}



//mi funcion para hacer una busqueda lineal por nombre

void buscarProducto() {

    if (numProductos == 0) {

        cout << "\nNo hay productos registrados \n";

        return;

    }



    cout << "\nIngrese el nombre a buscar: ";

    string buscado; //variable para almacenar el nombre asignado

    cin >> buscado;



    bool encontrado = false; //Se usa una bandera para saber si encontre el producto



//recorro todos los productos desde el indice 0 hasta numpProductos -1

    for (int i = 0; i < numProductos; i++) {

        //comparo el nombre que busco con el nombre de producto actual

        if (productos[i].nombre == buscado) {

            //la condicion es: si el nombre coincide, muestro los detalles de producto

            cout << "\nProducto encontrado:\n";

            cout << "Nombre: " << productos[i].nombre << endl;

            cout << "Precio: " << productos[i].precio << endl;

            cout << "Cantidad: " << productos[i].cantidad << endl;

            encontrado = true; //se marca como true entonces

        }

    }



    if (!encontrado) //si es false, no se encontro el producto

        cout << "\nProducto no encontrado\n";

}



//funcion para actualizar precio o cantidad del producto

void actualizarProducto() {

    if (numProductos == 0) {

        cout << "\nNo hay productos registrados\n";

        return;

    }



    int indice;

    cout << "\nIngrese el indice del producto a actualizar: ";

    cin >> indice;



//valido que este en el rango

    if (indice < 1 || indice > numProductos) {

        cout << "\nError: Indice fuera de rango. Intente de nuevo.\n";

        return;

    }



    indice--;

    //ajusto el indice



    cout << "¿Que es lo que desea actualizar?\n";

    cout << "1. Precio\n";

    cout << "2. Cantidad\n";

    cout << "Opción: ";



    int opcion;

    cin >> opcion;



    //uso un if-else para saber que campo modificar del producto

    if (opcion == 1) {

        cout << "Nuevo precio: ";

        cin >> productos[indice].precio;

    } else {

        cout << "Nueva cantidad: ";

        cin >> productos[indice].cantidad;

    }



    cout << "\nProducto actualizado!\n";

}



//funcion para generar el reporte final de mi inventario

void generarReporteFinal() {

    cout << "\n------ REPORTE FINAL -------\n";



    cout << "Total de productos registrados: " << numProductos << endl;



    if (numProductos == 0) {

        cout << "Valor total en inventario: 0\n";

        cout << "Producto con mayor cantidad: N/A\n";

        return;

    }



    double total = 0; //inicializo el acomulador del valor total del inventario

    int mayor = 0;



    //recorro productos para calcular el valor total

    //y encontrar el de mayor cantidad

    for (int i = 0; i < numProductos; i++) {

        total += productos[i].precio * productos[i].cantidad;

//compruebo si la cantidad del producto actual es mayor a 'mayor'

        if (productos[i].cantidad > productos[mayor].cantidad)

            mayor = i; //si cumple con la condicion se actualiza

    }

//muestro los resultados de mi calculo

    cout << "Valor total en inventario: $ " << total << endl;

    cout << "Producto con mayor cantidad: "

         << productos[mayor].nombre

         << " (" << productos[mayor].cantidad << ")\n";

}