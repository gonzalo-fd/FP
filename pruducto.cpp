#include <iostream>
using namespace std;

int main() 
{
	int op1, op2, resultado;
	cout << "Introduce el primer numero ";	
	cin >> op1;
	cout << "Introduce el segundo numero ";
	cin >> op2;
	resultado = op1*op2;
	cout << "Resultado de "<< op1 << " * " << op2 << " es " << resultado << endl;
	return 0;

}