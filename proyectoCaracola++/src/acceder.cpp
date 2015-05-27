#include "comienzo.h"//para usar el clear
#include <stdio.h>//para usar fgtes y sscanf
#include "clientes.h"//para usar sus metodos
#include "profesor.h"//para usar sus metodos
#include "acceder.h"
#include "opcionesCliente.h"//para poder llamar a sus metodos
using namespace std;//para el cout y endl
using namespace contenedorClientes;
using namespace contenedorProfesor;

int enunciadoInicioIII(){

		int num = 0;
		cout << "Por favor introduce tu dni" << endl;
		cin >> num;
		return num;
}

void comprobarCP(int totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores){
	int i=0;
	int j=0;
	int bandera=0;
	for(i=0; i < totalClientes; i++){
		if(misClientes[i]->getDni() == dni){
			cout << "Bienvenido//Egunon se�or/se�ora:  "<<misClientes[i]->getNombre()<< endl;
			entrarCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes[i]);
			bandera=1;
		}
	}
	for(j=0; j < totalProfesores; j++){
			if(misProfesores[j]->getDni() == dni){
				cout << "Bienvenido//Egunon se�or/se�ora:  "<<misProfesores[j]->getNombre()<< endl;
				bandera=1;
			}
		}
	if(bandera==0){
		cout<<"No se ha encontrado ninguna coincidencia"<<endl;
	}
}
void entrarCliente(int totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas,  Clientes* misClientes){
	string clave;
	cout << "Introduzca su contrase�a "<< endl;
	cin  >> clave;
	if(clave.compare(misClientes->getClave()) == 0){
		cout << "Contrase�a CORRECTA"<< endl;
		opcionesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes );
	}else{//si es falsa la contrase�a
		cout << "Contrase�a INCORRECTA"<< endl;
	}
}

void opcionesCliente(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes){
	int opcion;
	cout<<"Pulsa 1 para pedir cita"<<endl;
	cout<<"Pulsa 2 para eliminarte de la BD y de el programa"<<endl;
	cin>>opcion;

	switch(opcion){
	case 1://para pedir una cita
		pedirCita(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes);
		break;
	case 2://para eliminar este cliente

		break;
	}

}
