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
   // Constructor y destructor básicos:
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

   // Insertar en árbol ordenado:
    void Insertar(Ingresado *dat){
        Nodo *padre = NULL;

        actual = raiz;
        // Buscar el int en el árbol, manteniendo un puntero al nodo padre
        while(!Vacio(actual) && dat->getCodigo() != actual->dato->getCodigo()) {
        padre = actual;
        if(dat->getCodigo() > actual->dato->getCodigo()) actual = actual->derecho;
        else if(dat->getCodigo() < actual->dato->getCodigo()) actual = actual->izquierdo;
        }

        // Si se ha encontrado el elemento, regresar sin insertar
        if(!Vacio(actual)) return;
        // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
        // el nodo raiz
        if(Vacio(padre)) raiz = new Nodo(dat);
        // Si el int es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
        else if(dat->getCodigo() < padre->dato->getCodigo()) padre->izquierdo = new Nodo(dat);
        // Si el int es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
        else if(dat->getCodigo() > padre->dato->getCodigo()) padre->derecho = new Nodo(dat);
   }
   // Borrar un elemento del árbol:
    void Borrar(Ingresado *dat){
        Nodo *padre = NULL;
        Nodo *nodo;
        int aux;

        actual = raiz;
        // Mientras sea posible que el valor esté en el árbol
        while(!Vacio(actual)) {
          if(dat->getCodigo() == actual->dato->getCodigo()) { // Si el valor está en el nodo actual
             if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
                if(padre) // Si tiene padre (no es el nodo raiz)
                   // Anulamos el puntero que le hace referencia
                   if(padre->derecho == actual) padre->derecho = NULL;
                   else if(padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                return;
             }
             else { // Si el valor está en el nodo actual, pero no es hoja
                // Buscar nodo
                padre = actual;
                // Buscar nodo más izquierdo de rama derecha
                if(actual->derecho) {
                   nodo = actual->derecho;
                   while(nodo->izquierdo) {
                      padre = nodo;
                      nodo = nodo->izquierdo;
                   }
                }
                // O buscar nodo más derecho de rama izquierda
                else {
                   nodo = actual->izquierdo;
                   while(nodo->derecho) {
                      padre = nodo;
                      nodo = nodo->derecho;
                   }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que sólo se eliminan nodos hoja.
                aux = actual->dato->getCodigo();
                actual->dato = nodo->dato;
                nodo->dato->setCodigo(aux);
                actual = nodo;
             }
          }
          else { // Todavía no hemos encontrado el valor, seguir buscándolo
             padre = actual;
             if(dat->getCodigo() > actual->dato->getCodigo()) actual = actual->derecho;
             else if(dat->getCodigo() < actual->dato->getCodigo()) actual = actual->izquierdo;
          }
        }
    }
    // Función de búsqueda:
    bool Buscar(const int dat){
        actual = raiz;

        // Todavía puede aparecer, ya que quedan nodos por mirar
        while(!Vacio(actual)) {
          if(dat == actual->dato->getCodigo()) return true; // int encontrado
          else if(dat > actual->dato->getCodigo()) actual = actual->derecho; // Seguir
          else if(dat < actual->dato->getCodigo()) actual = actual->izquierdo;
        }
        return false; // No está en árbol
    }
    // Comprobar si el árbol está vacío:
    bool Vacio(Nodo *r) { return r==NULL; }
    // Comprobar si es un nodo hoja:
    bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
    // Contar el número de nodos
    const int NumeroNodos()
    {
       contador = 0;

       auxContador(raiz); // FUnción auxiliar
       return contador;
    }
    // Calcular la altura del árbol, que es la altura del nodo de mayor altura.
    const int AlturaArbol()
    {
       altura = 0;

       auxAltura(raiz, 0); // Función auxiliar
       return altura;
    }
    // Calcular la altura del nodo que contiene el int dat
    int Altura(Ingresado *dat){
        int altura = 0;
        actual = raiz;

        // Todavía puede aparecer, ya que quedan nodos por mirar
        while(!Vacio(actual)) {
          if(dat->getCodigo() == actual->dato->getCodigo()) return altura; // int encontrado
          else {
             altura++; // Incrementamos la altura, seguimos buscando
             if(dat->getCodigo() > actual->dato->getCodigo()) actual = actual->derecho;
             else if(dat->getCodigo() < actual->dato->getCodigo()) actual = actual->izquierdo;
          }
        }
        return -1; // No está en árbol
    }
   // Devolver referencia al int del nodo actual:
   Ingresado *ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
    // Aplicar una función a cada elemento del árbol:
    // Recorrido de árbol en inorden, aplicamos la función func, que tiene
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
    // Recorrido de árbol en preorden, aplicamos la función func, que tiene
    // el prototipo:
    // void func(int&);
    void PreOrden(void (*func)(int) , Nodo *nodo=NULL, bool r=true){
        if(r) nodo = raiz;
        func(nodo->dato->getCodigo());
        if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
        if(nodo->derecho) PreOrden(func, nodo->derecho, false);
    }
    // Recorrido de árbol en postorden, aplicamos la función func, que tiene
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
    // Función auxiliar para contar nodos. Función recursiva de recorrido en
    //   preorden, el proceso es aumentar el contador
    void auxContador(Nodo *nodo)
    {
       contador++;  // Otro nodo
       // Continuar recorrido
       if(nodo->izquierdo) auxContador(nodo->izquierdo);
       if(nodo->derecho)   auxContador(nodo->derecho);
    }
    // Función auxiliar para calcular altura. Función recursiva de recorrido en
    // postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
    // altura de la máxima actual
    void auxAltura(Nodo *nodo, int a)
    {
       // Recorrido postorden
       if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
       if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
       // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
       // árbol, actualizamos la altura actual del árbol
       if(EsHoja(nodo) && a > altura) altura = a;
    }
};

// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
   cout << d << ",";
}

#endif // ABB_H_INCLUDED
