///Estudiante: Mario Adalberto Rivera Olivo
///Código: RO16-I04-001
///Grupo: 07

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void buscarMostrar(char letra[], char frase[], int longitud);

int cont = 0;
char frase[80];
char letra[1];
int op;
int longitud;

int main()
{
    do{
        system("cls");
        cout << "********** MENU DE OPCIONES **********" << endl;
        cout << "\t1. Digitar frase" << endl;
        cout << "\t2. Salir" << endl;
        cout << "\tDigite la opcion que desea implementar: ";
        cin >> op;
        system("cls");
        switch(op){
            case 1:
                cin.get(); //para que pida los valores en cin.getline()
                cout << "Digite la frase: ";
                cin.getline(frase, 80);
                cout << "Digite el caracter a buscar: ";
                cin >> letra;
                longitud = strlen(frase);
                system("cls");

                buscarMostrar(letra, frase, longitud);

            break;
            case 2:
                cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opcion no valida" << endl;
            break;
        }
    system("pause");
    }while(op != 2);

    return 0;
}

void buscarMostrar(char letra[], char frase[], int longitud){
    cout << "******** Frase: " << frase << " *****" << endl;
    cout << "******** Longitud de frase: " << longitud << " *****" << endl << endl;
    cout << "******** Caracter a buscar: " << letra << " *****" << endl << endl;
    if(longitud != 0){
        cout << "---------------------------------------------" << endl;
        while(cont <= longitud){
            if(frase[cont] == letra[0]){ //frase en la pos del contador debe ser igual a letra
                cout << "\tCaracter '" << letra << "' en posicion: " << cont + 1 << endl;
            }
            cont++; //pasa a la siguiente pos de la frase
        }
        cout << "---------------------------------------------" << endl;
    }else{
        cout << "No se encontro ese caracter" << endl;
    }
}
