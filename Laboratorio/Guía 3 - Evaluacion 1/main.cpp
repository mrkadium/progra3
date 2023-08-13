///Estudiante: Mario Adalberto Rivera Olivo
///Código: RO16-I04-001
///Grupo: 07

#include <iostream>
using namespace std;
#include "stdlib.h"
#include "Lista.h"

Lista lst;
Contacto co = Contacto(0, "", "", "", "", "");
Contacto auxco = Contacto(0, "", "", "", "", "");
int cont = 0;
int id;
int op;
string n;
string a;
string c;
string t;
string em;
int idaux;
string naux, aaux, caux, taux, eaux;

void insertarInicio();
void insertarAntesDe();
void insertarFinal();
void mostrarContacto();
void eliminarContacto();
void modificarContacto();
void buscarMostrar();

int main()
{
    do{
        system("cls");

        cout << "******************** MENU DE OPCIONES ********************" << endl;
        cout << "\t1. Insertar contacto al inicio" << endl;
        cout << "\t2. Insertar antes de otro contacto" << endl;
        cout << "\t3. Insertar contacto al final" << endl;
        cout << "\t4. Busqueda de contactos" << endl;
        cout << "\t5. Eliminar contacto" << endl;
        cout << "\t6. Mostrar todos los contactos" << endl;
        cout << "\t7. Mostrar un contacto especifico" << endl;
        cout << "\t8. Obtener la cantidad de contactos en la lista" << endl;
        cout << "\t9. Modificar contactos" << endl;
        cout << "\t10. Salir" << endl << endl;
        cout << "\tDigite la opcion que desea implementar: ";
        cin >> op;
        system("cls");

        switch(op){
            case 1:
                insertarInicio();
                cont++;
            break;
            case 2:
                insertarAntesDe();
                cont++;
            break;
            case 3:
                insertarFinal();
                cont++;
            break;
            case 4:
                buscarMostrar();
            break;
            case 5:
                eliminarContacto();
                cont = cont - 1;
            break;
            case 6:
                cout << "*************** LISTA DE CONTACTOS ***************" << endl;
                lst.Mostrar();
            break;
            case 7:
                mostrarContacto();
            break;
            case 8:
                cout << "La cantidad de contactos es: " << cont << endl;
            break;
            case 9:
                modificarContacto();
            break;
            case 10:
                cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opcion no valida" << endl;
            break;
        }

        system("pause");
    }while(op != 10);

    return 0;
}

void insertarInicio(){
    cout << "ID del contacto: ";
    cin >> id;
    cout << "Celular del contacto: ";
    cin >> c;
    co = Contacto(id, "", "", c, "", "");
    if(lst.Buscar(co) != NULL){
        cout << "Ese numero ya existe en los contactos" << endl;
    }else{
        cout << "Telefono del contacto: ";
        cin >> t;
        co = Contacto(id, "", "", "", t, "");
        if(lst.Buscar(co) == NULL){
            cout << "Nombre del contacto: ";
            cin >> n;
            cout << "Apellido del contacto: ";
            cin >> a;
            cout << "Email del contacto: ";
            cin >> em;
            co = Contacto(id, n, a, c, t, em);
            lst.InsertarInicio(co);
        }else{
            cout << "Ese numero ya existe en los contactos" << endl;
        }
    }
}

