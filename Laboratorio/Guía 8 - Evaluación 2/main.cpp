///Mario Adalberto Rivera Olivo
///Código: R016-I04-001
///Grupo: 07
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Prestamo.h"

int menu(){
    int op;
    cout << "\n************************************" << endl;
    cout << "********** BIBLIOTECA USO **********" << endl;
    cout << "************************************" << endl << endl;
    cout << "\t1. Agregar autor" << endl;
    cout << "\t2. Agregar estudiante" << endl;
    cout << "\t3. Agregar libro" << endl;
    cout << "\t4. Agregar prestamo" << endl;
    cout << "\t5. Ver lista de autores" << endl;
    cout << "\t6. Ver lista de estudiantes" << endl;
    cout << "\t7. Ver lista de libros" << endl;
    cout << "\t8. Ver prestamos" << endl;
    cout << "\t9. Salir" << endl << endl;
    cout << "************************************" << endl << endl;
    cout << "Digite la opcion a implementar: ";
    cin >> op;
    return op;
}
Autor *buscarA(list<Autor*> *lst, int id){
    list<Autor*>::iterator pos = lst->begin();
    bool encontrado = false;
    Autor *a = new Autor(0, "", "", "", "");
    while(pos != lst->end() && !encontrado){
        a = *pos;
        if(a->getIdAutor() == id){
            encontrado = true;
            return a;
        }else{
            pos++;
        }
    }
    if(!encontrado){
        return a;
    }
}
Estudiante *buscarE(list<Estudiante*> *lst, int id){
    list<Estudiante*>::iterator pos = lst->begin();
    bool encontrado = false;
    Estudiante *a = new Estudiante(0, "", "", "");
    while(pos != lst->end() && !encontrado){
        a = *pos;
        if(a->getIdEstudiante() == id){
            encontrado = true;
            return a;
        }else{
            pos++;
        }
    }
    if(!encontrado){
        return a;
    }
}
Libro *buscarL(list<Libro*> *lst, int id){
    list<Libro*>::iterator pos = lst->begin();
    bool encontrado = false;
    list<Autor*> lstAA;
    Libro *a = new Libro(0, "", "", "", lstAA);
    while(pos != lst->end() && !encontrado){
        a = *pos;
        if(a->getIdLibro() == id){
            encontrado = true;
            return a;
        }else{
            pos++;
        }
    }
    if(!encontrado){
        return a;
    }
}
Prestamo *buscarP(list<Prestamo*> *lst, int id){
    list<Prestamo*>::iterator pos = lst->begin();
    bool encontrado = false;
    Estudiante e = Estudiante(0, "", "", "");
    list<Libro*> lstLL;
    Fecha *fpres = new Fecha(0, 0, 0);
    Fecha *fdev = new Fecha(0, 0, 0);
    int dpres = 0;
    Prestamo *a = new Prestamo(0, e, lstLL, fpres, dpres, fdev);
    while(pos != lst->end() && !encontrado){
        a = *pos;
        if(a->getId() == id){
            encontrado = true;
            return a;
        }else{
            pos++;
        }
    }
    if(!encontrado){
        return a;
    }
}
void ingresarAutor(list<Autor*> *lst){
    int id;
    string nombre, apellido, fechanac, nacionalidad;
    Autor *a;
    cout << "REGISTRO DE AUTOR" << endl << endl;
    cout << "ID del autor: ";
    cin >> id;
    if(buscarA(lst, id)->getIdAutor() == id){
        cout << "Ese ID ya existe, debe asignar otro :(" << endl;
    }else{
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Fecha de nacimiento: ";
        cin >> fechanac;
        cout << "Nacionalidad: ";
        cin >> nacionalidad;
        a = new Autor(id, nombre, apellido, fechanac, nacionalidad);
        lst->push_back(a);
        cout << "\nIngresado correctamente :)" << endl;
    }
}
void mostrarAutores(list<Autor*> *lst){
    list<Autor*>::iterator pos = lst->begin();
    while(pos != lst->end()){
        Autor *a = *pos;
        cout << "--------------------------------------" << endl;
        cout << "ID: " << a->getIdAutor() << endl;
        cout << "Nombre: " << a->getNombre() << " " << a->getApellido() << endl;
        cout << "Fecha de nacimiento: " << a->getFechaNac() << endl;
        cout << "Nacionalidad: " << a->getNacionalidad() << endl;
        cout << "--------------------------------------" << endl << endl;
        pos++;
    }
}
void ingresarEstudiante(list<Estudiante*> *lst){
    int id;
    string nombre, apellido, carrera;
    Estudiante *e;
    cout << "REGISTRO DE AUTOR" << endl << endl;
    cout << "ID del estudiante: ";
    cin >> id;
    if(buscarE(lst, id)->getIdEstudiante() == id){
        cout << "Ese ID ya existe, debe asignar otro :(" << endl;
    }else{
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Carrera: ";
        cin.get();
        getline(cin, carrera);
        e = new Estudiante(id, nombre, apellido, carrera);
        lst->push_back(e);
        cout << "Ingresado correctamente :)" << endl;
    }
}
void mostrarEstudiantes(list<Estudiante*> *lst){
    list<Estudiante*>::iterator pos = lst->begin();
    while(pos != lst->end()){
        Estudiante *e = *pos;
        cout << "-----------------------------------------------------" << endl;
        cout << "ID: " << e->getIdEstudiante() << endl;
        cout << "Nombre: " << e->getNombre() << " " << e->getApellido() << endl;
        cout << "Carrera: " << e->getCarrera() << endl;
        cout << "-----------------------------------------------------" << endl;
        pos++;
    }
}
void ingresarLibro(list<Libro*> *lstl, list<Autor*> *lsta){
    int id, ida, idAutor, op;
    char opc = 's';
    string titulo, editorial, anio, nombre, apellido, fnac, nacio;
    Libro *l;
    Autor *aut, *aut2;
    list<Autor*> lstAA;
    cout << "Ingrese el ID del libro: ";
    cin >> id;
    if(buscarL(lstl, id)->getIdLibro() == id){
        cout << "Ese ID ya existe, debe asignar otro :(" << endl;
    }else{
        cout << "Nombre del libro: ";
        cin.get();
        getline(cin, titulo);
        cout << "Editorial del libro: ";
        cin >> editorial;
        cout << "Anio de publicacion del libro: ";
        cin >> anio;
        while(opc == 's' || opc == 'S'){
            cout << "Agregar autor(1) o elegir de la lista(2)?: ";
            cin >> op;
            if(op == 1){
                system("cls");
                cout << "ID del autor: ";
                cin >> idAutor;
                if(buscarA(lsta, idAutor)->getIdAutor() == idAutor){
                    cout << "Ese ID ya existe, debe asignar otro :(" << endl;
                }else{
                    cout << "Nombre: ";
                    cin >> nombre;
                    cout << "Apellido: ";
                    cin >> apellido;
                    cout << "Fecha de nacimiento: ";
                    cin >> fnac;
                    cout << "Nacionalidad: ";
                    cin >> nacio;
                    aut2 = new Autor(idAutor, nombre, apellido, fnac, nacio);
                    lstAA.push_back(aut2);
                    lsta->push_back(aut2);
                }
            }else{
                if(op == 2){
                    cout << "Elija el autor: " << endl;
                    mostrarAutores(lsta);
                    cout << "Digite el ID del autor que desea agregar: ";
                    cin >> ida;
                    if(buscarA(lsta, ida)->getIdAutor() == ida){
                        aut = buscarA(lsta, ida);
                        lstAA.push_back(aut);
                    }else{
                        cout << "Ese ID no existe :(" << endl;
                    }
                }else{
                    cout << "Opcion no valida :(" << endl;
                }
            }
            cout << "Desea agregar otro autor del libro? (s/n): ";
            cin >> opc;
            system("cls");
        }
        l = new Libro(id, titulo, editorial, anio, lstAA);
        lstl->push_back(l);
        cout << "Ingresado correctamente :)" << endl << endl;
    }
}
void mostrarLibros(list<Libro*> *lst){
    list<Libro*>::iterator pos = lst->begin();
    while(pos != lst->end()){
        Libro *l = *pos;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "ID: " <<l->getIdLibro() << endl;
        cout << "Titulo: " << l->getTitulo() << endl;
        cout << "Editorial: " << l->getEditorial() << endl;
        cout << "Anio: " << l->getAnio() << endl;
        cout << "Autor/Autores: " << endl;
        //////////////////////////////////////////////////////////////////////////////////////////////
        list<Autor*>::iterator posA = l->getAutor().begin();
        int cont = 0;
        while(posA != l->getAutor().end()){ //mientras que no llegue al final
            if(l->getAutor().size() == 0 || cont == l->getAutor().size()){ //sale (break) del while si no hay autores o si llegó al final
                break;
            }else{
                Autor *a = *posA;
                cout << "\t* " << a->getNombre() << " " << a->getApellido() << endl;
                posA++;
                cont++;
            }
        }
        //////////////////////////////////////////////////////////////////////////////////////////////
        cout << "---------------------------------------------------------------------------" << endl;
        pos++;
    }
}
void ingresarPrestamo(list<Prestamo*> *lstp, list<Libro*> *lstl, list<Estudiante*> *lste){
    char opc = 's';
    bool valida = false;
    int id, diasprestamo, dia, mes, anio, idE, idL, idE2;
    string n, a, c;
    list<Libro*> lstLL;
    Libro *l;
    Fecha *f, *fdev;
    Estudiante *e, e2;
    Prestamo *p;
    cout << "Ingrese el ID del prestamo: ";
    cin >> id;
    if(buscarP(lstp, id)->getId() == id){
        cout << "Ese ID ya existe, debe asignar otro :(" << endl;
    }else{
        cout << "Fecha de prestamo (Ej: 1/2/2017):" << endl;
        cout << "\tDia: ";
        cin >> dia;
        cout << "\tMes: ";
        cin >> mes;
        cout << "\tAnio: ";
        cin >> anio;
        f = new Fecha(dia, mes, anio);
        valida = f->esValida();
        if(!valida){
            cout << "Fecha no valida :(" << endl;
        }else{
            cout << "Ingrese los dias que se extendera el prestamo: ";
            cin >> diasprestamo;
            fdev = f->CalculoFecha(f, diasprestamo);
            mostrarEstudiantes(lste);
            cout << "\nIngrese el ID del estudiante: ";
            cin >> idE;
            if(buscarE(lste, idE)->getIdEstudiante() == idE){
                e = buscarE(lste, idE);
                idE2 = e->getIdEstudiante();
                n = e->getNombre();
                a = e->getApellido();
                c = e->getCarrera();
                e2 = Estudiante(idE2, n, a, c);
                mostrarLibros(lstl);
                while(opc == 's' || opc =='s'){
                    cout << "\nDigite el ID del libro que se prestara: ";
                    cin >> idL;
                    if(buscarL(lstl, idL)->getIdLibro() == idL){
                        l = buscarL(lstl, idL);
                        lstLL.push_back(l);
                    }else{
                        cout << "Ese ID no existe :(" << endl;
                    }
                    cout << "Desea agregar otro libro? (s/n): ";
                    cin >> opc;
                }
                p = new Prestamo(id, e2, lstLL, f, diasprestamo, fdev);
                lstp->push_back(p);
                cout << "Ingresado correctamente :)" << endl;

            }else{
                cout << "El ID no existe :(" << endl;
            }
        }
    }


}
void mostrarPrestamos(list<Prestamo*> *lst){
    list<Prestamo*>::iterator pos = lst->begin();
    while(pos != lst->end()){
        Prestamo *p = *pos;
        p->getDetalles();
        pos++;
    }
}
int main()
{
    list<Autor*> lstAutor;
    list<Estudiante*> lstEstudiante;
    list<Libro*> lstLibro;
    list<Prestamo*> lstPrestamo;
    int opc;
    do{
        system("cls");
        opc = menu();
        system("cls");

        switch(opc){
            case 1:
                ingresarAutor(&lstAutor);
            break;
            case 2:
                ingresarEstudiante(&lstEstudiante);
            break;
            case 3:
                ingresarLibro(&lstLibro, &lstAutor);
            break;
            case 4:
                ingresarPrestamo(&lstPrestamo, &lstLibro, &lstEstudiante);
            break;
            case 5:
                mostrarAutores(&lstAutor);
            break;
            case 6:
                mostrarEstudiantes(&lstEstudiante);
            break;
            case 7:
                mostrarLibros(&lstLibro);
            break;
            case 8:
                mostrarPrestamos(&lstPrestamo);
            break;
            case 9:
                cout << "Que tenga un lindo dia :)\n\nAbandonando programa..." << endl << endl;
            break;
            default:
                cout << "Opcion no valida :(" << endl;
            break;
        }

        system("pause");
    }while(opc != 9);
    return 0;
}
