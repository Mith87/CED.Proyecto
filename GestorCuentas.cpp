#include <iostream>
#include <sstream>
#include "GestorCuentas.h"

namespace GestorCuentas
{
    using namespace std;

    namespace
    {
        Cuenta *cuentaSeleccionada = NULL;
        Arbin *arbolDolares = NULL;
        Arbin *arbolColones = NULL;

        Arbin *seleccionarArbol(char charTipo)
        {
            Arbin **arbol = (charTipo == 'c') ? &arbolColones : &arbolDolares;

            if (!(*arbol)) {
                *arbol = (new Arbin());
            }

            return *arbol;
        }
    }

    void registrarDatosPrueba()
    {
        for (int i = 1; i <= 6; i++) {
            stringstream sstm;
            bool c = i <= 3;

            sstm << "Pablo " << i;

            registrar(sstm.str(), c ? i : i - 3, (c ? 'c' : 'd'), i * (c ? 1000 : 2));
        }
    }

    bool hayCuentaSeleccionada()
    {
        return cuentaSeleccionada != NULL;
    }

    void deseleccionarCuenta()
    {
        cuentaSeleccionada = NULL;
    }

    void cambiarSaldo(float saldo)
    {
        cuentaSeleccionada->setSaldo(saldo);
    }

    void eliminarCuenta() {
        char tipo = (cuentaSeleccionada->getTipo() == "colones") ? 'c' : 'd';
        Arbin *arbol = seleccionarArbol(tipo);
        arbol->borrarCuenta(cuentaSeleccionada->getNumero());
        deseleccionarCuenta();
    }

    bool registrar(string nombre, int numero, char charTipo, float saldo)
    {
        Arbin *arbol = seleccionarArbol(charTipo);
        string tipo = (charTipo == 'c') ? "colones" : "dolares";
        Cuenta *cuenta = new Cuenta(nombre, numero, tipo, saldo);

        //return arbol->insertarCuenta(cuenta);
        return arbol->insertarCuentaRecursivo(cuenta);
    }

    void imprimirDatos(Cuenta *cuenta)
    {
        using namespace std;

        if (!cuenta) {
            cuenta = cuentaSeleccionada;
        }

        cout << endl;
        cout << "--------------------------" << endl;
        cout << "=== Datos de la cuenta ===" << endl;
        cout << "Numero: " << cuenta->getNumero() << endl;
        cout << "Nombre: " << cuenta->getNombreCliente() << endl;
        cout << "Saldo: " << cuenta->getSaldo() << endl;
        cout << "Tipo: " << cuenta->getTipo() << endl;
    }

    void imprimirInOrden(char charTipo){
        Arbin *arbol = seleccionarArbol(charTipo);
        arbol->recorrerInOrden(imprimirDatos);
    }

    bool buscarPorNumero(int numero, char charTipo)
    {
        Arbin *arbol = seleccionarArbol(charTipo);
        cuentaSeleccionada = arbol->buscarCuenta(numero);

        return cuentaSeleccionada;
    }

    bool buscarPorNombre(std::string nombre, char charTipo)
    {
        Arbin *arbol = seleccionarArbol(charTipo);
        cuentaSeleccionada = arbol->buscarCuenta(nombre);

        return cuentaSeleccionada;
    }

    void finalizar()
    {
        if (arbolColones) {
            delete arbolColones;
        }

        if (arbolDolares) {
            delete arbolDolares;
        }
    }
}
