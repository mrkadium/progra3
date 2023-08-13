#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Objeto.h"
#include "Producto.h"
#include "Cliente.h"

class Lista;

class Venta : public Objeto{
    private:
        int noFactura;
        Cliente *cliente;
        Lista *lstProductosVendidos;
    public:
        Venta(){}
        Venta(int nf, Cliente *c, Lista *lpv){
            this->noFactura = nf;
            this->cliente = c;
            this->lstProductosVendidos = lpv;
        }
        void setNumeroFactura(int nf){
            this->noFactura = nf;
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
        Lista *getLstProductos(){
            return this->lstProductosVendidos;
        }
        int getTipoObjeto(){
            return 3;
        }
};

#endif // VENTA_H_INCLUDED
