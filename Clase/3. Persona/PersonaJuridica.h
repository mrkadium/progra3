#ifndef PERSONAJURIDICA_H_INCLUDED
#define PERSONAJURIDICA_H_INCLUDED
#include "Persona.h"

class PersonaJuridica : public Persona{
    private:
        string Nit;
    public:
        PersonaJuridica(int i, string n, string a) : Persona(i, n, a){
        }
        void setNit(string n){
            this->Nit =  n;
        }
        string getNit(){
            return this->Nit;
        }
        int getTipoPersona(){
            return 2;
        }

};

#endif // PERSONAJURIDICA_H_INCLUDED
