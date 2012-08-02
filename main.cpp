#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Cuenta.h"

using namespace std;

Cuenta *crearCuenta();
void imprimirDatosCuenta(Cuenta *);
void mostrarMenu();

int main()
{
    Cuenta *cuenta = crearCuenta();

    imprimirDatosCuenta(cuenta);

    delete cuenta;
    return EXIT_SUCCESS;
}

void imprimirDatosCuenta(Cuenta *cuenta)
{
    cout << "== Datos de la cuenta ==" << endl;
    cout << "Numero: " << cuenta->getNumero() << endl;
    cout << "Nombre: " << cuenta->getNombreCliente() << endl;
    cout << "Saldo: " << cuenta->getSaldo() << endl;
    cout << "Tipo: " << cuenta->getTipo() << endl;
    cout << endl;
}

Cuenta *crearCuenta()
{
    string nombre, tipo;
    char charTipo;
    int numero;
    float saldo;

    cout << "== Introduzca los datos de la cuenta ==" << endl;

    cout << "Numero: ";
    cin >> numero;

    cout << "Nombre: ";
    cin >> nombre;

    cout << "Tipo: ";
    cin >> charTipo;

    tipo = (charTipo == 'c') ? "colones" : "dolares";

    cout << "Saldo: ";
    cin >> saldo;

    cout >> endl;

    return new Cuenta(nombre, numero, tipo, saldo);
}
