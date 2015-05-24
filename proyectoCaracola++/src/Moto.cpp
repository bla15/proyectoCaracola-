/*
 * Moto.cpp
 *
 *  Created on: 24/05/2015
 *      Author: Alumno
 */

#include "Moto.h"

Moto::Moto(int matricula, int antiguedad, string color, int cilindrada): Vehiculo(matricula, antiguedad, color){

	this->cilindrada = cilindrada;
}

int Moto::getCilindrada() const{

	return this->cilindrada;
}

void Moto::setCilindrada(int cilindrada){

	this->cilindrada = cilindrada;
}
