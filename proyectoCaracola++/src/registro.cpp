#include "comienzo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "clientes.h"
#include "profesor.h"
#include "DBConnector.h"
using namespace std;
using namespace contenedorClientes;
using namespace contenedorProfesor;

int enunciadoInicioII(){

	int num = 0;
	cout << "Elige una opción" << endl;
	cout << "Pulsa 1 para registrarse como cliente" << endl;
	cout << "Pulsa 2 para registrarse como profesor" << endl;
	cout << "Pulsa 3 para salir" << endl;
	cin >> num;

	return num;
}

void registroClientes(Clientes ** misClientes, int totalClientes, DBConnector &dbconnector){
	string nombre;
	string apellido;
	string clave;
	int dni;
	int telefono;
	cout << "Escribe tu nombre" << endl;
	cin  >> nombre;
	cout << "Escribe tu apellido" << endl;
	cin  >> apellido;
	cout << "Escribe tu clave" << endl;
	cin  >> clave;
	cout << "Escribe tu DNI" << endl;
	cin  >> dni;
	cout << "Escribe tu telefono" << endl;
	cin  >> telefono;




	//guardamos los datos del nuevo cliente
	misClientes[totalClientes] = new Clientes(nombre,apellido, clave, dni, telefono);
	dbconnector.insertNewCliente(dni, nombre, apellido, clave, telefono);


}

void registroProfesores(Profesor ** misProfesores, int totalProfesores, DBConnector &dbconnector){
	string nombre;
	string apellido;
	string clave;
	int dni;
	int telefono;
	cout << "Escribe tu nombre" << endl;
	cin  >> nombre;
	cout << "Escribe tu apellido" << endl;
	cin  >> apellido;
	cout << "Escribe tu clave" << endl;
	cin  >> clave;
	cout << "Escribe tu DNI" << endl;
	cin  >> dni;
	cout << "Escribe tu telefono" << endl;
	cin  >> telefono;




	//guardamos los datos del nuevo cliente
	misProfesores[totalProfesores]= new Profesor(nombre,apellido, clave, dni, telefono);
	dbconnector.insertNewProfesor(dni, nombre, apellido, clave, telefono);

}


