#ifndef ACCEDER_H_
#define ACCEDER_H_
using namespace contenedorClientes;
using namespace contenedorProfesor;

int enunciadoInicioIII();
void comprobarCP(int totalClientes, int totalProfesores, int totalVehiculos, int dni, int &totalCitas, Clientes * *misClientes, Profesor ** misProfesores);
void entrarCliente(int totalClientes, int totalVehiculos, int &totalCitas, Clientes* misClientes);

#endif
