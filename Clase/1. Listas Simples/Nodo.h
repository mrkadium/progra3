#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
class Nodo{
private:
    int Valor;
    Nodo *Siguiente; //para tener referencia del siguiente nodo
public:
    Nodo(int v, Nodo *sig = NULL){
        this->Valor = v;
        this->Siguiente = sig; //se inicializa con NULL
    }
friend class Lista;
};
#endif // NODO_H_INCLUDED
