/*
 * profesor.h
 *
 *  Created on: 14/05/2015
 *      Author: Alumno
 */

#ifndef PROFESOR_H_
#define PROFESOR_H_

#include<iostream>


namespace contenedorProfesor{
class Profesor{
	int dni;
	std::string clave;
	std::string nombre;
	std::string apellido;
	int telefono;

public:
	Profesor(std::string nombre, std::string apellido, std::string clave, int dni, int telefono);

	void setProfesor(std::string nombre, std::string apellido, std::string clave, int dni, int telefono );

	int getDni() const;
	void setDni(int dni);

	std::string getClave() const;
	void setClave(std::string clave);

	std::string getNombre() const;
	void setNombre(std::string nombre);

	std::string getApellido() const;
	void setApellido(std::string apellido);

	int getTelefono() const;
	void setTelefono(int telefono);


};
}

#endif /* PROFESOR_H_ */
