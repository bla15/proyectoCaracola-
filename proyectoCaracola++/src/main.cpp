#include <iostream>
#include "clientes.h"
#include "comienzo.h"
using namespace std;


int main() {
	int opcion;
	cout << "Bienvenido a la autoescuela Caracola!!!" << endl;
	do{
		opcion=enunciadoInicio();
		if(opcion==1){
			cout<<"ueeeeeeee"<<endl;
		}
	}while(opcion!=4);

	return 0;
}
