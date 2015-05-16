#include "comienzo.h"//para usar el clear

#include <stdio.h>//para usar fgtes y sscanf

#include "clientes.h"//para usar sus metodos
#include "profesor.h"//para usar sus metodos
using namespace std;//para el cout y endl
using namespace contenedorClientes;
using namespace contenedorProfesor;

int enunciadoInicioIII(){
		char str[10];
		int num;
		cout << "Por favor introduce tu dni" << endl;
		fgets(str, 10, stdin);
		sscanf(str, "%d", &num);
		clear_if_needed(str);
		return num;
}
