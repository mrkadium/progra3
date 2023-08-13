#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <string.h>

class Producto{
    protected:
        double precio;
    private:
        string categoria;
        string nombre;
    public:
        Producto(){
        }
        Producto(double p, string c, string n){
            this->precio = p;
            this->categoria = c;
            this->nombre = n;
        }
        void setPrecio(double p){
            this->precio = p;
        }
        double getPrecio(){
            return this->precio;
        }
        void setNombre(string n){
            this->nombre = n;
        }
        string getNombre(){
            return this->nombre;
        }
        void setCategoria(string c){
            this->categoria = c;
        }
        virtual string getCategoria(){
            return this->categoria;
        }
};

#endif // PRODUCTO_H_INCLUDED
