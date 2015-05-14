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

int main() {
	int opcion;
	int totalClientes=0;
	int totalProfesores;
	Clientes *misClientes=new Clientes[MAX_CLIENTES];

	cout << "Bienvenido a la autoescuela Caracola!!!" << endl;
	do{
		opcion=enunciadoInicio();
		switch(opcion){
			case 1:
				opcion=enunciadoInicioII();
				switch(opcion){
				case 1:
					registroClientes(misClientes,totalClientes);
					totalClientes++;
				}
				break;
		}

	}while(opcion!=4);

	return 0;
}
