#ifndef CUENTA_H_
#define CUENTA_H_

#include <string>

class Cuenta
{
    public:
        // nombreCliente, numero, tipo, saldo
        Cuenta(std::string, int, std::string, float = 0);
        ~Cuenta();

        // Accesadores
        int getNumero() const;
        std::string getTipo() const;
        std::string getNombreCliente() const;
        float getSaldo() const;
        int getAltura() const;

        // Mutadores
        void setSaldo(float);
        void setAltura(int);

    private:
        std::string nombreCliente;
        int num;
        std::string tipo;
        float saldo;
        int altura;
};

#endif
