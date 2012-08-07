#include "Arbin.h"
#include <string>
#include <iostream>

Arbin::Arbin() : raiz(NULL), actual(NULL) {}

Arbin::~Arbin()
{
    borrarNodoCascada(raiz);
}

Cuenta *Arbin::buscarCuenta(int numero) const
{
    return buscarCuenta(raiz, numero);
}

Cuenta *Arbin::buscarCuenta(std::string nombre) const
{
    return buscarCuenta(raiz, nombre);
}

Cuenta *Arbin::buscarCuenta(Nodo *nodo, int numero) const
{
    nodo = buscarNodo(nodo, numero);
    return nodo ? nodo->getCuenta() : NULL;
}

Cuenta *Arbin::buscarCuenta(Nodo *nodo, std::string nombre) const
{
    nodo = buscarNodo(nodo, nombre);
    return nodo ? nodo->getCuenta() : NULL;
}

Nodo *Arbin::buscarNodo(Nodo *nodo, int numero) const
{
    // se llego a un nodo vacio, no se encontro la cuenta
    if (!nodo) {
        return NULL;
    }

    if (numero == nodo->getCuenta()->getNumero()) {
        return nodo;
    }

    return (numero < nodo->getCuenta()->getNumero())
            ? buscarNodo(nodo->getIzquierdo(), numero)
            : buscarNodo(nodo->getDerecho(), numero);
}

Nodo *Arbin::buscarNodo(Nodo *nodo, std::string nombre) const
{
    if (!nodo) {
        return NULL;
    }

    if (nombre == nodo->getCuenta()->getNombreCliente()) {
        return nodo;
    }

    Nodo *izq, *der;

    if (nodo->getIzquierdo()) {
        izq = buscarNodo(nodo->getIzquierdo(), nombre);
        if (izq) {
            return izq;
        }
    }

    if (nodo->getDerecho()) {
        der = buscarNodo(nodo->getDerecho(), nombre);
        if (der) {
            return der;
        }
    }

    // si llega a este punto
    // cuenta no existe
    return NULL;
}

bool Arbin::insertarCuentaRecursivo(Cuenta *cta) {
    return insertarCuentaRecursivo(cta, raiz);
}

bool Arbin::insertarCuentaRecursivo(Cuenta *cta, Nodo *nodo) {

    //Arbol vacío, crea raíz
    if(!nodo) {
        if (!raiz) {
            raiz = new Nodo(cta);
            return true;
        } else {
            return false;
        }
    }

    int numero = cta->getNumero();

    //Cuenta existe
    if (numero == nodo->getCuenta()->getNumero()) {
        return false;
    }

    if(numero < nodo->getCuenta()->getNumero()) {

        if(!nodo->getIzquierdo()) {

            nodo->setIzquierdo(new Nodo(cta, nodo));
            balancearNodo(nodo->getPadre());
            return true;

        } else {
            return insertarCuentaRecursivo(cta, nodo->getIzquierdo());
        }

    } else {

        if(!nodo->getDerecho()) {

            nodo->setDerecho(new Nodo(cta, nodo));
            balancearNodo(nodo->getPadre());
            return true;

        } else {
            return insertarCuentaRecursivo(cta, nodo->getDerecho());
        }
    }
}

void Arbin::borrarCuenta(int numero)
{
    borrarNodo(buscarNodo(raiz, numero));
}

void Arbin::borrarNodoCascada(Nodo *nodo)
{
    if (nodo) {
        borrarNodoCascada(nodo->getIzquierdo());
        borrarNodoCascada(nodo->getDerecho());

        delete nodo;
        nodo = NULL;
    }
}

void Arbin::borrarNodo(Nodo *nodo)
{
    Nodo *hijo, *padre;

    if (!nodo) {
        return;
    }

    // nodo hoja
    if (nodo->esHoja()) {

        if (nodo->getPadre()) {
            padre = nodo->getPadre();

            if (padre->getDerecho() == nodo) {
                padre->setDerecho(NULL);
            } else {
                padre->setIzquierdo(NULL);
            }
        } else {
            raiz = NULL;
        }

        delete nodo;
        nodo = NULL;

    // nodo solo tiene un hijo
    } else if (((hijo = nodo->getIzquierdo()) && !nodo->getDerecho()) ||
               ((hijo = nodo->getDerecho()) && !nodo->getIzquierdo())) {

        if (nodo->getPadre()) {
            padre = nodo->getPadre();

            if (padre->getDerecho() == nodo) {
                padre->setDerecho(hijo);
            } else {
                padre->setIzquierdo(hijo);
            }
            hijo->setPadre(padre);
        } else {
            // es nodo raiz, reemplazar con el hijo
            raiz = hijo;
            hijo->setPadre(NULL);
        }

        delete nodo;
        nodo = NULL;

    // nodo tiene a los dos hijos
    } else {

        Nodo *padre = nodo;

        if (nodo->getDerecho()->getIzquierdo()) {
            hijo = nodo->getDerecho();
            while (hijo->getIzquierdo()) {
                padre = hijo;
                hijo = hijo->getIzquierdo();
            }
            if (padre == nodo) {
                padre->setDerecho(NULL);
            } else {
                padre->setIzquierdo(NULL);
            }
        } else {
            hijo = nodo->getIzquierdo();
            while (hijo->getDerecho()) {
                padre = hijo;
                hijo = hijo->getDerecho();
            }

            if (padre == nodo) {
                padre->setIzquierdo(NULL);
            } else {
                padre->setDerecho(NULL);
            }
        }

        nodo->setCuenta(hijo->getCuenta());
        hijo->setCuenta(NULL);
        delete hijo;
    }
}

