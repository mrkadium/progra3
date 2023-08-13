#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Contacto.h"
class Nodo
{
private:
Contacto variable;
Nodo *Siguiente;

public:
Nodo(Contacto valor, Nodo *Sig=NULL) {
this->variable = valor;
this->Siguiente = Sig;
}

Contacto getVariable(){
return this->variable;
}

void setVariable(Contacto SetVariable){
this->variable = SetVariable;
}

virtual ~Nodo() {}
friend class Lista;

};typedef Nodo *pNodo;

#endif // NODO_H_INCLUDED
