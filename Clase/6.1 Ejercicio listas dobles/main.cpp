#include <iostream>
using namespace std;
#include "string"
#include <string>
#include "ListaCliente.h"
#include "ListaProducto.h"
#include "ListaVenta.h"
#include <stdlib.h>


int menu(){
    int op;
    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Agregar cliente" << endl;
    cout << "3. Registrar venta" << endl;
    cout << "4. Ver lista de productos" << endl;
    cout << "5. Ver lista de clientes" << endl;
    cout << "6. Ver lista de ventas" << endl;
    cout << "7. Eliminar cliente" << endl;
    cout << "8. Eliminar producto" << endl;
    cout << "9. Ver factura" << endl;
    cout << "10. Salir" << endl << endl;
    cout << "Digite la opcion: ";
    cin >> op;

    return op;
}

void agregarProducto(ListaProducto *lst){
    /* char cadena[80] = "This is an example";
    string str(cadena);

    str = cadena;
    */
    int id;
    char nombre[80];
    string n;
    float e;
    cout << "Digite el ID del producto: ";
    cin >> id;
    cout << "Digite el nombre del producto: ";
    cin.get();
    cin.getline(nombre, 80);
    n = nombre;
    cout << "Digite la existencia: ";
    cin >> e;
    Producto p(id, n);
    p.setExistencia(e);
    lst->Insertar(p);
    cout << "Agregado con exito :)" << endl;
}

void agregarCliente(ListaCliente *lst){
    int id;
    string n, a;
    cout << "Digite el ID del cliente: ";
    cin >> id;
    Cliente c(id, "", "");
    if(lst->Buscar(id).getIdCliente() != id){
        cout << "Digite el nombre del cliente: ";
        cin >> n;
        cout << "Digite el apellido del cliente: ";
        cin >> a;
        c = Cliente(id, n, a);
        lst->Insertar(c);
        cout << "Agregado con exito :)" << endl;
    }else{
        cout << "Ese ID de cliente ya existe" << endl;
    }
}

void registrarVenta(ListaVenta *lst, ListaProducto *lstp, ListaCliente *lstc){
    //buscar al cliente, agregar productos a la lista de productos de la venta, quitar la existencia
    Producto aux; //para usar la cantidad de productos comprados en lugar de existencia
    Cliente auxc; //si se elimina el cliente, aun quedará en el registro
    int id, idaux, idp, nf, idcliaux;
    char op;
    float existencia, eaux, c;
    string n, naux, a, nombreaux, apeaux;
    cout << "Digite el ID del cliente que compra: ";
    cin >> id;
    if(lstc->Buscar(id).getIdCliente() == id){ //si coinciden, el cliente existe
        Cliente cli = lstc->Buscar(id);
        cout << "Digite el numero de factura: ";
        cin >> nf;
        if(lst->Buscar(id).getNumeroFactura() != nf){ //si no coinciden, la factura no existe y se puede crear
            system("cls");
            idcliaux = lstc->Buscar(id).getIdCliente();
            nombreaux = lstc->Buscar(id).getNombre();
            apeaux = lstc->Buscar(id).getApellido();
            auxc = Cliente(idcliaux, nombreaux, apeaux);
            Venta v(nf, auxc);
            lstp->Mostrar();
            do{
                cout << "Digite el ID del producto que desea comprar: ";
                cin >> idp;
                cout << "Digite la cantidad de productos: ";
                cin >> c;
                if(lstp->Buscar(idp).getIdProducto() == idp){ //si coinciden, el producto existe
                    idaux = lstp->Buscar(idp).getIdProducto();
                    naux = lstp->Buscar(idp).getNombreProducto();
                    aux = Producto(idaux, naux);
                    aux.setExistencia(c);
                    v.addLstProducto(aux);
            ///NO ME RESTA LA COMPRA A LA EXISTENCIA O NO ASIGNA LA EXISTENCIA AL PRODUCTO
                    eaux = lstp->Buscar(idp).getExistencia();
                    existencia = eaux - c; //restar a la existencia lo que se compra
                    lstp->Buscar(idp).setExistencia(existencia); //asignándole a la existencia en la lista el valor de float existencia
            ///---------------------------------------------------------------------------
                }else{
                    cout << "No se encontró el producto :(" << endl;
                }
                cout << "Desea agregar otro producto?(s/n): ";
                cin >> op;
                system("cls");
            }while(op == 's' || op == 'S');
            lst->Insertar(v);//ingresa la venta a la ListaVenta
            cout << "Compra existosa :)" << endl;
        }else{
            cout << "No se pudo efectuar la compra, verifique que los datos sean correctos :(" << endl;
        }
    }else{
        cout << "No se encontró el cliente :(" << endl;
    }
    cin.get();
}

