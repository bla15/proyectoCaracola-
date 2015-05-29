/*
 * Camion.cpp
 *
 *  Created on: 24/05/2015
 *      Author: Alumno
 */

#include "Camion.h"
//heredamos de la clase vehiculos y le añadimos el atributo peso
Camion::Camion(int matricula, int antiguedad, string color, int peso): Vehiculo(matricula, antiguedad, color){

	this->peso = peso;
}

int Camion::getPeso() const{
	return this->peso;
}

void Camion::setPeso(int peso){
	this->peso = peso;
}

