///Mario Adalberto Rivera Olivo
///Código: RO16-I04-001
///Grupo: 07

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Lista.h"

void insercion();
void buscar();
void eliminar();
Lista lst;
Paciente pa = Paciente(0,"","","","");
int c;
string n;
string a;
string d;
string t;
int main(){

    int opcion;
    do{
    system("cls");
    cout << "*********** PACIENTES **********" << endl << endl;
    cout << "\t1. Insertar"<< endl;
    cout << "\t2. Buscar" << endl;
    cout << "\t3. Mostrar lista" << endl;
    cout << "\t4. Eliminar" << endl;
    cout << "\t5. Salir" << endl;
    cout << "\tDigita una opcion: ";
    cin >> opcion;
    system("cls");

    switch(opcion){
        case 1:
            insercion();
        break;
        case 2:
            buscar();
        break;
        case 3:
            lst.Mostrar();
        break;
        case 4:
            eliminar();
        break;
        case 5:
            cout << "Saliendo..." << endl;
        break;
        default:
            cout << "Opcion no valida"<<endl;
        break;
    }
    system("pause");

    }while(opcion!=5);
    return 0;
}

void insercion(){
    cout << "Digite el codigo del paciente (en numero entero): ";
    cin >> c;
    pa = Paciente(c, "", "", "", "");
    if(lst.Buscar(pa) == NULL){
        cout << "Digite el nombre del paciente: ";
        cin >> n;
        cout << "Digite el apellido del paciente: ";
        cin >> a;
        cout << "Digite el departamento del paciente: ";
        cin >> d;
        cout << "Digite el telefono del paciente: ";
        cin >> t;
        pa = Paciente(c,n,a,d,t);
        lst.Insertar(pa);
        cout << "Insertado correctamente :)" << endl;
    }else{
        cout << "Ese codigo de paciente ya existe" << endl;
    }
}

void buscar(){
   cout << "Digite codigo del paciente: ";
   cin>>c;
   pa = Paciente(c,"","","","");
   if(lst.Buscar(pa)!= NULL){
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "--------------------------- DATOS DEL PACIENTE ------------------------" << endl;
        cout << "\tCodigo del paciente: " << lst.Buscar(pa)->getVariable().getCodigo() << endl;
        cout << "\tNombre del paciente: " << lst.Buscar(pa)->getVariable().getNombre() << endl;
        cout << "\tApellido: " << lst.Buscar(pa)->getVariable().getApellido() << endl;
        cout << "\tDepartamento: " << lst.Buscar(pa)->getVariable().getDepartamento() << endl;
        cout << "\tTelefono: " << lst.Buscar(pa)->getVariable().getTelefono() << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }else{
        cout << "No se encontro al paciente..." << endl;
}


}

void eliminar(){
    cout << "Digite codigo del paciente: ";
    cin >> c;
    pa = Paciente(c,"","","","");
    if(lst.Eliminar(pa)){
        cout << "Eliminado con exito" << endl;
    }
    else{
        cout << "No se pudo eliminar" << endl;
    }
}
