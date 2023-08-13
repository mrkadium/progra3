#ifndef TRABAJADOR_H_INCLUDED
#define TRABAJADOR_H_INCLUDED
#include <string.h>

class Trabajador{
    private:
        int id;
        string nom;
        string ape;
        float sueldoMensual;
        float descuentoSeguro;
        float desscuentoAfp;
        float descuentoIsr;
        float totalDes;
        float totalPagar;
    public:
        Trabajador(int i, string n, string a, float sm){
            this->id = i;
            this->nom = n;
            this->ape = a;
            this->sueldoMensual = sm;
            ///aplicacion de descuentos (tarea)
            //this->descuentoSeguro = 0;
            ///todos los descuentos a 0
        }
        ///getters
        int getId(){
            return this->id;
        }
        string getNombre(){
            return this->nom;
        }
        string getApellido(){
            return this->ape;
        }
        float getSueldoMensual(){
            return this->sueldoMensual;
        }
        float getDescuentoSeguro(){
            return this->descuentoSeguro;
        }
        float getDescuentoAfp(){
            return this->desscuentoAfp;
        }
        float getDescuentoIsr(){
            return this->descuentoIsr;
        }
        float getTotalDescuento(){
            return this->totalDes;
        }
        float getTotalPagar(){
            return this->totalPagar;
        }
        friend class Nodo;
};

#endif // TRABAJADOR_H_INCLUDED
