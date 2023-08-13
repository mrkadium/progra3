#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include "Persona.h"

class Estudiante : public Persona{
    private:
        string codigo;
    public:
        Estudiante(string n, string a, string c) : Persona(n, a){
            this->codigo = c;
        }
        string getCodigo(){
            return this->codigo;
        }
        void setCodigo(string c){
            this->codigo = c;
        }
        string getTipoPersona(){
            return "Estudiante";
        }
};

#endif // ESTUDIANTE_H_INCLUDED
