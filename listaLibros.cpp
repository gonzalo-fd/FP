#include <iostream>
#include <string>
#include "listaLibros.h"
using namespace std;

void inicializar(tListaLibros &lista)
{
	lista.cont = 0;
}

bool buscar(const tListaLibros &lista, const string &fecha, int &pos)
{
	int ini = 0, final = lista.cont - 1, mitad;
	bool encontrado = false;

	while((ini <= final) && !encontrado)
	{
		mitad = (ini + final) / 2;
		if(lista.libros[mitad]->fecha == fecha)
			encontrado = true;

		else if(lista.libros[mitad]->fecha < fecha)
		{
			final = mitad -1;
		}
		else
		{
			ini = mitad +1;
		}
	}
	if(encontrado)
	{
		pos = mitad;
	}
	else
	{
		pos = ini;
	}

	return encontrado;
}

bool insertar(tLibro libro, tListaLibros &lista)
{
	bool encontrado = false;
	int pos;
	bool ok = true;

	if(lista.cont == MAX_LIBROS)
	{
		ok = false;
	}
	else
	{
		buscar(lista, libro.fecha, pos);
		if(!encontrado)
		{
			for (int i = lista.cont; i > pos; i--)
			{
				lista.libros[i] = lista.libros[i - 1];
			}
			lista.libros[pos] = new tLibro(libro);
			lista.cont++;
		}
	}
	return ok;
}

void mostrar(const tListaLibros lista){
	mostrar(lista, 0);
}

void mostrar(const tListaLibros lista, int pos)
{
	if (pos < lista.cont) 
	{
		mostrar(*(lista.libros[pos]));
		mostrar(lista, pos + 1);
	}
}

void destruir(tListaLibros &lista)
{
	for (int i = 0; i < lista.cont; i++) 
	{
		delete lista.libros[i];
	}
	lista.cont = 0;
}