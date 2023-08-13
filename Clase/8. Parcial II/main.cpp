#include <iostream>
#include <list>;
using namespace std;
#include "ListaProducto.h"
#include "Venta.h"
#include "Cliente.h"
#include <stdlib.h>

Venta *buscar(list<Venta*> *lst, string noFactura){
    list<Venta*>::iterator pos = lst->begin();
    Cliente cli = Cliente("", "", "");
    Venta *retorno = new Venta("", "", cli);
    bool encontrado = false;
    if(lst->size() == 0){
        return retorno;
    }else{
        while(pos != lst->end() && !encontrado){
            Venta *v = *pos;
            if(v->getNumeroFactura() == noFactura){
                encontrado = true;
                retorno = v;
            }else{
                pos++;
            }
        }
        return retorno;
    }
}
Cliente *buscarC(list<Cliente*> *lst, string nombre){
    list<Cliente*>::iterator pos = lst->begin();
    Cliente *retorno = new Cliente("", "", "");
    bool encontrado = false;
    if(lst->size() == 0){
        return retorno;
    }else{
        while(pos != lst->end() && !encontrado){
            Cliente *v = *pos;
            if(v->getIdCliente() == nombre){
                encontrado = true;
                retorno = v;
            }else{
                pos++;
            }
        }
        return retorno;
    }
}
Producto *buscarP(list<Producto*> *lst, int id){
    list<Producto*>::iterator pos = lst->begin();
    Producto *retorno = new Producto(0, "", 0);
    bool encontrado = false;
    if(lst->size() == 0){
        return retorno;
    }else{
        while(pos != lst->end() && !encontrado){
            Producto *v = *pos;
            if(v->getIdProducto() == id){
                encontrado = true;
                retorno = v;
            }else{
                pos++;
            }
        }
        return retorno;
    }
}
void buscarVenta(list<Venta*> *lst){
    string nomb;
    cout << "Ingrese el numero de factura: ";
    cin >> nomb;
    if(buscar(lst, nomb)->getNumeroFactura() == nomb){
        cout << "\nLa factura se encontro :)" << endl << endl;
        cout << "Numero de factura: " << nomb << endl;
        cout << "Fecha de venta: " << buscar(lst, nomb)->getFecha();
        cout << "\nNombre del cliente: " << buscar(lst, nomb)->getCliente().getNombre() << " " << buscar(lst, nomb)->getCliente().getApellido() << endl;
        ListaProducto lstp = buscar(lst, nomb)->getListaProductos();
        cout << "Productos: " << endl;
        lstp.Mostrar();
    }else{
        cout << "No se encontro a la persona :(" << endl;
    }
}
void insertarProducto(list<Producto*> *lst, ListaProducto *lstc){
    int id;
    string nombre;
    float sueldo;
    Producto *p;
    Producto p2;
    cout << "Digite el ID: ";
    cin >> id;
    cout << "Digite descripcion: ";
    cin >> nombre;
    cout << "Digite el precio: ";
    cin >> sueldo;
    p = new Producto(id, nombre, sueldo);
    p2 = Producto(id, nombre, sueldo);
    lst->push_back(p);
    lstc->Insertar(p2);
    cout << "El producto se ingreso :)" << endl;
}
void insertarCliente(list<Cliente*> *lst){
    string id;
    string nombre, apellido;
    Cliente *c;
    cout << "Digite el ID: ";
    cin >> id;
    cout << "Digite el nombre: ";
    cin >> nombre;
    cout << "Digite el apellido: ";
    cin >> apellido;
    c = new Cliente(id, nombre, apellido);
    lst->push_back(c);
    cout << "El cliente se ingreso :)" << endl;
}
void mostrarProductos(list<Producto*> *lst){
    list<Producto*>::iterator pos = lst->begin();
    cout << "Lista de Productos" << endl << endl;
    while(pos != lst->end()){
        Producto *p = *pos;
        cout << "--------------------------------" << endl;
        cout << "ID: " << p->getIdProducto() << endl;
        cout << "Descripcion: " << p->getDescripcion() << endl;
        cout << "Precio unitario: $" << p->getPrecioUnitario() << endl;
        cout << "--------------------------------" << endl;
        pos++;
    }
}
void registrarVenta(list<Venta*> *lstv, list<Producto*> *lstp, list<Cliente*> *lstc){
    Producto aux; //para usar la cantidad de productos comprados en lugar de existencia
    Cliente auxc; //si se elimina el cliente, aun quedará en el registro
    Venta *v;
    string idcliaux, fv, daux;
    int idp, idaux;
    char op;
    float paux, existencia, eaux, c;
    string id, nf, n, naux, a, nombreaux, apeaux;
    cout << "Digite el ID del cliente que compra: ";
    cin >> id;
    if(buscarC(lstc, id)->getIdCliente() == id){ //si coinciden, el cliente existe
        Cliente *cli = buscarC(lstc, id);
        cout << "Digite el numero de factura: ";
        cin >> nf;
        if(buscar(lstv, nf)->getNumeroFactura() != nf){ //si no coinciden, la factura no existe y se puede crear
            cout << "Digite la fecha de venta: ";
            cin >> fv;
            system("cls");
            idcliaux = buscarC(lstc, id)->getIdCliente();
            nombreaux = buscarC(lstc, id)->getNombre();
            apeaux = buscarC(lstc, id)->getApellido();
            auxc = Cliente(idcliaux, nombreaux, apeaux);
            v = new Venta(nf, fv, auxc);
            mostrarProductos(lstp);
            do{
                cout << "Digite el ID del producto que desea comprar: ";
                cin >> idp;
                cout << "Digite la cantidad de productos: ";
                cin >> c;
                if(buscarP(lstp, idp)->getIdProducto() == idp){ //si coinciden, el producto existe
                    idaux = buscarP(lstp, idp)->getIdProducto();
                    paux = buscarP(lstp, idp)->getPrecioUnitario();
                    daux = buscarP(lstp, idp)->getDescripcion();
                    aux = Producto(idaux, daux, paux);
                    v->agregarProductos(aux);
                }else{
                    cout << "No se encontro el producto :(" << endl;
                }
                cout << "Desea agregar otro producto?(s/n): ";
                cin >> op;
                system("cls");
            }while(op == 's' || op == 'S');
            lstv->push_back(v);//ingresa la venta a la ListaVenta
            cout << "Compra existosa :)" << endl;
        }else{
            cout << "No se pudo efectuar la compra, verifique que los datos sean correctos :(" << endl;
        }
    }else{
        cout << "No se encontro el cliente :(" << endl;
    }
    cin.get();
}
void mostrarClientes(list<Cliente*> *lst){
    list<Cliente*>::iterator pos = lst->begin();
    cout << "Lista de Productos" << endl << endl;
    while(pos != lst->end()){
        Cliente *p = *pos;
        cout << "--------------------------------" << endl;
        cout << "ID: " << p->getIdCliente() << endl;
        cout << "Nombre: " << p->getNombre() << endl;
        cout << "Apellido: " << p->getApellido() << endl;
        cout << "--------------------------------" << endl;
        pos++;
    }
}
void mostrarVentas(list<Venta*> *lst){
    list<Venta*>::iterator pos = lst->begin();
    cout << "Lista de Productos" << endl << endl;
    while(pos != lst->end()){
        Venta *p = *pos;
        cout << "--------------------------------" << endl;
        cout << "ID: " << p->getNumeroFactura() << endl;
        cout << "Fecha de venta: " << p->getFecha() << endl;
        cout << "Nombre de cliente: " << p->getCliente().getNombre() << " " << p->getCliente().getApellido() << endl;
        cout << "--------------------------------" << endl;
        pos++;
    }
}
int menu(){
    int op;
    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Agregar clientes" << endl;
    cout << "3. Registrar venta" << endl;
    cout << "4. Mostrar lista de productos" << endl;
    cout << "5. Mostrar lista de clientes" << endl;
    cout << "6. Mostrar lista de ventas" << endl;
    cout << "7. Mostrar detalles de la venta" << endl;
    cout << "8. Salir" << endl;
    cout << "Digite la opcion que desesa implementar: ";
    cin >> op;
    return op;
}

int main()
{
    list<Cliente*> lstCliente;
    list<Venta*> lstVenta;
    list<Producto*> lstProducto;
    ListaProducto lstProductosComprados;

    int opc;
    do{
        system("cls");
        opc = menu();
        system("cls");
        switch(opc){
        case 1:
            insertarProducto(&lstProducto, &lstProductosComprados);
            break;
        case 2:
            insertarCliente(&lstCliente);
            break;
        case 3:
            registrarVenta(&lstVenta, &lstProducto, &lstCliente);
            break;
        case 4:
            mostrarProductos(&lstProducto);
            break;
        case 5:
            mostrarClientes(&lstCliente);
            break;
        case 6:
            mostrarVentas(&lstVenta);
            break;
        case 7:
            buscarVenta(&lstVenta);
            break;
        case 8:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida :(" << endl;
            break;
        }
        system("pause");
    }while(opc != 8);
    return 0;
}
