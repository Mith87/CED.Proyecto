#ifndef CUENTA_H
#define CUENTA_H

class Cuenta {
    public:
	Cuenta();
	~Cuenta();
		
	int crearCuenta(string , string , float);
		
	float getSaldo();
	string getTipo();
	string getNombreCliente();
	string getNumero();
		
	void setSaldo(float);

    private:
	string num; 
	string tipo;
	string nombreCliente;
	float saldo;
};

#endif