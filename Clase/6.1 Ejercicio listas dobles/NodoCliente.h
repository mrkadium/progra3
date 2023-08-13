#ifndef NODOCLIENTE_H_INCLUDED
#define NODOCLIENTE_H_INCLUDED
#include "Cliente.h"

class NodoCliente{
    private:
        Cliente Valor;
        NodoCliente *Siguiente;
        NodoCliente *Anterior;
    public:
        NodoCliente(Cliente c, NodoCliente *sig=NULL, NodoCliente *ant=NULL){
            this->Valor = c;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        friend class ListaCliente;
};

#endif // NODOCLIENTE_H_INCLUDED
