/*
 * vehiculo.h
 *
 *  Created on: 14/5/2015
 *      Author: Alumno
 */

#ifndef SRC_VEHICULO_H_
#define SRC_VEHICULO_H_

namespace contenedorvehiculos{

class vehiculo{

	int matricula;
	int antiguedad;
	std:: string color;


public:
vehiculo(int matricula, int antiguedad, std:: string color);
void setmatricula(int matricula);
void setantiguedad(int antiguedad);
void setcolor(std::string color );

int getMatricula();
int getAntiguedad();
std:: string getColor();

};

}




#endif /* SRC_VEHICULO_H_ */
