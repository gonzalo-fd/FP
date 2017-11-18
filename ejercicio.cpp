#include <iostream>
using namespace std;
int main()

{
double capital, interesA, años, ratio, plazo, cuota, total, intereses;
cout << "Introduzca capital prestado:" ;
cin >> capital ;
cout << "Introduzca interes anual: " ;
cin >> interesA ;
cout << "Introduzca años de duracion del prestamo: " ;
cin >> años ;
ratio = (interesA / 12) ;
plazo = (años * 12 ) ;
cuota = (capital * ratio) / (100 * (1 - (1 + ratio / 100) - ratio) )
total = (cuota * 12) ;
intereses = (total - capital)
cout << "Couta mensual: " << cuota <<   endl;
cout << "Total: " << total << '=' << capital << '+' << intereses ;

return 0;
}