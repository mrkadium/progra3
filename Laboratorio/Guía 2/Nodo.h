#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Paciente.h"
class Nodo
{
private:
Paciente variable;
Nodo *Siguiente;

public:
Nodo(Paciente valor,Nodo *Sig=NULL) {
this->variable = valor;
this->Siguiente = Sig;
}

Paciente getVariable(){
return this->variable;
}

void setVariable(Paciente SetVariable){
this->variable = SetVariable;
}

virtual ~Nodo() {}
friend class Lista;

};typedef Nodo *pNodo;


#endif // NODO_H_INCLUDED
