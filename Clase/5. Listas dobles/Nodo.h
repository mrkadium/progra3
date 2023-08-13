#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo{
    private:
        int valor;
        Nodo *Siguiente;
        Nodo *Anterior;
    public:
        Nodo(int v, Nodo *sig = NULL, Nodo *ant = NULL){
            this->valor = v;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        void setValor(int v){
            this->valor = v;
        }
        int getValor(){
            return this->valor;
        }
friend class Lista;
};

#endif // NODO_H_INCLUDED
