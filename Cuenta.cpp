#include "Cuenta.h"
#include <string>


Cuenta::Cuenta(std::string nombreCliente, int num, std::string tipo, float saldo = 0) {

    this->nombreCliente = nombreCliente;
    this->num = num;
    this->tipo = tipo;

    setSaldo(saldo);
}

Cuenta::~Cuenta() {

}

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

void Cuenta::setSaldo(float saldo) {
    this->saldo = saldo;
}