void insertarAntesDe(){
    cout << "Datos del contacto ya existente" << endl;
    cout << "ID de contacto: ";
    cin >> idaux;
    cout << "Nombre de contacto: ";
    cin >> naux;
    cout << "Apellido de contacto: ";
    cin >> aaux;
    cout << "Celular del contacto: ";
    cin >> caux;
    auxco = Contacto(idaux, naux, aaux, caux, "", "");

    if(lst.Buscar(auxco) != NULL){
        taux = lst.Buscar(auxco)->getVariable().getTelefono(); //para extraer los valores restantes de auxco
        eaux = lst.Buscar(auxco)->getVariable().getEmail(); //lo mismo
        auxco = Contacto(idaux, naux, aaux, caux, taux, eaux); //para insertar los valores obtenidos del contacto existente
        cout << "Datos del nuevo contacto" << endl; ///Do while
        cout << "ID del contacto: ";
        cin >> id;
        cout << "Celular del contacto: ";
        cin >> c;
        co = Contacto(id, "", "", c, "", "");
        if(lst.Buscar(co) != NULL){
            cout << "Ese numero ya existe en los contactos" << endl;
        }else{
            cout << "Telefono del contacto: ";
            cin >> t;
            co = Contacto(id, "", "", "", t, "");
            if(lst.Buscar(co) == NULL){
                cout << "Nombre del contacto: ";
                cin >> n;
                cout << "Apellido del contacto: ";
                cin >> a;
                cout << "Email del contacto: ";
                cin >> em;
                co = Contacto(id, n, a, c, t, em);
                lst.InsertarAntes(auxco, co); //lst.InsertarAntes(contacto existente, contacto nuevo)
            }else{
                cout << "Ese numero ya existe en los contactos" << endl;
            }
        }
    }else{
        cout << "No existe ese contacto" << endl;
    }
}

void insertarFinal(){
    cout << "ID del contacto: ";
    cin >> id;
    cout << "Celular del contacto: ";
    cin >> c;
    co = Contacto(id, "", "", c, "", "");
    if(lst.Buscar(co) != NULL){
        cout << "Ese numero ya existe en los contactos" << endl;
    }else{
        cout << "Telefono del contacto: ";
        cin >> t;
        co = Contacto(id, "", "", "", t, "");
        if(lst.Buscar(co) == NULL){
            cout << "Nombre del contacto: ";
            cin >> n;
            cout << "Apellido del contacto: ";
            cin >> a;
            cout << "Email del contacto: ";
            cin >> em;
            co = Contacto(id, n, a, c, t, em);
            lst.Insertar(co);
        }else{
            cout << "Ese numero ya existe en los contactos" << endl;
        }
    }
}

void eliminarContacto(){
    cout << "Digite el ID del contacto: "<<endl;
    cin >> id;
    cout << "Digite celular del contacto: " << endl;
    cin >> c;
    co = Contacto (id, "", "", c, "", "");
    if(lst.Eliminar(co)){
        cout << "Eliminado con exito" << endl;
    }
    else{
        cout << "No se pudo eliminar" << endl;
    }
}

void buscarMostrar(){
    cout << "Digite el nombre del contacto: "<<endl;
    cin >> n;
    lst.buscarMostrar(n);
}

void mostrarContacto(){
   cout << "Digite el ID del contacto: " << endl;
   cin >> id;
   cout << "Digite celular del contacto: " << endl;
   cin >> c;
   co = Contacto (id, "", "", c, "", "");
   if(lst.Buscar(co) != NULL){
        cout << "------------------------------------------------------------------------" << endl;
        cout << "\tNombre: " << lst.Buscar(co)->getVariable().getNombre() << " " << lst.Buscar(co)->getVariable().getApellido() << endl;
        cout << "\tCelular: " << lst.Buscar(co)->getVariable().getCelular() << endl;
        cout << "\tTelefono: " << lst.Buscar(co)->getVariable().getTelefono() << endl;
        cout << "\tE-mail: " << lst.Buscar(co)->getVariable().getEmail() << endl;
        cout << "------------------------------------------------------------------------" << endl;
    }else{
        cout << "No se encontro al contacto..." << endl;
    }
}

void modificarContacto(){
    cout << "Digita el ID del contacto a modificar : "<<endl;
    cin>>id;
    cout << "Digite celular del contacto: " << endl;
    cin >> c;
    co = Contacto (id, "", "", c, "", "");
    if(lst.Buscar(co)!= NULL){
        cout << "Nombre del contacto: ";
        cin >> n;
        cout << "Apellido del contacto: ";
        cin >> a;
        cout << "Celular del contacto: ";
        cin >> c;
        cout << "Telefono del contacto: ";
        cin >> t;
        cout << "Email del contacto: ";
        cin >> em;
        auxco = Contacto(id, n, a, c, t, em);
        lst.modificar(co, auxco);
        cout<<"Modificado con exito"<<endl;
    }else{
        cout<<"No se pudo modificar"<<endl;
    }
}
