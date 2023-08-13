#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
#include "ClientePersonaNatural.h"
#include "ClientePersonaJuridica.h"

class Lista{
    private:
        pn Primero;
        pn Ultimo;
        bool ListaVacia(){
            return this->Primero == NULL;
        }
    public:
        Lista(){
            this->Primero = NULL;
            this->Ultimo = NULL;
        }
        void Insertar(Cliente *cli){
            pn nuevo = new Nodo(cli);
            if(this->ListaVacia()){
                this->Primero = nuevo;
            }
            else{
                this->Ultimo->Siguiente = nuevo;
            }
            this->Ultimo = nuevo;
        }
        void Mostrar(){
            pn tmp = this->Primero;
            while(tmp){
                if(tmp->Valor->getTipoCliente() == 1){
                    ClientePersonaNatural *cpn = static_cast<ClientePersonaNatural*>(tmp->Valor);
                    cout << cpn->getId() << "\t";
                    cout << cpn->getNombre() << "\t";
                    cout << cpn->getNumeroDui() << "\n";
                }
                else{
                    ClientePersonaJuridica *cpj = static_cast<ClientePersonaJuridica*>(tmp->Valor);
                    cout << cpj->getId() << "\t";
                    cout << cpj->getNombre() << "\t";
                    cout << cpj->getNumeroNit() << "\n";
                }
                tmp = tmp->Siguiente;
            }
            cout << "NULL";
        }

};


#endif // LISTA_H_INCLUDED
