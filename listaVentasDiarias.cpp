#include "listaVentasDiarias.h"
#include <fstream>

using namespace std;

int totalVentas(const tListaVentasDiarias &lista)
{
	int total = 0;

	for (int i = 0; i < lista.cont; i++)
	{
		total += totalVentas(lista.lista[i]->ventas);
	}

	return total;	
}

void mostrar(const tListaVentasDiarias &lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		mostrar(lista.lista[i]->ventas);
	}
}

bool buscar(const tListaVentasDiarias &lista, string fecha, int &pos, int ini, int fin)
{
	bool encontrado = false;
	
	if (ini > fin)
		pos = ini;
	else
	{
		pos = (ini + fin) / 2;
		if (fecha == lista.lista[pos]->fecha)
			encontrado = true;
		else if (fecha < lista.lista[pos]->fecha)
			encontrado = buscar(lista, fecha, pos, ini, pos - 1);
		else
			encontrado = buscar(lista, fecha, pos, pos + 1, fin);
	}
	return encontrado;
}

bool insertar(tListaVentasDiarias &lista, tVenta venta, string fecha)
{
	bool insertar = true;

	int pos, i;
	
	if (!buscar(lista, fecha, pos, 0, lista.cont - 1))
	{
		i = pos;
		for (int j = lista.cont; j > i; j--)
		{
			lista.lista[j] = lista.lista[j - 1];
		}

		lista.lista[i]->fecha = fecha;
		lista.lista[i]->ventas.listaVentas[1] = venta;
	}
	else
	{
		insertar = false;
	}

	return insertar;
}

void cargar(tListaVentasDiarias &lista)
{
	ifstream archivo;
	string fecha;
	tVenta venta;
	int pos;

	archivo.open("datos.txt");

	if (archivo.is_open())
	{
		lista.cont = 0;
		archivo >> fecha;
		while (fecha != "XXX")
		{
			archivo >> venta.hora;
			archivo >> venta.codigo;
			archivo >> venta.precio;
			archivo >> venta.unidades;

			if (!buscar(lista, fecha, pos, 0, lista.cont - 1))
			{
				insertar(lista, venta, fecha);
			}
			else
			{
				lista.lista[pos]->ventas.listaVentas[lista.lista[pos]->ventas.cont] = venta;
			}
		}
	}

}

void apocalypse(tListaVentasDiarias &lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		apocalypse(lista.lista[1]->ventas);
		delete lista.lista[i];
	}

	lista.cont = 0;
}