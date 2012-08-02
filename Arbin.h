#ifndef ARBIN_H_
#define ARBIN_H_

#include "Nodo.h"
#include <string>

class Arbin
{
    public:
        Arbin();
        ~Arbin();

        bool insertarCuenta(Cuenta *);

        // buscar cuenta por numero de cuenta
        Cuenta *buscarCuenta(int);
        // buscar cuenta por numero de cliente
        Cuenta *buscarCuenta(std::string);

        void borrarNodoCascada(Nodo *);

        void recorrerInOrden(void (*func)(Cuenta *) , Nodo *nodo=NULL);

    private:
        Nodo *raiz;
        Nodo *actual;

        // buscar cuenta por numero de cuenta a partir de un nodo
        Cuenta *buscarCuenta(Nodo *, int);

        // buscar cuenta por nombre de cliente a partir de un nodo
        Cuenta *buscarCuenta(Nodo *, std::string);
};

#endif

