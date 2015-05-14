#ifndef CLIENTES_H_
#define CLIENTES_H_

#include <iostream>
#include <string>

namespace contenedorClientes{
class Clientes
{
private:
	std::string nombre;
	std::string apellido;
	std::string clave;
	int dni;
	int telefono;
public:
	Clientes(std::string nombre, std::string apellido, std::string clave, int dni, int telefono );

	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setClave(std::string clave);
	void setDni(int dni);
	void setTelefono(int telefono);

	std::string getNombre() const;
	std::string getApellido() const;
	std::string getClave() const;
	int getDni()const;
	int getTelefono()const;


};
}
#endif

