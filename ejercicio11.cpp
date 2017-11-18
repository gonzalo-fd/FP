#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>

void coordenadas (double r, double o, double &x, double &y);

int main()
{
	double r, o, x, y;

	cout << "Introduzca las coodenadas polares del numero complejo: " << endl;
	cout << "r: ";
	cin >> r;
	cout << "o: ";
	cin >> o;
	coordenadas(r,o,x,y);
	cout << "Las coordenadas cartesianas del numero complejo introducido son: " << endl;
	cout << '(' << setprecision(2) << fixed<< x << " , " << y << ')' << endl;

	system("pause");
	return 0;
}

void coordenadas (double r, double o, double &x, double &y)
{
	x = r * cos(o);
	y = r * sin(o);
}