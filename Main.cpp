#include "nota.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	tNota nota;

	nota.nif = "444444f";
	nota.notaCual = "SS",
	nota.notaNum = 3;

	mostrar(nota);
	cout << notaCualitativa(nota.notaNum) << endl;



	system("pause");
	return 0;
}

