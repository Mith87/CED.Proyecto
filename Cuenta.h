#ifndef CUENTA_H
#define CUENTA_H

class Cuenta {
    public:
	//nombreCliente, numero, tipo, saldo
	Cuenta(string, string, string, float = 0 ); 
	~Cuenta();
		
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