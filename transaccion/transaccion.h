#pragma once
#include <iostream>
using namespace std;


class Cliente;
class Transaccion {

    protected:
        int nro_transaccion, diaT, mesT, anioT, nroCliente;
        float cantidad;
        char tipoT;
        static vector<Transaccion> transaccionVector;
        static int contadorTransacciones;
        Cliente *cliente;
    public:
        Transaccion();
        Transaccion(int _dia, int _mes, int _anioT, float _cantidad, char _tipoT);  
        void Mostrar(int periodo);
        float Get_cantidad();
        int Get_diaT(); 
        int Get_mesT();
        int Get_anioT();
        int Get_nro_transaccion();
        char Get_tipoT();
        int Get_nro_cliente();
        void setCliente(Cliente*);



        vector<Transaccion> transaccionPorCliente(int nro_cliente);
        vector<Transaccion> nuevaTransaccion(Cliente *cliente,Transaccion *nueva_transaccion);
        vector<Transaccion> MostrarPorPeriodo(int mes, int anio);
        vector<Transaccion> MostrarPorAnio(int anio);
        vector<Transaccion> MostrarTotal();
        
};



