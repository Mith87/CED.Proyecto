#include <iostream>
#include "GestorCuentas.h"

namespace GestorCuentas
{
    using namespace std;

    namespace
    {
        Cuenta *cuentaSeleccionada;
        Arbin *arbolDolares = new Arbin();
        Arbin *arbolColones = new Arbin();

        Arbin *seleccionarArbol(char charTipo)
        {
            return (charTipo == 'c') ? arbolColones : arbolDolares;
        }
    }

    bool registrar(string nombre, int numero, char charTipo, float saldo)
    {
        Arbin *arbol = seleccionarArbol(charTipo);
        string tipo = (charTipo == 'c') ? "colones" : "dolares";
        Cuenta *cuenta = new Cuenta(nombre, numero, tipo, saldo);

        return arbol->insertarCuenta(cuenta);
    }

    void imprimirDatos(Cuenta *cuenta)
    {
        using namespace std;
        cout << "=== Datos de la cuenta ===" << endl;
        cout << "Numero: " << cuenta->getNumero() << endl;
        cout << "Nombre: " << cuenta->getNombreCliente() << endl;
        cout << "Saldo: " << cuenta->getSaldo() << endl;
        cout << "Tipo: " << cuenta->getTipo() << endl;
        cout << endl;
    }

    bool buscarPorNumero(int numero, char charTipo)
    {
        Arbin *arbol = seleccionarArbol(charTipo);
        cuentaSeleccionada = arbol->buscarCuenta(numero);

        if (cuentaSeleccionada) {
            imprimirDatos(cuentaSeleccionada);
        }

        return cuentaSeleccionada;
    }

    bool buscarPorNombre(std::string nombre, char charTipo)
    {
        Arbin *arbol = seleccionarArbol(charTipo);
        cuentaSeleccionada = arbol->buscarCuenta(nombre);

        if (cuentaSeleccionada) {
            imprimirDatos(cuentaSeleccionada);
        }

        return cuentaSeleccionada;
    }
}
