#ifndef CLIENTEPERSONANATURAL_H_INCLUDED
#define CLIENTEPERSONANATURAL_H_INCLUDED
#include "Cliente.h"

class ClientePersonaNatural : public Cliente{
    public:
        ClientePersonaNatural(){
        }
            ClientePersonaNatural(int i, string n, string a) : Cliente(i, n, a){
            }
        void setNumeroDui(string du){
            this->setNumeroDui(du);
        }
        string getNumeroDui(){
            return getDocumento();
        }
        int getTipoCliente(){
            return 2;
        }

};


#endif // CLIENTEPERSONANATURAL_H_INCLUDED
