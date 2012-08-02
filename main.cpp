#include <iostream>
#include <cstdlib>
#include <string.h>

#include "GestorCuentas.h"
#include "Cuenta.h"

using namespace std;

bool ejecutarOpcion(int);
void mostrarMenuPrincipal();
void mostrarMenuCuenta();

void crearCuenta();
void buscarCuenta(char);
void buscarCuentaPorNumero(char);
void buscarCuentaPorNombre(char);

char leerTipoCuenta();

int main(int argc, char **argv)
{
    bool salir = false;
    char opcion;

    if (strcmp(argv[1], "--prueba") == 0) {
        GestorCuentas::registrarDatosPrueba();
    }

    cout << " --==Proyecto Final, Estructuras de Datos 1==-- " << endl;
    cout << " Integrantes: Ernesto Villarreal, Pablo Naranjo " << endl;
    cout << endl;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        cout << endl;

        salir = ejecutarOpcion(opcion);
        cout << endl;

    } while (!salir);

    return EXIT_SUCCESS;
}

bool ejecutarOpcion(int opcion)
{
    bool salir = false;

    switch (opcion) {
    case 'r':
        crearCuenta();
        break;

    case 'c':
    case 'd':
        buscarCuenta(opcion);
        break;

    case 'q':
        salir = true;
        break;

    default:
        cout << "Error: Opcion no valida" << endl;
        break;
    }

    return salir;
}

void mostrarMenuPrincipal()
{
    cout << "=== Menu principal ===" << endl;
    cout << "[r] Registrar una cuenta" << endl;
    cout << "[c] Buscar cuenta en colones" << endl;
    cout << "[d] Buscar cuenta en dolares" << endl;
    cout << "[q] Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuCuenta()
{
    cout << "[s] Cambiar saldo" << endl;
    cout << "[q] Salir" << endl;
    // aqui se podria poner eliminar cuenta, etc
}

void crearCuenta()
{
    string nombre;
    char tipo;
    int numero;
    float saldo;

    cout << "=== Introduzca los datos de la cuenta ===" << endl;

    cout << "Numero: ";
    cin >> numero;

    cout << "Nombre: ";
    cin >> nombre;

    tipo = leerTipoCuenta();

    cout << "Saldo: ";
    cin >> saldo;

    cout << endl;

    if(GestorCuentas::registrar(nombre, numero, tipo, saldo)) {
        cout << "La cuenta ha sido registrada" << endl;
    } else {
        cout << "La cuenta no se pudo registrar" << endl;
    }
}

void buscarCuenta(char tipo) {
    char c;
    cout << "Buscar por:" << endl;
    cout << "[1] Numero" << endl;
    cout << "[2] Nombre" << endl;
    cout << "Seleccione una opcion: ";

    cin >> c;
    (c == '1') ? buscarCuentaPorNumero(tipo) : buscarCuentaPorNombre(tipo);
}

void buscarCuentaPorNumero(char tipo) {
    int numero;

    cout << "Numero: ";
    cin >> numero;

    if (GestorCuentas::buscarPorNumero(numero, tipo)) {
        GestorCuentas::imprimirDatos();
    } else {
        cout << "Error: La cuenta no se pudo encontrar" << endl;
    }
}

void buscarCuentaPorNombre(char tipo)
{
    string nombre;

    cout << "Nombre: ";
    cin >> nombre;

    if (GestorCuentas::buscarPorNombre(nombre, tipo)) {
        GestorCuentas::imprimirDatos();
    } else {
        cout << "Error: La cuenta no se pudo encontrar" << endl;
    }
}

char leerTipoCuenta()
{
    char tipo;
    cout << "Tipo (dolares: d, colones: c): ";
    cin >> tipo;

    return tipo;
}
