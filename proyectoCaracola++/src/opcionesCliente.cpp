#include "clientes.h"//para usar sus metodos
#include "profesor.h"//para usar sus metodos
#include "citas.h"
#include "acceder.h"
#include "listar.h"
#include "opcionesCliente.h"//para poder llamar a sus metodos
using namespace std;//para el cout y endl
using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;
void enunciadoOpcinesCliente(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas){
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
			verInforDelCliente(totalClientes, totalCitas, misClientes,misCitas);
			break;
		case 2://para cambiar los datos del cliente
			cambiarInformacion(misClientes);
			break;
		case 3://para pedir una cita
			pedirCita(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes);
			break;
		case 4://para eliminar este cliente

			break;

	}
}while(opcion!=5);

}
void verInforDelCliente(int totalClientes, int totalCitas, Clientes* misClientes, Cita** misCitas){
	mostrarClienteDetallado(misClientes);
	//ahora comprobamos si hay alguna cita para este profesor
	for(int i=0;i<totalCitas;i++){
		if(misCitas[i]->getDniCl()==misClientes->getDni()){
			mostrarCitasDetallado(misCitas[i]);
		}else{
			cout<<"No hay citas para usted programadas"<<endl;
		}
	}
}
void cambiarInformacion(Clientes* misClientes){
	int opcionDos;
	cout<<"Pulsa 1 para cambiar el nombre"<<endl;
	cout<<"Pulsa 2 para cambiar el apellido"<<endl;
	cout<<"Pulsa 3 para cambiar la clave"<<endl;
	cout<<"Pulsa 4 para cambiar el DNI"<<endl;
	cout<<"Pulsa 5 para cambiar el telefonpo"<<endl;
	cout<<"Pulsa 6 para salir"<<endl;
	cin>>opcionDos;
	cambiarInformacionMecanismo(opcionDos, misClientes);
}
void cambiarInformacionMecanismo(int opcionDos, Clientes *misClientes){
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
void pedirCita(int totalClientes, int totalProfesores, int totalVehiculos, int  &totalCitas, Clientes* misClientes){

}

void eliminarCliente(int *totalClientes, int * totalCitas, Clientes* misClientes){

}
