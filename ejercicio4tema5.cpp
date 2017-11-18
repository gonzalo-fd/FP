
#include <iostream>
using namespace std;

#include <fstream>
#include <string>

int main()
{
	ifstream archivo;
	char c;
	int contador = 0;
	bool encontrado = true;

	archivo.open("input.txt");

	if (!archivo.is_open())
	{
		cout << "Error, el archivo no existe o no se pudo abrir.";
		encontrado = false;
	}

	else
	{
		do {archivo.get(c);			
			
			if (c == 'x')
			{
				archivo.get(c);

				if (c == 'y')
				{
					archivo.get(c);
					contador++;
				}
			}
		}
		while (c != '*');
	}
	archivo.close();
	
	if (encontrado == true)
	{
		cout << "La secuencia aparece " << contador << " veces.";
	}

	system("pause");

	return 0;
}