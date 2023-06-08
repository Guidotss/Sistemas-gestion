#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include"../transaccion/transaccion.h"

using namespace std;

class Cliente {   
    protected:    
        static int contadorClientes;
        int nro_cliente, anioC;
        float saldo;
        string nombre, apellido, tipoC, estado;
        
        vector<Transaccion>transaccion;
        vector<Cliente>clientesVector;
    public:
        Cliente();
        Cliente(int _anioC, string _nombre, string _apellido, string _tipoC, float _saldo);
        
        string Get_nombre(); 
        string Get_apellido();
        string Get_tipoC();
        string Get_estado();
        string cambiarEstado();
        int Get_anioC();
        int Get_nro_cliente();
        int limiteTarjeta(string tipoC);
        float Get_saldo(); 
        void Get_Clientes(); 
        void Set_nro_cliente(int);
        void Set_saldo(float);
        bool comprobarTipo(int anioC, string tipoC);
        vector<Cliente> BuscarClientePorId(int nro_cliente);
        vector<Cliente> AgregarCliente(Cliente *nuevo_cliente);
        vector<Cliente> EliminarCliente(int nro_cliente); 
};
