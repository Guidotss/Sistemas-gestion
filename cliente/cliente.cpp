#include <iostream>
#include <fstream>
#include "cliente.h"
using namespace std;

int Cliente::contadorClientes = 0;

Cliente::Cliente(){
    contadorClientes++;
    this-> saldo = 0; 
    this->nro_cliente = contadorClientes;
    this->anioC = 0;
    this->nombre = "";
    this->apellido = "";
    this->tipoC = "";
    this->estado = "";
}

Cliente::Cliente(int _anioC, string _nombre, string _apellido, string _tipoC, float _saldo){
    contadorClientes++;
    this->nro_cliente = contadorClientes;
    this->saldo = _saldo;
    this->anioC = _anioC;
    this->nombre = _nombre;
    this->apellido = _apellido;
    this->tipoC = _tipoC;
    this->estado = "activo";
}

string Cliente::Get_nombre(){
    return this->nombre;
}

string Cliente::Get_apellido(){
    return this->apellido;
}

string Cliente::Get_tipoC(){
    return this->tipoC;
}

string Cliente::Get_estado(){
    return this->estado;
}

int Cliente::Get_anioC(){
    return this->anioC;
}
void Cliente::Set_nro_cliente(int nC){
    nro_cliente = nC;
}
int Cliente::Get_nro_cliente(){
    return nro_cliente;
}

string Cliente::cambiarEstado() {
    //this->estado == "activo" ? this->estado = "inactivo" : "activo";
    if(this->estado == "activo"){
        this->estado = "inactivo"; 
    }
    return this->estado;
}



vector<Cliente> Cliente::AgregarCliente(Cliente *nuevo_cliente) {

    ofstream archivoClientes("clientes.txt", ios::app); 
    if(!archivoClientes){ 
        cerr<<"Error al abrir archivo"<<endl;
        return this->clientesVector; 
    } 
    archivoClientes<<"----------cliente "<<nuevo_cliente->Get_nro_cliente()<<"------------"<<endl;
    archivoClientes<<"nombre: "<<nuevo_cliente->Get_nombre()<<endl;
    archivoClientes<<"apellido: "<<nuevo_cliente->Get_apellido()<<endl;
    archivoClientes<<"anio: "<<nuevo_cliente->Get_anioC()<<endl;
    archivoClientes<<"tipo: "<<nuevo_cliente->Get_tipoC()<<endl;
    archivoClientes<<"estado: "<<nuevo_cliente->Get_estado()<<endl;
    cout<<endl<<endl;

    this->clientesVector.push_back(*nuevo_cliente);
    archivoClientes.close();

    return clientesVector;
}





void Cliente:: Set_saldo(float _saldo){
    saldo = _saldo;
}

float Cliente::Get_saldo(){
    return saldo;
}

bool Cliente::comprobarTipo(int anioC, string tipoC) {
    if(((2023 - anioC) < 3) && (tipoC == "black")) { 
        cout<<"El cliente no puede ser black"<<endl;
        return false;
    }
    return true;
}


int Cliente::limiteTarjeta(string tipoC) {  
    if(tipoC == "black") { 
        return 250000;
    }else if(tipoC == "oro"){
        return 50000;
    }

    return 0; 
}
