#include "Nodo.h"
#include "Cuenta.h"

Nodo::Nodo(Cuenta *cta, Nodo *izq, Nodo *der)
    : cuenta(cta), izquierdo(izq), derecho(der) {

    //this->cuenta = cta;
    //this->izquierdo = izq;
    //this->derecho = der;
}

Nodo::~Nodo() {
    if(cuenta) delete cuenta;
}

//Métodos

bool Nodo::esHoja() const {
    return (!this->izquierdo && !this->derecho);
}

//Accesadores

Cuenta *Nodo::getCuenta() const {
    return this->cuenta;
}

Nodo *Nodo::getIzquierdo() const {
    return this->izquierdo;
}

Nodo *Nodo::getDerecho() const {
    return this->derecho;
}

//Mutadores

void Nodo::setCuenta(Cuenta *cta) {
    this->cuenta = cta;
}

void Nodo::setIzquierdo(Nodo *izq) {
    this->izquierdo = izq;
}

void Nodo::setDerecho(Nodo *der) {
    this->derecho = der;
}
