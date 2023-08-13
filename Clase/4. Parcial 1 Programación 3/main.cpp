///Mario Adalberto Rivera Olivo
///Grupo 07
///Catedrático: Iván Alvarado

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Cuenta.h"

Cliente *cli;
ClientePersonaJuridica *clij;
ClientePersonaNatural *clin;
Cuenta *cu;
Lista lstC;
int main()
{
    int op;
    int id;
    string no, ape, doc, tp;

    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Agregar clientes" << endl
    cout << "2. Agregar cuentas" << endl;
    cout << "3. Hacer abonos" << endl;
    cout << "4. Ver lista de clientes" << endl;
    cout << "5. Ver lista de cuentas" << endl;
    cout << "6. Ver detalles de la cuenta" << endl;
    cout << "7. Salir" << endl << endl;
    cout << "Digite la opcion que desea implementar: ";
    cin >> op;

    do{
        system("cls");
        switch(op){
            case 1:
                cout << "INGRESAR CLIENTE" << endl;
                cout << "1.Persona juridica \n2.Persona natural";
                cin >> tp;
                cout << "Digite el ID del cliente: ";
                cin >> id;
                cout << "\nDigite el nombre del cliente: ";
                cin >> no;
                cout << "\nDigite el apellido del cliente: ";
                cin >> ape;
                if(tp == 1){
                    cout << "Digite el numero de NIT: ";
                    cin >> doc;
                    clij = new ClientePersonaJuridica(id, no, ape);
                    clij.setDocumento(doc);
                    lstC.Insertar(clij);
                }else{
                    cout << "Digite el numero de DUI: ";
                    cin >> doc;
                    clin = new ClientePersonaNatural(id, no, ape);
                    clin.setDocumento(doc);
                    lstC.Insertar(clin);
                }
                cout << "Cliente ingresado correctamente :)";

            break;
            case 2:
                int auxid, tp;
                cout << "INGRESAR CUENTA" << endl;
                cout << "1.Persona juridica \n2.Persona natural";
                cin >> tp;
                if(tp = 1){
                    cout << "Digite el ID de cliente";
                    cin >> auxid;
                        if(clij.getId() == auxid){
                            int nc;
                            cout << "Ingrese el numero de cuenta: ";
                            cin >> nc;
                            cu = new Cuenta(nc);
                            cu.setCliente(clij);
                        }else{cout << "No existe ese ID de cliente";}
                }else{
                    cout << "Digite el ID de cliente";
                    cin >> auxid;
                        if(clin.getId() == auxid){
                            int nc;
                            cout << "Ingrese el numero de cuenta: ";
                            cin >> nc;
                            cu = new Cuenta(nc);
                            cu.setCliente(clin);
                        }else{cout << "No existe ese ID de cliente";}
                }
                cout << "Cuenta agragada exitosamente :)";

            break;
            case 3:
                cout << "HACER ABONOS" << endl;
            break;
            case 4:
                cout <<"VER LISTA DE CLIENTES";
                lstC.Mostrar();
            break;
            case 5:
                cout <<"VER LISTA DE CUENTAS";
            break;
            case 6:
                cout << "VER DETALLES DE CUENTA"
            break;
            case 7:
                cout << "Saliendo..."
            break;
        }
        system("pause");
    }while(op!=7);

    return 0;
}
