#include "comienzo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int enunciadoInicio(){

	int num=0;
	cout << "Elige una opcón" << endl;
	cout << "Pulsa 1 para registrarse" << endl;
	cout << "Pulsa 2 para listar" << endl;
	cout << "Pulsa 3 para acceder" << endl;
	cout << "Pulsa 4 para salir" << endl;
	cout << "Pulsa 4 para salir" << endl;
	cin >> num;

	return num;

}

void clear_if_needed(char *str) // Funcion para vaciar el buffer de la consola. Yo creo que en C++ esto no hace falta
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}
