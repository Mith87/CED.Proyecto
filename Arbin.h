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
        Cuenta *buscarCuenta(int) const;
        // buscar cuenta por numero de cliente
        Cuenta *buscarCuenta(std::string) const;

        void borrarNodoCascada(Nodo *);

        void recorrerInOrden(void (*func)(Cuenta *) , Nodo *nodo=NULL) const;

    private:
        Nodo *raiz;
        Nodo *actual;

        // buscar cuenta por numero de cuenta a partir de un nodo
        Cuenta *buscarCuenta(Nodo *, int) const;

        // buscar cuenta por nombre de cliente a partir de un nodo
        Cuenta *buscarCuenta(Nodo *, std::string) const;
};

#endif

