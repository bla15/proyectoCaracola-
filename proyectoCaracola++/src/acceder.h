#ifndef ACCEDER_H_
#define ACCEDER_H_
#include <string>
#include "vehiculo.h"
#include "DBConnector.h"
using namespace std;
using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;
using namespace contenedorVehiculos;

int enunciadoInicioIV();
void comprobarCP(int& totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores, Cita** misCitas, Vehiculo** misVehiculos, DBConnector &dbconnector);
void entrarCliente(int& totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente, DBConnector &dbconnector);
void entrarProfesores(int& totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes, DBConnector &dbconnector);
void opcionesCliente(int& totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente, DBConnector &dbconnector);
void opcionesProfesor(int& totalClientes, int totalProfesores, int totalVehiculos, int totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes, DBConnector &dbconnector);
#endif
