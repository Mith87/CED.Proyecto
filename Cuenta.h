#ifndef CUENTA_H_
#define CUENTA_H_

#include <string>

class Cuenta
{
    public:
        //nombreCliente, numero, tipo, saldo
        Cuenta(std::string, int, std::string, float);
        ~Cuenta();

        int getNumero();
        std::string getTipo();
        std::string getNombreCliente();
        float getSaldo();

        void setSaldo(float);

    private:
        std::string nombreCliente;
        int num;
        std::string tipo;
        float saldo;
};

#endif
