#include <iostream>
#include "listar.h"
#include "clientes.h"
#include "profesor.h"
#include "citas.h"
#include "vehiculo.h"
using namespace std;

void enunciadoIII(int totalClientes, int totalProfesores, int totalCitas, int totalVehiculos, Clientes** misclientes, Profesor** misProfesores, Cita** miscitas){
	int opcion;
	cout<<"Que quieres que se te muestre: "<<endl;
	cout<<"Pulsa 1 para los clientes registrados en nuestra base de datos"<<endl;
	cout<<"Pulsa 2 para los profeosres que imparten clase en nuestra autoescuela"<<endl;
	cin>>opcion;
	switch(opcion){
	case 1:
		mostrarCliente(totalClientes, misclientes);
		break;
	case 2:
		mostrarProfeosres(totalProfesores, misProfesores);
		break;
	}
}
void mostrarCliente (int totalClietes,Clientes** misclientes){
	cout<<endl;
	cout<<"Prodecemos a mostrar los clientes guardados en la BD"<<endl;
	for(int i=0;i<totalClietes;i++){
		cout<<"El "<<i+1<<"� cliente es: "<<misclientes[i]->getNombre()<<endl;
	}
	cout<<endl;
}
void mostrarProfeosres(int totalProfesores, Profesor** misProfesores){
	cout<<endl;
	cout<<"Prodecemos a mostrar los profeosres que imparten clase en caracola"<<endl;
	for(int i=0;i<totalProfesores;i++){
		cout<<"El "<<i+1<<"� profesor es: "<<misProfesores[i]->getNombre()<<endl;
	}
	cout<<endl;
}

void mostrarCitas(int totalCitas, Cita** miscitas){

}
void mostrarVehiculos(int totalVehiculos){

}

void mostrarClienteDetallado(Clientes* misclientes){
	cout<<endl;
	cout<<"El nombre es: "<<misclientes->getNombre()<<endl;
	cout<<"El apellido es: "<<misclientes->getApellido()<<endl;
	cout<<"La clave es: "<<misclientes->getClave()<<endl;
	cout<<"El DNI es: "<<misclientes->getDni()<<endl;
	cout<<"El telefono es: "<<misclientes->getTelefono()<<endl;
	cout<<endl;
}
void mostrarProfeosresDetallado(Profesor* misProfesores){
	cout<<endl;
	cout<<"El nombre es: "<<misProfesores->getNombre()<<endl;
	cout<<"El apellido es: "<<misProfesores->getApellido()<<endl;
	cout<<"La clave es: "<<misProfesores->getClave()<<endl;
	cout<<"El DNI es: "<<misProfesores->getDni()<<endl;
	cout<<"El telefono es: "<<misProfesores->getTelefono()<<endl;
	cout<<endl;
}
void mostrarCitasDetallado(Cita* miscitas){

	cout<<endl;
	cout<<"Sus citas Programadas son"<<endl;
	cout<<"El profesor es: "<<miscitas->getDniProf()<<" DNI"<<endl;;
	cout<<"El vehiculo es: "<<miscitas->getMatricula()<<" matricula"<<endl;
	cout<<endl;
}
void mostrarVehiculosDetallado(int totalVehiculos){

}
