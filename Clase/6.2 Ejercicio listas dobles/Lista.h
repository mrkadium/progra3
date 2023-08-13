#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
#include "Venta.h"

class Lista{
    private:
        Nodo *elemento;
        bool ListaVacia(){
            return (this->elemento == NULL);
        }
    public:
        Lista(){
            this->elemento = NULL;
        }
        ~Lista(){
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
        void Insertar(Venta *v){
            Nodo *nuevo = new Nodo(v);
            if(this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                this->elemento->Siguiente = nuevo;
                nuevo->Anterior = this->elemento;
            }
        }
        void Mostrar(){
            Nodo *tmp;
            this->Ultimo();
            tmp = this->elemento;
            /*while(tmp){
                cout << "--------------------------------------------------------------------" << endl;
                cout << "No de factura: " << tmp->Valor.getNumeroFactura()<< endl;
                cout << "Cliente: " << tmp->Valor.getCliente().getNombre() << " " << tmp->Valor.getCliente().getApellido() << endl;
                cout << "Productos comprados: " << endl;
                tmp->Valor.getLstProducto().MostrarComprados();
                cout << "--------------------------------------------------------------------" << endl;
                tmp = tmp->Anterior;
            }*/
            cout << "NULL" << endl;
        }

        Objeto Buscar(int i){
            Objeto r;
            bool encontrado = false;
            Nodo *tmp = this->elemento;
            while(tmp && !encontrado){
                if(tmp->Valor.getNumeroFactura() == i){
                    encontrado = true;
                    r = tmp->Valor;
                }else{
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }

        Objeto Buscar(int i){
            Objeto r;
            bool encontrado = false;
            Nodo *tmp = this->elemento;
            while(tmp && !encontrado){
                if(tmp->Valor.getTipoObjeto() == i){
                    encontrado = true;
                    r = tmp->Valor;
                }else{
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }
        Nodo *BuscarNodo(int i){
            Nodo *r;
            bool encontrado = false;
            Nodo *tmp = this->elemento;
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
            Nodo *aux = this->BuscarNodo(id);
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

#endif // LISTA_H_INCLUDED
