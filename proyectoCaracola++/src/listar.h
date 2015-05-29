#ifndef LISTAR_H_
#define LISTAR_H_

#include "clientes.h"
#include "profesor.h"
#include "citas.h"
#include "vehiculo.h"
#include "DBConnector.h"

using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;
using namespace contenedorVehiculos;

void enunciadoIII(int totalClientes, int totalProfesores, int totalCitas, int totalVehiculos, Clientes** misclientes, Profesor** misProfesores, Cita** miscitas, DBConnector &dbconnector);
void mostrarCliente(int totalClietes,Clientes** misclientes, DBConnector &dbconnector);
void mostrarProfeosres(int totalProfesores, Profesor** misProfesores, DBConnector &dbconnector);
void mostrarCitas(int totalCitas, Cita** miscitas, DBConnector &dbconnector);
void mostrarVehiculos(int totalVehiculos, DBConnector &dbconnector);

void mostrarClienteDetallado(Clientes* misclientes);
void mostrarProfesoresDetallado(Profesor* misProfesores);
void mostrarCitasDetallado(Cita* miscitas);
void mostrarVehiculosDetallado(int totalVehiculos, Vehiculo** misvehiculos);
#endif
