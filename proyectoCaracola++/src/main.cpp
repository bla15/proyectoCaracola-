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
#define MAX_VEHICULOS 2

void inicializarVehiculo(Coche ** misCoches, Moto ** misMotos, Camion ** misCamiones){


	misCoches[0] = new Coche(1822, 15, "Plateado", "Delantera"); // Esto lo puedo hacer? Parece que no da ningun problema, pero apunta al coche en su totalidad?
	misMotos[0] = new Moto(2819, 2, "Rojo", 125);
	misCamiones[0] = new Camion(8210, 6, "Blanco", 1000);
	misCoches[1] = new Coche(6201, 3, "Verde", "Trasera");
	misMotos[1] = new Moto(4489, 1, "Azul", 250);
	misCamiones[1] = new Camion(7298, 7, "Negro", 1500);
	misCoches[2] = new Coche(2247, 10, "Amarillo", "4x4");
	misMotos[2] = new Moto(5219, 4, "Marron", 500);
	misCamiones[2] = new Camion(9472, 8, "Gris", 1750);



}

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
	misCitas[0]=new Cita(1822, 1,2);
	totalCitas++;

	Coche ** misCoches = new Coche * [MAX_VEHICULOS]; // He intentado hacer todos los vehiculos en un solo array pero no me ha dejado
	Moto ** misMotos = new Moto * [MAX_VEHICULOS];
	Camion ** misCamiones = new Camion * [MAX_VEHICULOS];

	inicializarVehiculo(misCoches, misMotos, misCamiones);

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
