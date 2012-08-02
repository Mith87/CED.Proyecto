#ifndef ARBIN_H_
#define ARBIN_H_

#include "Nodo.h"
#include <string>

class Arbin
{
    public:
        Arbin();
        ~Arbin();

        Cuenta *buscarCuenta(Nodo *, int);
        Cuenta *buscarCuenta(Nodo *, std::string);
        bool insertarCuenta(Cuenta *);
        void borrarNodoCascada(Nodo *);
        void recorrerInOrden(void (*func)(Cuenta *) , Nodo *nodo=NULL);

    private:
        Nodo *raiz;
        Nodo *actual;

};

#endif

