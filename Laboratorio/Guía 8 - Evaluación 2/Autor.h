#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED
#include <list>
class Autor{
private:
    int idAutor;
    string Nombre;
    string Apellido;
    string fechaNac;
    string Nacionalidad;
public:
    Autor(){
    }
    Autor(int id, string n, string a, string f, string nac){
        this->idAutor = id;
        this->Nombre = n;
        this->Apellido = a;
        this->fechaNac = f;
        this->Nacionalidad = nac;
    }
    int getIdAutor(){
        return this->idAutor;
    }
    string getNombre(){
        return this->Nombre;
    }
    string getApellido(){
        return this->Apellido;
    }
    string getFechaNac(){
        return this->fechaNac;
    }
    string getNacionalidad(){
        return this->Nacionalidad;
    }
};

#endif // AUTOR_H_INCLUDED
