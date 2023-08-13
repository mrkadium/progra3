#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>

class Cliente{
    private:
        int id;
        string nombre;
        string apellido;
        string documento;
    public:
        Cliente(){
        }
        Cliente(int i, string n, string a){
            this->id = i;
            this->nombre = n;
            this->apellido = a;
        }
        int getId(){
            return this->id;
        }
        void setNombre(string n){
            this->nombre = n;
        }
        string getNombre(){
            return this->nombre;
        }
        void setApellido(string a){
            this->apellido = a;
        }
        string getApellido(){
            return this->apellido;
        }
        void setDocumento(string d){
            this->documento = d;
        }
        string getDocumento(){
            return this->documento;
        }
        virtual int getTipoCliente()=0;

};


#endif // CLIENTE_H_INCLUDED
