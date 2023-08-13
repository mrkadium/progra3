#ifndef INGRESADO_H_INCLUDED
#define INGRESADO_H_INCLUDED
using namespace std;
#include <string.h>
#include <string>

class Ingresado{
private:
    string nombre;
    string razon;
    int codigo;
public:
    Ingresado(string n, string r, int c){
        this->nombre = n;
        this->razon = r;
        this->codigo = c;
    }
    string getNombre(){
    return this->nombre;}
    string getRazon(){
    return this->razon;}
    void setCodigo(int c){
    this->codigo = c;}
    int getCodigo(){
    return this->codigo;}
};

#endif // INGRESADO_H_INCLUDED
