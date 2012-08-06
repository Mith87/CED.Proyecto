#ifndef NODO_H_
#define NODO_H_

#include "Cuenta.h"

class Nodo
{
    public:
        //cuenta, izquierdo, derecho
        //Nodo(Cuenta *, Nodo *izq=NULL, Nodo *der=NULL);
        Nodo(Cuenta *, Nodo *padre=NULL);
        ~Nodo();

        //Métodos
        bool esHoja() const;

        //Accesadores
        Cuenta *getCuenta() const;
        Nodo *getPadre() const;
        Nodo *getIzquierdo() const;
        Nodo *getDerecho() const;
        int getAltura() const;

        //Mutadores
        void setCuenta(Cuenta *);
        void setIzquierdo(Nodo *);
        void setDerecho(Nodo *);
        void setPadre(Nodo *);
        void setAltura(int h);


    private:
        Cuenta *cuenta;
        Nodo *padre;
        Nodo *izquierdo;
        Nodo *derecho;
        int altura;

};

#endif
