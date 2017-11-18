#include <iostream>
using namespace std;
#include <fstream>

int main()
{
	int num1, num2, num3;
	ifstream numeros;
	numeros.open("numeros.txt");

	numeros >> num1;
	numeros >> num2;
	numeros >> num3;


	numeros.close();
	
	if (num1 > num2 && num1 > num3)
	{
		cout << "El numero mayor es " << num1 << endl;
	}
	else
	{
		if (num2 > num1 && num2 > num3)
		{
			cout << "El numero mayor es " << num2 << endl;
		}
		else
		{
			cout << "El numero mayor es " << num3 << endl;
		}
	}	
	
	system("pause");
	
	return 0;
}