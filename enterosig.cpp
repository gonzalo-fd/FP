#include <iostream>
using namespace std;
int main() 

{
	int entero1, entero2 = 7;
	entero1 = entero2++;
	cout << entero1 << "Pre" << entero2 << endl;
	entero1 = ++entero2;
	cout << entero1 << "Post" << entero2 << endl;
	return 0;
}