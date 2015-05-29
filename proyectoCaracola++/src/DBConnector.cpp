/*
 * DBConnector.cpp
 *
 *  Created on: 27/05/2015
 *      Author: Alumno
 */

#include "DBConnector.h"


int DBConnector::showAllClientes() {
	sqlite3_stmt *stmt; // Statement

	char sql[] = "select dni, nombre, apellido, clave, telefono from Clientes"; // El SELECT

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int dni;
	char nombre[100];
	char apellido[100];
	char clave[100];
	int telefono;

	printf("\n");
	printf("\n");
	printf("Imprimiendo clientes:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			dni = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
			strcpy(clave, (char *) sqlite3_column_text(stmt, 3));
			telefono = sqlite3_column_int(stmt, 4);
			printf("DNI: %d Nombre: %s Apellido: %s Clave: %s Telefono: %d\n", dni, nombre, apellido, clave, telefono);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int DBConnector::showAllProfesores(){
	sqlite3_stmt *stmt; // Statement

		char sql[] = "select dni, nombre, apellido, clave, telefono from Profesores"; // El SELECT

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		int dni;
		char nombre[100];
		char apellido[100];
		char clave[100];
		int telefono;

		printf("\n");
		printf("\n");
		printf("Imprimiendo Profesores:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				dni = sqlite3_column_int(stmt, 0);
				strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
				strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
				strcpy(clave, (char *) sqlite3_column_text(stmt, 3));
				telefono = sqlite3_column_int(stmt, 4);
				printf("DNI: %d Nombre: %s Apellido: %s Clave: %s Telefono: %d\n", dni, nombre, apellido, clave, telefono);
			}
		} while (result == SQLITE_ROW);

		printf("\n");
		printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (SELECT)\n");

		return SQLITE_OK;
}

int DBConnector::showAllCitas(){
	sqlite3_stmt *stmt; // Statement

		char sql[] = "select matricula, dniCl, dniProf from Citas"; // El SELECT

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		int matricula;
		int dniCl;
		int dniProf;


		printf("\n");
		printf("\n");
		printf("Imprimiendo Citas:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				matricula = sqlite3_column_int(stmt, 0);
				dniCl = sqlite3_column_int(stmt, 1);
				dniProf = sqlite3_column_int(stmt, 2);
				printf("MATRICULA: %d DNICL: %d DNIPROF: %d\n", matricula, dniCl, dniProf);
			}
		} while (result == SQLITE_ROW);

		printf("\n");
		printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (SELECT)\n");

		return SQLITE_OK;
}

int DBConnector::showAllVehiculos(){
	sqlite3_stmt *stmt; // Statement

			char sql[] = "select matricula, antiguedad, color from Vehiculos"; // El SELECT

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("SQL query prepared (SELECT)\n");

			int matricula;
			int antiguedad;
			char color[100];


			printf("\n");
			printf("\n");
			printf("Imprimiendo Vehiculos:\n");
			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
					matricula = sqlite3_column_int(stmt, 0);
					antiguedad = sqlite3_column_int(stmt, 1);
					strcpy(color, (char *)sqlite3_column_text(stmt, 3));
					printf("MATRICULA: %d ANTIGUEDAD: %d COLOR: %s\n", matricula, antiguedad, color);
				}
			} while (result == SQLITE_ROW);

			printf("\n");
			printf("\n");

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("Prepared statement finalized (SELECT)\n");

			return SQLITE_OK;
}

int DBConnector::deleteCliente(int dni) { // No nos interesa eliminar todos los clientes, solo uno
	sqlite3_stmt *stmt;

	char sql[] = "delete * from Clientes where dni = ?";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_bind_int(stmt, 1, dni);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int DBConnector::deleteAllClientes(){
	sqlite3_stmt *stmt;

		char sql[] = "delete from Clientes";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
}


int DBConnector::deleteAllProfesores(){
	sqlite3_stmt *stmt;

		char sql[] = "delete from Profesores";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
}

int DBConnector::deleteAllCitas(){
	sqlite3_stmt *stmt;

		char sql[] = "delete from Citas";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
}

int DBConnector::deleteAllVehiculos(){
	sqlite3_stmt *stmt;

		char sql[] = "delete from Vehiculos";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
}




int DBConnector::insertNewCliente(int dni, string nombre, string apellido, string clave, int telefono) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into Clientes (dni, nombre, apellido, clave, telefono) values (?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, dni); // Metemos dni
	if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}


	result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC); // metemos nombre
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 3, apellido.c_str(), apellido.length(), SQLITE_STATIC); // metemos apellido
	if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

	result = sqlite3_bind_text(stmt, 4, clave.c_str(), clave.length(), SQLITE_STATIC); // metemos clave
	if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

	result = sqlite3_bind_int(stmt,5,telefono); // metemos telefono
	if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Cliente table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int DBConnector::insertNewProfesor(int dni, string nombre, string apellido, string clave, int telefono) {
	sqlite3_stmt *stmt;

		char sql[] = "insert into Profesores (dni, nombre, apellido, clave, telefono) values (?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_int(stmt, 1, dni); // Metemos dni
		if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}


		result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC); // metemos nombre
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 3, apellido.c_str(), apellido.length(), SQLITE_STATIC); // metemos apellido
		if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

		result = sqlite3_bind_text(stmt, 4, clave.c_str(), clave.length(), SQLITE_STATIC); // metemos clave
		if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

		result = sqlite3_bind_int(stmt,5,telefono); // metemos telefono
		if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into Profesor table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
}

int DBConnector::insertNewVehiculo(int matricula, int antiguedad, string color){
	sqlite3_stmt *stmt;

		char sql[] = "insert into Vehiculos (matricula, antiguedad, color) values (?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_int(stmt, 1, matricula); // Metemos matricula
		if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				return result;
			}


		result = sqlite3_bind_int(stmt, 2, antiguedad); // metemos antiguedad
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 3, color.c_str(), color.length(), SQLITE_STATIC); // metemos color
		if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into vehiculo table\n");
			printf("%d\n", result);
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
}

DBConnector::DBConnector(string dbFile) { // Aqui se abre la conexion
	int result = sqlite3_open("Karakola.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");

	}
}

DBConnector::~DBConnector() { // Aqui se cierra la conexion
	int result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error closing database\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}
