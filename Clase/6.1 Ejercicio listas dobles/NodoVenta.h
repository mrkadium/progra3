#ifndef NODOVENTA_H_INCLUDED
#define NODOVENTA_H_INCLUDED
#include "Venta.h"

class NodoVenta{
    private:
        Venta Valor;
        NodoVenta *Siguiente;
        NodoVenta *Anterior;
    public:
        NodoVenta(Venta v, NodoVenta *sig=NULL, NodoVenta *ant=NULL){
            this->Valor = v;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        friend class ListaVenta;
};

#endif // NODOVENTA_H_INCLUDED
