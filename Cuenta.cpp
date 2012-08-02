#include "Cuenta.h"
#include <string>

Cuenta::Cuenta(std::string nombre, int num, std::string tipo, float saldo)
    : nombreCliente(nombre), num(num), tipo(tipo), saldo(saldo) { }

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

// Mutadores

void Cuenta::setSaldo(float saldo)
{
    this->saldo = saldo;
}
