#include "cliente/cliente.h"
#include "transaccion/transaccion.h"
#include "menues.cpp"
#include <memory.h>
#include <iostream>
#include <stdexcept>

#define CYAN "\033[36m"

using namespace std;

int main()
{
    int opcion = 0;
    int counter = 0;
    vector<Cliente> clientes;
    vector<Transaccion> transacciones;

    while (opcion != 8)
    {

        cout << CYAN << "Sistema de Gestion:" << endl;
        cout << "1. Crear cliente." << endl;
        cout << "2. Eliminar cliente."<<endl;
        cout << "3. Realizar transaccion." << endl;
        cout << "4. Buscar un cliente por su codigo." << endl;
        cout << "5. Mostrar todos los clientes." << endl;
        cout << "6. Mostrar las transacciones realizadas por cierto cliente." << endl;
        cout << "7. Mostrar las transacciones en cierto periodo." << endl;
        cout << "8. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            clientes = crearCliente(clientes);
            clientes[counter].AgregarCliente(&clientes[counter]);
            break;
        case 2:
            cout<<"Ingrese el numero del cliente que quiere eliminar: "; 
            int code; 
            cin>>code;
            EliminarCliente(code, clientes); 
            break;

        case 3:

            cout<<"Ingese el numero del cliente que hara la transaccion: "; 
            int nro_cliente; 
            cin>>nro_cliente; 
            transacciones = crearTransaccion(transacciones);

            transacciones[counter].nuevaTransaccion(&clientes[nro_cliente-1], &transacciones[counter - transacciones.size() * (counter != transacciones.size()) - counter==transacciones.size()]);
            cout<<(counter - transacciones.size() * (counter != transacciones.size()) - counter==transacciones.size())<<endl; 

            break;
        case 4:
        {
            int code;
            cout << "Ingrese un codigo para buscar: ";
            cin >> code;

            BuscarClientePorId(code, clientes);
            break;
        }
        case 5: 
            mostrarClientes();
            cout<<endl<<endl;
            break;
        case 6:
            int codigoCliente;
            cout << "Ingrese un codigo de cliente para ver las transacciones: ";
            cin >> codigoCliente;

            transaccionPorCliente(codigoCliente, transacciones);
            break;
        case 7: 
            int opcion; 
            cout<<"1. Mostrar total"<<endl; 
            cout<<"2. Buscar por anio"<<endl; 
            cout<<"3. Buscar por periodo de 6 meses"<<endl; 
            cout<<"Opcion: "; 
            cin>>opcion; 

            if(opcion == 1) {
                MostrarTotal(transacciones); 
            }else if(opcion == 2){
                cout<<"Ingrese un anio: ";
                int anio; 
                cin>>anio; 
                MostrarPorAnio(anio, transacciones); 
            }

            break;
            
        default:
            break;
        }

        counter++;
    }

    return 0;
}