#include "Nodo.h"
#include "Cuenta.h"

Nodo::Nodo(Cuenta *cta, Nodo *padre)
    : cuenta(cta), padre(padre), izquierdo(NULL),
        derecho(NULL) {

        altura = (padre) ? padre->getAltura() + 1 : 0;
        cta->setAltura(altura);
}

Nodo::~Nodo()
{
    delete cuenta;
}

// Métodos

bool Nodo::esHoja() const
{
    return (!this->getIzquierdo() && !this->getDerecho());
}

// Accesadores

Cuenta *Nodo::getCuenta() const
{
    return this->cuenta;
}

Nodo *Nodo::getIzquierdo() const
{
    return this->izquierdo;
}

Nodo *Nodo::getDerecho() const
{
    return this->derecho;
}

Nodo *Nodo::getPadre() const
{
    return this->padre;
}

int Nodo::getAltura() const
{
    return this->altura;
}

// Mutadores

void Nodo::setCuenta(Cuenta *cta)
{
    this->cuenta = cta;
}

void Nodo::setIzquierdo(Nodo *izq)
{
    this->izquierdo = izq;
}

void Nodo::setDerecho(Nodo *der)
{
    this->derecho = der;
}

void Nodo::setPadre(Nodo *padre)
{
    this->padre = padre;
}

void Nodo::setAltura(int h)
{
    this->altura = h;
    this->getCuenta()->setAltura(h);
}

void Nodo::incAltura()
{
    this->altura++;
    this->cuenta->setAltura(this->altura);
}

void Nodo::decAltura()
{
    this->altura--;
    this->cuenta->setAltura(this->altura);
}
