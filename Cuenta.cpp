#include "Cuenta.h"
#include <string>


Cuenta::Cuenta(std::string nombre, int num, std::string tipo, float saldo = 0)
    : nombreCliente(nombre), num(num), tipo(tipo), saldo(saldo) {

    //this->nombreCliente = nombreCliente;
    //this->num = num;
    //this->tipo = tipo;
    //setSaldo(saldo);
}

Cuenta::~Cuenta() {
}

//Accesadores

std::string Cuenta::getNombreCliente() {
    return nombreCliente;
}

int Cuenta::getNumero() {
    return num;
}

std::string Cuenta::getTipo() {
    return tipo;
}

float Cuenta::getSaldo() {
    return saldo;
}

//Mutadores

void Cuenta::setSaldo(float saldo) {
    this->saldo = saldo;
}
