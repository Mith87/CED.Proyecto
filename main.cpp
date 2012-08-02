#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Cuenta.h"

using namespace std;

Cuenta *cuentaSeleccionada;

Cuenta *crearCuenta();
bool ejecutarOpcion(int);
void imprimirDatosCuenta(Cuenta *);
void mostrarMenuPrincipal();
void mostrarMenuCuenta();

int main()
{
    bool salir = false;
    int opcion;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        salir = ejecutarOpcion(opcion);

    } while (!salir);

    return EXIT_SUCCESS;
}

bool ejecutarOpcion(int opcion)
{
    bool salir = false;
    Cuenta *cuenta;

    switch (opcion) {
    case 1:
        cuenta = crearCuenta();
        imprimirDatosCuenta(cuenta);
        break;

    default:
        cout << "Error: Opcion no valida" << endl;
        break;
    }

    return salir;
}

void mostrarMenuPrincipal()
{
    cout << "[1] Registrar una cuenta" << endl;
    cout << "[2] Buscar cuenta por numero" << endl;
    cout << "[3] Buscar cuenta por nombre" << endl;
    cout << "[4] Salir" << endl;
}

void mostrarMenuCuenta()
{
    cout << "[1] Cambiar saldo" << endl;
    // aqui se podria poner eliminar cuenta, etc
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

    cout << endl;

    return new Cuenta(nombre, numero, tipo, saldo);
}
