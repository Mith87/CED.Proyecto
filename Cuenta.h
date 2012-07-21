#ifndef CUENTA_H
#define CUENTA_H

class Cuenta {
	public:
		Cuenta(string num, string tipo, string nombre, float saldo = 0);
		~Cuenta();
			
		int crearCuenta(string nombre, string tipo, float saldo = 0);
			
		float getSaldo();
		string getTipo();
		string getNombreCliente();
		string getNumero();
			
		void setSaldo(float saldo);

	private:
		string num; 
		string tipo;
		string nombreCliente;
		float saldo;
};

#endif