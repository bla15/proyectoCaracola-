#ifndef ACCEDER_H_
#define ACCEDER_H_
#include <string>
#include "vehiculo.h"
using namespace std;
using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;
using namespace contenedorVehiculos;

int enunciadoInicioIV();
void comprobarCP(int& totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores, Cita** misCitas, Vehiculo** misVehiculos);
void entrarCliente(int& totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente);
void entrarProfesores(int& totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes);
void opcionesCliente(int& totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores, Clientes** cliente);
void opcionesProfesor(int& totalClientes, int totalProfesores, int totalVehiculos, int totalCitas, Profesor * misProfesores, Cita**misCitas, Vehiculo **misVehiculos, Clientes** misClientes);
#endif
