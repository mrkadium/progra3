#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Producto.h"
#include "Cliente.h"
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

        void InsertarInicio(Objeto *o){
            this->Primero();
            Nodo *nuevo = new Nodo(o);
            if(this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                this->elemento->Anterior = nuevo;
                nuevo->Siguiente = this->elemento;
            }
        }

        void insertarAntes(int vviejo, Objeto *vnuevo){
            Primero();
            Nodo *nuevo = new Nodo(vnuevo);
            nuevo->Siguiente = NULL;
            Producto *p;
            Cliente *c;
            Venta *v;
            if(buscarNodo(vviejo) == NULL){
                this->insertarFinal(vnuevo);
            }else{
                if(ListaVacia()){
                    this->elemento = nuevo;
                }else{
                    if(this->elemento->getValor()->getTipoObjeto() == 1){
                        p = static_cast<Producto*>(this->elemento->Valor);
                        if(p->getIdProducto() == vviejo){
                            this->InsertarInicio(vnuevo);
                        }else{
                            Nodo *posterior = this->elemento;
                            Nodo *anterior;
                            Nodo *aux = this->buscarNodo(vviejo);
                            while(elemento->Siguiente->getValor() != aux->getValor()){
                                anterior = posterior;
                                posterior = posterior->Siguiente;
                            }
                            anterior->Siguiente = nuevo;
                            nuevo->Siguiente = posterior;
                        }
                    }
                    if(this->elemento->getValor()->getTipoObjeto() == 2){
                        c = static_cast<Cliente*>(this->elemento->Valor);
                        if(c->getIdCliente() == vviejo){
                            this->InsertarInicio(vnuevo);
                        }else{
                            Nodo *posterior = this->elemento;
                            Nodo *anterior;
                            Nodo *aux = this->buscarNodo(vviejo);
                            while(elemento->Siguiente->getValor() != aux->getValor()){
                                anterior = posterior;
                                posterior = posterior->Siguiente;
                            }
                            anterior->Siguiente = nuevo;
                            nuevo->Siguiente = posterior;
                        }
                    }
                    if(this->elemento->getValor()->getTipoObjeto() == 3){
                        v = static_cast<Venta*>(this->elemento->Valor);
                        if(v->getNumeroFactura() == vviejo){
                            this->InsertarInicio(vnuevo);
                        }else{
                            Nodo *posterior = this->elemento;
                            Nodo *anterior;
                            Nodo *aux = this->buscarNodo(vviejo);
                            while(elemento->Siguiente->getValor() != aux->getValor()){
                                anterior = posterior;
                                posterior = posterior->Siguiente;
                            }
                            anterior->Siguiente = nuevo;
                            nuevo->Siguiente = posterior;
                        }
                    }
                }
            }
        }

        void insertarFinal(Objeto *o){
            Nodo *nuevo = new Nodo(o);
            if(this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                this->elemento->Siguiente = nuevo;
                nuevo->Anterior = this->elemento;
            }
        }

        Nodo *buscarNodo(int nombre){
            Nodo *r = NULL;
            bool encontrado = false;
            Ultimo();
            Nodo *tmp = this->elemento;
            Producto *p = new Producto(0, "", 0);
            Cliente *c = new Cliente(0, "", "");
            Lista *l;
            Venta *v = new Venta(0, c, l);
            while(tmp && !encontrado){
                if(tmp->Valor->getTipoObjeto() == 1){
                    p = static_cast<Producto*>(tmp->Valor);
                    if(p->getIdProducto() == nombre){
                        encontrado = true;
                        r = tmp;
                    }
                }
                if(tmp->Valor->getTipoObjeto() == 2){
                    c = static_cast<Cliente*>(tmp->Valor);
                    if(c->getIdCliente() == nombre){
                        encontrado = true;
                        r = tmp;
                    }
                }
                if(tmp->Valor->getTipoObjeto() == 3){
                    v = static_cast<Venta*>(tmp->Valor);
                    if(v->getNumeroFactura() == nombre){
                        encontrado = true;
                        r = tmp;
                    }
                }
                if(r != tmp){ //si aún no son iguales
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }

        Nodo *buscarObjeto(int nombre, int obj){
            Nodo *r = NULL;
            bool encontrado = false;
            Ultimo();
            Nodo *tmp = this->elemento;
            Producto *p = new Producto(0, "", 0);
            Cliente *c = new Cliente(0, "", "");
            Lista *l;
            Venta *v = new Venta(0, c, l);
            int ob = obj;
            while(tmp && !encontrado){
                if(tmp->Valor->getTipoObjeto() == ob){
                    p = static_cast<Producto*>(tmp->Valor);
                    if(p->getIdProducto() == nombre){
                        encontrado = true;
                        r = tmp;
                    }
                }
                if(tmp->Valor->getTipoObjeto() == ob){
                    c = static_cast<Cliente*>(tmp->Valor);
                    if(c->getIdCliente() == nombre){
                        encontrado = true;
                        r = tmp;
                    }
                }
                if(tmp->Valor->getTipoObjeto() == ob){
                    v = static_cast<Venta*>(tmp->Valor);
                    if(v->getNumeroFactura() == nombre){
                        encontrado = true;
                        r = tmp;
                    }
                }
                if(r != tmp){ //si aún no son iguales
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }

        void mostrar(int op){
            Nodo *tmp = this->elemento;
            Producto *p;
            //Venta *v;
            Cliente *cl;
            int ob = op;
            if(ListaVacia()){
                cout << "No hay valores en la lista :(" << endl;
            }else{
                while(tmp){
                    if(ob == 1){
                        if(tmp->getValor()->getTipoObjeto() == 1){
                            p = static_cast<Producto*>(tmp->Valor);
                            cout << "---------------------------------------------------------" << endl;
                            cout << "PRODUCTO" << endl;
                            cout << "ID: " << p->getIdProducto() << endl;
                            cout << "Nombre: " << p->getNombreProducto() << endl;
                            cout << "Existencia: " << p->getExistencia() << " unidades" << endl;
                            cout << "---------------------------------------------------------" << endl;
                        }
                    }
                    if(ob == 2){
                        if(tmp->getValor()->getTipoObjeto() == 2){
                            cl = static_cast<Cliente*>(tmp->Valor);
                            cout << "---------------------------------------------------------" << endl;
                            cout << "CLIENTE" << endl;
                            cout << "ID: " << cl->getIdCliente() << endl;
                            cout << "Nombre: " << cl->getNombre() << " " << cl->getApellido() << endl;
                            cout << "---------------------------------------------------------" << endl;
                        }
                    }
                    tmp = tmp->Siguiente;
                }
            }
        }

        void eliminar(int nombre, int obj){
            int ob = obj;
            Nodo *aux = this->buscarObjeto(nombre, ob);
            if(ListaVacia()){
                cout << "La lista esta vacia :(" << endl;
            }else{
                if (aux){
                    if (aux->Anterior==NULL && aux->Siguiente==NULL){
                                ///Es unico
                                this->elemento = NULL;
                                cout << "Eliminado correctamente :)" << endl;
                            }
                        else{
                        if (aux->Anterior==NULL){
                        ///Al principio
                            this->elemento = this->elemento->Siguiente;
                            this->elemento->Anterior = NULL;
                            cout << "Eliminado correctamente :)" << endl;
                        }
                        else{
                            if (aux->Siguiente == NULL){
                                ///Ultimo
                                this->Ultimo();
                                this->elemento = this->elemento->Anterior;
                                this->elemento->Siguiente = NULL;
                                cout << "Eliminado correctamente :)" << endl;
                            }else{
                                ///Esta en medio
                                    this->elemento = aux;
                                    this->elemento->Siguiente->Anterior = this->elemento->Anterior;
                                    this->elemento->Anterior->Siguiente = this->elemento->Siguiente;
                                    this->elemento = aux->Siguiente;
                                    cout << "Eliminado correctamente :)" << endl;
                            }
                        }
                    }
                }else{
                    cout<<"No se pudo eliminar :("<<endl;
                }
            }
            delete aux;
        }
};

#endif // LISTA_H_INCLUDED
