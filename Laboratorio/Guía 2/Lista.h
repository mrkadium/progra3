#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
using namespace std;
#include "Nodo.h"

class Lista{
    private:
        pNodo primero;
        pNodo actual;
    public:

    Lista(void){
        this->primero = actual = NULL;
    }

    virtual ~Lista(){
    pNodo aux;
    while (this->primero){
        aux = this->primero;
        this->primero = this->primero->Siguiente;
        delete aux;
        }
    }

    bool ListaVacia(){
        return (this->primero == NULL);
    }

    void Primero(){
        this->actual = this->primero;
    }

    void Siguiente(){
        if(this->actual->Siguiente != NULL){
            this->actual = this->actual->Siguiente;
        }
    }
    void Final(){
        this->Primero();
        if(ListaVacia()!= true){
            while(this->actual->Siguiente != NULL){
                this->Siguiente();
            }
        }
    }

    void Insertar(Paciente valor){
        if(this->ListaVacia()){
            this->primero = new Nodo(valor);
        }
        else{
            this->Final();
            this->actual->Siguiente = new Nodo(valor);
        }
    }

    void Mostrar(){
        if(this->ListaVacia()!=true){
            this->Primero();
            cout << "--------------------------- LISTA DE PACIENTES ------------------------"<< endl << endl;
            while(this->actual){
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "\tCodigo del paciente: " << this->actual->getVariable().getCodigo() << endl;
                cout << "\tNombre del paciente: " << this->actual->getVariable().getNombre() << endl;
                cout << "\tApellido: " << this->actual->getVariable().getApellido() << endl;
                cout << "\tDepartamento: " << this->actual->getVariable().getDepartamento() << endl;
                cout << "\tTelefono: " << this->actual->getVariable().getTelefono() << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                this->actual = this->actual->Siguiente;
            }
        }
        else{
            cout << "No hay datos que mostrar"<<endl;
        }
    }

    pNodo Buscar(Paciente valor){
        this->Primero();
        while(this->actual != NULL){
            if(this->actual->getVariable().getCodigo() == valor.getCodigo()){
                return this->actual;
            }
        this->actual = this->actual->Siguiente;
        }
    return NULL;
    }

    bool Eliminar(Paciente valor){
        if(this->ListaVacia() == true || this->Buscar(valor) == NULL ) {
            return false;
        }
        else{
            this->Primero();
            pNodo aux;

            if(this->primero->getVariable().getCodigo() == valor.getCodigo()){
                aux = this->primero;
                this->primero = aux->Siguiente;
                delete aux;
                return true;
            }else{
                while(this->actual->Siguiente != NULL){
                    if(this->actual->Siguiente->getVariable().getCodigo() == valor.getCodigo()){
                        aux = this->actual->Siguiente;
                        this->actual->Siguiente = this->actual->Siguiente->Siguiente;

                        delete aux;
                        return true;
                    }
                this->Siguiente();
                }
            }
        }
    }

};


#endif // LISTA_H_INCLUDED
