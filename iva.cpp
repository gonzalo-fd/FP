#include <iostream>
using namespace std;

int main()
{
   //Declaración de variables
   double numero, precio, total;
   
   //Datos de entrada
   cout << "Numero de unidades : ";
   cin >> numero;
   cout << "Precio del producto (por unidad): "; 
   cin >> precio;
   
   //Cálculos
   total = (numero*precio)*1.21;   
   //Mostrar resultados
   cout << "Resultado: " << total << endl;

   return 0;
}