void mostrarFactura(ListaVenta *lst){
    int nf;
    cout << "Digite el numero de la factura: ";
    cin >> nf;
    if(lst->Buscar(nf).getNumeroFactura() == nf){
        cout << "\n\nFactura No. " << nf << endl;
        cout << "\tID: " << lst->Buscar(nf).getCliente().getIdCliente() << endl;
        cout << "\tNombre: " << lst->Buscar(nf).getCliente().getNombre() << " " << lst->Buscar(nf).getCliente().getApellido() << endl;
        lst->Buscar(nf).getLstProducto().MostrarComprados();
    }else{
        cout << "No existe esa factura :(" << endl;
    }
}

void eliminarCliente(ListaCliente *lst){
    int id;
    cout << "Digite el ID del cliente que desea eliminar: ";
    cin >> id;
    if(lst->Buscar(id).getIdCliente() == id){
        lst->Eliminar(id);
        cout << "Eliminado exitosamente :)" << endl;
    }else{
        cout << "No se encontro el cliente :(" << endl;
    }
}

void eliminarProducto(ListaProducto *lst){
    int id;
    cout << "Digite el ID del producto que desea eliminar: ";
    cin >> id;
    if(lst->Buscar(id).getIdProducto() == id){
        lst->Eliminar(id);
        cout << "Eliminado exitosamente :)" << endl;
    }else{
        cout << "No se encontro el cliente :(" << endl;
    }
}

int main(){
    /*
    Tareas:
    -Desarrolar ejercicio con super nodo y super lista (no puede ser escalar, tienen que ser punteros los objetos)
    - :) Desarrolar ejercico con listas y nodos independientes
    -Desarrolar ejercicio con super nodo y super lista sobrecargando el metodo insertar(insertar principio, en medio y al final) (no puede ser escalar, tienen que ser punteros los objetos)
    */
    int opc;
    ListaProducto lstProducto;
    ListaCliente lstCliente;
    ListaVenta lstVenta;
    do{
        system("cls");
        opc = menu();
        system("cls");
        switch(opc){
            case 1: ///Agregar producto
                agregarProducto(&lstProducto);
            break;
            case 2: ///Agregar cliente
                agregarCliente(&lstCliente);
            break;
            case 3: ///Registrar venta
                registrarVenta(&lstVenta, &lstProducto, &lstCliente);
            break;
            case 4: ///Ver lista de productos
                lstProducto.Mostrar();
            break;
            case 5: ///Ver lista de clientes
                lstCliente.Mostrar();
            break;
            case 6: ///Ver registro de ventas (todas)
                lstVenta.Mostrar();
            break;
            case 7: ///Eliminar cliente
                eliminarCliente(&lstCliente);
            break;
            case 8: ///Eliminar producto
                eliminarProducto(&lstProducto);
            break;
            case 9: ///Ver factura de venta (específica)
                mostrarFactura(&lstVenta);
            break;
            case 10:
                cout << "Saliendo..." << endl;
            break;
        }
        system("pause");
        cin.get();
    }while(opc != 10);

    return 0;
}
