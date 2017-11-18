#include <iostream>
using namespace std;
#include <string>
#include <cctype>

int main()
{
	char c;
	int blancos = 0, letras = 0, digitos = 0;
	bool fin;

		do
		{
			cout << "Introduzca una secuencia de caracteres:" << endl;

			do
			{
	
			cin.get(c);

				if (isdigit(c))
				{
					digitos++;
				}

				else if (isalpha(c))
				{
					letras++;
				}

				else if (c == ' ')
				{
					blancos++;
				}
				else if (c == '.')
				{
					if (c == '.')
					{
						fin = 0;
					}
				}

			} while (c != '.' || c != ')');
			
			cout << "Blancos: " << blancos << "Letras: " << letras << "Digitos: " << digitos << endl;
			
			letras = 0;
			blancos = 0;
			digitos = 0;
		
	} while (fin == 1);

		cout << "Fin del programa" << endl;

	system("pause");

	return 0;
}