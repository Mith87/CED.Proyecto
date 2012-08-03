#ifndef GESTOR_CUENTAS_H_
#define GESTOR_CUENTAS_H_

#include <string>
#include "Arbin.h"
#include "Cuenta.h"

namespace GestorCuentas
{
    // indica si hay una cuenta seleccionada (resultado de una busqueda)
    bool hayCuentaSeleccionada();
    // deselecciona la cuenta
    void deseleccionarCuenta();
    // cambia el saldo de la cuenta seleccionada
    void cambiarSaldo(float);

    // registra varias cuentas de prueba
    void registrarDatosPrueba();
    // registra una cuenta, devuelve si se pudo registrar la cuenta
    bool registrar(std::string, int, char, float);
    // busca una cuenta por numero (la guarda como cuenta seleccionada), devuelve si se pudo encontrar
    bool buscarPorNumero(int, char);
    // busca una cuenta por nombre de cliente (la guarda como cuenta seleccionada), devuelve si se pudo encontrar
    bool buscarPorNombre(std::string, char);

    // imprime los datos de una cuenta
    void imprimirDatos(Cuenta *cuenta=NULL);

    void finalizar();
}

#endif
