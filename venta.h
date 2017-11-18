#ifndef venta_h
#define venta_h

#include <string>
using std::string;

typedef struct
{
	int codigo;
	int precio;
	int unidades;
	string hora;
}tVenta;

void mostrar(tVenta venta);
int totalVenta(tVenta venta);

#endif