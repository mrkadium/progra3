#ifndef CEREAL_H_INCLUDED
#define CEREAL_H_INCLUDED
#include "Producto.h"

class Cereal : public Producto{
    private:
        string fecha_cad;
        double peso_g;
    public:
        Cereal(){
        }
        Cereal(double p, string c, string n, string fc, double pg) : Producto(p, c, n){
            this->fecha_cad = fc;
            this->peso_g = pg;
        }
        string getCategoria(){
            return "Cereal";
        }
        double getPeso(){
            return this->peso_g;
        }
        void getInfo(){
            cout << "Nombre: " << this->getNombre() << endl;
            cout << "Categoria: " << this->getCategoria() << endl;
            cout << "Precio: $" << this->getPrecio() << endl;
            cout << "Fecha de caducidad: " << this->fecha_cad << endl;
            cout << "Peso: " << this->peso_g << "g" << endl << endl;
        }

};

#endif // CEREAL_H_INCLUDED
