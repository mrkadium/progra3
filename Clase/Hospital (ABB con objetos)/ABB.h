#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include "Nodo.h"
#include <iostream>
using namespace std;

class ABB{
  private:
   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:
   // Constructor y destructor b�sicos:
   ABB(Nodo *r=NULL, Nodo *a=NULL){
       this->raiz = r;
       this->actual = a;
    }
   ~ABB(){
       Podar(raiz);
    }
    // Devuelve la raiz
    Nodo *getRaiz(){
        return this->raiz;
    }

   // Insertar en �rbol ordenado:
    void Insertar(Ingresado *dat){
        Nodo *padre = NULL;

        actual = raiz;
        // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
        while(!Vacio(actual) && dat->getCodigo() != actual->dato->getCodigo()) {
        padre = actual;
        if(dat->getCodigo() > actual->dato->getCodigo()) actual = actual->derecho;
        else if(dat->getCodigo() < actual->dato->getCodigo()) actual = actual->izquierdo;
        }

        // Si se ha encontrado el elemento, regresar sin insertar
        if(!Vacio(actual)) return;
        // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
        // el nodo raiz
        if(Vacio(padre)) raiz = new Nodo(dat);
        // Si el int es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
        else if(dat->getCodigo() < padre->dato->getCodigo()) padre->izquierdo = new Nodo(dat);
        // Si el int es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
        else if(dat->getCodigo() > padre->dato->getCodigo()) padre->derecho = new Nodo(dat);
   }
   // Borrar un elemento del �rbol:
    void Borrar(Ingresado *dat){
        Nodo *padre = NULL;
        Nodo *nodo;
        int aux;

        actual = raiz;
        // Mientras sea posible que el valor est� en el �rbol
        while(!Vacio(actual)) {
          if(dat->getCodigo() == actual->dato->getCodigo()) { // Si el valor est� en el nodo actual
             if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
                if(padre) // Si tiene padre (no es el nodo raiz)
                   // Anulamos el puntero que le hace referencia
                   if(padre->derecho == actual) padre->derecho = NULL;
                   else if(padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                return;
             }
             else { // Si el valor est� en el nodo actual, pero no es hoja
                // Buscar nodo
                padre = actual;
                // Buscar nodo m�s izquierdo de rama derecha
                if(actual->derecho) {
                   nodo = actual->derecho;
                   while(nodo->izquierdo) {
                      padre = nodo;
                      nodo = nodo->izquierdo;
                   }
                }
                // O buscar nodo m�s derecho de rama izquierda
                else {
                   nodo = actual->izquierdo;
                   while(nodo->derecho) {
                      padre = nodo;
                      nodo = nodo->derecho;
                   }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que s�lo se eliminan nodos hoja.
                aux = actual->dato->getCodigo();
                actual->dato = nodo->dato;
                nodo->dato->setCodigo(aux);
                actual = nodo;
             }
          }
          else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
             padre = actual;
             if(dat->getCodigo() > actual->dato->getCodigo()) actual = actual->derecho;
             else if(dat->getCodigo() < actual->dato->getCodigo()) actual = actual->izquierdo;
          }
        }
    }
    // Funci�n de b�squeda:
    bool Buscar(const int dat){
        actual = raiz;

        // Todav�a puede aparecer, ya que quedan nodos por mirar
        while(!Vacio(actual)) {
          if(dat == actual->dato->getCodigo()) return true; // int encontrado
          else if(dat > actual->dato->getCodigo()) actual = actual->derecho; // Seguir
          else if(dat < actual->dato->getCodigo()) actual = actual->izquierdo;
        }
        return false; // No est� en �rbol
    }
    // Comprobar si el �rbol est� vac�o:
    bool Vacio(Nodo *r) { return r==NULL; }
    // Comprobar si es un nodo hoja:
    bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
    // Contar el n�mero de nodos
    const int NumeroNodos()
    {
       contador = 0;

       auxContador(raiz); // FUnci�n auxiliar
       return contador;
    }
    // Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
    const int AlturaArbol()
    {
       altura = 0;

       auxAltura(raiz, 0); // Funci�n auxiliar
       return altura;
    }
    // Calcular la altura del nodo que contiene el int dat
    int Altura(Ingresado *dat){
        int altura = 0;
        actual = raiz;

        // Todav�a puede aparecer, ya que quedan nodos por mirar
        while(!Vacio(actual)) {
          if(dat->getCodigo() == actual->dato->getCodigo()) return altura; // int encontrado
          else {
             altura++; // Incrementamos la altura, seguimos buscando
             if(dat->getCodigo() > actual->dato->getCodigo()) actual = actual->derecho;
             else if(dat->getCodigo() < actual->dato->getCodigo()) actual = actual->izquierdo;
          }
        }
        return -1; // No est� en �rbol
    }
   // Devolver referencia al int del nodo actual:
   Ingresado *ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
    // Aplicar una funci�n a cada elemento del �rbol:
    // Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
    // el prototipo:
    // void func(int&);
    void InOrden(Nodo *nodo=NULL, bool r=true){
        if(r) nodo = raiz;
        if(nodo->izquierdo) InOrden(nodo->izquierdo, false);
        cout << "---------------------------------------" << endl;
        cout << "Codigo: " << nodo->dato->getCodigo() << endl;
        cout << "Nombre: " << nodo->dato->getNombre() << endl;
        cout << "Razon: " << nodo->dato->getRazon() << endl;
        cout << "---------------------------------------" << endl;
        if(nodo->derecho) InOrden(nodo->derecho, false);
    }
    // Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
    // el prototipo:
    // void func(int&);
    void PreOrden(void (*func)(int) , Nodo *nodo=NULL, bool r=true){
        if(r) nodo = raiz;
        func(nodo->dato->getCodigo());
        if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
        if(nodo->derecho) PreOrden(func, nodo->derecho, false);
    }
    // Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
    // el prototipo:
    // void func(int&);
    void PostOrden(void (*func)(int) , Nodo *nodo=NULL, bool r=true){
        if(r) nodo = raiz;
        if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
        if(nodo->derecho) PostOrden(func, nodo->derecho, false);
        func(nodo->dato->getCodigo());
    }
  private:
   // Funciones auxiliares
   // Poda: borrar todos los nodos a partir de uno, incluido
    void Podar(Nodo* &nodo){
        // Algoritmo recursivo, recorrido en postorden
        if(nodo) {
          Podar(nodo->izquierdo); // Podar izquierdo
          Podar(nodo->derecho);   // Podar derecho
          delete nodo;            // Eliminar nodo
          nodo = NULL;
        }
    }
    // Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
    //   preorden, el proceso es aumentar el contador
    void auxContador(Nodo *nodo)
    {
       contador++;  // Otro nodo
       // Continuar recorrido
       if(nodo->izquierdo) auxContador(nodo->izquierdo);
       if(nodo->derecho)   auxContador(nodo->derecho);
    }
    // Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
    // postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
    // altura de la m�xima actual
    void auxAltura(Nodo *nodo, int a)
    {
       // Recorrido postorden
       if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
       if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
       // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
       // �rbol, actualizamos la altura actual del �rbol
       if(EsHoja(nodo) && a > altura) altura = a;
    }
};

// Funci�n de prueba para recorridos del �rbol
void Mostrar(int &d)
{
   cout << d << ",";
}

#endif // ABB_H_INCLUDED
