#ifndef LISTAR_H_
#define LISTAR_H_

#include "clientes.h"
#include "profesor.h"
#include "citas.h"
#include "vehiculo.h"

using namespace contenedorClientes;
using namespace contenedorProfesor;
using namespace contenedorCitas;
using namespace contenedorVehiculos;

void enunciadoIII(int totalClientes, int totalProfesores, int totalCitas, int totalVehiculos, Clientes** misclientes, Profesor** misProfesores, Cita** miscitas);
void mostrarCliente(int totalClietes,Clientes** misclientes);
void mostrarProfeosres(int totalProfesores, Profesor** misProfesores);
void mostrarCitas(int totalCitas, Cita** miscitas);
void mostrarVehiculos(int totalVehiculos);

void mostrarClienteDetallado(Clientes* misclientes);
void mostrarProfeosresDetallado(Profesor* misProfesores);
void mostrarCitasDetallado(Cita* miscitas);
void mostrarVehiculosDetallado();
#endif
