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
    
    while (opcion != 7)
    {
        
        cout << CYAN << "Sistema de Gestion:" << endl;
        cout << "1. Crear cliente." << endl;
        cout << "2. Realizar transaccion." << endl;
        cout << "3. Buscar un cliente por su codigo." << endl;
        cout << "4. Mostrar todos los clientes." << endl;
        cout << "5. Mostrar las transacciones realizadas por cierto cliente." << endl;
        cout << "6. Mostrar las transacciones en cierto periodo." << endl;
        cout << "7. Salir" << endl;

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
            transacciones = crearTransaccion(transacciones); 
            transacciones[counter].nuevaTransaccion(&clientes[counter], &transacciones[counter]);

            break;
        case 3 : {
            int code;
            cout<<"Ingrese un codigo para buscar: ";
            cin>>code;
            Cliente cliente;
            cliente.BuscarClientePorId(code);

            break;
        }
        default:
            break;
        }

        counter++;
        cout<<counter<<endl;
    }

    return 0;
}