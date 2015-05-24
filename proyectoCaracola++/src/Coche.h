/*
 * Coche.h
 *
 *  Created on: 24/05/2015
 *      Author: Alumno
 */

#ifndef COCHE_H_
#define COCHE_H_

#include "vehiculo.h"
using namespace contenedorvehiculos;



class Coche: public Vehiculo{

	string traccion;

public:
	Coche(int matricula, int antiguedad, string color, string traccion);
	// Destructor virtual
	string getTraccion() const;
	void setTraccion(string traccion);


};


#endif /* COCHE_H_ */
