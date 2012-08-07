#include "Cuenta.h"
#include <string>

Cuenta::Cuenta(std::string nombre, int num, std::string tipo, float saldo)
    : nombreCliente(nombre), num(num), tipo(tipo), saldo(saldo) , altura(0) { }

Cuenta::~Cuenta() {}

// Accesadores

std::string Cuenta::getNombreCliente() const
{
    return nombreCliente;
}

int Cuenta::getNumero() const
{
    return num;
}

std::string Cuenta::getTipo() const
{
    return tipo;
}

float Cuenta::getSaldo() const
{
    return saldo;
}

int Cuenta::getAltura() const
{
    return altura;
}

// Mutadores

void Cuenta::setSaldo(float saldo)
{
    this->saldo = saldo;
}

void Cuenta::setAltura(int h)
{
    this->altura = h;
}

