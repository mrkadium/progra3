#ifndef NODOPRODUCTO_H_INCLUDED
#define NODOPRODUCTO_H_INCLUDED
#include "Producto.h"

class NodoProducto{
    private:
        Producto Valor;
        NodoProducto *Siguiente;
        NodoProducto *Anterior;
    public:
        NodoProducto(Producto p, NodoProducto *sig=NULL, NodoProducto *ant=NULL){
            this->Valor = p;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        friend class ListaProducto;

};

#endif // NODOPRODUCTO_H_INCLUDED
