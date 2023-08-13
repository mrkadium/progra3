#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Cliente.h"
#include "Producto.h"
#include "ListaProducto.h"


class Venta{
private:
    string noFactura;
    string fechaVenta;
    Cliente cliente;
    ListaProducto lstProductosVendidos;
public:
    Venta(){
    }
    Venta(string nf, string fv, Cliente c){
        this->noFactura = nf;
        this->fechaVenta = fv;
        this->cliente = c;
    }
    void setNumeroFactura(string nf){
        this->noFactura = nf;
    }
    string getNumeroFactura(){
        return this->noFactura;
    }
    void setFecha(string f){
        this->fechaVenta = f;
    }
    string getFecha(){
        return this->fechaVenta;
    }
    void setCliente(Cliente c){
        this->cliente = c;
    }
    Cliente getCliente(){
        return this->cliente;
    }
    void agregarProductos(Producto p){
        lstProductosVendidos.Insertar(p);
    }
    ListaProducto getListaProductos(){
        return this->lstProductosVendidos;
    }
    int getNumeroProductos(){
        lstProductosVendidos.Numero();
    }
};

#endif // VENTA_H_INCLUDED
