#include <iostream>
using namespace std;

#include <fstream>
#include <string>
bool triangulo(int entero);

int main()
{
	ifstream archivo;
	ofstream archout;
	int entero;

	archivo.open("enteros.txt");
	archout.open("enterosOut.txt");

	if (!archivo.is_open())
	{
		cout << "Error, el archivo no existe o no se pudo abrir.";
	}

	else
	{
		do
		{
			archivo >> entero;

			if (entero == 0) // Asi no mete el 0 en el archivo y hace un cout al final para que el programa no aparezca vacio.
			{
				cout << "Fin del programa" << endl;
			}

			else if (triangulo(entero) == true)
			{
				archout << entero << " SI es triangular." << endl;
			}
			else
			{
				archout << entero << " NO es triangular." << endl;
			}
		}

		while (entero != 0);

	}
	
	archivo.close();
	archout.close();
	system("pause");

		return 0;
}

bool triangulo(int entero)
{
	int triangulo = 0, aux = 0;
	bool tri = false;
	
	while (triangulo <= entero)
	{
		aux++;


		if (entero == (triangulo + aux))
		{
			tri = true;
		}

		else
		{
			triangulo = triangulo + aux;
		}
	}
	
	return tri;
}
