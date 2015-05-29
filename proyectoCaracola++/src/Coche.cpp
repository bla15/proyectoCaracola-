/*
 * Coche.cpp

 *
 *  Created on: 24/05/2015
 *      Author: Alumno
 */

#include "Coche.h"
//heredamos de la clase vehiculos y le añadimos el atributo traccion
Coche::Coche(int matricula, int antiguedad, string color, string traccion): Vehiculo(matricula, antiguedad, color){

	this->traccion = traccion;
}

string Coche::getTraccion() const{
	return this->traccion;
}

void Coche::setTraccion(string traccion){
	this->traccion = traccion;
}

