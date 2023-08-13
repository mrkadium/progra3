#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#define TAM 10
#include "Fecha.h"
#include "Abonos.h"
#include "Cliente.h"

class Cuenta{
private:
    int numeroCuenta;
    Cliente *cliente;
    Abonos ListaAbonos[TAM];
    float saldo;
public:
    Cuenta(int nc){
        this->numeroCuenta = nc;
    }
    Cliente *getCliente(){
        return this->cliente;
    }
    void setCliente(Cliente *cli){
        this->cliente = cli;
    }
    void setAbonos(Abonos la){
        this->ListaAbonos = la;
    }
    Abonos getAbonos(){
        return this->ListaAbonos;
    }
    float ConsultarSaldo(){
        return this->saldo;
    }
};

#endif // CUENTA_H_INCLUDED
