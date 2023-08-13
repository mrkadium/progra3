#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Cliente.h"
#include "Producto.h"
#include "ListaProducto.h"

class Venta{
    private:
        int noFactura;
        Cliente cliente;
        ListaProducto lstProductosVendidos;
    public:
        Venta(){
        }
        Venta(int nf, Cliente c){
            this->noFactura = nf;
            this->cliente = c;
        }
        void setNumeroFactura(int n){
            this->noFactura = n;
        }
        int getNumeroFactura(){
            return this->noFactura;
        }
        void setCliente(Cliente c){
            this->cliente = c;
        }
        Cliente getCliente(){
            return this->cliente;
        }
        void addLstProducto(Producto p){
            this->lstProductosVendidos.Insertar(p);
        }
        ListaProducto getLstProducto(){
            return this->lstProductosVendidos;
        }

};

#endif // VENTA_H_INCLUDED
