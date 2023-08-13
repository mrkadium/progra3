#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
private:
    int idProducto;
    string descripcion;
    float precioUnitario;
public:
    Producto(){
    }
    Producto(int idp, string desc, float pu){
        this->idProducto = idp;
        this->descripcion = desc;
        this->precioUnitario = pu;
    }
    void setIdProducto(int idp){
        this->idProducto = idp;
    }
    int getIdProducto(){
        return this->idProducto;
    }
    void setDescripcion(string desc){
        this->descripcion = desc;
    }
    string getDescripcion(){
        return this->descripcion;
    }
    void setPrecioUnitario(float pu){
        this->precioUnitario = pu;
    }
    float getPrecioUnitario(){
        return this->precioUnitario;
    }

};

#endif // PRODUCTO_H_INCLUDED
