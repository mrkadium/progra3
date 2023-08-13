#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
class Lista{
    private:
        Nodo *Primero;
        Nodo *Ultimo;
        Nodo *Anterior;
        bool ListaVacia(){ //m�todo para verificar si la lista est� vac�a
            return (this->Primero==NULL);
        }
    public:
        Lista(){ //constructor
            //se inicializan en NULL ambos nodos
            this->Primero = NULL;
            this->Ultimo = NULL;
        }
        ~Lista(){ //destructor
            this->Ultimo = NULL;
            while(this->Primero){ //mientras haya un nodo
                Nodo *tmp = this->Primero; //el temporal es el primer nodo
                this->Primero = this->Primero->Siguiente; //el nodo siguiente pasa a ser el primer nodo
                delete tmp; //el primer nodo se elimina
            }
        }
        void Insertar(int v){ //se recibe el valor
            Nodo *nuevo = new Nodo(v); //se crea un nuevo nodo con el valor recibido
            if(this -> ListaVacia()){ //si la lista est� vac�a
                this -> Primero = nuevo; //el primer nodo es el nuevo nodo
            }
            else { //si la lista no est� vac�a
                this->Ultimo->Siguiente = nuevo; //el nuevo nodo es el siguiente del �ltimo
            }
            this->Ultimo = nuevo; //el nuevo es el �ltimo
        }
        void Mostrar(){
            Nodo *tmp = this->Primero; //el temporal pasa a ser el primero
            //el temporal se usa para no cambiar el valor del primer nodo
            while (tmp){ //mientras que el temporal no sea NULL
                    cout<<tmp->Valor <<"-->";
                    tmp = tmp->Siguiente;
            }
            cout << "NULL\n" << endl;
        }
        void Buscar(int v){
            cout << "Valor buscado: " << v << endl;
            Nodo *tmp = this->Primero;
            Nodo *buscado = NULL;
            int contador = 0;
            while(tmp){
                if(tmp->Valor == v){
                    cout << "Valor encontrado :)" << endl;
                    buscado = tmp;
                    break;
                }
                contador += 1;
                tmp = tmp->Siguiente;
            }
            if(buscado != NULL){
                cout << buscado->Valor << " en la posicion " << contador << " de la lista" << endl;
            }
        }
        void BuscarEnPosicion(){

        }
//        Nodo *Buscar(int v){
//            bool encontrado = false;
//            Nodo *tmp = this->Primero;
//            Nodo *this->Anterior = tmp;
//            if(tmp){
//
//            }
//        }
//        void Modificar(int v, int n){
//            Nodo *tmp = this->Buscar(v);
//            if(tmp){
//                tmp->Valor = n;
//            }else{
//
//            }
//        }
//        void Eliminar{
//
//        }

};
#endif // LISTA_H_INCLUDED
