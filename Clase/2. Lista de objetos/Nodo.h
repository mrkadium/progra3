#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <stdlib.h>
#include "Trabajador.h"

class Nodo{
    private:
        Trabajador *Valor; ///declaracion, no instancia
        Nodo *Siguiente;
    public:
        Nodo(Trabajador *t, Nodo *Sig=NULL){
            this->Valor = t;
            this->Siguiente = Sig;
        }
        friend class Lista;
};

#endif // NODO_H_INCLUDED
