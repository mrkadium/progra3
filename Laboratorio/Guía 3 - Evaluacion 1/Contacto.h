#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED

class Contacto{
private:
    int idContacto;
    string nombre;
    string apellido;
    string celular;
    string telefono;
    string email;
public:
    Contacto(){
    }
    Contacto(int id, string n, string a, string cel, string tel, string mail){
        this->idContacto = id;
        this->nombre = n;
        this->apellido = a;
        this->celular = cel;
        this->telefono = tel;
        this->email = mail;
    }
    int getId(){
        return this->idContacto;
    }
    string getNombre(){
        return this->nombre;
    }
    string getApellido(){
        return this->apellido;
    }
    string getCelular(){
        return this->celular;
    }
    string getTelefono(){
        return this->telefono;
    }
    string getEmail(){
        return this->email;
    }
};

#endif // CONTACTO_H_INCLUDED
