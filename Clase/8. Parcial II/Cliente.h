#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente{
private:
    string idCliente;
    string Nombre;
    string Apellido;
public:
    Cliente(){
    }
    Cliente(string idc, string n, string a){
        this->idCliente = idc;
        this->Nombre = n;
        this->Apellido = a;
    }
    void setIdCliente(string idc){
        this->idCliente = idc;
    }
    string getIdCliente(){
        return this->idCliente;
    }
    void setNombre(string idc){
        this->Nombre = idc;
    }
    string getNombre(){
        return this->Nombre;
    }
    void setApellido(string idc){
        this->Apellido = idc;
    }
    string getApellido(){
        return this->Apellido;
    }
};

#endif // CLIENTE_H_INCLUDED
