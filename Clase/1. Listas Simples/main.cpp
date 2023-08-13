#include <iostream>
using namespace std;
#include "Lista.h"

int main(){
    Lista lst; //asumimos que el puntero primero y último han sido inicializados
    lst.Insertar (7);
    lst.Mostrar();

    lst.Insertar(4);
    lst.Mostrar();

    lst.Insertar(11);
    lst.Mostrar();

    lst.Buscar(11);

    lst.Insertar(346);
    lst.Mostrar();

    lst.Buscar(11);

    return 0;
}
