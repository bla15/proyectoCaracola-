/*
 * vehiculo.h
 *
 *  Created on: 14/5/2015
 *      Author: Alumno
 */

#ifndef SRC_VEHICULO_H_
#define SRC_VEHICULO_H_
#include <iostream>
using namespace std;

namespace contenedorvehiculos{

class Vehiculo{

	int matricula;
	int antiguedad;
	string color;


public:
Vehiculo(int matricula, int antiguedad, string color);
// Destructor virtual
void setmatricula(int matricula);
void setantiguedad(int antiguedad);
void setcolor(string color );

int getMatricula() const;
int getAntiguedad() const;
string getColor() const;

};

}




#endif /* SRC_VEHICULO_H_ */
