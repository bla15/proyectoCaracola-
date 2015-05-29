#ifndef SRC_OPCIONESPROFESOR_H_
#define SRC_OPCIONESPROFESOR_H_
using namespace contenedorClientes;
using namespace contenedorProfesor;

void enunciadoOpcinesProfesor(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Profesor *misProfesores, Vehiculo * misVehiculos);
void verInforDelProfesor(int totalProfesores, int totalVehiculos, Profesor * misProfesores, Vehiculo ** misVehiculos);
void cambiarInformacion(Profesor * misProfesores);
void cambiarInformacionMecanismo(int opcionDos, Profesor * misProfesores);
void verVehiculos(int totalVehiculos, Vehiculo** misVehiculos); //iepa


#endif /* SRC_OPCIONESPROFESOR_H_ */




