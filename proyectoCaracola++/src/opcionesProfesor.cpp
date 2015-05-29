#include "clientes.h"//para usar sus metodos
#include "profesor.h"//para usar sus metodos
#include "citas.h"
#include "vehiculo.h"
#include "acceder.h"
#include "listar.h"
#include "opcionesProfesor.h"//para poder llamar a sus metodos
using namespace std;//para el cout y endl
using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;

//mediante este metodo podemos ver la informacion del profesor
void verInforDelProfesor(int totalProfesores, int totalCitas, Profesor* misProfesores, Cita** misCitas, DBConnector &dbconnector){
	mostrarProfesoresDetallado(misProfesores);
	for(int i=0;i<totalCitas;i++){
		if(misCitas[i]->getDniProf()==misProfesores->getDni()){
			mostrarCitasDetallado(misCitas[i]);
		}else{
			cout<<"No hay citas para mostrar"<<endl;
		}
	}
}
//estas son las 3 opciones que tiene el profesor: ver los datos de forma detallada, ver los vehiculos o salir
void  enunciadoOpcionesProfesor(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Profesor *misProfesores, Vehiculo ** misVehiculos,  Cita **misCitas, DBConnector &dbconnector){
	int opcion;
	do{
		cout<<endl;
		cout<<"Pulsa 1 para ver tus datos de forma detallada"<<endl;
		cout<<"Pulsa 2 para ver los vehiculos"<<endl;
		cout<<"Pulsa 3 para salir"<<endl;
		cin>>opcion;
		switch(opcion){
		case 1://para ver los datos
			verInforDelProfesor( totalProfesores,  totalCitas,  misProfesores, misCitas, dbconnector);
			break;
		case 2://para ver los vehiculos
			mostrarVehiculosDetallado(totalVehiculos, misVehiculos);
			break;


	}
}while(opcion!=4);

}




