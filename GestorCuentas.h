#ifndef GESTOR_CUENTAS_H_
#define GESTOR_CUENTAS_H_

#include <string>
#include "Arbin.h"
#include "Cuenta.h"

namespace GestorCuentas
{
    // registra una cuenta, devuelve si se pudo registrar la cuenta
    bool registrar(std::string, int, char, float);

    // busca una cuenta por numero, devuelve si se pudo encontrar
    bool buscarPorNumero(int, char);
    // busca una cuenta por nombre de cliente, devuelve si se pudo encontrar
    bool buscarPorNombre(std::string, char);

    // imprime los datos de una cuenta
    void imprimirDatos(Cuenta *);
}

#endif
