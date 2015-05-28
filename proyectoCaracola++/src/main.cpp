#include <iostream>
#include "DBConnector.h"
#include "clientes.h"
#include "profesor.h"
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
#define MAX_VEHICULOS 3

void inicializarVehiculo(Coche ** misCoches, Moto ** misMotos, Camion ** misCamiones, DBConnector dbconnector){


	misCoches[0] = new Coche(1822, 15, "Plateado", "Delantera");
	dbconnector.insertNewVehiculo(misCoches[0]->getMatricula(), misCoches[0]->getAntiguedad(), misCoches[0]->getColor());
	misMotos[0] = new Moto(2819, 2, "Rojo", 125);
	dbconnector.insertNewVehiculo(misMotos[0]->getMatricula(), misMotos[0]->getAntiguedad(), misMotos[0]->getColor());
	misCamiones[0] = new Camion(8210, 6, "Blanco", 1000);
	dbconnector.insertNewVehiculo(misCamiones[0]->getMatricula(), misCamiones[0]->getAntiguedad(), misCamiones[0]->getColor());
	misCoches[1] = new Coche(6201, 3, "Verde", "Trasera");
	dbconnector.insertNewVehiculo(misCoches[1]->getMatricula(), misCoches[1]->getAntiguedad(), misCoches[1]->getColor());
	misMotos[1] = new Moto(4489, 1, "Azul", 250);
	dbconnector.insertNewVehiculo(misMotos[1]->getMatricula(), misMotos[1]->getAntiguedad(), misMotos[1]->getColor());
	misCamiones[1] = new Camion(7298, 7, "Negro", 1500);
	dbconnector.insertNewVehiculo(misCamiones[1]->getMatricula(), misCamiones[1]->getAntiguedad(), misCamiones[1]->getColor());
	misCoches[2] = new Coche(2247, 10, "Amarillo", "4x4");
	dbconnector.insertNewVehiculo(misCoches[2]->getMatricula(), misCoches[2]->getAntiguedad(), misCoches[2]->getColor());
	misMotos[2] = new Moto(5219, 4, "Marron", 500);
	dbconnector.insertNewVehiculo(misMotos[2]->getMatricula(), misMotos[2]->getAntiguedad(), misMotos[2]->getColor());
	misCamiones[2] = new Camion(9472, 8, "Gris", 1750);
	dbconnector.insertNewVehiculo(misCamiones[2]->getMatricula(), misCamiones[2]->getAntiguedad(), misCamiones[2]->getColor());


}

int main() {

	int opcion = 0;
	int opcion2 = 0;
	int totalClientes=0;
	int totalProfesores=0;
	int totalVehiculos=MAX_VEHICULOS;
	int totalCitas=0;

	//Abrimos conexion con la base de datos
	DBConnector dbconnector("Karakola.sqlite");

	Clientes **misClientes=new Clientes*[MAX_CLIENTES];
	misClientes[0]= new Clientes("PEPE", "García", "1",1,1);
	totalClientes++;
	dbconnector.insertNewCliente(misClientes[0]->getDni(), misClientes[0]->getNombre(), misClientes[0]->getApellido(), misClientes[0]->getClave(), misClientes[0]->getTelefono());

	Profesor **misProfesores=new Profesor* [MAX_PROFESORES];
	misProfesores[0]= new Profesor("Ana", "García", "2",2,2);
	totalProfesores++;

	Cita **misCitas=new Cita*[MAX_CITAS];
	misCitas[0]=new Cita(1822, 1,2);
	totalCitas++;

	Coche ** misCoches = new Coche * [MAX_VEHICULOS]; // He intentado hacer todos los vehiculos en un solo array pero no me ha dejado
	Moto ** misMotos = new Moto * [MAX_VEHICULOS];
	Camion ** misCamiones = new Camion * [MAX_VEHICULOS];

	inicializarVehiculo(misCoches, misMotos, misCamiones, dbconnector);

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
				case 2://para listar el contenido
					if(totalClientes+totalProfesores==0){//si no hy elementos en la BD no se puede mostrar nada
						cout<<"no hay datos guardados en la base de datos"<<endl;
					}else{
						enunciadoIII(totalClientes, totalProfesores, totalCitas, totalVehiculos, misClientes, misProfesores, misCitas);
					}


					break;
				case 3://para acceder
					if(totalClientes+totalProfesores!=0){
						int dni=enunciadoInicioIV();
						comprobarCP(totalClientes, totalProfesores, totalVehiculos, dni, totalCitas, misClientes, misProfesores, misCitas);

					}else{
						cout << "No hay ningun cliente o profesor registrado" << endl;
					}
					break;

		}

	}while(opcion!=4);

	return 0;
}
