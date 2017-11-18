#ifndef listaVenta_h
#define listaventa_h

#include "venta.h"

typedef tVenta *tVentaPtr;

typedef struct
{
	tVentaPtr listaVentas;
	int cont;
}tListaVentas;

void insertarVenta(tListaVentas &lista, const tVenta &venta);
void mostrar(const tListaVentas &lista);
int totalVentas(const tListaVentas &lista);
void apocalypse(tListaVentas &lista);

#endif