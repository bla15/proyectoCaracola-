#include "comienzo.h"//para usar el clear
#include <stdio.h>//para usar fgtes y sscanf
#include "clientes.h"//para usar sus metodos
#include "profesor.h"//para usar sus metodos
//los vehiculos aqui
#include "citas.h"
#include "acceder.h"
#include "opcionesCliente.h"//para poder llamar a sus metodos
#include "listar.h"
#include <string>//para poder usar strings
#include <iostream>//para poder usar string
using namespace std;//para el cout y endl
using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;

int enunciadoInicioIV(){

		int num = 0;
		cout << "Por favor introduce tu dni" << endl;
		cin >> num;
		return num;
}

void comprobarCP(int totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores, Cita** misCitas){
	int i=0;
	int j=0;
	int bandera=0;
	for(i=0; i < totalClientes; i++){
		if(misClientes[i]->getDni() == dni){
			cout << "Bienvenido//Egunon señor/señora:  "<<misClientes[i]->getNombre()<< endl;
			entrarCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes[i],  misCitas);
			bandera=1;
		}
	}
	for(j=0; j < totalProfesores; j++){
		if(misProfesores[j]->getDni() == dni){
			cout << "Bienvenido//Egunon señor/señora:  "<<misProfesores[j]->getNombre()<< endl;
			bandera=1;
		}
	}
	if(bandera==0){
		cout<<"No se ha encontrado ninguna coincidencia"<<endl;
	}
}
void entrarCliente(int totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas,  Clientes* misClientes, Cita** misCitas){
	string clave;
	cout << "Introduzca su contraseña "<< endl;
	cin  >> clave;
	if(clave.compare(misClientes->getClave()) == 0){
		cout << "Contraseña CORRECTA"<< endl;
		opcionesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes, misCitas );
	}else{//si es falsa la contraseña
		cout << "Contraseña INCORRECTA"<< endl;
	}
}

void opcionesCliente(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas){
	int opcion;
	do{
		cout<<endl;
		cout<<"Pulsa 1 para ver tus datos de forma detallada"<<endl;
		cout<<"Pulsa 2 para cambiar tus datos"<<endl;
		cout<<"Pulsa 3 para pedir cita"<<endl;
		cout<<"Pulsa 4 para eliminarte de la BD y de el programa"<<endl;
		cout<<"Pulsa 5 para salir"<<endl;
		cin>>opcion;

		switch(opcion){
		case 1://para ver los datos
			mostrarClienteDetallado(misClientes);
			//ahora comprobamos si hay alguna cita para este profesor
			for(int i=0;i<totalCitas;i++){
				if(misCitas[i]->getDniCl()==misClientes->getDni()){
					mostrarCitasDetallado(misCitas[i]);
				}else{
					cout<<"No hay citas para usted programadas"<<endl;
				}
			}
			break;
		case 2://para cambiar los datos del cliente
			int opcionDos;
			cout<<"Pulsa 1 para cambiar el nombre"<<endl;
			cout<<"Pulsa 2 para cambiar el apellido"<<endl;
			cout<<"Pulsa 3 para cambiar la clave"<<endl;
			cout<<"Pulsa 4 para cambiar el DNI"<<endl;
			cout<<"Pulsa 5 para cambiar el telefonpo"<<endl;
			cout<<"Pulsa 6 para salir"<<endl;
			cin>>opcionDos;
			cambiarParametrosClientes(opcionDos, misClientes);
			break;
		case 3://para pedir una cita
			pedirCita(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes);
			break;
		case 4://para eliminar este cliente

			break;
		}
	}while(opcion!=5);


string nombre;
}

void cambiarParametrosClientes(int opcionDos, Clientes *misClientes){
	string nombre;
	string apellido;
	string clave;
	int telefono;
	int DNI;
	switch(opcionDos){
	case 1:
		cout<<"introduzca se nuevo nombre"<<endl;
		cin>>nombre;
		misClientes->setNombre(nombre);
		break;
	case 2:
		cout<<"introduzca se nuevo apellido"<<endl;
				cin>>apellido;
				misClientes->setApellido(apellido);
		break;
	case 3:
		cout<<"introduzca su vieja clave"<<endl;
				cin>>clave;
				if(clave.compare(misClientes->getClave()) == 0){
					cout<<"introduzca su clave nueva"<<endl;
					cin>>clave;
					misClientes->setClave(clave);
				}
				break;
	case 4:
		cout<<"introduzca se nuevo DNI"<<endl;
		cin>>DNI;
		misClientes->setDni(DNI);
		break;
	case 5:
		cout<<"introduzca se nuevo telefono"<<endl;
		cin>>telefono;
		misClientes->setTelefono(telefono);
		break;

	}
}
