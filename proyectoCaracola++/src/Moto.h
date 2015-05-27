/*
 * Moto.h
 *
 *  Created on: 24/05/2015
 *      Author: Alumno
 */

#ifndef MOTO_H_
#define MOTO_H_

#include "Vehiculo.h"
using namespace contenedorVehiculos;

class Moto: public Vehiculo{

	int cilindrada;

public:
	Moto(int matricula, int antiguedad, string color, int cilindrada);
	// Destructor polimorfico
	int getCilindrada() const;
	void setCilindrada(int cilindrada);
};

#endif /* MOTO_H_ */
