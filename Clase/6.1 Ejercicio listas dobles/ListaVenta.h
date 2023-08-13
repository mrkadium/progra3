#ifndef LISTAVENTA_H_INCLUDED
#define LISTAVENTA_H_INCLUDED
#include "NodoVenta.h"

class ListaVenta{
    private:
        NodoVenta *elemento;
        bool ListaVacia(){
            return (this->elemento == NULL);
        }
    public:
        ListaVenta(){
            this->elemento = NULL;
        }
        ~ListaVenta(){
        }
        void Anterior(){
            if (this->elemento)
                this->elemento = this->elemento->Anterior;
        }
        void Siguiente(){
            if (this->elemento)
                this->elemento = this->elemento->Siguiente;
        }
        void Primero(){
            if (!this->ListaVacia()){
                while (this->elemento->Anterior){
                    this->Anterior();
                }
            }
        }
        void Ultimo(){
            if (!this->ListaVacia()){
                while (this->elemento->Siguiente){
                    this->Siguiente();
                }
            }
        }
        void Insertar(Venta v){
            NodoVenta *nuevo = new NodoVenta(v);
            if(this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                this->elemento->Siguiente = nuevo;
                nuevo->Anterior = this->elemento;
            }
        }
        void Mostrar(){
            NodoVenta *tmp;
            this->Ultimo();
            tmp = this->elemento;
            while(tmp){
                cout << "--------------------------------------------------------------------" << endl;
                cout << "No de factura: " << tmp->Valor.getNumeroFactura()<< endl;
                cout << "Cliente: " << tmp->Valor.getCliente().getNombre() << " " << tmp->Valor.getCliente().getApellido() << endl;
                cout << "Productos comprados: " << endl;
                tmp->Valor.getLstProducto().MostrarComprados();
                cout << "--------------------------------------------------------------------" << endl;
                tmp = tmp->Anterior;
            }
            cout << "NULL" << endl;
        }

        Venta Buscar(int i){
            Venta r;
            bool encontrado = false;
            NodoVenta *tmp = this->elemento;
            while(tmp && !encontrado){
                if(tmp->Valor.getNumeroFactura() == i){
                    encontrado = true;
                    r = tmp->Valor;
                }else{
                    tmp = tmp->Anterior;
                }
            }
            return r;
        }
        /*void eliminar(int i){
            ///TAREA
        }*/

};

#endif // LISTAVENTA_H_INCLUDED
