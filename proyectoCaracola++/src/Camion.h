/*
 * Camion.h
 *
 *  Created on: 24/05/2015
 *      Author: Alumno
 */

#ifndef CAMION_H_
#define CAMION_H_

#include "vehiculo.h"
using namespace contenedorvehiculos;

class Camion: public Vehiculo{

	int peso;

public:
	Camion(int matricula, int antiguedad, string color, int peso);
	// Destructor polimorfico
	int getPeso() const;
	void setPeso(int peso);

};

#endif /* CAMION_H_ */
