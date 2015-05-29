#include "comienzo.h"//para usar el clear
#include <stdio.h>//para usar fgtes y sscanf
#include "clientes.h"//para usar sus metodos
#include "profesor.h"//para usar sus metodos
#include "vehiculo.h"//para usar sus metodods
#include "citas.h"
#include "acceder.h"
#include "opcionesCliente.h"//para poder llamar a sus metodos
#include "opcionesProfesor.h"//para poder llamar a sus metodos
#include "listar.h"
#include <string>//para poder usar strings
#include <iostream>//para poder usar string
using namespace std;//para el cout y endl
using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;
using namespace contenedorVehiculos;

int enunciadoInicioIV(){

		int num = 0;
		cout << "Por favor introduce tu dni" << endl;
		cin >> num;
		return num;
}

void comprobarCP(int &totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores, Cita** misCitas, Vehiculo** misVehiculos){
	int i=0;
	int j=0;
	int bandera=0;
	for(i=0; i < totalClientes; i++){
		if(misClientes[i]->getDni() == dni){
			cout << "Bienvenido//Egunon señor/señora:  "<<misClientes[i]->getNombre()<< endl;
			entrarCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes[i],  misCitas, misVehiculos, misProfesores, misClientes);
			bandera=1;
		}
	}
	for(j=0; j < totalProfesores; j++){
		if(misProfesores[j]->getDni() == dni){
			cout << "Bienvenido//Egunon señor/señora:  "<<misProfesores[j]->getNombre()<< endl;
			entrarProfesores(totalClientes, totalProfesores, totalVehiculos, totalCitas, misProfesores[j], misCitas, misVehiculos, misClientes);
			bandera=1;
		}
	}
	if(bandera==0){
		cout<<"No se ha encontrado ninguna coincidencia"<<endl;
	}
}
void entrarCliente(int &totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas,  Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente){
	string clave;
	cout << "Introduzca su contraseña "<< endl;
	cin  >> clave;
	if(clave.compare(misClientes->getClave()) == 0){
		cout << "Contraseña CORRECTA"<< endl;
		opcionesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes, misCitas, misVehiculos, misProfesores, cliente);
	}else{//si es falsa la contraseña
		cout << "Contraseña INCORRECTA"<< endl;
	}
}

void entrarProfesores(int& totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes){
	string clave;
		cout << "Introduzca su contraseña "<< endl;
		cin  >> clave;
		if(clave.compare(misProfesores->getClave()) == 0){
			cout << "Contraseña CORRECTA"<< endl;
			opcionesProfesor(totalClientes, totalProfesores, totalVehiculos, totalCitas, misProfesores, misCitas, misVehiculos, misClientes);
		}else{//si es falsa la contraseña
			cout << "Contraseña INCORRECTA"<< endl;
		}
}

void opcionesCliente(int& totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente){
	enunciadoOpcinesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes, misCitas, misVehiculos, misProfesores, cliente);
}

void opcionesProfesor(int &totalClientes, int totalProfesores, int totalVehiculos, int totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes){
	enunciadoOpcionesProfesor( totalClientes,  totalProfesores, totalVehiculos, totalCitas, misProfesores,  misVehiculos,  misCitas);


}

