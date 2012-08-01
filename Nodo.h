#ifndef NODO_H_
#define NODO_H_

#include "Cuenta.h"

class Nodo
{
    public:
        //cuenta, izquierdo, derecho
        Nodo(Cuenta *, Nodo *izq=NULL, Nodo *der=NULL);
        ~Nodo();

        //Métodos
        bool esHoja() const;

        //Accesadores
        Cuenta *getCuenta() const;
        Nodo *getIzquierdo() const;
        Nodo *getDerecho() const;

        //Mutadores
        void setCuenta(Cuenta *);
        void setIzquierdo(Nodo *);
        void setDerecho(Nodo *);

    private:
        Cuenta *cuenta;
        Nodo *izquierdo;
        Nodo *derecho;

};

#endif
