#include "Arbin.h"
#include <string>

Arbin::Arbin() : raiz(NULL), actual(NULL) {

}

Arbin::~Arbin() {
    borrarNodoCascada(raiz);
}

Cuenta *Arbin::buscarCuenta(Nodo *nodo, int numero){

    if(numero == nodo->getCuenta()->getNumero())
        return nodo->getCuenta();

    return (numero < nodo->getCuenta()->getNumero())
            ? buscarCuenta(nodo->getIzquierdo(), numero)
            : buscarCuenta(nodo->getDerecho(), numero);
}

Cuenta *Arbin::buscarCuenta(Nodo *nodo, std::string nombre){

    if(nombre == nodo->getCuenta()->getNombreCliente())
        return nodo->getCuenta();

    Cuenta *izq, *der;

    if(nodo->getIzquierdo()){
        izq = buscarCuenta(nodo->getIzquierdo(), nombre);
        if(izq) return izq;
    }
    if(nodo->getDerecho()){
        der = buscarCuenta(nodo->getDerecho(), nombre);
        if(der) return der;
    }

    //si llega a este punto
    //cuenta no existe
    return NULL;
}

bool Arbin::insertarCuenta(Cuenta *cta){

    Nodo *padre; actual = raiz;
    int numero = cta->getNumero();

    //Arbol vacío, crea raíz
    if(!raiz) { raiz = new Nodo(cta); return true; }

    while(actual && numero != actual->getCuenta()->getNumero()) {
        padre = actual;
       (numero < actual->getCuenta()->getNumero())
            ? actual = actual->getIzquierdo()
            : actual = actual->getDerecho();
    }

    //Cuenta existe
    if(actual) return false;
    //Agrega nuevo nodo a su respectiva posición
    (numero < padre->getCuenta()->getNumero())
            ? padre->setIzquierdo(new Nodo(cta))
            : padre->setDerecho(new Nodo(cta));

    return true;
}

void Arbin::borrarNodoCascada(Nodo *nodo){

    if(nodo){
        borrarNodoCascada(nodo->getIzquierdo());
        borrarNodoCascada(nodo->getDerecho());
        delete nodo;
    }
}

void Arbin::recorrerInOrden(void (*func)(Cuenta *), Nodo *nodo) {
   //valida si nodo existe (default: nodo = null)
   if(!nodo){
       //nodo es hoja o raiz, evita endless loop
       if(nodo->esHoja()) return;
       else nodo = this->raiz;
   }
   //recorrido recursivo de nodos in-orden
   if(nodo->getIzquierdo()) recorrerInOrden(func, nodo->getIzquierdo());
   func(nodo->getCuenta());
   if(nodo->getDerecho()) recorrerInOrden(func, nodo->getDerecho());
}
