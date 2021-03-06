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
void mostrarMenuInorden();

void crearCuenta();
void buscarCuenta(char);
void buscarCuentaPorNumero(char);
void buscarCuentaPorNombre(char);
void cambiarSaldoCuenta();
void imprimirInOrden(char);
void eliminarCuenta();

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



    if (!GestorCuentas::hayCuentaSeleccionada()) {
        switch (opcion) {
        case 'r':
            crearCuenta();
            break;
        case 'c':
            buscarCuenta(opcion);
            break;
        case 'd':
            buscarCuenta(opcion);
            break;
        case 'i':
            mostrarMenuInorden();
            break;
        default:
            cout << "Error: Opcion no valida" << endl;
            break;
        case 'q':
            salir = true;
            break;
        }
    } else {
        switch (opcion) {
        case 's':
            cambiarSaldoCuenta();
            break;
        case 'e':
            eliminarCuenta();
            break;
        default:
            cout << "Error: Opcion no valida" << endl;
            break;
        case 'q':
            salir = true;
            break;
        }
    }

    return salir;
}

void mostrarMenuPrincipal()
{
    cout << endl;
    cout << "=== Menu principal ===" << endl;
    cout << "[r] Registrar una cuenta" << endl;
    cout << "[c] Buscar cuenta en colones" << endl;
    cout << "[d] Buscar cuenta en dolares" << endl;
    cout << "[i] Imprimir Arbol Inorden" << endl;
    cout << "[q] Salir" << endl;
    cout << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuCuenta()
{
    cout << endl;
    cout << "=== Menu de cuenta ===" << endl;
    cout << "[s] Cambiar saldo" << endl;
    cout << "[e] Eliminar cuenta" << endl;
    cout << "[q] Salir" << endl;
    cout << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuInorden()
{
    cout << endl;
    cout << "=== Impresion In-Orden ===" << endl;
    cout << "[c] Arbol Colones" << endl;
    cout << "[d] Arbol Dolares" << endl;
    cout << endl;
    char c = leerChar("Seleccione una opcion: ");

    (c == 'c') ? imprimirInOrden('c') : imprimirInOrden('d');
}

void imprimirInOrden(char tipo) {
    GestorCuentas::imprimirInOrden(tipo);
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
    if (tipo != 'c' && tipo != 'd') {
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

void eliminarCuenta() {
    GestorCuentas::eliminarCuenta();
    cout << "Se elimino la cuenta" << endl;
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
        cout << "Error: La cuenta no se pudo encontrar";
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

        cout << "Opcion invalida, trate de nuevo: ";
    }

    return c;
}
