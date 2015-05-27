#include <iostream>
#include "DBConnector.h"
#include "clientes.h"
#include "profesor.h"
#include "vehiculo.h"
#include "citas.h"
#include "comienzo.h"
#include "registro.h"
#include "acceder.h"
using namespace std;
using namespace contenedorProfesor;
using namespace contenedorClientes;
using namespace contenedorCitas;
// Definicion de la cantidad de clientes maxima
#define MAX_CLIENTES 10
#define MAX_PROFESORES 5
#define MAX_CITAS 25

int main() {
	int opcion = 0;
	int opcion2 = 0;
	int totalClientes=0;
	int totalProfesores=0;
	int totalVehiculos=0;
	int totalCitas=0;
	Clientes **misClientes=new Clientes*[MAX_CLIENTES];
	misClientes[0]= new Clientes("PEPE", "García", "1",1,1);
	totalClientes++;

	Profesor **misProfesores=new Profesor* [MAX_PROFESORES];
	misProfesores[0]= new Profesor("Ana", "García", "2",2,2);
	totalProfesores++;

	Cita **misCitas=new Cita*[MAX_CITAS];

	cout << "Bienvenido a la autoescuela Caracola!!!" << endl;
	do{
		opcion=enunciadoInicio();


		switch(opcion){
			case 1://Para registrarse

				opcion2=enunciadoInicioII();

				switch(opcion2){
				case 1://registro de clientes
					if(totalClientes<MAX_CLIENTES){
						registroClientes(misClientes,totalClientes);
						totalClientes++;
					}else{
						cout << "La lista clientes esta llena" << endl;
					}

					break;
				case 2://registro de profesores
					if(totalProfesores<MAX_PROFESORES){
						registroProfesores(misProfesores, totalProfesores);
						totalProfesores++;
					}else{
						cout << "La lista profesores esta llena" << endl;
					}

					break;

				}
				break;
				case 2:
					break;
				case 3://para acceder
					if(totalClientes+totalProfesores!=0){
						int dni=enunciadoInicioIII();
						comprobarCP(totalClientes, totalProfesores, totalVehiculos, dni, totalCitas, misClientes, misProfesores);

					}else{
						cout << "No hay ningun cliente o profesor registrado" << endl;
					}
					break;

		}

	}while(opcion!=4);

	return 0;
}
