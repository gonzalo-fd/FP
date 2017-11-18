#include <iostream>
using namespace std;
#include <fstream>

const int N = 101;
typedef double tLista[N];
tLista lista;

int menu();
void eliminarCantidadPosicion(int cantidad);

int main()
{
	int opcion, cantidad;

		do
		{
			opcion = menu();

			switch(opcion)
			{
				case 1:
				{
					cout << "Introduza la cantidad: ";
					cin >> cantidad;
					eliminarCantidadPosicion(cantidad);
					break;
				}
				case 2:
				{
					break;
				}
				case 3:
				{
					break;
				}
				case 4:
				{
					break;
				}
			}

	}while(opcion != 0);
	
	system("pause");
	return 0;
}

int menu()
{
	int opcion;

	cout << "1 - Eliminar una cantidad dada su posición en la lista." << endl;
	cout << "2 - Eliminar una cantidad dada de la lista." << endl;
	cout << "3 - Localizar la posición que ocupa una cantidad dada." << endl;
	cout << "4 - Mostrar la lista de cantidades." << endl;
	cout << "0 - Salir." << endl;
	cout << "opcion: ";
	cin >> opcion;

	while (opcion < 0 || opcion > 4)
	{
		cout << "opcion invalida, seleccione otra opcion.";
		cin >> opcion;
	}

	return opcion;
}

void eliminarCantidadPosicion (int cantidad)
{
	ofstream escribir;

	escribir.open("lista.txt");

	if (!escribir.is_open())
	{
		cout << "Error al abrir el archivo" << endl;
	}

	else
	{
		

	}



}