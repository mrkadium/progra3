#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Objeto.h"

class Cliente : public Objeto{
    private:
        int idCliente;
        string Nombre;
        string Apellido;
    public:
        Cliente(){}
        Cliente(int id, string nom, string ape){
            this->idCliente = id;
            this->Nombre = nom;
            this->Apellido = ape;
        }
        void setIdCliente(int id){
            this->idCliente = id;
        }
        int getIdCliente(){
            return this->idCliente;
        }
        void setNombre(string nom){
            this->Nombre = nom;
        }
        string getNombre(){
            return this->Nombre;
        }
        void setApellido(string ape){
            this->Apellido = ape;
        }
        string getApellido(){
            return this->Apellido;
        }
        int getTipoObjeto(){
            return 2;
        }
};

#endif // CLIENTE_H_INCLUDED
