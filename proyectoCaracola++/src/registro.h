#ifndef REGISTRO_H_
#define REGISTRO_H_
using namespace contenedorClientes;
using namespace contenedorProfesor;

int enunciadoInicioII();
void registroClientes(Clientes ** misClientes, int totalClientes, DBConnector &dbconnector);
void registroProfesores(Profesor ** misProfesores, int totalProfesores, DBConnector &dbconnector);

#endif
