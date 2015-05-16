#include <iostream>
#include "clientes.h"
#include "profesor.h"
#include "vehiculo.h"
#include "comienzo.h"
#include "registro.h"
#include "acceder.h"
using namespace std;
using namespace contenedorProfesor;
using namespace contenedorClientes;
// Definicion de la cantidad de clientes maxima
#define MAX_CLIENTES 10
#define MAX_PROFESORES 5

int main() {
	int opcion;
	int opcion2;
	int totalClientes=0;
	int totalProfesores=0;
	Clientes *misClientes=new Clientes[MAX_CLIENTES];
	Profesor *misProfesores=new Profesor [MAX_PROFESORES];

	cout << "Bienvenido a la autoescuela Caracola!!!" << endl;
	do{
		opcion=0;
		opcion=enunciadoInicio();

		switch(opcion){
			case 1:

				opcion2=enunciadoInicioII();
				switch(opcion2){
				case 1:
					if(totalClientes<MAX_CLIENTES){
						registroClientes(misClientes,totalClientes);
						totalClientes++;
					}else{
						cout << "La lista clientes esta llena" << endl;
					}

					break;
				case 2:
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
				case 3:
					if(totalClientes+totalProfesores!=0){
						int dni=enunciadoInicioIII();
					}else{
						cout << "No hay ningun cliente o profesor registrado" << endl;
					}
					break;

		}

	}while(opcion!=4);

	return 0;
}
