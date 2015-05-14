#include "comienzo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "clientes.h"
using namespace std;
using namespace contenedorClientes;

int enunciadoInicioII(){
	char str[10];
	int num;
	cout << "Elige una opcón" << endl;
	cout << "Pulsa 1 para registrarse como cliente" << endl;
	cout << "Pulsa 2 para registrarse como profesor" << endl;
	cout << "Pulsa 3 para salir" << endl;
	fgets(str, 10, stdin);
	sscanf(str, "%d", &num);
	clear_if_needed(str);
	return num;
}

void registroClientes(Clientes * misClientes, int totalClientes){
	char str[10];
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
	misClientes[totalClientes].setCliente(nombre,apellido, clave, dni, telefono);

}

