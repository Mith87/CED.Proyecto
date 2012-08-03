#include <iostream>
#include <cstdlib>
#include <sstream>
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
void cambiarSaldoCuenta();

char leerChar(string);
int leerInt(string);
float leerFloat(string);
string leerString(string);

int main(int argc, char **argv)
{
    bool salir = false;
    char opcion;

    if (argc > 1 && strcmp(argv[1], "--prueba") == 0) {
        GestorCuentas::registrarDatosPrueba();
    }

    cout << " --==Proyecto Final, Estructuras de Datos 1==-- " << endl;
    cout << " Integrantes: Ernesto Villarreal, Pablo Naranjo " << endl;
    cout << endl;

    do {
        bool c = GestorCuentas::hayCuentaSeleccionada();

        if (c) {
            GestorCuentas::imprimirDatos();
            cout << endl;
            mostrarMenuCuenta();
        } else {
            mostrarMenuPrincipal();
        }

        opcion = leerChar("");
        cout << endl;

        salir = ejecutarOpcion(opcion);

        if (c && salir) {
            GestorCuentas::deseleccionarCuenta();
            salir = false;
        }

    } while (!salir);

    GestorCuentas::finalizar();

    return EXIT_SUCCESS;
}

bool ejecutarOpcion(int opcion)
{
    bool salir = false;

    switch (opcion) {

    if (GestorCuentas::hayCuentaSeleccionada()) {
        case 'r':
            crearCuenta();
            break;

        case 'c':
        case 'd':
            buscarCuenta(opcion);
            break;
    } else {
        case 's':
            cambiarSaldoCuenta();
            break;
    }

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
    cout << "=== Menu de cuenta ===" << endl;
    cout << "[s] Cambiar saldo" << endl;
    cout << "[q] Salir" << endl;
    cout << "Seleccione una opcion: ";
    // aqui se podria tambien poner eliminar cuenta, etc
}

void crearCuenta()
{
    string nombre;
    char tipo;
    int numero;
    float saldo;

    cout << "=== Introduzca los datos de la cuenta ===" << endl;

    numero = leerInt("Numero: ");
    nombre = leerString("Nombre: ");
    tipo = leerChar("Tipo (colones: c, dolares: d): ");

    // si se ingreso un tipo invalido, usar colones por defecto
    if (tipo != 'c' || tipo != 'd') {
        tipo = 'c';
    }

    saldo = leerFloat("Saldo: ");

    cout << endl;

    if(GestorCuentas::registrar(nombre, numero, tipo, saldo)) {
        cout << "La cuenta ha sido registrada" << endl;
    } else {
        cout << "La cuenta no se pudo registrar" << endl;
    }
}

void cambiarSaldoCuenta() {
    float saldo = leerFloat("Saldo: ");
    GestorCuentas::cambiarSaldo(saldo);
}

void buscarCuenta(char tipo) {
    cout << "Buscar por:" << endl;
    cout << "[1] Numero" << endl;
    cout << "[2] Nombre" << endl;
    char c = leerChar("Seleccione una opcion: ");

    (c == '1') ? buscarCuentaPorNumero(tipo) : buscarCuentaPorNombre(tipo);
}

void buscarCuentaPorNumero(char tipo) {
    int numero = leerInt("Numero: ");

    if (!GestorCuentas::buscarPorNumero(numero, tipo)) {
        cout << "Error: La cuenta no se pudo encontrar" << endl;
    }

    cout << endl;
}

void buscarCuentaPorNombre(char tipo)
{
    string nombre = leerString("Nombre: ");

    if (!GestorCuentas::buscarPorNombre(nombre, tipo)) {
        cout << "Error: La cuenta no se pudo encontrar" << endl;
    }

    cout << endl;
}

int leerInt(string msj)
{
    string input = "";
    int num;

    for (;;) {
        cout << msj;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> num) {
            break;
        }

        cout << "Numero invalido, trate de nuevo" << endl;
    }

    return num;
}

float leerFloat(string msj)
{
    string input = "";
    float num;

    for (;;) {
        cout << msj;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> num) {
            break;
        }

        cout << "Numero invalido, trate de nuevo" << endl;
    }

    return num;
}

string leerString(string msj)
{
    string nombre = "";
    cout << msj;

    getline(cin, nombre);

    return nombre;
}

char leerChar(string msj)
{
    string input = "";
    char c;

    for (;;) {
        cout << msj;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> c) {
            break;
        }

        cout << "Caracter invalido, trate de nuevo" << endl;
    }

    return c;
}
