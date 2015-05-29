#ifndef SRC_OPCIONESPROFESOR_H_
#define SRC_OPCIONESPROFESOR_H_
#include "DBConnector.h"
using namespace contenedorClientes;
using namespace contenedorProfesor;

void enunciadoOpcionesProfesor(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Profesor *misProfesores, Vehiculo ** misVehiculos,  Cita **misCitas, DBConnector &dbconnector);
void verInforDelProfesor(int totalProfesores, int totalCitas, Profesor* misProfesores, Cita** misCitas, DBConnector &dbconnector);




#endif /* SRC_OPCIONESPROFESOR_H_ */




