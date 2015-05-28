/*
 * DBConnector.h
 *
 *  Created on: 27/05/2015
 *      Author: Alumno
 */

#ifndef DBCONNECTOR_H_
#define DBCONNECTOR_H_
#include "sqlite3.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class DBConnector {

private:
		sqlite3 *db = NULL; // Antes, en el main.c, este puntero a sqlite3 estaba como parametro

public:
	int showAllClientes();
	int showAllProfesores();
	int showAllCitas();
	int showAllVehiculos();
	int deleteCliente(int dni);
	int deleteAllProfesores();
	int deleteAllCitas();
	int deleteAllVehiculos();
	int insertNewCliente(int dni, string nombre, string apellido, string clave, int telefono);
	int insertNewProfesor(int dni, string nombre, string apellido, string clave, int telefono);
	int insertNewVehiculo(int matricula, int antiguedad, string color);
	DBConnector(string dbFile);
	~DBConnector();
};

#endif /* DBCONNECTOR_H_ */
