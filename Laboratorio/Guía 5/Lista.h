#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
#include "Cereal.h"
#include "Detergente.h"

class Lista{
    private:
        p elemento;
        bool ListaVacia(){
            return (this->elemento==NULL);
        }
    public:
        ///Constructor
        Lista(){
            this->elemento = NULL;
        }

        ~Lista(){
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

        void Insertar(Producto *v){
            this->Ultimo();
            p nuevo = new Nodo(v);
            if (this->ListaVacia()){
                    this->elemento = nuevo;
            }else{
                this->elemento->Siguiente = nuevo;
                nuevo->Anterior = this->elemento;
                //this->elemento = nuevo;
            }
        }

        /*void InsertarInicio(Producto *v){
            this->Primero();
            p nuevo = new Nodo(v);
            if(this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                this->elemento->Anterior = nuevo;
                nuevo->Siguiente = this->elemento;
            }
        }*/

        /*void insertarAntes(int vviejo, int vnuevo){
            Primero();
            p nuevo = new Nodo(vnuevo);
            nuevo->Siguiente = NULL;
            if(Buscar(vviejo) == NULL){
                this->Insertar(vnuevo);
            }else{
                if(ListaVacia()){
                    this->elemento = nuevo;
                }else{
                    if(this->elemento->getValor() == vviejo){
                        this->InsertarInicio(vnuevo);
                    }else{
                        p posterior = this->elemento;
                        p anterior;
                        p aux = this->Buscar(vviejo);
                        while(elemento->Siguiente->getValor() != aux->getValor()){
                            anterior = posterior;
                            posterior = posterior->Siguiente;
                        }
                        anterior->Siguiente = nuevo;
                        nuevo->Siguiente = posterior;
                    }
                }
            }
        }*/

        p Buscar(string nombre){
            bool encontrado = false;
            this->Primero();
            p aux = this->elemento;
            p retorno = NULL;
            while (aux && !encontrado){
                if (aux->getValor()->getNombre() == nombre){
                    encontrado=true;
                    retorno = aux;
                }else{
                    aux = aux->Siguiente;
                }
            }
            return retorno;
        }

        void Eliminar(string nombre){
            p aux = this->Buscar(nombre);
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

        /*void Modificar(int v, int n){
            p aux = this->Buscar(v);
            if (aux){
                aux->Valor = n;
            }else{
                cout << "No se pudo modificar porque no existe\n";
            }
        }*/

        void Mostrar(){
            Nodo *tmp;
            string c = "Cereal";
            string d = "Detergente";
            this->Primero();
            tmp = this->elemento;
            while(tmp){
                if(tmp->getValor()->getCategoria() == d){
                    cout << "---------------------------------" << endl;
                    Detergente *det = static_cast<Detergente*>(tmp->Valor);
                    det->getInfo();
                    cout << "---------------------------------" << endl;
                }
                if(tmp->getValor()->getCategoria() == c){
                    cout << "---------------------------------" << endl;
                    Cereal *cer = static_cast<Cereal*>(tmp->Valor);
                    cer->getInfo();
                    cout << "---------------------------------" << endl;
                }
                tmp = tmp->Siguiente;
            }
            cout << "NULL" << endl << endl;
        }
};

#endif // LISTA_H_INCLUDED
