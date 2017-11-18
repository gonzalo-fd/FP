#include <iostream>

using namespace std;

int main()
{
   double examen1, examenfeb, examen2, examenfinal, notapracticas, actadicional, notafinal;
   cout << "Programa para el calculo de la nota final de alumnos: " << endl;
   cout << "Nota del alumno en el examen del primer cuatrimestre: " << endl;
   cin >> examen1;
   cout << "Nota del alumno en el examen de febrero: " << endl;
   cin >> examenfeb;
   cout << "Nota del alumno en el examen del segundo cuatrimestre: " << endl;
   cin >> examen2;
   cout << "Nota del alumno en el examen final: " << endl;
   cin >> examenfinal;
   cout << "Nota  media del alumno en las practicas: " << endl;
   cin >> notapracticas;
   cout << "Nota del alumno en la actividad adicional: " << endl;
   cin >> actadicional;
   notafinal = examen1 * 0.05 + examenfeb * 0.1 + examen2 * 0.1 + examenfinal * 0.45 + notapracticas * 0.2 + actadicional * 0.1;
   cout << "La nota final del alumno es: " << notafinal;
   
   return 0;
}