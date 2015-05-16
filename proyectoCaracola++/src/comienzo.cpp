#include "comienzo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int enunciadoInicio(){
	char str[10];
	int num=0;
	cout << "Elige una opcón" << endl;
	cout << "Pulsa 1 para registrarse" << endl;
	cout << "Pulsa 2 para listar" << endl;
	cout << "Pulsa 3 para acceder" << endl;
	cout << "Pulsa 4 para salir" << endl;
	fgets(str, 10, stdin);
	sscanf(str, "%d", &num);
	clear_if_needed(str);

	return num;

}

void clear_if_needed(char *str) // Funcion para vaciar el buffer de la consola
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}
