#include <iostream>
using namespace std;

int main()
{
   //Declaración de variables
   double numerador, denominador, resultado;
   
   //Datos de entrada
   cout << "Numerador: ";
   cin >> numerador;
   cout << "Denominador: "; 
   cin >> denominador;
   
   //Cálculos
   resultado = numerador / denominador;
   
   //Mostrar resultados
   cout << "Resultado: " << resultado << endl;

   return 0;
}
