#include <iostream>

using namespace std;

int main()
{
   int total, horas, minutos, segundos;
   cout << "Programa para la conversion de segundos a horas, minutos y segundos: " << endl;
   cout << "Numero de segundos que quieres convertir: " << endl;
   cin >> total;
   horas = int (total / 3600);
   minutos = int ((total - (horas * 3600)) / 60);
   segundos = int (total - (horas * 3600 + minutos * 60));
   cout << total << " segundos son " << horas << " horas " << minutos << " minutos y " << segundos << " segundos";
   
   return 0;
}