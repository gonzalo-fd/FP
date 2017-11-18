#include <iostream>

using namespace std;

int main()
{
   double sueldoneto, sueldobase, compdestino, compacademico, horasextra, numhijos, nummayores, sueldobruto, impuestosporcent, impuestos;
   cout << "Programa para el calculo de nominas: " << endl;
   cout << "Sueldo base: ";
   cin >> sueldobase;
   cout << "Complemento de destino: ";
   cin >> compdestino;
   cout << "Complemento de cargo academico: ";
   cin >> compacademico;
   cout << "Horas extra realizadas: ";
   cin >> horasextra;
   cout << "Hijos: ";
   cin >> numhijos;
   cout << "Mayores: ";
   cin >> nummayores;
   sueldobruto = sueldobase + compdestino + compacademico + 23 * horasextra;
   impuestosporcent = 24 - (2 * numhijos) - nummayores;
   impuestos = impuestosporcent * sueldobruto / 100;
   sueldoneto = sueldobruto - impuestos;
   cout << "Calculo de la nomina.- " << endl;
   cout << "Sueldo bruto: " << sueldobruto << " euros" << endl;
   cout << "Porcentaje de IRPF: " << impuestosporcent << " %" << endl;
   cout << "Retencion por IRPF: " << impuestos << " euros" << endl;
   cout << "Sueldo neto: " << sueldoneto << " euros";
  
   return 0;
}