///Mario Adalberto Rivera Olivo
///Código: RO16-I04-001
///Grupo: 07A

#include <iostream>
using namespace std;
#include "ListaDoble.h"
#include "stdlib.h"

void insertarValor();
void insertarValorInicio();
//void insertarValorAntes();
void mostrarValor();
void buscarValor();
void modificarValor();
void eliminarValor();

ListaDoble lst;
int num;
int op;

int main()
{
    do{
        system("cls");

        cout << "LISTAS DOBLES" << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "XXXXXXXXXXXXXX          2. Insertar antes de otro elemento" << endl;
        cout << "3. Insertar al final" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Buscar" << endl;
        cout << "6. Modificar" << endl;
        cout << "7. Eliminar" << endl;
        cout << "8. Salir" << endl << endl;
        cout << "Digite la opcion: ";
        cin >> op;

        system("cls");

        switch(op){
            case 1:
                insertarValorInicio();
            break;
            case 2:
                //insertarValorAntes();
            break;
            case 3:
                insertarValor();
            break;
            case 4:
                mostrarValor();
            break;
            case 5:
                buscarValor();
            break;
            case 6:
                modificarValor();
            break;
            case 7:
                eliminarValor();
            break;
            case 8:
                cout << "Saliendo..." << endl << endl;
            break;
            default:
                cout << "Opcion no valida" << endl;
            break;
        }

        system("pause");
    }while(op != 8);

    return 0;
}

void insertarValor(){
    cout << "Digite el numero: ";
    cin >> num;
    lst.Insertar(num);
    cout << "Insertado :)" << endl;
}

void insertarValorInicio(){
    cout << "Digite el numero: ";
    cin >> num;
    lst.InsertarInicio(num);
    cout << "Insertado :)" << endl;
}

/*void insertarValorAntes(){
    cout << "Digite el numero que ira despues: ";
    cin >> num;
    cout << "Digite el nuevo numero: ";
    cin >> op;
    lst.insertarAntes(num, op);
    cout << "Insertado :)" << endl;
}*/

void mostrarValor(){
    cout << "1. Orden ascendente" << endl;
    cout << "2. Orden descendente" << endl;
    cout << "Digite el orden: ";
    cin >> op;
    if(op == 1 || op ==2){
        lst.Mostrar(op);
    }
}

void buscarValor(){
    cout << "Digite el numero que desea buscar: ";
    cin >> num;
    if(lst.Buscar(num) != NULL){
        cout << "Elemento encontrado: " << lst.Buscar(num)->getValor() << endl;
    }else{
        cout << "No se encontro el elemento :(" << endl;
    }
}

void modificarValor(){
    cout << "Digite el valor que desea modificar: ";
    cin >> num;
    cout << "Digite el nuevo valor: ";
    cin >> op;
    if(lst.Buscar(num) != NULL){
        lst.Modificar(num, op);
        cout << "Modificado con exito :)" << endl;
    }else{
        cout << "No se encontro el valor :(" << endl;
    }
}

void eliminarValor(){
    cout << "Digite el valor que desea eliminar: ";
    cin >> num;
    if(lst.Buscar(num) != NULL){
        lst.Eliminar(num);
        cout << "Eliminado con exito :)" << endl;
    }else{
        cout << "No se encontro el valor :(" << endl;
    }
}
