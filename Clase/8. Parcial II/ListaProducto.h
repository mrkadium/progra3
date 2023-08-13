#ifndef LISTAPRODUCTO_H_INCLUDED
#define LISTAPRODUCTO_H_INCLUDED

#include "NodoProducto.h"

class ListaProducto{
    private:
        NodoProducto *elemento;
        bool ListaVacia(){
            return (this->elemento == NULL);
        }
    public:
        ListaProducto(){
            this->elemento = NULL;
        }
        ~ListaProducto(){
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
        void Insertar(Producto p){
            NodoProducto *nuevo = new NodoProducto(p);
            if(this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                this->elemento->Siguiente = nuevo;
                nuevo->Anterior = this->elemento;
            }
        }
        void Mostrar(){
            NodoProducto *tmp;
            this->Ultimo();
            tmp = this->elemento;
            while(tmp){
                cout << "-----------------------------------------" << endl;
                cout << "\tID: " << tmp->Valor.getIdProducto() << endl;
                cout << "\tDescripcion: " << tmp->Valor.getDescripcion() << endl;
                cout << "\tPrecio: $" << tmp->Valor.getPrecioUnitario() << endl;
                cout << "-----------------------------------------" << endl;
                tmp = tmp->Anterior;
            }
            cout << "NULL" << endl << endl;
        }
        int Numero(){
            NodoProducto *tmp;
            this->Ultimo();
            tmp = this->elemento;
            int numeroComprados = 0;
            while(tmp){
                numeroComprados++;
                tmp = tmp->Anterior;
            }
            return numeroComprados;
        }
        /*void MostrarComprados(){
            NodoProducto *tmp;
            this->Ultimo();
            tmp = this->elemento;
            while(tmp){
                cout << "-----------------------------------------" << endl;
                cout << "\tID: " << tmp->Valor.getIdProducto() << endl;
                cout << "\tNombre: " << tmp->Valor.getNombreProducto() << endl;
                cout << "\tNumero de productos comprados: " << tmp->Valor.getExistencia() << endl;
                cout << "-----------------------------------------" << endl;
                tmp = tmp->Anterior;
            }
            cout << "NULL" << endl << endl;;
        }*/

        Producto Buscar(int i){
            Producto r;
            bool encontrado = false;
            NodoProducto *tmp = this->elemento;
            while(tmp && !encontrado){
                if(tmp->Valor.getIdProducto() == i){
                    encontrado = true;
                    r = tmp->Valor;
                }else{
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }
        NodoProducto *BuscarNodo(int i){
            NodoProducto *r;
            bool encontrado = false;
            NodoProducto *tmp = this->elemento;
            while(tmp && !encontrado){
                if(tmp->Valor.getIdProducto() == i){
                    encontrado = true;
                    r = tmp;
                }else{
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }
        void Eliminar(int id){
            NodoProducto *aux = this->BuscarNodo(id);
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

};

#endif // LISTAPRODUCTO_H_INCLUDED
