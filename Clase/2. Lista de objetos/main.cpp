#include <iostream>
using namespace std;
#include "Lista.h"
void insertarTrabajador();
void mostrarTrabajadores();

    Lista lstT;
    Trabajador *tra;
int main()
{
    /*Trabajador *tb1 = new Trabajador (1, "Mario", "Rivera", 800);
    Trabajador *tb2 = new Trabajador (2, "Adalberto", "Olivo", 800);

    Lista lst;
    lst.Insertar(tb1);
    lst.Insertar(tb2);
    lst.Insertar(3, "Brandon", "Rivera", 1000);
    lst.Insertar(4, "Geovanny", "Olivo", 1000);

    lst.Mostrar();*/
    int op;

    do{
        system("cls");
        cout << "Trabajadores" << endl;
        cout << "1. Insertar trabajador" << endl;
        cout << "2. Mostrar lista de trabajadores" << endl;
        cout << "3. Salir" << endl;
        cout << "Digite la opción que desea implementar: ";
        cin >> op;

        switch(op){
            case 1:
                insertarTrabajador();
            break;
            case 2:
                mostrarTrabajadores();
            break;
            case 3:
            break;
            default:
                cout << "Comando no aceptado";
            break;
        }
        system("pause");
    }while(op!=3);
    return 0;
}
void insertarTrabajador(){
    string n, a;
    int id;
    float sueldoM;
    cout << "Digite el ID del trabajador: ";
    cin >> id;
    cout << "\nDigite el nombre del trabajador: ";
    cin >> n;
    cout << "\nDigite el apellido del trabajador: ";
    cin >> a;
    cout << "\nDigite el sueldo del trabajador: ";
    cin >> sueldoM;
    tra = new Trabajador(id, n, a, sueldoM);
    lstT.Insertar(tra);

}
void mostrarTrabajadores(){
    lstT.Mostrar();
}