void Arbin::recorrerInOrden(void (*func)(Cuenta *)) const
{
    recorrerInOrden(func, raiz);
}

void Arbin::recorrerInOrden(void (*func)(Cuenta *), Nodo *nodo) const
{
    //valida si nodo existe (default: nodo )
    if (!nodo) {
       return;
    }
    //recorrido recursivo de nodos in-orden
    if(nodo->getIzquierdo()) {
       recorrerInOrden(func, nodo->getIzquierdo());
    }

    func(nodo->getCuenta());

    if(nodo->getDerecho()) {
       recorrerInOrden(func, nodo->getDerecho());
    }
}

void Arbin::balancearNodo(Nodo *nodo) {

    if(!nodo) {
        return;
    }

    //obtiene el balance
    int balance = getBalanceNodo(nodo);
    //valor absoluto |balance| para
    //saber si el balance se ha excedido > 1
    if(abs(balance) > 1) {
        //if arbol pesado en la
        //derecha (right-heavy)
        if(balance > 0) {

            int sBalance = getBalanceNodo(nodo->getDerecho());
            //if necesario rotacion derecha-izquierda
            //por exceso de peso a izquierda del subnodo
            if(sBalance < 0) {
                rotacionDerecha(nodo->getDerecho());
            }

            //se rota el subnodo derecho de raiz
            rotacionIzquierda(nodo->getDerecho());

        }
        //else arbol pesado en la
        //izquierda (left-heavy)
        else {

            int sBalance = getBalanceNodo(nodo->getIzquierdo());
            //if necesario rotacion izquierda-derecha
            //por exceso de peso a la derecha del subnodo
            if(sBalance > 0) {
                rotacionIzquierda(nodo->getIzquierdo());
            }

            //se rota el subnodo izquierdo de raiz
            rotacionDerecha(nodo->getIzquierdo());
        }
    }
}

int Arbin::abs(int a) {
    return ( (a<0) ? a*(-1) : a);
}

int Arbin::getBalanceNodo(Nodo *nodo) {

    int hIzq = (nodo->getIzquierdo()) //subnodo izquierdo == null?
        ? getMaxAlturaNodo(nodo->getIzquierdo()) //altura de hoja mas baja
        : nodo->getAltura(); //altura de raiz
    int hDer = (nodo->getDerecho()) //subnodo derecho == null?
        ? getMaxAlturaNodo(nodo->getDerecho()) //altura de hoja mas baja
        : nodo->getAltura(); //altura de raiz

    return hDer - hIzq;
}

int Arbin::getMaxAlturaNodo(Nodo *nodo){

    int hIzq = 0, hDer = 0;

    if(nodo->esHoja()) {
        return nodo->getAltura();
    } else {
        if(nodo->getIzquierdo()) {
            hIzq = getMaxAlturaNodo(nodo->getIzquierdo());
        }
        if(nodo->getDerecho()) {
            hDer = getMaxAlturaNodo(nodo->getDerecho());
        }

        return (hIzq <= hDer) ? hDer : hIzq;
    }
}

void Arbin::rotacionIzquierda(Nodo *nodo) {

    //obtiene el padre del padre (predecesor)
    Nodo *predecesor = nodo->getPadre()->getPadre();
    Nodo *padre = nodo->getPadre();

    //si es la raiz del arbol
    if(!predecesor) {
        //raiz pasa a ser el nodo desbalanceado
        raiz = nodo;
    } else {
        predecesor->setDerecho(nodo);
    }

    padre->setDerecho(nodo->getIzquierdo());
    nodo->setIzquierdo(padre);

    //modifica la altura de los nodos
    nodo->decAltura();
    nodo->getDerecho()->decAltura();
    padre->incAltura();
}

void Arbin::rotacionDerecha(Nodo *nodo) {

    //obtiene el padre del padre (predecesor)
    Nodo *predecesor = nodo->getPadre()->getPadre();
    Nodo *padre = nodo->getPadre();

    //si es la raiz del arbol
    if(!predecesor) {
        //raiz pasa a ser el nodo desbalanceado
        raiz = nodo;
    } else {
        predecesor->setIzquierdo(nodo);
    }

    padre->setIzquierdo(nodo->getDerecho());
    nodo->setDerecho(padre);

    //modifica la altura de los nodos
    nodo->decAltura();
    nodo->getIzquierdo()->decAltura();
    padre->incAltura();
}
