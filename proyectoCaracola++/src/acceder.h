#ifndef ACCEDER_H_
#define ACCEDER_H_
#include <string>
using namespace std;
using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;

int enunciadoInicioIV();
void comprobarCP(int totalClientes, int totalProfesores, int totalVehiculos, int dni, int & totalCitas, Clientes ** misClientes, Profesor * *misProfesores, Cita** misCitas);
void entrarCliente(int totalClientes, int totalProfesores, int totalVehiculos, int &totalCitas, Clientes* misClientes, Cita** misCitas);
void opcionesCliente(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas);
#endif
