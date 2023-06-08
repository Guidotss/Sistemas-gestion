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

void BuscarClientePorId(int nro_cliente, vector<Cliente> clientes)
{
    for (auto &it : clientes)
    {
        if (it.Get_nro_cliente() == nro_cliente)
        {
            cout << it.Get_nombre() << endl;
            cout << it.Get_apellido() << endl;
            cout << it.Get_tipoC() << endl;
            cout << it.Get_estado() << endl;
            cout << it.Get_anioC() << endl;
        }
    }
}

vector<Cliente> EliminarCliente(int nro_cliente, vector<Cliente> clientes)
{

    ofstream archivoClientes("clientes.txt");
    for (auto &it : clientes)
    {

        archivoClientes << "----------cliente " << it.Get_nro_cliente() << "------------" << endl;
        archivoClientes << "nombre " << it.Get_nombre() << endl;
        archivoClientes << "apellido " << it.Get_apellido() << endl;
        archivoClientes << "tipo " << it.Get_tipoC() << endl;
        if (nro_cliente == it.Get_nro_cliente())
        {
            it.cambiarEstado();
        }
        archivoClientes << "estado " << it.Get_estado() << endl;
        cout << endl
             << endl;
    }

    if (!archivoClientes)
    {
        cerr << "Error al abrir archivo" << endl;
    }

    return clientes;
}

void mostrarClientes()
{

    ifstream archivoClientes("clientes.txt");
    if (!archivoClientes)
    {
        cerr << "Error al abrir archivo" << endl;
    }

    archivoClientes.seekg(0, ios::end);
    if (archivoClientes.tellg() == 0)
    {
        cout << "No hay clientes registrados" << endl;
        return;
    }
    else
    {
        archivoClientes.seekg(0, ios::beg);
        string linea;
        while (getline(archivoClientes, linea))
        {
            cout << linea << endl;
        }
        archivoClientes.close();
    }
}

void transaccionPorCliente(int clienteBuscado, vector<Transaccion> transacciones)
{

    for (auto &it : transacciones)
    {

        if (it.Get_nro_cliente() == clienteBuscado)
        {
            cout << "Nro transaccion " << it.Get_nro_transaccion() << endl;
            cout << "Cantidad: " << it.Get_cantidad() << endl;
            cout << "Tipo: " << it.Get_tipoT() << endl;
            cout << "Dia: " << it.Get_diaT() << endl;
            cout << "Mes: " << it.Get_mesT() << endl;
            cout << "Anio: " << it.Get_anioT() << endl;
            cout << endl
                 << endl;
        }
    }
}

vector<Transaccion> MostrarPorPeriodo(int mes, int anio, vector<Transaccion> transaccionVector)
{
    vector<Transaccion> transaccionPeriodo;
    int mesInicial, anioInicial;
    mesInicial = mes - 6;
    anioInicial = anio;

    if ((mesInicial) < 1)
    {
        anioInicial--;
        mesInicial += 12;
    }

    for (auto &transaccion : transaccionVector)
    {
        int anioTransaccion = transaccion.Get_anioT();
        int mesTransaccion = transaccion.Get_mesT();
        if ((anioTransaccion > anioInicial && anioInicial <= anio) ||
            (anioTransaccion == anioInicial && mesTransaccion >= mesInicial) ||
            (anioTransaccion == anio && mesInicial <= mes))
        {
            cout << transaccion.Get_nro_transaccion() << endl;
            cout << transaccion.Get_diaT() << endl;
            cout << transaccion.Get_mesT() << endl;
            cout << transaccion.Get_anioT() << endl;
            cout << transaccion.Get_cantidad() << endl;
            cout << transaccion.Get_tipoT() << endl;
        }
    }
    return transaccionPeriodo;
}

void MostrarTotal(vector<Transaccion> transaccionVector)
{
    for (auto &transaccion : transaccionVector)
    {
        cout << "----------------------" << endl;
        cout << transaccion.Get_nro_transaccion() << endl;
        cout << transaccion.Get_diaT() << endl;
        cout << transaccion.Get_mesT() << endl;
        cout << transaccion.Get_anioT() << endl;
        cout << transaccion.Get_cantidad() << endl;
        cout << transaccion.Get_tipoT() << endl
             << endl;
        cout << "----------------------" << endl;
    }
}
void MostrarPorAnio(int anio, vector<Transaccion> transaccionVector)
{
    vector<Transaccion> transaccionAnio;
    for (auto &transaccion : transaccionVector)
    {
        if (anio == transaccion.Get_anioT())
        {

            cout << "----------------------" << endl;
            cout << transaccion.Get_nro_transaccion() << endl;
            cout << transaccion.Get_diaT() << endl;
            cout << transaccion.Get_mesT() << endl;
            cout << transaccion.Get_anioT() << endl;
            cout << transaccion.Get_cantidad() << endl;
            cout << transaccion.Get_tipoT() << endl
                 << endl;
            cout << "----------------------" << endl;
        }
    }
}
