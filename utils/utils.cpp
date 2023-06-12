#include"./utils.h"

using namespace std; 

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


void MostrarPorPeriodo(int mes, int anio, vector<Transaccion> transaccionVector)
{
    vector<Transaccion> transaccionPeriodo;
    int mesInicial, anioInicial;
    mesInicial = mes - 6;
    bool flag=false;
    anioInicial = anio;

    if (mesInicial<1){
        anioInicial--;
        mesInicial += 12;
        flag=true;
    }

    for (auto &transaccion : transaccionVector)
    {
        int anioTransaccion = transaccion.Get_anioT();
        int mesTransaccion = transaccion.Get_mesT();
        if (flag==true){

            if((anioTransaccion == anio) && (mesTransaccion <= mes)){
                cout<<"--------------------------"<<endl;
                cout << transaccion.Get_nro_transaccion() << endl;
                cout << transaccion.Get_diaT() << endl;
                cout << transaccion.Get_mesT() << endl;
                cout << transaccion.Get_anioT() << endl;
                cout << transaccion.Get_cantidad() << endl;
                cout << transaccion.Get_tipoT() << endl;
                cout<<"--------------------------"<<endl<<endl;
            }else if((anioTransaccion == anioInicial) && (mesTransaccion >= mesInicial)){
                cout<<"--------------------------"<<endl;
                cout << transaccion.Get_nro_transaccion() << endl;
                cout << transaccion.Get_diaT() << endl;
                cout << transaccion.Get_mesT() << endl;
                cout << transaccion.Get_anioT() << endl;
                cout << transaccion.Get_cantidad() << endl;
                cout << transaccion.Get_tipoT() << endl;
                cout<<"--------------------------"<<endl<<endl;                
            }
        }else{
            if(anioTransaccion == anio && mesInicial <= mesTransaccion && mesTransaccion <= mes){
                cout<<"--------------------------"<<endl;
                cout << transaccion.Get_nro_transaccion() << endl;
                cout << transaccion.Get_diaT() << endl;
                cout << transaccion.Get_mesT() << endl;
                cout << transaccion.Get_anioT() << endl;
                cout << transaccion.Get_cantidad() << endl;
                cout << transaccion.Get_tipoT() << endl;
                cout<<"--------------------------"<<endl<<endl;                
            }
        }
    }
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

