///Mario Adalberto Rivera Olivo
///Código: R016-I04-001
///Grupo: 07

#include <iostream>
#include "ArbolBinario.h"
#include <stdlib.h>
using namespace std;

int Menu();
void insertarValor(ArbolABB *arbol);
void eliminarValor(ArbolABB *arbol);
void mostrarArbol(ArbolABB *arbol);


int main()
{
    ArbolABB arbol;
    int op;
    do{
        system("cls");
        op = Menu();
        system("cls");
        switch(op){
            case 1: ///Insertar valor
                insertarValor(&arbol);
            break;
            case 2: ///Eliminar valor
                eliminarValor(&arbol);
            break;
            case 3: ///Mostrar árbol
                mostrarArbol(&arbol);
                cout << endl;
            break;
            case 4: ///Salir
                cout << "Saliendo..." << endl << endl;
            break;
            default:
                cout << "Opcion no valida :(" << endl;
            break;
        }
        system("pause");
    }while(op != 4);

    return 0;
}
int Menu(){
    int op;
    cout << "Arboles binarios de busqueda" << endl << endl;
    cout << "1. Insertar valor" << endl;
    cout << "2. Eliminar valor" << endl;
    cout << "3. Mostrar arbol" << endl;
    cout << "4. Salir" << endl << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}
void insertarValor(ArbolABB *arbol){
    int v;
    cout << "Digite el valor: ";
    cin >> v;
    arbol->Insertar(v);
    cout << "\nInsertado correctamente :)" << endl;
}
void eliminarValor(ArbolABB *arbol){
    int v;
    cout << "Digite el valor: ";
    cin >> v;
    arbol->Borrar(v);
    cout << "\nEliminado correctamente :)" << endl;
}
void mostrarArbol(ArbolABB *arbol){
    if(arbol->getRaiz() == NULL){
        cout << "No hay valores en el arbol :(" << endl;
    }else{
        cout << "Pre-orden: ";
        arbol->PreOrden(Mostrar);
        cout << endl;
        cout << "In-orden: ";
        arbol->InOrden(Mostrar);
        cout << endl;
        cout << "Pos-orden: ";
        arbol->PostOrden();
        cout << endl << endl;
        cout << "Altura: " << arbol->AlturaArbol() << endl;
        cout << "Numero de nodos: " << arbol->NumeroNodos() << endl;
        cout << endl;
        arbol->mostrarPosFibonazi();
//        cout << arbol->iz() << endl;
//        arbol->espacios();
    }
}
