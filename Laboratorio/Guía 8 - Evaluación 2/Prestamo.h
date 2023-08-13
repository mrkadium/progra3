#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "Fecha.h"
#include "Libro.h"
#include "Estudiante.h"

class Prestamo{
private:
    int idPrestamo;
    Estudiante est;
    list<Libro*> librosPrestados;
    Fecha *fechaPedido;
    int diasPrestamo;
    Fecha *fechaDevolucion;
public:
    Prestamo(){
    }
    Prestamo(int id, Estudiante e, list<Libro*> l, Fecha *fpres, int diasp, Fecha *fdev){
        this->idPrestamo = id;
        this->est = e;
        this->librosPrestados = l;
        this->fechaPedido = fpres;
        this->diasPrestamo = diasp;
        this->fechaDevolucion = fdev;
    }
    void setId(int id){
        this->idPrestamo = id;
    }
    int getId(){
        return this->idPrestamo;
    }
    void getDetalles(){
        cout << "--------------------------------------------------------" << endl;
        cout << "ID de prestamo: " << idPrestamo << endl;
        cout << "Nombre del estudiante: " << est.getNombre() << " " << est.getApellido() << endl;
        cout << "Fecha de prestamo: " << fechaPedido->getDia() << "/" << fechaPedido->getMes() << "/" << fechaPedido->getAnio() << endl;
        cout << "Fecha de devolucion: " << fechaDevolucion->getDia() << "/" << fechaDevolucion->getMes() << "/" << fechaDevolucion->getAnio() << endl;
        cout << "Libro/libros: " << endl;
        list<Libro*>::iterator pos = librosPrestados.begin();
        while(pos != librosPrestados.end()){
            Libro *l = *pos;
            cout << "\t* " << l->getTitulo() << endl;
            pos++;
        }
        cout << "--------------------------------------------------------" << endl << endl;
    }
};

#endif // PRESTAMO_H_INCLUDED
