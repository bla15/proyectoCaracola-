#include "comienzo.h"//para usar el clear

#include <stdio.h>//para usar fgtes y sscanf

#include "clientes.h"//para usar sus metodos
#include "profesor.h"//para usar sus metodos
#include "acceder.h"
using namespace std;//para el cout y endl
using namespace contenedorClientes;
using namespace contenedorProfesor;

int enunciadoInicioIII(){
		char str[10];
		int num;
		cout << "Por favor introduce tu dni" << endl;
		fgets(str, 10, stdin);
		sscanf(str, "%d", &num);
		clear_if_needed(str);
		return num;
}

void comprobarCP(int totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes * misClientes, Profesor * misProfesores){
	int i=0;
	int j=0;
	for(i=0; i < totalClientes; i++){
		if(misClientes[i].getDni() == dni){
			cout << "Bienvenido//Egunon señor/señora:  "<<misClientes[i].getNombre()<< endl;
			entrarCliente(totalClientes, totalVehiculos, totalCitas, misClientes[i]);
		}
	}
	for(j=0; j < totalClientes; j++){
			if(misProfesores[i].getDni() == dni){
				cout << "Bienvenido//Egunon señor/señora:  "<<misProfesores[i].getNombre()<< endl;
			}
		}
}
void entrarCliente(int totalClientes, int totalVehiculos, int &totalCitas,  Clientes misClientes){
	string clave;
	cout << "Introduzca su contraseña "<< endl;
	cin  >> clave;
	if(clave.compare(misClientes.getClave()) == 0){
		cout << "Contraseña CORRECTA"<< endl;
	}else{//si es falsa la contraseña
		cout << "Contraseña INCORRECTA"<< endl;
	}
}
