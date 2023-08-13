#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
#include "PersonaNatural.h"
#include "PersonaJuridica.h"

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
        ///Destructor
        void Insertar(Persona *p){
            pn nuevo = new Nodo(p);
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
                if(tmp->Valor->getTipoPersona() == 1){
                    ///Persona Natural
                    PersonaNatural *pnat = static_cast<PersonaNatural*>(tmp->Valor);
                    cout << pnat->getId() << "\t";
                    cout << pnat->getNombre() << "\t";
                    cout << pnat->getDui() << "\n";
                }
                else{
                    ///Persona Juridica
                    PersonaJuridica *pjud = static_cast<PersonaJuridica*>(tmp->Valor);
                    cout << pjud->getId() << "\t";
                    cout << pjud->getNombre() << "\t";
                    cout << pjud->getNit() << "\n";
                }
                tmp = tmp->Siguiente;
            }
            cout << "NULL";
        }

};

#endif // LISTA_H_INCLUDED
