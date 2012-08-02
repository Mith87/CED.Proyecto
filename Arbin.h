#ifndef ARBIN_H_
#define ARBIN_H_

#include "Nodo.h"
#include <string>

class Arbin
{
    public:
        Arbin();
        ~Arbin();

        Nodo *buscarNodo(Nodo *, int);
        Nodo *buscarNodo(Nodo *, std::string);
        void insertarNodo(Cuenta *);
        void borrarNodoCascada(Nodo *);
        void recorrerInOrden(void (*func)(Cuenta *) , Nodo *nodo=NULL);

    private:
        Nodo *raiz;
        Nodo *actual;

};

#endif

