#ifndef CUENTA_H_
#define CUENTA_H_

#include <string>

class Cuenta
{
    public:
        //nombreCliente, numero, tipo, saldo
        Cuenta(std::string, int, std::string, float = 0);
        ~Cuenta();

        //Accesadores
        int getNumero();
        std::string getTipo();
        std::string getNombreCliente();
        float getSaldo();

        //Mutadores
        void setSaldo(float);

    private:
        std::string nombreCliente;
        int num;
        std::string tipo;
        float saldo;
};

#endif
