#include "nota.h"
#include <iostream>
using namespace std;

void mostrar(const tNota &nota)
{
	cout << nota.nif << " - " << nota.notaNum << " - " << nota.notaCual << endl;
}

string notaCualitativa(int nota)
{
	string notaCual;

	if (nota < 5)
	{
		notaCual = "SS";
	}
	else if (nota >= 5 && nota < 7)
	{
		notaCual = "AP";
	}
	else if (nota >= 7 && nota < 9)
	{
		notaCual = "NT";
	}
	else if (nota >= 9 && nota < 10)
	{
		notaCual = "SB";
	}
	else if (nota == 10)
	{
		notaCual = "MH";
	}

	return notaCual;
}