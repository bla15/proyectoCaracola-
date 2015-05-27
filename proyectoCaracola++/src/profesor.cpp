/*
 * profesor.cpp

 *
 *  Created on: 14/05/2015
 *      Author: Alumno
 */

#include "profesor.h"
#include <iostream>
using namespace std;

namespace contenedorProfesor{



Profesor::Profesor(string nombre, string apellido, string clave, int dni, int telefono){
	this->nombre = nombre;
	this->apellido = apellido;
	this->clave = clave;
	this->dni = dni;
	this->telefono = telefono;
}

	int Profesor:: getDni() const{
		return this->dni;
	}

	void Profesor:: setDni(int dni){
		this->dni = dni;

	}

	string Profesor:: getClave() const{
		return this->clave;
	}

	void Profesor:: setClave(string clave){
		this->clave = clave;

	}

	string Profesor:: getNombre() const{
		return this->nombre;
	}

	void Profesor::setNombre(string nombre){
		this->nombre = nombre;

	}

	string Profesor:: getApellido() const{
		return this->apellido;
	}

	void Profesor:: setApellido(string apellido){
		this->apellido = apellido;
	}

	int Profesor:: getTelefono() const{
		return this->telefono;
	}

	void Profesor:: setTelefono(int telefono){
		this->telefono = telefono;
	}

	void Profesor:: setProfesor(string nombre, string apellido, string clave, int dni, int telefono){
		this->nombre = nombre;
		this->apellido = apellido;
		this->clave = clave;
		this->dni = dni;
		this->telefono = telefono;
	}








}


