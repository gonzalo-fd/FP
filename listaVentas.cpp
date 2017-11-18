#include "listaVenta.h"
#include <iostream>
using namespace std;

void insertarVenta(tListaVentas &lista, const tVenta &venta)
{
	if (lista.cont == 300)
	{
		cout << "lista llena" << endl;
	}
	else
	{
		lista.listaVentas = new tVenta[300];
		lista.listaVentas[lista.cont] = venta;
		lista.cont++;
	}
}

void mostrar(const tListaVentas &lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		mostrar(lista.listaVentas[i]);
	}
}

int totalVentas(const tListaVentas &lista)
{
	int total = 0;

	for (int i = 0; i < lista.cont; i++)
	{
		total += totalVenta(lista.listaVentas[i]);
	}

	return total;
}

void apocalypse(tListaVentas &lista)
{
	delete[] lista.listaVentas;
	lista.cont = 0;
}