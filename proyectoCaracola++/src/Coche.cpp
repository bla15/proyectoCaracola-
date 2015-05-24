/*
 * Coche.cpp

 *
 *  Created on: 24/05/2015
 *      Author: Alumno
 */

#include "Coche.h"

Coche::Coche(int matricula, int antiguedad, string color, string traccion): Vehiculo(matricula, antiguedad, color){

	this->traccion = traccion;
}

string Coche::getTraccion() const{
	return this->traccion;
}

void Coche::setTraccion(string traccion){
	this->traccion = traccion;
}

