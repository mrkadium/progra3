///Mario Adalberto Rivera Olivo
///Codigo: RO16-I04-001
///Grupo: 07
#include <iostream>
#include <list>
using namespace std;
#include "Estudiante.h"
#include "Trabajador.h"
#include <stdlib.h>

Persona *buscar(list<Persona*> *per, string nombre){
    list<Persona*>::iterator pos = per->begin();
    Persona *retorno;
    bool encontrado = false;
    while(pos != per->end() && !encontrado){
        Persona *p = *pos;
        if(p->getNombre() == nombre){
            encontrado = true;
            retorno = p;
        }else{
            pos++;
        }
    }
    return retorno;
}

void buscarPersona(list<Persona*> *per){
    string nomb;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nomb;
    if(buscar(per, nomb)->getNombre() == nomb){
        cout << "\nLa persona se encontro :)" << endl << endl;
        if(buscar(per, nomb)->getTipoPersona() == "Estudiante"){
            Estudiante *est = static_cast<Estudiante*>(buscar(per, nomb));
            cout << "\nNombre: " << est->getNombre()  << endl;
            cout << "Apellido: " << est->getApellido() << endl;
            cout << "Codigo: " << est->getCodigo() << endl << endl;
        }else{
            Trabajador *est = static_cast<Trabajador*>(buscar(per, nomb));
            cout << "\nNombre: " << est->getNombre()  << endl;
            cout << "Apellido: " << est->getApellido() << endl;
            cout << "Sueldo: " << est->getSueldo() << endl << endl;
        }
    }else{
        cout << "No se encontro a la persona :(" << endl;
    }
}

void insertarPersonaFinal(list<Persona*> *lst){
    int op;
    string nombre, apellido, codigo;
    double sueldo;
    Estudiante *estudent;
    Trabajador *traba;
    cout << "Trabajador(1) o Estudiante(2)?: ";
    cin >> op;
    if(op == 1){
        cout << "Digite el nombre: ";
        cin >> nombre;
        cout << "Digite el apellido: ";
        cin >> apellido;
        cout << "Digite el sueldo: ";
        cin >> sueldo;
        traba = new Trabajador(nombre, apellido, sueldo);
        lst->push_back(traba);
    }else{
        cout << "Digite el nombre: ";
        cin >> nombre;
        cout << "Digite el apellido: ";
        cin >> apellido;
        cout << "Digite el codigo: ";
        cin >> codigo;
        estudent = new Estudiante(nombre, apellido, codigo);
        lst->push_back(estudent);

    }
    cout << "La persona se ingreso :)" << endl;
}

void insertarPersonaInicio(list<Persona*> *lst){
    int op;
    string nombre, apellido, codigo;
    double sueldo;
    Estudiante *estudent;
    Trabajador *traba;
    cout << "Trabajador(1) o Estudiante(2)?: ";
    cin >> op;
    if(op == 1){
        cout << "Digite el nombre: ";
        cin >> nombre;
        cout << "Digite el apellido: ";
        cin >> apellido;
        cout << "Digite el sueldo: ";
        cin >> sueldo;
        traba = new Trabajador(nombre, apellido, sueldo);

        lst->push_front(traba);
    }else{
        cout << "Digite el nombre: ";
        cin >> nombre;
        cout << "Digite el apellido: ";
        cin >> apellido;
        cout << "Digite el codigo: ";
        cin >> codigo;
        estudent = new Estudiante(nombre, apellido, codigo);
        lst->push_front(estudent);
    }
    cout << "La persona se ingreso :)" << endl;
}

void insertarPersonaAntes(list<Persona*> *lst){
    list<Persona*>::iterator pos = lst->begin();
    int op;
    string nombre, apellido, codigo;
    string n;
    cout << "Digite el nombre de la persona que ira despues: ";
    cin >> n;
    double sueldo;
    Estudiante *estudent;
    Trabajador *traba;
    bool encontrado = false;
    while(pos != lst->end() && !encontrado){
        if(buscar(lst, n)->getNombre() == n){
            encontrado = true;
            cout << "Trabajador(1) o Estudiante(2)?: ";
            cin >> op;
            if(op == 1){
                cout << "Digite el nombre: ";
                cin >> nombre;
                cout << "Digite el apellido: ";
                cin >> apellido;
                cout << "Digite el sueldo: ";
                cin >> sueldo;
                traba = new Trabajador(nombre, apellido, sueldo);
                lst->insert(pos, traba);
            }else{
                cout << "Digite el nombre: ";
                cin >> nombre;
                cout << "Digite el apellido: ";
                cin >> apellido;
                cout << "Digite el codigo: ";
                cin >> codigo;
                estudent = new Estudiante(nombre, apellido, codigo);
                lst->insert(pos, estudent);
            }
            cout << "La persona se ingreso :)" << endl;
        }else{
            pos++;
        }
    }
}

