#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
#include "Autor.h"
#include <list>

class Libro{
private:
    int idLibro;
    string Titulo;
    string Editorial;
    string Anio;
    list<Autor*> autor;
public:
    Libro(){
    }
    Libro(int id, string t, string e, string a, list<Autor*> aut){
        this->idLibro = id;
        this->Titulo = t;
        this->Editorial = e;
        this->Anio = a;
        this->autor = aut;
    }
    int getIdLibro(){
        return this->idLibro;
    }
    string getTitulo(){
        return this->Titulo;
    }
    string getEditorial(){
        return this->Editorial;
    }
    string getAnio(){
        return this->Anio;
    }
    list<Autor*> getAutor(){
        return this->autor;
    }
};

#endif // LIBRO_H_INCLUDED
