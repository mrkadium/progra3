#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Persona.h"

class Nodo{
    private:
        Persona *Valor;
        Nodo *Siguiente;
    public:
        Nodo(Persona *p, Nodo *sig=NULL){
            this->Valor = p;
            this->Siguiente = sig;
        }
        friend class Lista;

};typedef Nodo *pn;

#endif // NODO_H_INCLUDED
