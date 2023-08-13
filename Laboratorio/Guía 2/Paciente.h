#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include <string.h>

class Paciente{
private:
    int Codigo;
    string Nombre;
    string Apellido;
    string Departamento;
    string Telefono;

public:
    Paciente(){

    }

    Paciente(int c,string n,string a,string d,string t){
        this->Codigo=c;
        this->Nombre=n;
        this->Apellido=a;
        this->Departamento=d;
        this->Telefono=t;

    }

    int getCodigo(){
        return this->Codigo;
    }

    void setCodigo(int co){
        this->Codigo=co;
    }

    string getNombre(){
        return this->Nombre;
    }

    void setNombre(string no){
        this->Nombre=no;
    }

    string getApellido(){
        return this->Apellido;
    }

    void setApellido(string ap){
        this->Apellido=ap;
    }

    string getDepartamento(){
        return this->Departamento;
    }

    void setDepartamento(string de){
        this->Departamento=de;
    }

    string getTelefono(){
        return this->Telefono;
    }

    void setTelefono(string te){
        this->Telefono=te;
    }
};

#endif // PACIENTE_H_INCLUDED
