#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

class Nodo{
    private:
        tipo *valor;
        Nodo *Siguiente;
        Nodo *Anterior;
    public:
        Nodo(topi *v, Nodo *sig = NULL, Nodo *ant = NULL){
            this->valor = v;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        topi *getValor(){
            return this->valor;
        }
        friend class List;
};

template<typename tipo> //crea un parámetro de cualquier tipo
class List{
private:
    Nodo *elemento;
    bool ListaVacia(){
        return (this->elemento == NULL);
    }
public:
        void Anterior(){
            if (this->elemento)
                this->elemento = this->elemento->Anterior;
        }

        void Siguiente(){
            if (this->elemento)
                this->elemento = this->elemento->Siguiente;
        }

        void Primero(){
            if (!this->ListaVacia()){
                while (this->elemento->Anterior){
                    this->Anterior();
                }
            }
        }

        void Ultimo(){
            if (!this->ListaVacia()){
                while (this->elemento->Siguiente){
                    this->Siguiente();
                }
            }
        }
    List(){
        this->elemento = NULL;
    }
    ~List(){
        this->Primero();
        while(this->elemento){
            Nodo *aux = this->elemento;
            this->Siguiente();
            delete aux;
        }
    }

    void insertarFinal(tipo *v){
        this->Ultimo();
        Nodo *nuevo = new Nodo(v);
        if(this->ListaVacia()){
            this->elemento = nuevo;
        }else{
            this->elemento->Siguiente = nuevo;
            nuevo->Anterior = this->elemento;
        }
    }
    void insertarInicio(tipo *v){
        this->Primero();
        Nodo *nuevo = new Nodo(v);
        if(this->ListaVacia()){
            this->elemento = nuevo;
        }else{
            this->elemento->Anterior = nuevo;
            nuevo->Siguiente = this->elemento;
        }
    }
    tipo *buscar(tipo *v){
        bool encontrado = false;
        this->Primero();
        Nodo *aux = this->elemento;
        Nodo *retorno = NULL;
        while (aux && !encontrado){
            if (aux->valor = v){
                encontrado = true;
                retorno->valor = aux->valor;
            }else{
                aux = aux->Siguiente;
            }
        }
        return retorno->getValor();
    }

};

#endif // LIST_H_INCLUDED
