#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Objeto.h"

class Nodo{
    private:
        Objeto *Valor;
        Nodo *Siguiente;
        Nodo *Anterior;
    public:
        Nodo(Objeto *v, Nodo *sig=NULL, Nodo *ant=NULL){
            this->Valor = v;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        friend class Lista;
};

#endif // NODO_H_INCLUDED
