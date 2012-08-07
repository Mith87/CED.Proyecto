#ifndef ARBIN_H_
#define ARBIN_H_

#include "Nodo.h"
#include <string>

class Arbin
{
    public:
        Arbin();
        ~Arbin();

        bool insertarCuentaRecursivo(Cuenta *);

        // buscar cuenta por numero de cuenta
        Cuenta *buscarCuenta(int) const;
        // buscar cuenta por numero de cliente
        Cuenta *buscarCuenta(std::string) const;

        void borrarCuenta(int);
        void recorrerInOrden(void (*func)(Cuenta *)) const;

    private:
        Nodo *raiz;
        Nodo *actual; //no se usa

        // buscar cuenta por numero de cuenta a partir de un nodo
        Cuenta *buscarCuenta(Nodo *, int) const;
        // buscar cuenta por nombre de cliente a partir de un nodo
        Cuenta *buscarCuenta(Nodo *, std::string) const;

        Nodo *buscarNodo(Nodo *, int) const;
        Nodo *buscarNodo(Nodo *, std::string) const;

        void borrarNodo(Nodo *);

        int abs(int);
        int getMaxAlturaNodo(Nodo *);
        int getBalanceNodo(Nodo *);

        bool insertarCuentaRecursivo(Cuenta *, Nodo *);

        void balancearNodo(Nodo *);
        void rotacionIzquierda(Nodo *);
        void rotacionDerecha(Nodo *);
        void borrarNodoCascada(Nodo *);
        void recorrerInOrden(void (*func)(Cuenta *) , Nodo *nodo) const;





};

#endif

