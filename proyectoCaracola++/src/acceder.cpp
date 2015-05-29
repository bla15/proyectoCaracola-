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

//aqui introducimos nuestro DNI
int enunciadoInicioIV(){

		int num = 0;
		cout << "Por favor introduce tu dni" << endl;
		cin >> num;
		return num;
}

//Comprobamos si el DNI introducido corresponde a un cliente o a un profesor o a nadie
void comprobarCP(int &totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores, Cita** misCitas, Vehiculo** misVehiculos, DBConnector &dbconnector){
	int i=0;
	int j=0;
	int bandera=0;
	for(i=0; i < totalClientes; i++){
		if(misClientes[i]->getDni() == dni){
			cout << "Bienvenido//Egunon se�or/se�ora:  "<<misClientes[i]->getNombre()<< endl;
			entrarCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes[i],  misCitas, misVehiculos, misProfesores, misClientes, dbconnector);
			bandera=1;
		}
	}
	for(j=0; j < totalProfesores; j++){
		if(misProfesores[j]->getDni() == dni){
			cout << "Bienvenido//Egunon se�or/se�ora:  "<<misProfesores[j]->getNombre()<< endl;
			entrarProfesores(totalClientes, totalProfesores, totalVehiculos, totalCitas, misProfesores[j], misCitas, misVehiculos, misClientes, dbconnector);
			bandera=1;
		}
	}
	if(bandera==0){
		cout<<"No se ha encontrado ninguna coincidencia"<<endl;
	}
}
//En caso de que sea un cliente, entrar� como cliente y tendr� varias opciones
void entrarCliente(int &totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas,  Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente, DBConnector &dbconnector){
	string clave;
	cout << "Introduzca su contrase�a "<< endl;
	cin  >> clave;
	if(clave.compare(misClientes->getClave()) == 0){
		cout << "Contrase�a CORRECTA"<< endl;
		opcionesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes, misCitas, misVehiculos, misProfesores, cliente, dbconnector);
	}else{//si es falsa la contrase�a
		cout << "Contrase�a INCORRECTA"<< endl;
	}
}
//En caso de que sea un profesor, entrar� como profesor y tendr� varias opciones
void entrarProfesores(int& totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes, DBConnector &dbconnector){
	string clave;
		cout << "Introduzca su contrase�a "<< endl;
		cin  >> clave;
		if(clave.compare(misProfesores->getClave()) == 0){
			cout << "Contrase�a CORRECTA"<< endl;
			opcionesProfesor(totalClientes, totalProfesores, totalVehiculos, totalCitas, misProfesores, misCitas, misVehiculos, misClientes, dbconnector);
		}else{//si es falsa la contrase�a
			cout << "Contrase�a INCORRECTA"<< endl;
		}
}
//Cuando acceda como cliente, llegar� aqui y podr� elegir entre las opciones que tiene
void opcionesCliente(int& totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente, DBConnector &dbconnector){
	enunciadoOpcinesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes, misCitas, misVehiculos, misProfesores, cliente, dbconnector);
}
//Cunado acceda como profesor, llegar� aqui y podr� elegir entre las opciones que tiene
void opcionesProfesor(int &totalClientes, int totalProfesores, int totalVehiculos, int totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes, DBConnector &dbconnector){
	enunciadoOpcionesProfesor( totalClientes,  totalProfesores, totalVehiculos, totalCitas, misProfesores,  misVehiculos,  misCitas, dbconnector);


}

