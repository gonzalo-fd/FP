#include "venta.h"
#include "listaVenta.h"
#include "listaVentasDiarias.h"

int main()
{
	tListaVentasDiarias lista;

	cargar(lista);
	mostrar(lista);
	apocalypse(lista);

	system("pause");
	return 0;
}