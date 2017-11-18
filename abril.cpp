#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Peliculas.h"

using namespace std;

int main()
{
	tLista lista;
	lista.contador = 0;
	if(!cargar(lista))
	{
		cout << "ERROR NO ARCHIVO" << endl;
	}
	else 
	{
		mostrarPeliculas(lista);
		cout << endl;
		system("pause");
		cout << endl;
		importarEstrenos(lista);
		mostrarPeliculas(lista);
		cout << endl;
		system("pause");
	}

	return 0;
}
