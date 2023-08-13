#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
using namespace std;
#include "Nodo.h"   //Incluimos la clase nodo, ya que trabajaremos con elementos de esta

class Lista{
    private:
        pNodo primero;
        pNodo actual;   //el nodo que definara la posicion
    public:

    Lista(void) {
        this->primero = actual = NULL;//al momento de crear la lista se inicializara el primero y ultimo nodo como NULL
    }

    virtual ~Lista() {//destructor de la clase lista
    pNodo aux;
    while ( this->primero )//mientras exista algun nodo
        {
        aux = this->primero;
        this->primero = this->primero->Siguiente;
        delete aux;

        }
    }

    bool ListaVacia(){
        return (this->primero==NULL);//comprueba si esta vacia la lista , solo observando el primer nodo
    }

    void Primero(){
        this->actual = this->primero;//reiniciamos el orden para que actual este en la posicion del primero
    }

    void Siguiente(){
        if(this->actual->Siguiente != NULL){
            this->actual = this->actual->Siguiente;//nos movemos una posicion a la posicion siguiente
        }
    }
    void Final(){
        this->Primero();
        if(ListaVacia() != true){
            while(this->actual->Siguiente != NULL){//mientras exista un nodo mas que recorrer
                    this->Siguiente();//nos movemos una posicion
            }
        }
    }

    void Insertar(Contacto valor){//para insertar le pasamos el valor, que debe ser del tipo declarado en la clase nodo
        if(this->ListaVacia())  //si la lista está vacía
        {
            this->primero = new Nodo(valor);//insertamos el elemento en el primero
        }
        else
        {   //cuando ya contiene valores
            this->Final();//nos posicionamos al final de la lista
            //el ultimo nodo en la posicion siguiente apuntaba a null ahora apuntara al nuevo valor
            this->actual->Siguiente = new Nodo(valor);
        }

    }

    void InsertarInicio(Contacto valor){
        Primero();    //Almacenamos el valor del primer nodo en el nodo Actual
        pNodo nuevo = new Nodo(valor);    //declararemos ya el nuevo valor
        if(ListaVacia()){   //verificamos el estado de la lista
            this->primero = nuevo;    //si esta vacia ingresamos en el primero
        }else{
            nuevo->Siguiente = this->primero; //Almacenamos en la segunda posicion el puntero que era primero
            this->primero = nuevo;    //declaramos el primero como el nuevo valor
            while(this->actual){    //movemos la posicion de los nodos
                this->actual = this->actual->Siguiente;
            }
        }
    }

    void InsertarAntes(Contacto c, Contacto c2){
        Primero();
        pNodo nuevo = new Nodo(c2);
        nuevo->Siguiente = NULL;
        if(Buscar(c) == NULL){
            this->Insertar(c2);
        }else{
            if(ListaVacia()){
                this->primero = nuevo;
            }else{
                if(this->primero->variable.getId() == c.getId()){
                    this->InsertarInicio(c2);
                }else{
                    pNodo posterior = this->primero;
                    pNodo anterior;
                    pNodo aux = this->Buscar(c);
                    while(posterior->variable.getId() != aux->variable.getId()){
                        anterior = posterior;
                        posterior = posterior->Siguiente;
                    }
                    anterior->Siguiente = nuevo;
                    nuevo->Siguiente = posterior;
                }
            }
        }
    }

    void Mostrar(){
        if(this->ListaVacia()!=true){
            this->Primero();    //Comenzamos a recorrer la lista desde el inicio
            while(this->actual){//mientras todavia exista un nodo que recorrer
                cout << "------------------------------------------------------" << endl;
                cout << "\tID del contacto: " << this->actual->getVariable().getId() << endl;
                cout << "\tNombre del contacto: " << this->actual->getVariable().getNombre() << " " << this->actual->getVariable().getApellido()<< endl;
                cout << "\tNumero de celular: " << this->actual->getVariable().getCelular() << endl;
                cout << "\tNumero de telefono: " << this->actual->getVariable().getTelefono() << endl;
                cout << "\tEmail: " << this->actual->getVariable().getEmail()<<endl;
                cout << "------------------------------------------------------"<<endl;
                this->actual = this->actual->Siguiente;
            }
        }
        else{
            cout << "No hay datos que mostrar"<<endl;
        }
    }

    void buscarMostrar(string n){
        this->Primero();    //Comenzamos a recorrer la lista desde el inicio
        if(this->actual->getVariable().getNombre() == n){
        while(this->actual){//mientras todavia exista un nodo que recorrer
            if(this->actual->getVariable().getNombre() == n){
                cout << "------------------------------------------------------" << endl;
                cout << "\tID del contacto: " << this->actual->getVariable().getId() << endl;
                cout << "\tNombre del contacto: " << this->actual->getVariable().getNombre() << " " << this->actual->getVariable().getApellido()<< endl;
                cout << "\tNumero de celular: " << this->actual->getVariable().getCelular() << endl;
                cout << "\tNumero de telefono: " << this->actual->getVariable().getTelefono() << endl;
                cout << "\tEmail: " << this->actual->getVariable().getEmail()<<endl;
                cout << "------------------------------------------------------"<<endl;

            }
            this->actual = this->actual->Siguiente;
        }
        }else{
            cout << "No se encontro ningun contacto con ese nombre" << endl;
        }
    }

    bool modificar(Contacto canterior, Contacto cnuevo){
        if(ListaVacia()!=true){  //Si la lista no esta vacia
            Primero();  //Reiniciamos la lista
            pNodo temp = Buscar(canterior);  //Almacenamos lo que devuelve la funcion buscar en un nodo auxiliar
            if(temp){   //Si devuelve un nodo
                temp->setVariable(cnuevo);   //asignamos el nuevo valor
                return true;
            }
        }
        return false;
    }

    pNodo Buscar(Contacto valor){
        this->Primero();
        while(this->actual!=NULL){//mientras todavia exista un nodo que recorrer
            if(this->actual->getVariable().getId()== valor.getId()){
                return this->actual;
            }
            this->actual = this->actual->Siguiente;//nos movemos al elemento siguiente
        }
    return NULL;
    }

    bool Eliminar(Contacto valor){
    /** Primero se comprueba que la lista no esté vacía  y que el valor se encuentre **/
        if(this->ListaVacia()==true || this->Buscar(valor)==NULL ) {
            return false;
        }
        else//si paso es porque hay datos y se encontro el elemento
        {
            this->Primero();
            pNodo aux;//se crea un nodo auxliar que ayuda a las eliminaciones

            if(this->primero->getVariable().getId()==valor.getId())//comprueba que el elemento se encuentra en la primera posicion
            {
                aux = this->primero;
                this->primero = aux->Siguiente;// primero tiene la posicion de auxiliar en la posicion siguiente
                delete aux;//se elimina auxiliar
                return true;
            }
            else//si el elemento se encuentra ya sea en medio o al final de la lista
            {
                //mientras exista un nodo en la posicion siguiente
                while(this->actual->Siguiente!=NULL)
                {
                    //si nuestro dato esta en el nodo siguiente
                    if(this->actual->Siguiente->getVariable().getId()==valor.getId())
                    {
                        //se le asigna a auxiliar el nodo que contiene el valor buscado
                        aux = this->actual->Siguiente;

                        //actual en la posicion siguiente ahora apunta un nodo mas adelante
                        this->actual->Siguiente = this->actual->Siguiente->Siguiente;

                        delete aux;
                        return true;

                    }
                this->Siguiente();

                }

            }
        }
    }

};


#endif // LISTA_H_INCLUDED
