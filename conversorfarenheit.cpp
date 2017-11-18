#include <iostream>
using namespace std;
int main()
{
	double tempF, tempC; //temperatura en fahrenheit y celsius
	cout << "Introduzca la temperatura en grados Fahrenheit: ";
	cin >> tempF; //cin introduce el valor que escribe el usuario en una variable
	tempC = 5.0 / 9 * (tempF - 32);
	cout << "Temperatura en grados Celsius = " << tempC << endl;
	
	return 0;
}