void mostrarPersonas(list<Persona*> *per){
    list<Persona*>::iterator pos = per->begin();
    cout << "\n*** LISTA DE PERSONAS ***" << endl << endl;
    while(pos != per->end()){
        Persona *p = *pos;
        if(p->getTipoPersona() == "Estudiante"){
            Estudiante *est = static_cast<Estudiante*>(p);
            cout << "--------------------------" << endl;
            cout << "*** ESTUDIANTE ***" << endl;
            cout << "Nombre: " << est->getNombre() << endl;
            cout << "Apellido: " << est->getApellido() << endl;
            cout << "Codigo: " << est->getCodigo() << endl;
            cout << "--------------------------" << endl << endl;
        }else{
            Trabajador *tra = static_cast<Trabajador*>(p);
            cout << "--------------------------" << endl;
            cout << "*** TRABAJADOR ***" << endl;
            cout << "Nombre: " << tra->getNombre() << endl;
            cout << "Apellido: " << tra->getApellido() << endl;
            cout << "Sueldo: " << tra->getSueldo() << endl;
            cout << "--------------------------" << endl << endl;
        }
        pos++;
    }
}

void eliminar(list<Persona*> *per, string nombre){
    list<Persona*>::iterator pos = per->begin();
    bool encontrado = false;
    while(pos != per->end() && !encontrado){
        Persona *p = *pos;
        if(p->getNombre() == nombre){
            encontrado = true;
            per->remove(p);
        }else{
            pos++;
        }
    }
}

void eliminarPersona(list<Persona*> *per){
    list<Persona*>::iterator pos = per->begin();
    string nombre;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;
    if(buscar(per, nombre)->getNombre() == nombre){
        eliminar(per, nombre);
        cout << "La persona se elimino :)" << endl;
    }else{
        cout << "No se encontro a la persona :(" << endl;
    }
}

void modificarPersona(list<Persona*> *per){
    list<Persona*>::iterator pos = per->begin();
    bool encontrado = false;
    int op;
    string n, nombre, a, apellido, codigo;
    double sueldo;
    Trabajador *traba;
    Estudiante *estudent;
    cout << "Digite los datos de la persona a modificar" << endl;
    cout << "Nombre: ";
    cin >> n;
    cout << "Apellido: ";
    cin >> a;
    while(pos != per->end() && !encontrado){
        Persona *p = *pos;
        if(p->getNombre() == n && p->getApellido() == a){
            encontrado = true;
            cout << "\nDigite los nuevos datos" << endl;
            if(p->getTipoPersona() == "Trabajador"){
                cout << "Digite el nombre: ";
                cin >> nombre;
                cout << "Digite el apellido: ";
                cin >> apellido;
                cout << "Digite el sueldo: ";
                cin >> sueldo;
                traba = new Trabajador(nombre, apellido, sueldo);
                per->insert(pos, traba);
                per->remove(p);
            }else{
                cout << "Digite el nombre: ";
                cin >> nombre;
                cout << "Digite el apellido: ";
                cin >> apellido;
                cout << "Digite el codigo: ";
                cin >> codigo;
                estudent = new Estudiante(nombre, apellido, codigo);
                per->insert(pos, estudent);
                per->remove(p);
            }
            cout << "La persona se modifico :)" << endl;
        }else{
            pos++;
        }
    }
}

int main(){
    list<Persona*> per;
    int op;
    do{
        system("cls");
        cout << "\n\t***** MENU DE OPCIONES *****" << endl << endl;
        cout << "\t1. Ingresar persona al inicio de la lista" << endl;
        cout << "\t2. Ingresar persona al final de la lista" << endl;
        cout << "\t3. Ingresar persona antes de otra" << endl;
        cout << "\t4. Mostrar lista de personas" << endl;
        cout << "\t5. Buscar persona" << endl;
        cout << "\t6. Eliminar persona" << endl;
        cout << "\t7. Modificar persona" << endl;
        cout << "\t8. Salir" << endl << endl;
        cout << "Digite la opcion que desea implementar: ";
        cin >> op;
        system("cls");
        switch(op){
            case 1:
                insertarPersonaInicio(&per);
                break;
            case 2:
                insertarPersonaFinal(&per);
                break;
            case 3:
                insertarPersonaAntes(&per);
                break;
            case 4:
                mostrarPersonas(&per);
                break;
            case 5:
                buscarPersona(&per);
                break;
            case 6:
                eliminarPersona(&per);
                break;
            case 7:
                modificarPersona(&per);
                break;
            case 8:
                cout << "Saliendo..." << endl;
                break;
        }
        system("pause");
    }while(op != 8);


    return 0;
}
