#include "Arbin.h"
#include <string>

Arbin::Arbin() : raiz(NULL), actual(NULL) {

}

Arbin::~Arbin() {
    borrarNodoCascada(raiz);
}

Nodo *Arbin::buscarNodo(Nodo *nodo, int numero){

    if(numero == nodo->getCuenta()->getNumero())
        return nodo;

    return (numero < nodo->getCuenta()->getNumero())
            ? buscarNodo(nodo->getIzquierdo(), numero)
            : buscarNodo(nodo->getDerecho(), numero);
}

Nodo *Arbin::buscarNodo(Nodo *nodo, std::string nombre){

}

void Arbin::insertarNodo(Cuenta *cta){

    Nodo *padre; actual = raiz;
    int numero = cta->getNumero();

    while(!actual && numero != actual->getCuenta()->getNumero()) {
        padre = actual;
       (numero < actual->getCuenta()->getNumero())
            ? actual = actual->getIzquierdo()
            : actual = actual->getDerecho();
    }

    //Cuenta existe
    if(actual) return;
    //Arbol vacío, crea raíz
    if(!raiz) { raiz = new Nodo(cta); return; }
    //Agrega nuevo nodo a su respectiva posición
    (numero < padre->getCuenta()->getNumero())
            ? padre->setIzquierdo(new Nodo(cta))
            : padre->setDerecho(new Nodo(cta));
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
