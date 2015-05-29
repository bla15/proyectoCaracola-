#include "citas.h"
#include <iostream>
using namespace std;

//aqui hacemos los get de las variables que necesitamos para pedir una cita; es decir,
//la matricula del vehiculo, el DNI del cliente y el DNI del profesor
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
void Cita::borradoGeneral(){
	this->dniCl=NULL;
	this->dniProf=NULL;
	this->matricula=NULL;
}
void Cita::clonado(Cita* c){
	this->matricula=c->getMatricula();
	this->dniCl=c->getDniCl();
	this->dniProf=c->getDniProf();
}

}
