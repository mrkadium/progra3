#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

// Plantilla de Arbol Binario de B�squeda en C++
// (C) Abril 2002, Salvador Pozo
// C con Clase: http://c.conclase.net
#include "Nodo.h"
#include <iostream>
using namespace std;

class ArbolABB{
  private:
   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:
   // Constructor y destructor b�sicos:
   ArbolABB(Nodo *r=NULL, Nodo *a=NULL){
       this->raiz = r;
       this->actual = a;
    }
   ~ArbolABB(){
       Podar(raiz);
    }
    // Devuelve la raiz
    Nodo *getRaiz(){
        return this->raiz;
    }

   // Insertar en �rbol ordenado:
    void Insertar(const int dat){
        Nodo *padre = NULL;

        actual = raiz;
        // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
        while(!Vacio(actual) && dat != actual->dato) {
            padre = actual;
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }

        // Si se ha encontrado el elemento, regresar sin insertar
        if(!Vacio(actual)) return;
        // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
        // el nodo raiz
        if(Vacio(padre)) raiz = new Nodo(dat);
        // Si el int es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
        else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
        // Si el int es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
        else if(dat > padre->dato) padre->derecho = new Nodo(dat);
   }
   // Borrar un elemento del �rbol:
    void Borrar(const int dat){
        Nodo *padre = NULL;
        Nodo *nodo;
        int aux;

        actual = raiz;
        // Mientras sea posible que el valor est� en el �rbol
        while(!Vacio(actual)) {
          if(dat == actual->dato) { // Si el valor est� en el nodo actual
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
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
             }
          }
          else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
             padre = actual;
             if(dat > actual->dato) actual = actual->derecho;
             else if(dat < actual->dato) actual = actual->izquierdo;
          }
        }
    }
    // Funci�n de b�squeda:
    bool Buscar(const int dat){
        actual = raiz;

        // Todav�a puede aparecer, ya que quedan nodos por mirar
        while(!Vacio(actual)) {
          if(dat == actual->dato) return true; // int encontrado
          else if(dat > actual->dato) actual = actual->derecho; // Seguir
          else if(dat < actual->dato) actual = actual->izquierdo;
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
    int Altura(const int dat){
        int altura = 0;
        actual = raiz;

        // Todav�a puede aparecer, ya que quedan nodos por mirar
        while(!Vacio(actual)) {
          if(dat == actual->dato) return altura; // int encontrado
          else {
             altura++; // Incrementamos la altura, seguimos buscando
             if(dat > actual->dato) actual = actual->derecho;
             else if(dat < actual->dato) actual = actual->izquierdo;
          }
        }
        return -1; // No est� en �rbol
    }
   // Devolver referencia al int del nodo actual:
   int &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
    // Aplicar una funci�n a cada elemento del �rbol:
    // Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
    // el prototipo:
    // void func(int&);
    void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true){
        if(r) nodo = raiz;
        if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
        func(nodo->dato);
        if(nodo->derecho) InOrden(func, nodo->derecho, false);
    }
    // Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
    // el prototipo:
    // void func(int&);
    void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true){
        if(r) nodo = raiz;
        func(nodo->dato);
        if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
        if(nodo->derecho) PreOrden(func, nodo->derecho, false);
    }
    // Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
    // el prototipo:
    // void func(int&);
    void PostOrden(Nodo *nodo=NULL, bool r=true){
        if(r) nodo = raiz;
        if(nodo->izquierdo) PostOrden(nodo->izquierdo, false);
        if(nodo->derecho) PostOrden(nodo->derecho, false);
        //ya que la funci�n Mostrar s�lo es un cout de un entero, se puede hacer de esta forma, sin usar otra funci�n
        cout << nodo->dato << ",";
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    void mostrarPosFibonazi(Nodo *nodo = NULL, int cont = 0, bool r = true){
        if(raiz == NULL){ //Si el �rbol est� vac�o
            return;
        }else{
            if(r){ //se inicia desde la ra�z, por lo que se manda el r=true primero y luego los false, ya que los dem�s no son la ra�z
                nodo = raiz;
            }
            if(nodo->derecho){
                mostrarPosFibonazi(nodo->derecho, cont+1, false);
            }
            for(int i=0; i<cont; i++){ //ya que el contador al principio es 0, no deja espacio
                cout << "   ";
            }
            cout << nodo->dato << endl; //se imprime el valor
            if(nodo->izquierdo){
                mostrarPosFibonazi(nodo->izquierdo, cont+1, false);
            }
        }
    }
//    void espacios(Nodo *nodo=NULL,int cont = 0, bool r = true){
//        int cont2 = 0;
//        if(raiz == NULL){
//            return;
//        }else{
//            if(r){
//                nodo = raiz;
//            }
//            if(nodo->izquierdo){
//                cont = NumeroNodo2(nodo->izquierdo);
//                for(int i=0; i<cont; i++){
//                    cout << "   ";
//                }
//            }
//            cout << nodo->izquierdo->dato;
//            if(nodo->derecho){
//                cont2 = 0;
//                cont2 = NumeroNodo2(nodo->derecho) + 1;
//                for(int i=0; i<cont; i++){
//                    cout << "   ";
//                }
//            }
//            cout << nodo->derecho->dato;
//            cout<<endl;
//            espacios(nodo->izquierdo, cont = 0, false);
//            espacios(nodo->derecho, cont2 = 0, false);
//        }
//    }
    const int NumeroNodo2(Nodo *n)
    {
       contador = 0;

       auxContador(n); // FUnci�n auxiliar
       return contador;
    }

    int iz(Nodo *n = NULL){ //devuelve numero nodos de la izq
        int cont = 0;
        n = raiz;
        if(n->izquierdo){
            cont = NumeroNodo2(n->izquierdo);
        }
        return cont;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
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

#endif // ARBOLBINARIO_H_INCLUDED
