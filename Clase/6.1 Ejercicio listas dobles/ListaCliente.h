#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED
#include "NodoCliente.h"

class ListaCliente{
    private:
        NodoCliente *elemento;
        bool ListaVacia(){
            return (this->elemento == NULL);
        }
    public:
        ListaCliente(){
            this->elemento = NULL;
        }
        ~ListaCliente(){
        }
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
        void Insertar(Cliente c){
            NodoCliente *nuevo = new NodoCliente(c);
            if(this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                this->elemento->Siguiente = nuevo;
                nuevo->Anterior = this->elemento;
            }
        }
        void Mostrar(){
            NodoCliente *tmp;
            this->Ultimo();
            tmp = this->elemento;
            while(tmp){
                cout << "-----------------------------------------" << endl;
                cout << "\tID: " << tmp->Valor.getIdCliente() << endl;
                cout << "\tNombre: " << tmp->Valor.getNombre() <<" " << tmp->Valor.getApellido()<< endl;
                cout << "-----------------------------------------" << endl;
                tmp = tmp->Anterior;
            }
            cout << "NULL" << endl << endl;;
        }
        Cliente Buscar(int i){
            Cliente r;
            bool encontrado = false;
            NodoCliente *tmp = this->elemento;
            while(tmp && !encontrado){
                if(tmp->Valor.getIdCliente() == i){
                    encontrado = true;
                    r = tmp->Valor;
                }else{
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }
        NodoCliente *BuscarNodo(int i){
            NodoCliente *r;
            bool encontrado = false;
            NodoCliente *tmp = this->elemento;
            while(tmp && !encontrado){
                if(tmp->Valor.getIdCliente() == i){
                    encontrado = true;
                    r = tmp;
                }else{
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }
        void Eliminar(int id){
            NodoCliente *aux = this->BuscarNodo(id);
            if (aux){
                if (aux->Anterior==NULL && aux->Siguiente==NULL){
                            ///Es unico
                            this->elemento = NULL;
                        }
                    else{
                    if (aux->Anterior==NULL){
                    ///Al principio
                        this->elemento = this->elemento->Siguiente;
                        this->elemento->Anterior = NULL;
                    }
                    else{
                        if (aux->Siguiente == NULL){
                            ///Ultimo
                            this->Ultimo();
                            this->elemento = this->elemento->Anterior;
                            this->elemento->Siguiente = NULL;
                        }else{
                            ///Esta en medio
                                this->elemento = aux;
                                this->elemento->Siguiente->Anterior = this->elemento->Anterior;
                                this->elemento->Anterior->Siguiente = this->elemento->Siguiente;
                                this->elemento = aux->Siguiente;
                        }
                    }
                }
            }else{
                cout<<"No se pudo eliminar"<<endl;
            }
            delete aux;
        }

        /*pNodo Buscar(Contacto valor){
            this->Primero();
            while(this->actual!=NULL){//mientras todavia exista un nodo que recorrer
                if(this->actual->getVariable().getId()== valor.getId()){
                    return this->actual;
                }
                this->actual = this->actual->Siguiente;//nos movemos al elemento siguiente
            }
            return NULL;
        }*/

};

#endif // LISTACLIENTE_H_INCLUDED
