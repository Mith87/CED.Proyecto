#ifndef CUENTA_H
#define CUENTA_H

class Cuenta {

    private:
		string num, 
			   tipo,
			   nombreCliente;
	    float saldo;
		
	public:
		Cuenta(string num, string tipo, 
		       string nombre, float saldo = 0);
		~Cuenta();
		
		int crearCuenta(string nombre, string tipo, 
						float saldo = 0);
		
		void setSaldo(float saldo);
		float getSaldo();
		string getTipo();
		string getNombreCliente();
		string getNumero();

	};

#endif