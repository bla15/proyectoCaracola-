#include <iostream>
#include "clientes.h"
#include "profesor.h"
#include "vehiculo.h"
#include "comienzo.h"
#include "registro.h"
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
		opcion=enunciadoInicio();
		switch(opcion){
			case 1:
				opcion2=enunciadoInicioII();
				switch(opcion2){
				case 1:
					registroClientes(misClientes,totalClientes);
					totalClientes++;break;
				case 2:
					registroProfesores(misProfesores, totalProfesores);
					totalProfesores++;break;
				}
				break;
		}

	}while(opcion!=4);

	return 0;
}
