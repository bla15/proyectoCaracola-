/*
 * vehiculo.h
 *
 *  Created on: 14/5/2015
 *      Author: Alumno
 */

#ifndef SRC_VEHICULO_H_
#define SRC_VEHICULO_H_
#include <iostream>

namespace contenedorvehiculos{

class Vehiculo{

	int matricula;
	int antiguedad;
	std:: string color;


public:
Vehiculo(int matricula, int antiguedad, std:: string color);
void setmatricula(int matricula);
void setantiguedad(int antiguedad);
void setcolor(std::string color );

int getMatricula() const;
int getAntiguedad() const;
std:: string getColor() const;

};

}




#endif /* SRC_VEHICULO_H_ */
