#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string.h>

class Persona{
    private:
        int id;
        string nombre;
        string apellido;
    public:
        Persona(int i, string n, string a){
            this->id = i;
            this->nombre = n;
            this->apellido = a;
        }
        int getId(){
            return this->id;
        }
        string getNombre(){
            return this->nombre;
        }
        string getApellido(){
            return this->apellido;
        }
        virtual int getTipoPersona()=0; //Si retorna 1 es natural, si es 2 es juridica

};

#endif // PERSONA_H_INCLUDED
