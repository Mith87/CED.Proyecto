#include "Arbin.h"
#include <string>

Arbin::Arbin() : raiz(NULL), actual(NULL) {

}

Arbin::~Arbin() {
    borrarNodoCascada(raiz);
}

Nodo *Arbin::buscarNodo(int numero){

}

Nodo *Arbin::buscarNodo(std::string nombre){

}

void Arbin::insertarNodo(Cuenta *cta){

    Nodo *actual = raiz, *padre;
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
    if(!raiz) { raiz = new Nodo(cta);}
    //Agrega nuevo nodo a su respectiva posición
    (numero < padre->getCuenta()->getNumero())
            ? padre->setIzquierdo(new Nodo(cta))
            : padre->setDerecho(new Nodo(cta));
}

void Arbin::borrarNodoCascada(Nodo *nodo){

}
