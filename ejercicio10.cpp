#include <iostream>
using namespace std;

bool esPrimo(int n);
int menu();
void entreNaturales(int menor, int mayor);
void mayorNatural(int natural);
int contarMenores(int natural);

int main()
{
	int opcion, menor, mayor, natural;

	do
	{
		opcion = menu();

		if (opcion == 1)
		{
			cout << "Limite menor: ";
			cin >> menor;

			while (menor <= 0)
			{
				cout << "Error, el limite tiene que ser mayor que 0. Introduzca de nuevo: ";
				cin >> menor;
			}

			cout << "Limite mayor: ";
			cin >> mayor;

			while (menor >= mayor)
			{
				cout << "Error, el limite tiene que ser mayor que el menor. Introduzca de nuevo: ";
				cin >> mayor;
			}

			cout << "Primos desde " << menor << " hasta " << mayor << ": ";
			entreNaturales(menor, mayor);
			cout << "\n";
		}

		else if (opcion == 2)
		{
			cout << "Primer primo mayor que: ";
			cin >> natural;

			while (natural <= 0)
			{
				cout << "Error, el numero tiene que ser mayor que 0. Introduzca de nuevo: ";
				cin >> natural;
			}
			cout << ">>>";
			mayorNatural(natural);
			cout << "\n";
		}

		else if (opcion == 3)
		{
			cout << "Contar primos menores que: ";
			cin >> natural;

			while (natural <= 0)
			{
				cout << "Error, el numero tiene que ser mayor que 0. Introduzca de nuevo: ";
				cin >> natural;
			}
			cout << ">>>" << contarMenores(natural);
			cout << "\n";
		}

	} while (opcion != 0);

	system("pause");
	return 0;
}

bool esPrimo(int n)
{
	int contador = 0;
	bool primo = false; 

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			contador++;
		}
	}

	if (contador == 2)
	{
		primo = true;
	}

	return primo;
}

void entreNaturales(int menor, int mayor)
{
	
	for (menor; menor <= mayor; menor++)
	{
		if (esPrimo(menor))
		{
			cout << menor << ' ';
		}
	}
	cout << "\n";
}

void mayorNatural(int natural)
{
	int numero = natural; // Para evitar que el primo que se muestre sea igual al numero introducido.

	while (!esPrimo(numero) || numero == natural)
	{
		numero++;
	}
	
	cout << numero;
	cout << "\n";
}

int contarMenores(int natural) 
{
	int contador = 0;

	for (int i = 0; i < natural; i++)
	{
		if (esPrimo(i))
		{
			contador++;
		}	
	}
	return contador;
}

int menu()
{
	int opcion;

	cout << "1 - Primos entre dos naturales dados." << endl;
	cout << "2 - Primer primo mayor que un natural." << endl;
	cout << "3 - Contar primos menores que un natural." << endl;
	cout << "0 - Salir." << endl;
	cout << "Opcion:";
	cin >> opcion;

	while (opcion < 0 || opcion > 4)
	{
		cout << "Error. Opción incorrecta, seleccione una opcion válida: ";
		cin >> opcion;
	}

	return opcion;
}
