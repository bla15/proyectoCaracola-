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

void verInforDelProfesor(int totalProfesores, int totalCitas, Profesor* misProfesores, Cita** misCitas){
	mostrarProfesoresDetallado(misProfesores);
	for(int i=0;i<totalCitas;i++){
		if(misCitas[i]->getDniProf()==misProfesores->getDni()()){
		// Mostrar citas
		}else{
			cout<<"No hay citas para mostrar"<<endl;
		}
	}
}

void enunciadoOpcionesProfesor(int totalClientes, int totalProfesores, int totalVehiculos, int totalCitas, Profesor *misProfesores, Cita ** misCitas, Vehiculo **misVehiculos, Clientes **misClientes){
	int opcion;
	do{
		cout<<endl;
		cout<<"Pulsa 1 para ver tus datos de forma detallada"<<endl;
		cout<<"Pulsa 2 para cambiar tus datos"<<endl;
		cout<<"Pulsa 3 para ver los vehiculos"<<endl;
		cout<<"Pulsa 4 para salir"<<endl;
		cin>>opcion;
		switch(opcion){
		case 1://para ver los datos
			verInforDelProfesor(totalProfesores, totalVehiculos, misProfesores, misVehiculos);
			break;
		case 2://para cambiar los datos del profesorr
			cambiarInformacion(misProfesores);
			break;
		case 3://para ver los vehiculos
			verVehiculos(totalProfesores, totalVehiculos,misProfesores, misVehiculos);
			break;

	}
}while(opcion!=4);

}

void cambiarInformacion(Profesor *misProfesores){
	int opcionDos;
	cout<<"Pulsa 1 para cambiar el nombre"<<endl;
	cout<<"Pulsa 2 para cambiar el apellido"<<endl;
	cout<<"Pulsa 3 para cambiar la clave"<<endl;
	cout<<"Pulsa 4 para cambiar el DNI"<<endl;
	cout<<"Pulsa 5 para cambiar el telefonpo"<<endl;
	cout<<"Pulsa 6 para salir"<<endl;
	cin>>opcionDos;
	cambiarInformacionMecanismo(opcionDos, misProfesores);
}
void cambiarInformacionMecanismo(int opcionDos, Profesor *misProfesores){
	string nombre;
	string apellido;
	string clave;
	int telefono;
	int DNI;
	switch(opcionDos){
	case 1:
		cout<<"introduzca se nuevo nombre"<<endl;
		cin>>nombre;
		misProfesores->setNombre(nombre);
		break;
	case 2:
		cout<<"introduzca se nuevo apellido"<<endl;
		cin>>apellido;
		misProfesores->setApellido(apellido);
		break;
	case 3:
		cout<<"introduzca su vieja clave"<<endl;
		cin>>clave;
		if(clave.compare(misProfesores->getClave()) == 0){
			cout<<"introduzca su clave nueva"<<endl;
			cin>>clave;
			misProfesores->setClave(clave);
		}
		break;
	case 4:
		cout<<"introduzca se nuevo DNI"<<endl;
		cin>>DNI;
		misProfesores->setDni(DNI);
		break;
	case 5:
		cout<<"introduzca se nuevo telefono"<<endl;
		cin>>telefono;
		misProfesores->setTelefono(telefono);
		break;

	}
}
void verVehiculos(int totalProfesores, int totalVehiculos, Profesor *misProfesores, Vehiculo **misVehiculos){
	mostrarVehiculoDetallado(misVehiculos);
	for(int i=0;i<totalVehiculos;i++){
		if(misVehiculos[i]->getMatricula()==misProfesores->getMatricula()){
			mostrarVehiculosDetallado(misVehiculos[i]);
		}else{
			cout<<"No hay vehiculos para mostrar"<<endl;
		}
	}
}

