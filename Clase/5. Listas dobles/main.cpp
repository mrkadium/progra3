#include <iostream>
using namespace std;
#include "Lista.h"

void Buscar(int v);
void Eliminar(int v);

Lista lst;

int main()
{
    cout << "Mostrando: " << endl;
    //lst.InsertarInicio(9);
    lst.Insertar(4);
    lst.Mostrar();
    cout << endl;

    cout << "Buscando: " << endl;
    Buscar(9);
    cout << endl;

    cout << "Modificando: " << endl;
    lst.Modificar(4, 5);
    lst.Mostrar();
    cout << endl;

    cout << "Eliminando: " << endl;
    Eliminar(9);
    lst.Mostrar();
    cout << endl;

    return 0;
}

void Buscar(int v){
    if(lst.Buscar(v) != NULL){
        cout << "Encontrado: " << lst.Buscar(v)->getValor() << endl;
    }else{
        cout << "No se encontro el valor" << endl;
    }
}

void Eliminar(int v){
    if(lst.Buscar(v) != NULL){
        lst.Eliminar(v);
        cout << "Elemento eliminado" << endl;
    }else{
        cout << "No se encontro el elemento" << endl;
    }
}
