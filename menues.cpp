#include <iostream>
#include <stdexcept>
#include "cliente/cliente.h"
#include "transaccion/transaccion.h"

using namespace std;

vector<Cliente> crearCliente(vector<Cliente> clientes)
{
    int anio;
    float saldo;
    string nombre, apellido, tipo;

    do
    {
        try
        {
            cout << "Anio: ";
            cin >> anio;

            if (anio < 1907 || anio > 2023)
            {
                throw runtime_error("Ingrese un anio valido.");
            }
            break;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();            // Limpia el flujo de entrada
            cin.ignore(1000, '\n'); // Descarta el contenido restante en el búfer
        }
    } while (true);

    do
    {
        try
        {
            bool isNumber = false;
            cout << "Nombre: ";
            cin >> nombre;

            for (char c : nombre)
            {
                if (isdigit(c))
                {
                    isNumber = true;
                    break;
                }
            }

            if (isNumber)
            {
                throw runtime_error("Ingrese un nombre valido.");
            }

            break;
        }
        catch (exception &e)
        {
            cout << e.what() << std::endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (true);

    do
    {
        try
        {
            bool isNumber = false;
            cout << "Apellido: ";
            cin >> apellido;

            for (char c : apellido)
            {
                if (isdigit(c))
                {
                    isNumber = true;
                    break;
                }
            }

            if (isNumber)
            {
                throw runtime_error("Ingrese un apellido valido.");
            }

            break;
        }
        catch (exception &e)
        {
            cout << e.what() << std::endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (true);

    do
    {
        try
        {
            bool isNumber = false;
            cout << "Tipo (oro, black, plata): ";
            cin >> tipo;

            if (tipo != "oro" && tipo != "black" && tipo != "plata")
            {
                throw runtime_error("Ingrese un tipo valido (plata, oro, black).");
            }

            for (char c : tipo)
            {
                if (isdigit(c))
                {
                    isNumber = true;
                    break;
                }
            }

            if (isNumber)
            {
                throw runtime_error("Ingrese un tipo valido (plata, oro, black).");
            }

            break;
        }
        catch (exception &e)
        {
            cout << e.what() << std::endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (true);

    do
    {

        try
        {
            cout << "Saldo: ";
            cin >> saldo;
            float number = stof(to_string(saldo));
            if (saldo < 0 || number == 0)
            {
                throw runtime_error("Ingrese un saldo valido.");
            }
            break;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (true);

    Cliente cliente(anio, nombre, apellido, tipo, saldo);
    clientes.push_back(cliente);
    return clientes;
}

vector<Transaccion> crearTransaccion(vector<Transaccion> transacciones)
{
    int dia, mes, anio;
    float cantidad;
    char tipo;

    do
    {
        try
        {
            cout << "Dia: ";
            cin >> dia;

            if (dia < 1 || dia > 30)
            {
                throw runtime_error("Ingrese un dia valido.");
            }
            break;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (true);

    do
    {
        try
        {
            cout << "Mes: ";
            cin >> mes;

            if (mes < 1 || mes > 12)
            {
                throw runtime_error("Ingrese un mes valido.");
            }
            break;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (true);

    do
    {
        try
        {
            cout << "Anio: ";
            cin >> anio;

            if (anio < 1907 || anio > 2023)
            {
                throw runtime_error("Ingrese un anio valido.");
            }
            break;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (true);

    do
    {

        try
        {
            cout << "Cantidad: ";
            cin >> cantidad;
            float number = stof(to_string(cantidad));
            if (cantidad < 0 || number == 0)
            {
                throw runtime_error("Ingrese un saldo valido.");
            }
            break;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (true);

    do
    {
        try
        {
            bool isNumber = false;
            cout << "Tipo (D, E): ";
            cin >> tipo;

            if (tipo != 'D' && tipo != 'E')
            {
                throw runtime_error("Ingrese un tipo valido (D o E).");
            }

            if (isdigit(tipo))
            {
                isNumber = true;
                break;
            }

            if (isNumber)
            {
                throw runtime_error("Ingrese un tipo valido (D o E).");
            }

            break;
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (true);

    Transaccion transaccion(dia, mes, anio, cantidad, tipo);
    transacciones.push_back(transaccion);
    return transacciones;
}
