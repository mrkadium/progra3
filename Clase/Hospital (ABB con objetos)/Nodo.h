#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Ingresado.h"

class Nodo{
    private:
        Ingresado *dato;
        Nodo *izquierdo;
        Nodo *derecho;
    public:
        Nodo(Ingresado *i, Nodo *izq=NULL,Nodo *der=NULL){
            this->dato=i;
            this->izquierdo=izq;
            this->derecho=der;
        }
    friend class ABB;
};typedef Nodo *pnodo;

#endif // NODO_H_INCLUDED
