#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

class Estudiante{
private:
    int idEstudiante;
    string Nombre;
    string Apellido;
    string Carrera;
public:
    Estudiante(){
    }
    Estudiante(int id, string n, string a, string car){
        this->idEstudiante = id;
        this->Nombre = n;
        this->Apellido = a;
        this->Carrera = car;
    }
    int getIdEstudiante(){
        return this->idEstudiante;
    }
    string getNombre(){
        return this->Nombre;
    }
    string getApellido(){
        return this->Apellido;
    }
    string getCarrera(){
        return this->Carrera;
    }
};

#endif // ESTUDIANTE_H_INCLUDED
