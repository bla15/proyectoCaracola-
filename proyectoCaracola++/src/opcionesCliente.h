#ifndef OPCIONESCLIENTE_H_
#define OPCIONESCLIENTE_H_
using namespace contenedorClientes;
using namespace contenedorProfesor;


void pedirCita(int totalClientes, int totalProfesores, int totalVehiculos, int  &totalCitas, Clientes* misClientes);
void eliminarCliente(int &totalClientes, int &totalCitas, Clientes* misClientes);
#endif
