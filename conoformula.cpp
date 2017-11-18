#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double radio = 14.5, altura = 26.79, volumen; //establece las variables
	cout << "Introduzca el radio de la base del cono: ";
	cin >> radio; //cin introduce el valor que escribe el usuario
	cout << "Introduzca la altura del cono: ";
	cin >> altura;
	volumen = (3.141592 * (pow (radio , 2) * altura) / 3);
	cout << "Volumen del cono = " << volumen << endl;
	
	return 0;
}