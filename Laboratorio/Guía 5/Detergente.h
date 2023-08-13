#ifndef DETERGENTE_H_INCLUDED
#define DETERGENTE_H_INCLUDED
#include "Producto.h"

class Detergente : public Producto{
    private:
        string tipo;
        double peso_g;
    public:
        Detergente(){
        }
        Detergente(double p, string c, string n, string t, double pg) : Producto(p, c, n){
            this->tipo = t;
            this->peso_g = pg;
        }
        string getCategoria(){
            return "Detergente";
        }
        void getInfo(){
            cout << "Nombre: " << this->getNombre() << endl;
            cout << "Categoria: " << this->getCategoria() << endl;
            cout << "Precio: $" << this->getPrecio() << endl;
            cout << "Tipo de detergente: " << this->tipo << endl;
            cout << "Peso: " << this->peso_g << "g" << endl << endl;
        }

};

#endif // DETERGENTE_H_INCLUDED
