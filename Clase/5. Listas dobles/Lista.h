#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"

class Lista{
    private:
        Nodo *elemento;
        bool ListaVacia(){ //para verificar si la lista está vacía
        return (this->elemento == NULL);
        }
    public:
        ///Constructor
        ListaDoble(){
            this->elemento = NULL;
        }

        ~ListaDoble(){
            this->Primero();
            while (this->elemento){
                p aux = this->elemento;
                this->Siguiente();
                delete aux;
            }
        }

        ///Metodos de navegacion
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

        void Insertar(int v){
            this->Ultimo();
            p nuevo = new Nodo(v);
            if (this->ListaVacia()){
                    this->elemento = nuevo;
            }else{
                this->elemento->Siguiente = nuevo;
                nuevo->Anterior = this->elemento;
                this->elemento = nuevo;
            }
        }

        p Buscar(int v){
            bool encontrado=false;
            this->Primero();
            p aux = this->elemento;
            p retorno = NULL;
            while (aux && !encontrado){
                if (aux->Valor==v){
                    encontrado=true;
                    retorno = aux;
                }else{
                    aux = aux->Siguiente;
                }
            }
            return retorno;
        }

        void Eliminar(int v){
            p aux = this->Buscar(v);
            if (aux){ ///Determinando si esta al principio
                if (aux->Anterior==NULL){ ///Al principio
                    this->elemento = this->elemento->Siguiente;
                    aux->Siguiente->Anterior = NULL;
                    delete aux;
                }else{
                    if(aux->Siguiente == NULL){ ///Ultimo
                            this->elemento = this->elemento->Anterior;
                        aux->Anterior->Siguiente = NULL;
                        delete aux;
                    }else{
                        if (aux->Anterior==NULL && aux->Siguiente==NULL){ ///Es unico
                                this->elemento = NULL;
                                delete aux;
                        }else{ ///Esta en medio
                            this->elemento = aux->Siguiente;
                            aux->Siguiente->Anterior = aux->Anterior;
                            aux->Anterior->Siguiente = aux->Siguiente;
                            delete aux;
                        }
                    }
                }
            }else{
                cout << "No se pudo eliminar\n";
            }
        }

        void Modificar(int v, int n){
            p aux = this->Buscar(v);
            if (aux){
                aux->Valor = n;
            }else{
                cout << "No se pudo modificar porque no existe\n";
            }
        }

        void Mostrar(int orden){
            p aux;
            if (orden == 1){ ///1. Ascendente
                this->Primero();
                aux = this->elemento;
                cout << "NULL<-->";
                while (aux){
                    cout << aux->Valor;
                    cout << "<-->";
                    aux = aux->Siguiente;
                }
                cout << "NULL\n";
            }else{ ///2. Descendente
                this->Ultimo();
                aux = this->elemento;
                cout << "NULL<-->";
                while (aux){
                    cout << aux->Valor;
                    cout << "<-->";
                    aux = aux->Anterior;
                } cout << "NULL\n";
            }
        }
};

#endif // LISTA_H_INCLUDED
