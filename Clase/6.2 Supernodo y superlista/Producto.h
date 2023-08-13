#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "Objeto.h"

class Producto : public Objeto{
    private:
        int idProducto;
        string nombreProducto;
        float existencia;
    public:
        Producto(){}
        Producto(int id, string nombre, float exist){
            this->idProducto = id;
            this->nombreProducto = nombre;
            this->existencia = exist;
        }
        void setIdProducto(int id){
            this->idProducto = id;
        }
        int getIdProducto(){
            return this->idProducto;
        }
        void setNombreProducto(string nombre){
            this->nombreProducto = nombre;
        }
        string getNombreProducto(){
            return this->nombreProducto;
        }
        void setExistencia(float exist){
            this->existencia = exist;
        }
        float getExistencia(){
            return this->existencia;
        }
        int getTipoObjeto(){
            return 1;
        }
};

#endif // PRODUCTO_H_INCLUDED
