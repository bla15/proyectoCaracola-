#include <iostream>
#include "DBConnector.h"
#include "clientes.h"
#include "profesor.h"
#include "vehiculo.h"
#include "Coche.h"
#include "Moto.h"
#include "Camion.h"
#include "citas.h"
#include "comienzo.h"
#include "registro.h"
#include "acceder.h"
#include "listar.h"
using namespace std;
using namespace contenedorProfesor;
using namespace contenedorClientes;
using namespace contenedorCitas;
using namespace contenedorVehiculos;
// Definicion de la cantidad de clientes maxima
#define MAX_CLIENTES 10
#define MAX_PROFESORES 5
#define MAX_CITAS 25
#define MAX_VEHICULOS 9


void inicializarVehiculo(Vehiculo ** misVehiculos, DBConnector &dbconnector){ // Inicializacion de los vehiculos e inserción de los mismos en la BD

	misVehiculos[0] = new Coche(1822, 15, "Plateado", "Delantera");
	dbconnector.insertNewVehiculo(misVehiculos[0]->getMatricula(), misVehiculos[0]->getAntiguedad(), misVehiculos[0]->getColor());
	misVehiculos[1] = new Moto(2819, 2, "Rojo", 125);
	dbconnector.insertNewVehiculo(misVehiculos[1]->getMatricula(), misVehiculos[1]->getAntiguedad(),misVehiculos[1]->getColor());
	misVehiculos[2] = new Camion(8210, 6, "Blanco", 1000);
	dbconnector.insertNewVehiculo(misVehiculos[2]->getMatricula(), misVehiculos[2]->getAntiguedad(), misVehiculos[2]->getColor());
	misVehiculos[3] = new Coche(6201, 3, "Verde", "Trasera");
	dbconnector.insertNewVehiculo(misVehiculos[3]->getMatricula(),misVehiculos[3]->getAntiguedad(), misVehiculos[3]->getColor());
	misVehiculos[4] = new Moto(4489, 1, "Azul", 250);
	dbconnector.insertNewVehiculo(misVehiculos[4]->getMatricula(), misVehiculos[4]->getAntiguedad(), misVehiculos[4]->getColor());
	misVehiculos[5] = new Camion(7298, 7, "Negro", 1500);
	dbconnector.insertNewVehiculo(misVehiculos[5]->getMatricula(), misVehiculos[5]->getAntiguedad(), misVehiculos[5]->getColor());
	misVehiculos[6] = new Coche(2247, 10, "Amarillo", "4x4");
	dbconnector.insertNewVehiculo(misVehiculos[6]->getMatricula(),misVehiculos[6]->getAntiguedad(), misVehiculos[6]->getColor());
	misVehiculos[7] = new Moto(5219, 4, "Marron", 500);
	dbconnector.insertNewVehiculo(misVehiculos[7]->getMatricula(), misVehiculos[7]->getAntiguedad(), misVehiculos[7]->getColor());
	misVehiculos[8] = new Camion(9472, 8, "Gris", 1750);
	dbconnector.insertNewVehiculo(misVehiculos[8]->getMatricula(), misVehiculos[8]->getAntiguedad(), misVehiculos[8]->getColor());

}

int main() { //

	int opcion = 0;
	int opcion2 = 0;
	int totalClientes=0;
	int totalProfesores=0;
	int totalVehiculos=MAX_VEHICULOS;
	int totalCitas=0;

	//Abrimos conexion con la base de datos
	DBConnector dbconnector("Karakola.sqlite");

	Clientes **misClientes=new Clientes*[MAX_CLIENTES];

	Profesor **misProfesores=new Profesor* [MAX_PROFESORES];


	Cita **misCitas=new Cita*[MAX_CITAS];

	Vehiculo ** misVehiculos = new Vehiculo * [MAX_VEHICULOS];

	inicializarVehiculo(misVehiculos, dbconnector);


	cout << "Bienvenido a la autoescuela Caracola!!!" << endl;
	do{
		opcion=enunciadoInicio();


		switch(opcion){
			case 1://Para registrarse

				opcion2=enunciadoInicioII();

				switch(opcion2){
				case 1://registro de clientes
					if(totalClientes<MAX_CLIENTES){
						registroClientes(misClientes,totalClientes, dbconnector);
						totalClientes++;
					}else{
						cout << "La lista clientes esta llena" << endl;
					}

					break;
				case 2://registro de profesores
					if(totalProfesores<MAX_PROFESORES){
						registroProfesores(misProfesores, totalProfesores, dbconnector);
						totalProfesores++;
					}else{
						cout << "La lista profesores esta llena" << endl;
					}

					break;

				}
				break;
				case 2://para listar el contenido
					if(totalClientes+totalProfesores==0){//si no hy elementos en la BD no se puede mostrar nada
						cout<<"No hay datos guardados en la base de datos"<<endl;
					}else{
						enunciadoIII(totalClientes, totalProfesores, totalCitas, totalVehiculos, misClientes, misProfesores, misCitas, dbconnector);
					}


					break;
				case 3://para acceder
					if(totalClientes+totalProfesores!=0){

						int dni=enunciadoInicioIV();
						comprobarCP(totalClientes, totalProfesores, totalVehiculos, dni, totalCitas, misClientes, misProfesores, misCitas, misVehiculos, dbconnector);

					}else{
						cout << "No hay ningun cliente o profesor registrado" << endl;
					}
				break;
		}
	}while(opcion!=4);
	dbconnector.deleteAllClientes();
	dbconnector.deleteAllProfesores();
	dbconnector.deleteAllVehiculos();
	dbconnector.deleteAllCitas();
	for (int i = 0; i < totalClientes; i++){
		delete misClientes[i];
	}
	delete [] misClientes;
	for (int i = 0; i < totalProfesores; i++){
			delete misProfesores[i];
		}
	delete [] misProfesores;
	for (int i = 0; i < totalCitas; i++){
			delete misCitas[i];
		}
	delete [] misCitas;
	for (int i = 0; i < totalVehiculos; i++){
			delete misVehiculos[i];
		}
	delete [] misVehiculos;



	return 0;
}
