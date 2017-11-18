#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   double cuotamensual, capital, ratioanual, ratiomensual, plazoanos, plazomeses, totalpagar, intereses;
   cout << "Programa para el calculo de hipoteca: " << endl;
   cout << "Introduzca el capital prestado: ";
   cin >> capital;
   cout << "Introduzca el interes anual en porcentaje: ";
   cin >> ratioanual;
   cout << "Introduzca el plazo en anos para devolver el prestamo: ";
   cin >> plazoanos;
   ratiomensual = ratioanual / 12;
   plazomeses = plazoanos * 12;
   cuotamensual = ((capital * ratiomensual) / (100 * (1 - pow(1 + (ratiomensual / 100), -plazomeses))));
   totalpagar = cuotamensual * plazomeses;
   intereses = totalpagar - capital;
   cout << "Cuota mensual a pagar: " << cuotamensual << " euros" << endl;
   cout << "Total a pagar: " << totalpagar << " euros" << endl;
   cout << "El total a pagar se divide en cantidad de amortizacion e intereses de este modo:" << endl;
   cout << "Cantidad de amortizacion: " << capital << " euros" << endl;
   cout << "Intereses: " << intereses << " euros";
  
   return 0;
}