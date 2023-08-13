#ifndef TRABAJADOR_H_INCLUDED
#define TRABAJADOR_H_INCLUDED
#include "Persona.h"

class Trabajador : public Persona{
    private:
        double sueldo;
    public:
        Trabajador(string n, string a, double s) : Persona(n, a){
            this->sueldo = s;
        }
        void setSueldo(double s){
            this->sueldo = s;
        }
        double getSueldo(){
            return this->sueldo;
        }
        string getTipoPersona(){
            return "Trabajador";
        }
};

#endif // TRABAJADOR_H_INCLUDED
