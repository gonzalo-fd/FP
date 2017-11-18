#include "venta.h"
#include <iostream>
using namespace std;

void mostrar(tVenta venta)
{
	cout << venta.hora << ":  " << venta.codigo << "  -  " << venta.unidades << "  x  " << venta.precio << "  $  =  " << totalVenta(venta) << " $" << endl;
}

int totalVenta(tVenta venta)
{
	int total;

	total = venta.unidades * venta.precio;

	return total;
}