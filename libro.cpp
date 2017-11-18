#include <iostream>
#include <string>
#include "libro.h"
using namespace std;
#include <iomanip>

void mostrar(const tLibro &libro)
{
	cout << fixed << setw(12) << libro.codigo << " - " << setw(9) << libro.fecha << " - " << libro.dias << endl;
}