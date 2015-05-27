#ifndef CITAS_H_
#define CITAS_H_

#include <iostream>
#include <string>

namespace contenedorCitas{
class Cita{
private:
	int matricula;
	int dniCl;
	int dniProf;
public:
	Cita(int matricula, int dniCl, int dniProf);
	int getMatricula()const;
	int getDniCl() const;
	int getDniProf() const;
};
}
#endif
