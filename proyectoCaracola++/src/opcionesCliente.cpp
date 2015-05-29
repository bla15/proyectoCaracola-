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

void enunciadoOpcinesCliente(int &totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor** misProfesores, Clientes** cliente, DBConnector &dbconnector){
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
			cambiarInformacion(misClientes, dbconnector);
			break;
		case 3://para pedir una cita
			if(totalCitas<5){

			}else{
				cout<<"El array de citas esta lleno"<<endl;
			}
			pedirCita(totalClientes, totalProfesores, totalVehiculos, totalCitas, misClientes, misProfesores,misCitas, misVehiculos, dbconnector);
			break;
		case 4://para eliminar este cliente
			opcion=eliminarCliente(totalClientes, totalCitas, misClientes, misCitas, cliente, dbconnector);

			break;
	}

}while((opcion!=5));

}
void verInforDelCliente(int& totalClientes, int totalCitas, Clientes* misClientes, Cita** misCitas){
	mostrarClienteDetallado(misClientes);
	//ahora comprobamos si hay alguna cita para este profesor
	cout<<"Sus citas Programadas son: "<<endl;
	for(int i=0;i<totalCitas;i++){
		if(misCitas[i]->getDniCl()==misClientes->getDni()){
			mostrarCitasDetallado(misCitas[i]);
		}else{
			cout<<"No hay citas para usted programadas"<<endl;
		}
	}
}
void cambiarInformacion(Clientes* misClientes, DBConnector &dbconnector){
	int opcionDos;
	cout<<"Pulsa 1 para cambiar el nombre"<<endl;
	cout<<"Pulsa 2 para cambiar el apellido"<<endl;
	cout<<"Pulsa 3 para cambiar la clave"<<endl;
	cout<<"Pulsa 4 para cambiar el telefonpo"<<endl;
	cout<<"Pulsa 5 para salir"<<endl;
	cin>>opcionDos;
	cambiarInformacionMecanismo(opcionDos, misClientes, dbconnector);
}
void cambiarInformacionMecanismo(int opcionDos, Clientes *misClientes, DBConnector &dbconnector){
	string nombre;
	string apellido;
	string clave;
	int telefono;
	switch(opcionDos){
	case 1:
		cout<<"introduzca se nuevo nombre"<<endl;
		cin>>nombre;
		misClientes->setNombre(nombre);
		dbconnector.updateClienteString(misClientes->getDni(), "nombre", nombre);
		break;
	case 2:
		cout<<"introduzca se nuevo apellido"<<endl;
		cin>>apellido;
		misClientes->setApellido(apellido);
		dbconnector.updateClienteString(misClientes->getDni(), "apellido", apellido);
		break;
	case 3:
		cout<<"introduzca su vieja clave"<<endl;
		cin>>clave;
		if(clave.compare(misClientes->getClave()) == 0){
			cout<<"introduzca su clave nueva"<<endl;
			cin>>clave;
			misClientes->setClave(clave);
			dbconnector.updateClienteString(misClientes->getDni(), "clave", clave);
		}
		break;
	case 4:
		cout<<"introduzca su nuevo telefono"<<endl;
		cin>>telefono;
		misClientes->setTelefono(telefono);
		dbconnector.updateClienteInt(misClientes->getDni(), "telefono", telefono);
		break;

	}
}
void pedirCita(int &totalClientes, int totalProfesores, int totalVehiculos, int  &totalCitas, Clientes* misClientes, Profesor** misProfesores,  Cita** misCitas, Vehiculo** misVehiculos, DBConnector &dbconnector){
	int dni;
	int matricula;
	cout<<"En esta autoescuela hay los siguientes profesores: "<<endl;
	for(int i=0;i<totalProfesores;i++){
		cout<<misProfesores[i]->getNombre()<<" con DNI: "<<misProfesores[i]->getDni()<<endl;
	}

	cout<<"Introduce el DNI del profesor para la cita: "<<endl;
	cin>>dni;
	if(comprobarDNI(totalProfesores, dni,misProfesores)==true){
		cout<<"En esta autoescuela tenemos estos vehiculos: "<<endl;
		mostrarVehiculos(totalVehiculos, dbconnector);
		cout<<"Elige un vehiculo, introduciendo su matricula"<<endl;
		cin>>matricula;
		if(comprobarMatricula(totalVehiculos, matricula, misVehiculos)==true){
			crearCitas(totalCitas, misCitas, dni, matricula, misClientes, dbconnector);
		}else{
			cout<<"No existe esa matricula"<<endl;
		}
	}else{
		cout<<"No existe un profesor con ese dni"<<endl;
	}

}
bool comprobarDNI(int totalProfesores, int dni, Profesor** misProfesores){
	int existe=false;

	for(int i=0; i<totalProfesores;i++){

		if(misProfesores[i]->getDni()==dni){
			existe=true;
		}
	}

	return existe;
}
bool comprobarMatricula(int totalVehiculo, int matricula, Vehiculo** misVehiculos){
	int existe=false;
	for(int i=0; i<totalVehiculo;i++){

		if(misVehiculos[i]->getMatricula()==matricula){
			existe=true;
		}
	}
	return existe;
}
void crearCitas(int& totalCitas, Cita** miscitas, int dniProfesor, int matricula, Clientes* misClientes, DBConnector &dbconnector){
	miscitas[totalCitas]=new Cita(matricula, misClientes->getDni(),dniProfesor);
	totalCitas++;
	dbconnector.insertNewCita(matricula, misClientes->getDni(), dniProfesor);
	cout<<"Cita creada"<<endl;
}
int eliminarCliente(int &totalClientes, int &totalCitas, Clientes* misClientes,  Cita** misCitas, Clientes** cliente, DBConnector &dbconnector){
	int bandera=4;
	int seguro;
	int totalcit=totalCitas;
	int totalClie= totalClientes;
	cout<<"vas a eliminarte de la lista, pulsa 1 si es correcto o otro numero si deseas salir"<<endl;
	cin>>seguro;
	if(seguro==1){

		//hacemos una copia del cliente en cuestion
		Clientes* temCliente = misClientes;

		//primero borramos las citas asociadas a ese cliente
		if(totalcit>1){
			dbconnector.deleteCita(misClientes->getDni());
			for(int z=0;z<totalcit;z++){
				if(misClientes->getDni()==misCitas[z]->getDniCl()){

					for(int q=z+1;q<totalcit;q++){//Si hay una coincidencia desde ese punto corremos el array
						misCitas[q-1]->clonado(misCitas[q]);
					}
					totalCitas--;//reducimos el tamaño del array
				}
			}
		}else{//si solo hay una cita en el array entra
			if(temCliente->getDni()==misCitas[0]->getDniCl()){//comprobamos si la cita guardada es de nuestro cliente
				misCitas[0]->borradoGeneral();
				totalCitas--;
			}
		}

		//ahora se borra el cliente en cuestion ya que no hay ninguna cita asociada a el
		dbconnector.deleteCliente(misClientes->getDni());
		if(totalClie>1){
			for(int z=totalClie+1;z< totalClie;z++){//for que corre la lista de los clientes
				cliente[z-1]->clonado(cliente[z]);
			}
			totalClientes--;
		}else{
			delete misClientes;
			totalClientes--;

		}
		bandera=5;
	}else{
		cout<<"Has seleccionado no eliminar"<<endl;

	}
	return bandera;
}
