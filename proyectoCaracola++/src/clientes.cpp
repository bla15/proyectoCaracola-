#include "clientes.h"
#include <iostream>
using namespace std;

namespace contenedorClientes{
Clientes::Clientes(std::string nombre, std::string apellido, std::string clave, int dni, int telefono){
	this->nombre=nombre;
	this->apellido=apellido;
	this->clave=clave;
	this->dni=dni;
	this->telefono=telefono;
}
Clientes::Clientes(){

}

//metodos set de las variables
void Clientes::setNombre(string nombre){
	this->nombre=nombre;
}
void Clientes::setApellido(string apellido){
	this->apellido=apellido;
}
void Clientes::setClave(string clave){
	this->clave=clave;
}
void Clientes::setDni(int dni){
	this->dni=dni;
}
void Clientes::setTelefono(int telefono){
	this->telefono=telefono;
}
void Clientes::setCliente(std::string nombre, std::string apellido, std::string clave, int dni, int telefono ){
	this->nombre=nombre;
	this->apellido=apellido;
	this->clave=clave;
	this->dni=dni;
	this->telefono=telefono;
}
//metodos get de las variables
string Clientes::getNombre()const{
	return this->nombre;
}
string Clientes::getApellido()const{
	return this->apellido;
}
string Clientes::getClave()const{
	return this->clave;
}
int Clientes::getDni()const{
	return this->dni;
}
int Clientes::getTelefono()const{
	return this->telefono;
}
}
