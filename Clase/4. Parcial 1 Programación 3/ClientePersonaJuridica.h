#ifndef CLIENTEPERSONAJURIDICA_H_INCLUDED
#define CLIENTEPERSONAJURIDICA_H_INCLUDED
#include "Cliente.h"

class ClientePersonaJuridica : public Cliente{
    public:
        ClientePersonaJuridica(){
        }
        ClientePersonaJuridica(int i, string n, string a) : Cliente(i, n, a){
        }
        void setNumeroNit(string ni){
            this->setDocumento(ni);
        }
        string getNumeroNit(){
            return this->getDocumento();
        }
        int getTipoCliente(){
            return 1;
        }

};

#endif // CLIENTEPERSONAJURIDICA_H_INCLUDED
