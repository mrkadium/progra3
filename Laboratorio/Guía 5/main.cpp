///Mario Adalberto Rivera Olivo
///Código: RO16-I04-001
///Grupo: 07
#include <iostream>
using namespace std;
#include <string.h>
#include "Lista.h"
#include "Cereal.h"
#include "Detergente.h"
#include <stdlib.h>

void insertarProducto(Lista *lst){
    Cereal *c;
    Detergente *d;
    int op;
    string tipo, cat, nombre, fechacad;
    double peso, precio;
    cout << "Elija el tipo de producto que desea ingresar: " << "\n1. Detergente \n2. Cereal" << endl;
    cin >> op;
    system("cls");
    if(op == 1){
        cout << "*** Detergente ***" << endl;
        cout << "Ingrese el precio: ";
        cin >> precio;
        cat = "Detergente";
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el tipo de detergente: ";
        cin >> tipo;
        cout << "Ingrese el peso: ";
        cin >> peso;
        d = new Detergente(precio, cat, nombre, tipo, peso);
        lst->Insertar(d);
        cout << "Ingresado correctamente :)";
    }else{
        if(op == 2){
            cout << "*** Cereal ***" << endl;
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cat = "Cereal";
            cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese la fecha de caducidad (dd-mm-aa): ";
            cin >> fechacad;
            cout << "Ingrese el peso del producto: ";
            cin >> peso;
            c = new Cereal(precio, cat, nombre, fechacad, peso);
            lst->Insertar(c);
            cout << "Ingresado correctamente :)";
        }else{
            cout << "No existe esa categoria :(" << endl;
        }
    }
}
void buscarProducto(Lista *lst){
    string nombre, cat;
    system("cls");
    cout << "Digite el nombre: ";
    cin >> nombre;
    Cereal *c;
    //No pude hacer lst->Buscar(nombre)->getValor().getNombre() :/
    if(lst->Buscar(nombre) != NULL){
        cout << "Encontrado :)" << endl << endl;
        if(lst->Buscar(nombre)->getValor()->getCategoria() == "Cereal"){
            Cereal *cer = static_cast<Cereal*>(lst->Buscar(nombre)->getValor());
            cer->getInfo();
        }else{
            Detergente *cer = static_cast<Detergente*>(lst->Buscar(nombre)->getValor());
            cer->getInfo();
        }
    }else{
        cout << "No se encontro el producto :(" << endl;
    }
}
void eliminarProducto(Lista *lst){
    string nombre, cat;
    system("cls");
    cout << "Digite el nombre: ";
    cin >> nombre;
    //No pude hacer lst->Buscar(nombre)->getValor().getNombre() :/
    if(lst->Buscar(nombre) != NULL){
        lst->Eliminar(nombre);
        cout << "Elemento eliminado :)" << endl;
    }else{
        cout << "No se encontro el producto :(" << endl;
    }
}

int main()
{
    Lista lst;
    Cereal c;
    Detergente d;
    int op;

    do{
        system("cls");
        cout << "1. Ingresar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Eliminar producto" << endl;
        cout << "5. Salir" << endl;
        cout << "Digite la opcion que desea implementar: ";
        cin >> op;
        system("cls");

        switch(op){
        case 1:
            insertarProducto(&lst);
            break;
        case 2:
            cout << "******* LISTA DE PRODUCTOS *******" << endl << endl;
            lst.Mostrar();
            break;
        case 3:
            buscarProducto(&lst);
            break;
        case 4:
            eliminarProducto(&lst);
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        }

        system("pause");
    }while(op != 5);

    return 0;
}
