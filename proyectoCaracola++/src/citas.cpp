#include "citas.h"
#include <iostream>
using namespace std;

namespace contenedorCitas{
Cita::Cita(int matricula, int dniCl, int dniProf){
	this->matricula=matricula;
	this->dniCl=dniCl;
	this->dniProf=dniProf;
}

int Cita::getMatricula()const{
	return this->matricula;
}
int Cita::getDniCl() const{
	return this->dniCl;
}
int Cita::getDniProf() const{
	return this-> dniProf;
}

}