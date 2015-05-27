/*
 * vehiculo.cpp
 *
 *  Created on: 14/5/2015
 *      Author: Alumno
 */

#include "vehiculo.h"
#include <iostream>
using namespace std;

namespace contenedorVehiculos{


 Vehiculo:: Vehiculo(int matricula, int antiguedad, std:: string color ){
	 this->matricula=matricula;
	 this->antiguedad=antiguedad;
	 this->color=color;
 }

 int Vehiculo:: getMatricula() const{
	 return this->matricula;
 }


void Vehiculo::setmatricula(int matricula){
	this->matricula=matricula;
}

int Vehiculo:: getAntiguedad() const{
	return this->antiguedad;
}

void Vehiculo:: setantiguedad(int antiguedad){
	this->antiguedad =antiguedad;
}

string Vehiculo:: getColor() const{
	return this->color;
}

void Vehiculo:: setcolor(string color){
	this->color=color;
}
}


