#include <iostream>
using namespace std;
int main()
{
	double celsius, fahrenheit, resta;
	
	cout << " Fahrenheit= " ;
	cin >> fahrenheit;
	resta = fahrenheit - 32 ;
	celsius =  5.0 / 9 * resta;
	cout << " Celsius= " << celsius << endl;
	
	return 0;
}