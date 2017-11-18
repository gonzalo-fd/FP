#include <iostream>
using namespace std;
int main()
{
double ex1, exFeb, ex2, exFinal, pt, acAd, notaFinal;
cout << "Introduce la nota del examen de la mitad del 1 cuatrimestre: ";
cin >> ex1 ;
cout << "Introduce la nota del examen de febrero: ";
cin >> exFeb ;
cout << "Introduce la nota del examen de la mitad del 2 cuatrimestre: ";
cin >> ex2 ;
cout << "Introduce la nota del examen final: ";
cin >> exFinal ;
cout << "Introduce la nota de las practicas: ";
cin >> pt ;
cout << "Introduce la nota de la actividad adicional: ";
cin >> acAd ;
notaFinal= (ex1 * 0.05) + (exFeb * 0.1) + (ex2 * 0.1) + (exFinal * 0.45) + (pt * 0.2) + (acAd * 0.1) ;
cout << " Nota final= " << notaFinal ;
return 0;
}
