#include <iostream>
#include "ABB.h"
using namespace std;

int main()
{
    ABB arbolito;
    string n = "Mario Rivera";
    string r = "Espina bifida";
    int c = 2;
    Ingresado *paciente = new Ingresado(n, r, c);
    arbolito.Insertar(paciente);

    n = "Hazel Grace";
    r = "Cancer de pulmon";
    c = 1;
    paciente = new Ingresado(n, r, c);
    arbolito.Insertar(paciente);

    n = "Augustus Waters";
    r = "Cancer de pierna";
    c = 3;
    paciente = new Ingresado(n, r, c);
    arbolito.Insertar(paciente);

    arbolito.InOrden();

    return 0;
}
