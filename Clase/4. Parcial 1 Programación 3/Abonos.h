#ifndef ABONOS_H_INCLUDED
#define ABONOS_H_INCLUDED
#include "Fecha.h"

class Abonos{
private:
    Fecha *fechaAbono;
    float montoAbono;
public:
    Abonos(Fecha *f, float m){
        this->fechaAbono = f;
        this->montoAbono = m;
    }
    void setFechaAbono(Fecha *f){
        this->fechaAbono = f;
    }
    Fecha getFechaAbono(){
        return this->fechaAbono;
    }
    void setMonto(float m){
        this->montoAbono = m;
    }
    float getMonto(){
        return this->montoAbono;
    }
};

#endif // ABONOS_H_INCLUDED
