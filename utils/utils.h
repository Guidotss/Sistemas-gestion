#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "../cliente/cliente.h"

using namespace std;


void BuscarClientePorId(int nro_cliente, vector<Cliente> clientes);
void mostrarClientes();
void transaccionPorCliente(int clienteBuscado, vector<Transaccion> transacciones); 
void MostrarTotal(vector<Transaccion> transaccionVector); 
void MostrarPorAnio(int anio, vector<Transaccion> transaccionVector); 
vector<Cliente> EliminarCliente(int nro_cliente, vector<Cliente> clientes);
vector<Transaccion> MostrarPorPeriodo(int mes, int anio, vector<Transaccion> transaccionVector); 