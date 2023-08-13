#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Cliente.h"
#include "Producto.h"
#include "Lista.h"

class Venta : public Objeto{
    private:
        int noFactura;
        Cliente *cliente;
        Lista *lstProductosVendidos;
    public:
        Venta(){
        }
        Venta(int nf, Cliente *c){
            this->noFactura = nf;
            this->cliente = c;
        }
        void setNumeroFactura(int n){
            this->noFactura = n;
        }
        int getNumeroFactura(){
            return this->noFactura;
        }
        void setCliente(Cliente *c){
            this->cliente = c;
        }
        Cliente *getCliente(){
            return this->cliente;
        }
        void addLstProducto(Producto *p){
            this->lstProductosVendidos.Insertar(p);
        }
        /*Lista *getLstProducto(){
            return this->lstProductosVendidos;
        }*/
        int getTipoProducto(){
            return 3;
        }
};

#endif // VENTA_H_INCLUDED
