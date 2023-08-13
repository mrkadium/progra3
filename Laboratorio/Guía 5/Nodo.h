#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Producto.h"

class Nodo{
    private:
        Producto *Valor;    //Punteros, trabajaras con elementos que reservarán memoria
        Nodo *Siguiente;
        Nodo *Anterior;
    public:
        Nodo(Producto *v, Nodo *sig=NULL, Nodo *ant=NULL){
            this->Valor = v;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        Producto *getValor(){
            return this->Valor;
        }
    friend class Lista;
}; typedef Nodo *p;

#endif // NODO_H_INCLUDED
