#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <fstream>

string calculonotas(double nota);

int main()
{
	string nombre, apellido;
	double nota, suma = 0, media, total = 0;

	ofstream archivo;
	archivo.open("notas.txt");
	cout << "Nombre: ";
	cin >> nombre;

	while (nombre != "xxx")
	{
		cout << "apellido:";
		cin >> apellido;
		cout << "nota:";
		cin >> nota;

		suma += nota;
		total += 1;

		archivo << nombre << setw(10) << apellido << setw(10) << nota << " " << calculonotas(nota) << endl;

		cout << "Nombre: ";
		cin >> nombre;

	}
	archivo << "xxx" << endl;

	media = suma / total;
	archivo << "La nota media es: " << media;

	archivo.close();

	return 0;
}

string calculonotas(double nota)
{
	string notaL;

	if (nota < 5)
	{
		notaL = "SS";
	}
	else if (nota < 7)
	{
		notaL = "AP";
	}
	else if (nota < 9)
	{
		notaL = "NT";
	}
	else if (nota < 10)
	{
		notaL = "SB";
	}
	else if (nota == 10)
	{
		notaL = "MH";
	}

	return notaL;
}

