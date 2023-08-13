#ifndef PERSONANATURAL_H_INCLUDED
#define PERSONANATURAL_H_INCLUDED
#include "Persona.h"

class PersonaNatural : public Persona{
    private:
        string Dui;
    public:
        PersonaNatural(int i, string n, string a) : Persona(i, n, a){
        }
        void setDui(string d){
            this->Dui = d;
        }
        string getDui(){
            return this->Dui;
        }
        int getTipoPersona(){
            return 1;
        }

};

#endif // PERSONANATURAL_H_INCLUDED
