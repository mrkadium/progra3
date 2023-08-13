#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <time.h>
string dia();
void Menu();
void registroViajes(string);
void registrarConductor();
void buscarConductor(string);
void ingresarViajes();
void mostrarConductor();
void mostrarPlanilla(string);
void modificarConductor();
void eliminarConductor();
bool listaConductores();
void modificarDatosConductor();
string extraerMayusculas(int, string);
bool buscarCodigo(string);
string getCodigo(string);
string sumarNumerosDeCodigo(string);
void menu(){
    int opcion=0;
    do{
        system("cls");
        cout << "Fecha/Hora: " << dia() << endl;
        cout << "**** MENU DE OPCIONES ****" << endl << endl;
        cout << "1. Registrar conductor" << endl;
        cout << "2. Buscar conductor (mostrar informacion)" << endl;
        cout << "3. Modificar conductor" << endl;
        cout << "4. Eliminar conductor" << endl;
        cout << "5. Salir" << endl << endl;
        cout << "Que deseas hacer?: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
            case 1:
                registrarConductor();
            break;
            case 2:
                mostrarConductor();
            break;
            case 3:
                modificarConductor();
            break;
            case 4:
                eliminarConductor();
            break;
            case 5:
                cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opcion no valida :(" << endl;
        }
        system("pause");
    }while(opcion != 5);
}
string sumarNumerosDeCodigo(string codigo){
    int uno, dos, tres;
    //ejemplo de codigo: MARO001
    tres = codigo[codigo.size() - 3] - 48; //primer cero
    dos = codigo[codigo.size() - 2] - 48; //segundo cero
    uno = codigo[codigo.size()-1] - 48; //uno
    uno += 1; //Se suma 1 al ultimo numero (ej: de MARO002 a MARO003)
    if(uno > 9){ //Si se pasa de 9, se deja a 0 y se suma en el segundo (ej: de MARO009 a MARO010)
        uno = uno - 10;
        dos += 1;
    }else{
        if(dos>9){ //Si el segundo numero se pasa de 9, se deja en 0 y se suma al tercero (ej: de MARO099 a MARO100)
            dos = dos - 10;
            tres += 1;
        }
    }
                                        //Siguiendo el ejemplo:
    codigo[codigo.size()-1] = uno + 48; //dos (antes 1)
    codigo[codigo.size()-2] = dos + 48; //segundo 0
    codigo[codigo.size()-3] = tres + 48; //primer 0
    return codigo;
}
string getCodigo(string codigo){
    ifstream leerCodigos;
    leerCodigos.open("CodigoConductores.txt", ios::in);
    string cod;
    while(getline(leerCodigos, cod)){ //hasta que lea todo el documento
        if(codigo[0] == cod[0] && codigo[1] == cod[1] && codigo[2] == cod[2] && codigo[3] == cod[3]){
            codigo = cod;
            ///BUSCAR HASTA EL ULTIMO VALOR QUE SE PAREZCA; EJEMPLO: MARO015
        }
    }
    return codigo;
    leerCodigos.close();
}
bool buscarCodigo(string codigo){
    bool encontrado = false;
    ifstream leerCodigos;
    leerCodigos.open("CodigoConductores.txt", ios::in);
    string cod;
    while(getline(leerCodigos, cod)){ //hasta que lea todo el documento
        if(codigo[0] == cod[0] && codigo[1] == cod[1] && codigo[2] == cod[2] && codigo[3] == cod[3]){
            encontrado = true;
            ///BUSCAR HASTA EL ULTIMO VALOR QUE SE PAREZCA; EJEMPLO: MARO015
        }
    }
    return encontrado;
    leerCodigos.close();
}
string extraerMayusculas(int numeroLetras, string nombre){
    string codigo;
    for(int i=0; i<numeroLetras; i++){
        if(nombre[i] >= 65 && nombre[i] <= 90){
            codigo = codigo + nombre[i];
        }
    }
    return codigo;
}
void registrarConductor(){
    ofstream nombres, codigos; //para escribir en el archivo
    ifstream leerNombres, leerCodigos; //para leer el archivo
    int np, contador = 0, cont = 0;
    char op, codigo[6]; //extraer mayúsculas
    string n, codigo2;

    nombres.open("NombreConductores.txt", ios::out|ios::app);
    codigos.open("CodigoConductores.txt", ios::out|ios::app);
    leerNombres.open("NombreConductores.txt", ios::in);
    leerCodigos.open("CodigoConductores.txt", ios::in);

    if(nombres.is_open() && codigos.is_open() && leerNombres.is_open() && leerCodigos.is_open()){ //verifica si esta abierto el archivo
        do{
            cout << "Ingrese el nombre completo del conductor: ";
            cin.get();
            getline(cin, n);
            cout << "\nEs " << n << " correcto? s/n: ";
            cin>>op;
        }while(op!='s' && op!='S');
        codigo2 = extraerMayusculas(n.size(), n); //Extrayendo mayúsculas del nombre completo

        //////// SUMAR AL CODIGO //////////////
        if(!buscarCodigo(codigo2)){ //Si no hay ninguno parecido
            codigo2 += "001";
            codigos << codigo2 << endl;
        }else{
            //Si hay parecidos
            codigo2 = getCodigo(codigo2); //asigna al codigo el ultimo de la lista
            codigo2 = sumarNumerosDeCodigo(codigo2);
            codigos << codigo2 << endl; //Agregar el codigo al archivo
        }

        nombres << n << endl; //Agregar el nombre al archivo

        cout << "\n------------------------------------------------------------------------" << endl;
        cout << "Nombre del conductor: " << n << endl;
        cout << "Codigo: " << codigo2 << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "\nIngresado correctamente :)" << endl;
    }else{
        cout << "Error, no se pudo abrir el archivo :(" << endl;
    }

    nombres.close();
    codigos.close();
    leerNombres.close();
    leerCodigos.close();
}
bool listaConductores(){
    ifstream leerNombres, leerCodigos;
    bool open = false;
    leerNombres.open("NombreConductores.txt", ios::out|ios::in);
    leerCodigos.open("CodigoConductores.txt", ios::out|ios::in);
    if(leerNombres.is_open() && leerCodigos.is_open()){
        open = true;
        string nom, cod;
        cout << "\n\t**** CONDUCTORES ACTIVOS ****" << endl << endl;
        while(getline(leerNombres, nom) && getline(leerCodigos, cod)){ //mientras que el archivo no se haya leído completo
            cout << "----------------------------------------------------------------" << endl;
            cout << "\tNombre del conductor: " << nom << endl;
            cout << "\tCodigo: " << cod << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << endl;
    }
    leerNombres.close();
    leerCodigos.close();
    return open;
}
void buscarConductor(string cod){
    //int opc;
    string auxcod, nomb;
    bool found = false;
    ifstream leerNombres, leerCodigos; //leerPlanillas, leerViajes
    //leerPlanillas.open("PlanillaConductores.txt", ios::out|ios::in);
    //leerViajes.open("ViajesConductores.txt", ios::out|ios::in);
    leerNombres.open("NombreConductores.txt", ios::out|ios::in);
    leerCodigos.open("CodigoConductores.txt", ios::out|ios::in);

    while(getline(leerCodigos, auxcod) && getline(leerNombres, nomb) && !found){ //mientras que no acabe o que no lo haya encontrado
        if(auxcod == cod){ // en strcmp: 0 = coincide || 1 = no coincide
            found = true;
            system("cls");
            cout << "**** INFORMACION DE CONDUCTOR ****" << endl << endl;
            cout << "CONDUCTOR ENCONTRADO :)" << endl;
            cout << "\tNombre: " << nomb << endl;
            cout << "\tCodigo: " << auxcod << endl << endl;
        }
    }
    if(!found){
        cout << "No se encontro el conductor :(" << endl;
    }

    leerNombres.close();
    leerCodigos.close();
    //leerPlanillas.close();
    //leerViajes.close();
}
void mostrarConductor(){
    string codigo;
    int op;
    if(listaConductores()){
        cout << "Digite el codigo del conductor que desea buscar: ";
        cin >> codigo;
        buscarConductor(codigo);
        cout << "Desea ver:" << endl;
        cout << "1. Registro de viajes \n2. Planilla de pagos" << endl;
        cout << "Ingrese la opcion: ";
        cin >> op;
        if(op == 1){
            registroViajes(codigo);
        }else{
            cout << "planilla" << endl;
        }
    }else{
        cout << "No hay conductores registrados :(" << endl;
    }
}
void ingresarViajes(){
    //PAGARLE $0.09 POR KILÓMETRO, SI HACE MÁS DE 100KM DARLE BONO DE $100, MENOS LOS DESCUENTOS DE AFP, ISSS, RENTA
    //CREAR ARCHIVO PARA VIAJES, PONIENDO CODIGO AL PRINCIPIO, SEGUIDO DE SALIDA, DESTINO, DISTANCIA RECORRIDA

    ///AGREGAR EL DIA DEL VIAJE

    ifstream leerNombres, leerCodigos, leerViajes;
    ofstream viaje;
    string codigo, cd, auxcd, nm, salida, destino;
    char opc = 's', op = 'n';
    int dr;
    bool encontrado = false;
    viaje.open("Viajes.txt", ios::out|ios::app);
    leerNombres.open("NombreConductores.txt", ios::out|ios::in);
    leerCodigos.open("CodigoConductores.txt", ios::out|ios::in);
    leerViajes.open("Viajes.txt", ios::out|ios::in);

    cout << "Ingrese el codigo del conductor: ";
    cin >> codigo;
    if(leerCodigos.is_open() && leerNombres.is_open() && leerViajes.is_open() && viaje.is_open()){ //&& leerPlanilla.is_open() && leerAuxPlanilla.is_open && auxPlanilla.is_open()
        while(!encontrado && getline(leerCodigos, cd) && getline(leerNombres, nm)){ //&& getline(leerPlanilla, auxcd) && getline(leerPlanilla, auxdisss) && getline(leerPlanilla, auxdafp) && getline(leerPlanilla, auxdisr) && getline(leerPlanilla, auxtotalp)
            if(cd == codigo){
                encontrado = true;
                cout << "Conductor: " << nm << endl << endl;
                while(opc == 's' || opc == 'S'){
                    while(op == 'n' || op == 'N'){
                        cout << "Datos del viaje" << endl;
                        cout << "Punto de salida: ";
                        cin >> salida;
                        cout << "Punto de destino: ";
                        cin >> destino;
                        cout << "Distancia recorrida: ";
                        cin >> dr;
                        cout << "\nDatos correctos?(s/n): ";
                        cin >> op;
                    }
                    viaje << codigo << endl << salida << endl << destino << endl << dr << endl;
                    cout << "Ingresado correctamente :)" << endl;
                    cout << "\nDesea agregar otro viaje a este conductor?(s/n): ";
                    cin >> opc;
                }
            }
        }
        if(!encontrado){
            cout << "Ese codigo no existe :(" << endl;
        }
    }else{
        cout << "Error, no se pudo abrir/crear el archivo :(" << endl;
    }

    viaje.close();
    leerNombres.close();
    leerCodigos.close();
    leerViajes.close();

}
void registroViajes(string codigo){
    bool encontrado = false;
    ifstream leerViajes, leerNombres, leerCodigos;
    leerViajes.open("Viajes.txt", ios::in);
    leerNombres.open("NombreConductores.txt", ios::in);
    leerCodigos.open("CodigoConductores.txt", ios::in);
    string cod, nom, codviaje, salida, destino, drecorrida;
    while(getline(leerCodigos, cod) && getline(leerNombres, nom) && !encontrado){
        if(cod == codigo){
            encontrado = true;
            system("cls");
            cout << "Conductor: " << nom << endl;
            cout << "Codigo: " << cod << endl << endl;
            while(getline(leerViajes, codviaje) && getline(leerViajes,salida) && getline(leerViajes, destino) && getline(leerViajes,drecorrida)){
                if(codviaje == cod){
                    cout << "-----------------------------------------" << endl;
                    cout << "Punto de salida: " << salida << endl;
                    cout << "Punto de destino: " << destino << endl;
                    cout << "Distancia recorrida: " << drecorrida << " kilometros" << endl;
                    cout << "-----------------------------------------" << endl;
                }
            }
        }
    }
    if(!encontrado){
        cout << "No existe ese codigo :(" << endl;
    }
}
void mostrarPlanilla(string codigo){
    //float disss, dafp, disr, totalp, auxdisss, auxdafp, auxdisr, auxtotalp;

    //leerPlanilla.open("PlanillaConductores.txt", ios::out|ios::in);
    //auxPlanilla.open("AuxPlanillaConductores.txt", ios::out|ios::app);
    //leerAuxPlanilla.open("AuxPlanillaConductores.txt", ios::out|ios::in);

    //en auxPlantilla ingresar los mismos datos que en plantillaConductores (codigo, descuentoIsss, descuentoAfp, descuentoIsr, totalPagar), pero modificados

    //leerPlannilla.close();
    //auxPlanilla.close();
    //leerAuxPlanilla.close();
}
void modificarConductor(){
    int op;
    cout << "1. Ingresar viajes\n2. Modificar datos de conductor" << endl;
    cout << "Ingrese la opcion: ";
    cin >> op;
    if(op == 1){
        ingresarViajes();
    }else{
        modificarDatosConductor();
    }
}
void eliminarConductor(){
    string codigo;
    cout << "Ingrese el codigo del conductor: ";
    cin >> codigo;
    bool encontrado = false;
    ifstream leerCodigos, leerNombres;
    ofstream auxCodigo, auxNombre;
    auxCodigo.open("AuxCodigoConductores.txt", ios::out|ios::app);
    auxNombre.open("AuxNombreConductores.txt", ios::out|ios::app);
    leerCodigos.open("CodigoConductores.txt", ios::in);
    leerNombres.open("NombreConductores.txt", ios::in);
    ///AL ELIMINAR, AGRGAR AL CONDUCTOR A LISTA DE CONDUCTORES INACTIVOS, PARA PODER MOSTRAR AÚN LOS VIAJES DE ELLOS
    ///HACER UNA FUNCION QUE MUESTRE LOS VIAJES
    string cod, n;
    while(getline(leerCodigos, cod) && getline(leerNombres, n)){ //hasta que lea todo el documento
        if(codigo == cod){
            encontrado = true;
            cout << "Se elimino correctamente :)" << endl;
        }else{
            auxCodigo << cod << endl;
            auxNombre << n << endl;
        }
    }
    if(!encontrado){
        cout << "Ese codigo no existe :(" << endl;
    }
    leerCodigos.close();
    leerNombres.close();
    auxCodigo.close();
    auxNombre.close();
    remove("NombreConductores.txt");
    rename("AuxNombreConductores.txt", "NombreConductores.txt");
    remove("CodigoConductores.txt");
    rename("AuxCodigoConductores.txt", "CodigoConductores.txt");
}
void modificarDatosConductor(){
    ifstream leerNombres, leerCodigos, leerViajes; //leerPlanillas
    ofstream nombres, codigos, viajes, auxnombres, auxcodigos, auxviajes; //planillas
    nombres.open("NombreConductores.txt", ios::out | ios::app);
    codigos.open("CodigoConductores.txt", ios::out | ios::app);
    viajes.open("Viajes.txt", ios::out | ios::app);
    auxnombres.open("auxNombreConductores.txt", ios::out | ios::app);
    auxcodigos.open("auxCodigoConductores.txt", ios::out | ios::app);
    auxviajes.open("auxViajes.txt", ios::out | ios::app);
    //planillas.open("Planillas.txt", ios::out | ios::app);
    //historial.open()  //Simplemente sumarle a los conductores los kilometros recorridos, para que queden guardados por siempre (buscar por nombre o por codigo, hacer if(busqueda == codigo){}else{if(busqueda == nombre){}else{no se encontro}}
    leerNombres.open("NombreConductores.txt", ios::in);
    leerCodigos.open("CodigoConductores.txt", ios::in);
    leerViajes.open("Viajes.txt", ios::in);
    //leerPlanillas.open("Planillas.txt", ios::in);

    string codigo, cod, nom, cod2, sal, des, dr, nuevoNom, nuevoCod;
    char op = 's';
    bool found = false;
    cout << "Ingrese el codigo del conductor: ";
    cin >> codigo;
    while(getline(leerNombres, nom) && getline(leerCodigos, cod)){
        if(cod == codigo){
            found = true;
            cout << "Nombre: " << nom << endl;
            cout << "Codigo: " << cod << endl << endl;
            do{
                cout << "\nIngrese el nuevo nombre: ";
                cin.get();
                getline(cin, nuevoNom);
                cout << "Es " << nuevoNom << " correcto?(s/n): ";
                cin >> op;
            }while(op != 's');
            nuevoCod = extraerMayusculas(nuevoNom.size(), nuevoNom);
            if(!buscarCodigo(nuevoCod)){ //Si no hay ninguno parecido
                nuevoCod += "001";
                auxcodigos << nuevoCod << endl;
            }else{
                //Si hay parecidos
                nuevoCod = getCodigo(nuevoCod); //asigna al codigo el ultimo de la lista
                nuevoCod = sumarNumerosDeCodigo(nuevoCod);
                auxcodigos << nuevoCod << endl; //Agregar el codigo al archivo
            }
            auxnombres << nuevoNom << endl;
            cout << "Modificado correctamente :)" << endl;
            while(getline(leerViajes, cod) && getline(leerViajes, sal) && getline(leerViajes, des) && getline(leerViajes, dr)){
                if(cod == codigo){
                    auxviajes << nuevoCod << endl;
                    auxviajes << sal << endl;
                    auxviajes << des << endl;
                    auxviajes << dr << endl;
                }else{
                    auxviajes << cod << endl;
                    auxviajes << sal << endl;
                    auxviajes << des << endl;
                    auxviajes << dr << endl;
                }
            }
        }else{
            auxnombres << nom << endl;
            auxcodigos << cod << endl;
        }
    }
    if(!found){
        cout << "Ese codigo no existe :(" << endl;
    }

    nombres.close();
    codigos.close();
    viajes.close();
    auxnombres.close();
    auxcodigos.close();
    auxviajes.close();
    leerNombres.close();
    leerCodigos.close();
    leerViajes.close();
    remove("NombreConductores.txt");
    rename("auxNombreConductores.txt", "NombreConductores.txt");
    remove("CodigoConductores.txt");
    rename("auxCodigoConductores.txt", "CodigoConductores.txt");
    remove("Viajes.txt");
    rename("auxViajes.txt", "Viajes.txt");
}
string dia(){
    auto tiempo = chrono::system_clock::now();
    time_t exacto = chrono::system_clock::to_time_t(tiempo);
    string fechaDia = ctime(&exacto);
    ///DIAS
    if(fechaDia[0]=='S' && fechaDia[1]=='u' && fechaDia[2]=='n'){ //Sunday
        fechaDia[0] = 'D';
        fechaDia[1] = 'o';
        fechaDia[2] = 'm';
    }else{
        if(fechaDia[0]=='M' && fechaDia[1]=='o' && fechaDia[2]=='n'){ //Monday
            fechaDia[0] = 'L';
            fechaDia[1] = 'u';
        }else{
            if(fechaDia[0]=='T' && fechaDia[1]=='u' && fechaDia[2]=='e'){ //Tuesday
                fechaDia[0] = 'M';
                fechaDia[1] = 'a';
                fechaDia[2] = 'r';
            }else{
                if(fechaDia[0]=='W' && fechaDia[1]=='e' && fechaDia[2]=='d'){ //Wednesday
                    fechaDia[0] = 'M';
                    fechaDia[1] = 'i';
                    fechaDia[2] = 'e';
                }else{
                    if(fechaDia[0]=='T' && fechaDia[1]=='h' && fechaDia[2]=='u'){//Thursday
                        fechaDia[0] = 'J';
                        fechaDia[1] = 'u';
                        fechaDia[2] = 'e';
                    }else{
                        if(fechaDia[0]=='F' && fechaDia[1]=='r' && fechaDia[2]=='i'){ //Friday
                            fechaDia[0] = 'V';
                            fechaDia[1] = 'i';
                            fechaDia[2] = 'e';
                        }else{
                            if(fechaDia[0]=='S' && fechaDia[1]=='a' && fechaDia[2]=='t'){ //Saturday
                                fechaDia[2] = 'b';
                            }
                        }
                    }
                }
            }
        }
    }
    ///MESES
    if(fechaDia[4]=='J' && fechaDia[5]=='a'){ //January
        fechaDia[4] = 'E';
        fechaDia[5] = 'n';
        fechaDia[6] = 'e';
    }else{
        if(fechaDia[4]=='A' && fechaDia[5]=='p'){//April
            fechaDia[5] = 'b';
        }else{
            if(fechaDia[4]=='A' && fechaDia[5]=='u'){//August
                fechaDia[5] = 'g';
                fechaDia[6] = 'o';
            }else{
                if(fechaDia[4]=='D'){//December
                    fechaDia[5] = 'i';
                }
            }
        }
    }
    return fechaDia;
};
#endif // FUNCIONES_H_INCLUDED
