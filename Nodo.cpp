#include "Nodo.h"
#include "Cuenta.h"

Nodo::Nodo(Cuenta * cta, Nodo * izq, Nodo * der) {

    this->cuenta = cta;
    this->izquierdo = izq;
    this->derecho = der;
}

Nodo::~Nodo() {

}

Cuenta * Nodo::getCuenta() const {
    return this->cuenta;
}

Cuenta * Nodo::getIzquierdo() const {
    return this->izquierdo;
}

Cuenta * Nodo::getDerecho() const {
    return this->derecho;
}

void Nodo::setCuenta(Cuenta * cta) {
    this->cuenta = cta;
}

void Nodo::setIzquierdo(Nodo * izq) {
    this->izquierdo = izq;
}

void Nodo::setDerecho(Nodo * der) {
    this->derecho = der;
}