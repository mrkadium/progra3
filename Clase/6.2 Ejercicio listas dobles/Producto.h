#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "Objeto.h"
#include <string.h>

class Producto : public Objeto{
    private:
        int idProducto;
        string nombreProducto;
        float existencia;
    public:
        Producto(){
            this->idProducto = 0;
        }
        Producto(int i, string n){
            this->idProducto = i;
            this->nombreProducto = n;
            this->existencia = 0;
        }
        void setIdProducto(int i){
            this->idProducto = i;
        }
        int getIdProducto(){
            return this->idProducto;
        }
        void setNombreProducto(string n){
            this->nombreProducto = n;
        }
        string getNombreProducto(){
            return this->nombreProducto;
        }
        void setExistencia(float e){
            this->existencia = e;
        }
        float getExistencia(){
            return this->existencia;
        }
        int getTipoObjeto(){
            return 1;
        }
};



#endif // PRODUCTO_H_INCLUDED
