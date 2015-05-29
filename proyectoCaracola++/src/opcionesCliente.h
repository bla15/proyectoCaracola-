#ifndef OPCIONESCLIENTE_H_
#define OPCIONESCLIENTE_H_
#include "DBConnector.h"
using namespace contenedorClientes;
using namespace contenedorProfesor;

void enunciadoOpcinesCliente(int& totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor** misProfesores, Clientes** cliente, DBConnector &dbconnector);
void verInforDelCliente(int &totalClientes, int totalCitas, Clientes* misClientes, Cita** misCitas);
void cambiarInformacion(Clientes* misClientes, DBConnector &dbconnector);
void cambiarInformacionMecanismo(int opcionDos, Clientes *misClientes, DBConnector &dbconnector);
void pedirCita(int &totalClientes, int totalProfesores, int totalVehiculos, int  &totalCitas, Clientes* misClientes,  Profesor** misProfesores, Cita** misCitas, Vehiculo** misVehiculos, DBConnector &dbconnector );
bool comprobarDNI(int totalProfesores, int dni,  Profesor** misProfesores );
bool comprobarMatricula(int totalVehiculo, int matricula, Vehiculo** misVehiculos);
void crearCitas(int& totalCitas, Cita** miscitas, int dniProfesor, int matricula, Clientes* misClientes, DBConnector &dbconnector);
int eliminarCliente(int &totalClientes, int &totalCitas, Clientes* misClientes, Cita** misCitas, Clientes** cliente, DBConnector &dbconnector);
#endif
