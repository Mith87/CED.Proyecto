#ifndef ARBIN_H_
#define ARBIN_H_

#include "Nodo.h"
#include <string>

class Arbin
{
    public:
        Arbin();
        ~Arbin();

        Nodo *buscarNodo(int);
        Nodo *buscarNodo(std::string);
        void insertarNodo(Cuenta *);
        void borrarNodoCascada(Nodo *);

    private:
        Nodo *raiz;
        Nodo *actual;

};

#endif

