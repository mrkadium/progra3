#include <iostream>
using namespace std;
#include "Lista.h"

int main()
{
    PersonaNatural *pn = new PersonaNatural(1, "Juan", "Duran");
    pn->setDui("12345");

    PersonaJuridica *pj = new PersonaJuridica(2, "Roberto", "Deportes");
    pj->setNit("54321");

    Lista lst;
    lst.Insertar(pn);
    lst.Insertar(pj);
    lst.Mostrar();


    return 0;
}
