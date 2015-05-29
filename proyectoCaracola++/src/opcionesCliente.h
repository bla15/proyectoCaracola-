#ifndef OPCIONESCLIENTE_H_
#define OPCIONESCLIENTE_H_
using namespace contenedorClientes;
using namespace contenedorProfesor;

void enunciadoOpcinesCliente(int totalClientes, int totalProfesores, int totalVehiculos,int totalCitas, Clientes* misClientes, Cita** misCitas, Vehiculo** misVehiculos, Profesor** misProfesores);
void verInforDelCliente(int totalClientes, int totalCitas, Clientes* misClientes, Cita** misCitas);
void cambiarInformacion(Clientes* misClientes);
void cambiarInformacionMecanismo(int opcionDos, Clientes *misClientes);
void pedirCita(int totalClientes, int totalProfesores, int totalVehiculos, int  &totalCitas, Clientes* misClientes,  Profesor** misProfesores, Vehiculo** misVehiculos );
bool comprobarDNI(int totalProfesores, int dni,  Profesor** misProfesores );
bool comprobarMatricula(int totalVehiculo, int matricula, Vehiculo** misVehiculos);
void crearCitas(int totalCitas, Cita** miscitas, int dni, int matricula);
void eliminarCliente(int &totalClientes, int &totalCitas, Clientes* misClientes);
#endif
