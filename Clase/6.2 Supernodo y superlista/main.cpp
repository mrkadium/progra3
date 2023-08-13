#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Lista.h"

int menu(){
    int op;
    cout << "MENU DE OPCIONES" << endl << endl;
    cout << "1. Ingresar producto" << endl;
    cout << "2. Ingresar cliente" << endl;
    cout << "3. Registrar venta" << endl;
    cout << "4. Mostrar productos" << endl;
    cout << "5. Mostrar clientes" << endl;
    cout << "6. Eliminar productos" << endl;
    cout << "7. Eliminar cliente" << endl;
    cout << "8. Mostrar factura" << endl;
    cout << "9. Salir" << endl << endl;
    cout << "Digite la opcion que desea implementar: ";
    cin >> op;
    return op;
}
void ingresarVenta(Lista *lst){ /////////////////  INGRESANDO VENTA  /////////////////////
    char opc = 's';
    int nf, op, id;
    int producto = 1;
    int cliente = 2;
    int venta = 3;
    int idp;
    float cant, exis;
    string nc, ac;
    int idCliente;
    Venta *v, *vingresado;
    Cliente *c;
    Producto *p, *p2;
    Lista *lpc;
    if(lst->buscarNodo(producto) != NULL){ //si hay productos en la lista
        cout << "Ingrese el número de factura: ";
        cin >> nf;
        if(lst->buscarNodo(venta) == NULL){ //si no hay ventas no hay que ver si es el mismo id, ya que podrá ser cualquiera
            if(lst->buscarNodo(cliente) == NULL){ //si no hay clientes, sólo se podrá ingresar
                cout << "ID del cliente: ";
                cin >> idCliente;
                cout << "Nombre del cliente: ";
                cin >> nc;
                cout << "Apellido del cliente: ";
                cin >> ac;
                c = new Cliente(idCliente, nc, ac);
            }else{
                cout << "Elegir cliente(1) o ingresar cliente(2): ";
                cin >> op;
                if(op == 1){
                    system("cls");
                    lst->mostrar(cliente);
                    cout << "Digite el ID del comprador: ";
                    cin >> idCliente;
                    if(lst->buscarObjeto(idCliente, cliente) == NULL){ //si no existe ese cliente
                        cout << "Ese ID no existe :(" << endl;
                    }else{ //existe el cliente
                        c = static_cast<Cliente*>(lst->buscarObjeto(idCliente, cliente)->getValor())
                    }
//                    system("cls");
//                    lst->mostrar(producto);
//                    while(opc == 's' || opc == 'S'){
//                        cout << "Digite el ID del producto: ";
//                        cin >> idp;
//                        if(lst->buscarObjeto(idp, producto) == NULL){
//                            cout << "Ese ID no existe :(";
//                        }else{
//                            p = static_cast<Producto*>(lst->buscarObjeto(idp, producto)->getValor());
//                            lpc->insertarFinal(p);
//                            cout << "Producto ingresado :)" << endl << endl;
//                        }
//                        cout << "Desea agregar otro producto?(s/n): ";
//                        cin >> opc;
                    }
                }else{
                    if(op == 2){
                        cout << "ID del cliente: ";
                        cin >> idCliente;
                        cout << "Nombre del cliente: ";
                        cin >> nc;
                        cout << "Apellido del cliente: ";
                        cin >> ac;
                        c = new Cliente(idCliente, nc, ac);
//                        system("cls");
//                        lst->mostrar(producto);
//                        while(opc == 's' || opc == 'S'){
//                            cout << "Digite el ID del producto: ";
//                            cin >> idp;
//                            if(lst->buscarObjeto(idp, producto) == NULL){
//                                cout << "Ese ID no existe :(";
//                            }else{
//                                p = static_cast<Producto*>(lst->buscarObjeto(idp, producto)->getValor()); //producto en la lista
//                                cout << "Digite la cantidad: ";
//                                cin >> cant;
//                                p2 = new Producto(p->getIdProducto(), p->getNombreProducto(), cant); //producto de la venta
//                                exis = p->getExistencia() - cant;
//                                lst->
//                                p->setExistencia(cant);
//                                lpc->insertarFinal(p2);
//                                cout << "Producto ingresado :)" << endl << endl;
//                            }
//                            cout << "Desea agregar otro producto?(s/n): ";
//                            cin >> opc;
//                        }
                    }else{
                        cout << "Opcion no valida :(" << endl;
                    }
                }
                if(op > 2 || op < 1){
                    system("cls");
                    lst->mostrar(producto);
                    while(opc == 's' || opc == 'S'){
                        cout << "Digite el ID del producto: ";
                        cin >> idp;
                        if(lst->buscarObjeto(idp, producto) == NULL){
                            cout << "Ese ID no existe :(";
                        }else{
                            p = static_cast<Producto*>(lst->buscarObjeto(idp, producto)->getValor()); //producto en la lista
                            cout << "Digite la cantidad: ";
                            cin >> cant;
                            p2 = new Producto(p->getIdProducto(), p->getNombreProducto(), cant); //producto de la venta
                            exis = p->getExistencia() - cant;
                            lst->
                            p->setExistencia(cant);
                            lpc->insertarFinal(p2);
                            cout << "Producto ingresado :)" << endl << endl;
                        }
                        cout << "Desea agregar otro producto?(s/n): ";
                        cin >> opc;
                    }
                }
            }
        }else{
            v = static_cast<Venta*>(lst->buscarObjeto(nf, venta)->getValor());
            if(v->getNumeroFactura() == nf){
                cout << "Ese numero de factura ya existe, debe asignar otro :(" << endl;
            }else{
                if(lst->buscarNodo(cliente) == NULL){ //si no hay clientes, sólo se podrá ingresar
                    cout << "ID del cliente: ";
                    cin >> idCliente;
                    cout << "Nombre del cliente: ";
                    cin >> nc;
                    cout << "Apellido del cliente: ";
                    cin >> ac;
                    c = new Cliente(idCliente, nc, ac);
                }else{

                }
            }
            if(op ) //si es uno o dos
            {
                system("cls");
                lst->mostrar(producto);
                while(opc == 's' || opc == 'S'){
                    cout << "Digite el ID del producto: ";
                    cin >> idp;
                    if(lst->buscarObjeto(idp, producto) == NULL){
                        cout << "Ese ID no existe :(";
                    }else{
                        p = static_cast<Producto*>(lst->buscarObjeto(idp, producto)->getValor()); //producto en la lista
                        cout << "Digite la cantidad: ";
                        cin >> cant;
                        p2 = new Producto(p->getIdProducto(), p->getNombreProducto(), cant); //producto de la venta
                        exis = p->getExistencia() - cant;
                        lst->
                        p->setExistencia(cant);
                        lpc->insertarFinal(p2);
                        cout << "Producto ingresado :)" << endl << endl;
                    }
                    cout << "Desea agregar otro producto?(s/n): ";
                    cin >> opc;
                }
            }
        }
    }else{
        cout << "No hay producos en la lista :(" << endl;
    }
}
void buscarVenta(Lista *lst){ ///////////////////  BUSCANDO VENTA  /////////////////////
    int nf;
    cout << "Ingrese el número de factura: ";
    cin >> nf;
    Venta *v;
    int ob = 1;
    if(lst->buscarObjeto(nf, ob) != NULL){
        v = static_cast<Venta*>(lst->buscarObjeto(nf, ob)->getValor());
        if(v->getNumeroFactura() == nf){
            cout << "Numero de factura: " << nf;
            cout << "Cliente: " << v->getCliente()->getNombre() << " " << v->getCliente()->getApellido() << endl;
            cout << "Productos: " << endl;
            v->getLstProductos()->mostrar(ob);
        }
    }else{
        cout << "No hay ventas registradas :(" << endl;
    }
}
void ingresarProducto(Lista *lst){ //////////////  INGRESANDO PRODUCTO  /////////////////////
    int idProducto, prod = 1;
    string nombre;
    float exis;
    Producto *p;
    cout << "Ingrese el ID del producto: ";
    cin >> idProducto;
    if(lst->buscarNodo(prod) == NULL){
        cout << "Nombre: ";
        cin.get();
        getline(cin, nombre);
        cout << "Existencia: ";
        cin >> exis;
        p = new Producto(idProducto, nombre, exis);
        lst->insertarFinal(p);
        cout << "Ingresado correctamente :)" << endl;
    }else{
        p = static_cast<Producto*>(lst->buscarObjeto(idProducto, prod)->getValor());
        if(p->getIdProducto() == idProducto){
            cout << "Ese ID ya existe, debe asignar otro :(" << endl;
        }else{
            cout << "Nombre: ";
            cin.get();
            getline(cin, nombre);
            cout << "Existencia: ";
            cin >> exis;
            p = new Producto(idProducto, nombre, exis);
            lst->insertarFinal(p);
            cout << "Ingresado correctamente :)" << endl;
        }
    }
}
void ingresarCliente(Lista *lst){ ///////////////  INGRESANDO CLIENTE  /////////////////////
    int id, cliente = 2;
    string nom, ape;
    Cliente *c;
    cout << "Ingrese el ID del cliente: ";
    cin >> id;
    if(lst->buscarNodo(cliente) == NULL){
        cout << "Nombre: ";
        cin >> nom;
        cout << "Apellido: ";
        cin >> ape;
        c = new Cliente(id, nom, ape);
        lst->insertarFinal(c);
        cout << "Ingresado correctamente :)" << endl;
    }else{
        c = static_cast<Cliente*>(lst->buscarObjeto(id, cliente)->getValor());
        if(c->getIdCliente() == id){
            cout << "Ese ID ya existe, debe asignar otro :(" << endl;
        }else{
            cout << "Nombre: ";
            cin >> nom;
            cout << "Apellido: ";
            cin >> ape;
            c = new Cliente(id, nom, ape);
            lst->insertarFinal(c);
            cout << "Ingresado correctamente :)" << endl;
        }
    }
}
void eliminarProducto(Lista *lst){ //////////////  ELIMINANDO PRODUCTO  /////////////////////
    int id, producto = 1;
    cout << "Ingrese el ID del producto: ";
    cin >> id;
    lst->eliminar(id, producto);
}
void eliminarCliente(Lista *lst){ ///////////////  ELIMINANDO CLIENTE  /////////////////////
    int id, cliente = 2;
    cout << "Ingrese el ID del cliente: ";
    cin >> id;
    lst->eliminar(id, cliente);
}

int main(){
    int opc, ob;
    Lista lst;
    do{
        system("cls");
        opc = menu();
        system("cls");
        switch(opc){
            case 1://Ingresar producto
                ingresarProducto(&lst);
                break;
            case 2://Ingresar cliente
                ingresarCliente(&lst);
                break;
            case 3://Ingresar venta
                ingresarVenta(&lst);
                break;
            case 4://Mostrar productos
                ob = 1;
                lst.mostrar(ob);
                break;
            case 5://Mostrar clientes
                ob = 2;
                lst.mostrar(ob);
                break;
            case 6://Eliminar producto
                eliminarProducto(&lst);
                break;
            case 7://Eliminar cliente
                eliminarCliente(&lst);
                break;
            case 8://Ver factura
                buscarVenta(&lst);
                break;
            case 9:
                cout << "\n\tSaliendo..." << endl << endl;
                break;
            default:
                cout << "\n\tOpcion no valida :(" << endl << endl;
                break;
        }
        system("pause");
    }while(opc != 9);
    return 0;
}
