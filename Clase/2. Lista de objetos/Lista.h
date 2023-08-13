#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"

class Lista{
    private:
///nodos prim, ultim, bool listavacia
        Nodo *Primero;
        Nodo *Ultimo;
        bool ListaVacia(){
            return (this->Primero==NULL);
        }
    public:
        Lista(){
            this->Primero = NULL;
            this->Ultimo = NULL;
        }
        ~Lista(){
            this->Ultimo = NULL;
            while (this->Primero){
                Nodo *tmp = this->Primero;
                this->Primero = this->Primero->Siguiente;
                delete tmp;
            }
        }
        void Insertar(Trabajador *t){
            Nodo *nuevo = new Nodo(t);
            if(this->ListaVacia()){
                this->Primero = nuevo;
            }
            else{
                this->Ultimo->Siguiente = nuevo;
            }
            this->Ultimo = nuevo;
        }
        void Insertar(int id, string n, string a, float sm){
            Trabajador *tb = new Trabajador(id, n, a, sm);
            this->Insertar(tb);
        }
        void Mostrar(){
            Nodo *tmp = this->Primero;
            cout << "ID\tNombre\tApellido\tSueldo Mensual\n";
            while(tmp){
                cout << tmp->Valor->getId() << "\t";
                cout << tmp->Valor->getNombre() << "\t";
                cout << tmp->Valor->getApellido() << "\t";
                cout << tmp->Valor->getSueldoMensual() << "\n";
                tmp = tmp->Siguiente;
            }
            cout << "NULL";
        }

};

#endif // LISTA_H_INCLUDED
