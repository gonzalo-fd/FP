#ifndef listaVentasDiarias_h
#define listaVentasDIarias_h

#include "listaVenta.h"
#include "venta.h"

const int MAX_DIAS = 200;

typedef struct
{
	tListaVentas ventas;
	string fecha;
}tVentaDiaria;

typedef tVentaDiaria * tVentaDiariaPtr;

typedef tVentaDiariaPtr tVentasDiarias[MAX_DIAS];

typedef struct
{
	tVentasDiarias lista;
	int cont;
}tListaVentasDiarias;

int totalVentas(const tListaVentasDiarias &lista);
void mostrar(const tListaVentasDiarias &lista);
bool buscar(const tListaVentasDiarias &lista, string fecha, int &pos, int ini, int fin);
bool insertar(tListaVentasDiarias &lista, tVenta venta, string fecha);
void cargar(tListaVentasDiarias &lista);
void apocalypse(tListaVentasDiarias &lista);
#endif