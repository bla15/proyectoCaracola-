#include <iostream>
#include "listar.h"
#include "clientes.h"
#include "profesor.h"
#include "citas.h"
#include "vehiculo.h"
using namespace std;

//si elegimos la opcion de listar, nos dara dos opciones: listar clientes o listar profesores
void enunciadoIII(int totalClientes, int totalProfesores, int totalCitas, int totalVehiculos, Clientes** misclientes, Profesor** misProfesores, Cita** miscitas, DBConnector &dbconnector){
	int opcion;
	cout<<"Que quieres que se te muestre: "<<endl;
	cout<<"Pulsa 1 para los clientes registrados en nuestra base de datos"<<endl;
	cout<<"Pulsa 2 para los profesores que imparten clase en nuestra autoescuela"<<endl;
	cin>>opcion;
	switch(opcion){
	case 1:
		mostrarCliente(totalClientes, misclientes, dbconnector);
		break;
	case 2:
		mostrarProfeosres(totalProfesores, misProfesores, dbconnector);
		break;
	}
}
//si elegimos la opcion de listar clientes, lo haremos mediante este metodo
void mostrarCliente (int totalClietes,Clientes** misclientes, DBConnector &dbconnector){
	cout<<endl;
	cout<<"Prodecemos a mostrar los clientes guardados en la BD"<<endl;
	/*
	for(int i=0;i<totalClietes;i++){
		cout<<"El "<<i+1<<"� cliente es: "<<misclientes[i]->getNombre()<<endl;
	}
	*/
	dbconnector.showAllClientes();
	cout<<endl;
}
//si elegimos la opcion de listas profesores, lo ahremos mediante este metodo
void mostrarProfeosres(int totalProfesores, Profesor** misProfesores, DBConnector &dbconnector){
	cout<<endl;
	cout<<"Prodecemos a mostrar los profeosres que imparten clase en caracola"<<endl;
	/*
	for(int i=0;i<totalProfesores;i++){
		cout<<"El "<<i+1<<"� profesor es: "<<misProfesores[i]->getNombre()<<endl;
	}
	*/
	dbconnector.showAllProfesores();
	cout<<endl;
}
//con este metodo podremos mostrar las citas
void mostrarCitas(int totalCitas, Cita** miscitas, DBConnector &dbconnector){
	cout << "Procedemos a mostrar las citas guardadas en nuestra BD:" << endl;
	dbconnector.showAllCitas();

}
//mediante este metodo podremos mostrar los vehiculos
void mostrarVehiculos(int totalVehiculos, DBConnector &dbconnector){
	cout << "Procedemos a mostrar los vehiculos guardados en nuestra BD" << endl;
	dbconnector.showAllVehiculos();
}
//con este metodo podremos dar los datos detallados de los clientes
void mostrarClienteDetallado(Clientes* misclientes){
	cout<<endl;
	cout<<"El nombre es: "<<misclientes->getNombre()<<endl;
	cout<<"El apellido es: "<<misclientes->getApellido()<<endl;
	cout<<"La clave es: "<<misclientes->getClave()<<endl;
	cout<<"El DNI es: "<<misclientes->getDni()<<endl;
	cout<<"El telefono es: "<<misclientes->getTelefono()<<endl;
	cout<<endl;
}
//con este metodo podremos dar los datos detallados de los profesores
void mostrarProfesoresDetallado(Profesor* misProfesores){
	cout<<endl;
	cout<<"El nombre es: "<<misProfesores->getNombre()<<endl;
	cout<<"El apellido es: "<<misProfesores->getApellido()<<endl;
	cout<<"La clave es: "<<misProfesores->getClave()<<endl;
	cout<<"El DNI es: "<<misProfesores->getDni()<<endl;
	cout<<"El telefono es: "<<misProfesores->getTelefono()<<endl;
	cout<<endl;
}
//con este metodo podremos mostrar las citas detalladas
void mostrarCitasDetallado(Cita* miscitas){
	cout<<"El profesor es: "<<miscitas->getDniProf()<<" DNI"<<endl;;
	cout<<"El vehiculo es: "<<miscitas->getMatricula()<<" matricula"<<endl;
	cout<<endl;
}
//con este metodo podremos mostrar los vehiculos detallados
void mostrarVehiculosDetallado(int totalVehiculos, Vehiculo** misvehiculos){
	for(int i=0;i<totalVehiculos;i++){
		cout<<"El vehiculo "<<i+1<<"� "<<endl;
		cout<<"\tCon matricula: "<<misvehiculos[i]->getMatricula()<<endl;
		cout<<"\tCon color: "<<misvehiculos[i]->getColor()<<endl;
		cout<<"\tCon antiguedad: "<<misvehiculos[i]->getAntiguedad()<<" (a�os)"<<endl;
	}
}

