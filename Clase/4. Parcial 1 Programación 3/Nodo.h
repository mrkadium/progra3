#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Cliente.h"

class Nodo{
    private:
        Cliente *Valor;
        Nodo *Siguiente;
    public:
        Nodo(Cliente *cli, Nodo *sig=NULL){
            this->Valor = cli;
            this->Siguiente = sig;
        }
        friend class Lista;

};typedef Nodo *pn;


#endif // NODO_H_INCLUDED
