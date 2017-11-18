#include <iostream>
using namespace std;
int main() 

{
	double pi, radio, altura, resultado;
 
	pi = 3.141592;
 
	cout << " Radio= " << endl;
	cin >> radio;
	cout << " Altura= " << endl;
	cin >> altura;

	resultado = pi * radio * radio * altura / 3;
	cout << " Resultado= " << resultado;
	
	return 0;
	
}