#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo{
    private:
        int dato;
        Nodo *izquierdo;
        Nodo *derecho;
    public:
        Nodo(int v, Nodo *izq=NULL,Nodo *der=NULL){
            this->dato=v;
            this->izquierdo=izq;
            this->derecho=der;
        }
    //friend class ArbolBinario;
    friend class ArbolABB;
};typedef Nodo *pnodo;

#endif // NODO_H_INCLUDED
