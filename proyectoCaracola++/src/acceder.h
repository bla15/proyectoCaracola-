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
void comprobarCP(int totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores, Cita** misCitas, Vehiculo** misVehiculos);
void entrarCliente(int totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores);
void opcionesCliente(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor * *misProfesores);
#endif
