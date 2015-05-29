#ifndef SRC_OPCIONESPROFESOR_H_
#define SRC_OPCIONESPROFESOR_H_
using namespace contenedorClientes;
using namespace contenedorProfesor;

void enunciadoOpcionesProfesor(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Profesor *misProfesores, Vehiculo ** misVehiculos,  Cita **misCitas);
void verInforDelProfesor(int totalProfesores, int totalCitas, Profesor* misProfesores, Cita** misCitas);
void cambiarInformacion(Profesor * misProfesores);
void cambiarInformacionMecanismo(int opcionDos, Profesor * misProfesores);
void verVehiculos(int totalVehiculos, Vehiculo** misVehiculos); //iepa


#endif /* SRC_OPCIONESPROFESOR_H_ */




