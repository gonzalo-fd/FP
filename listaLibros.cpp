#include <iostream>
#include <string>
#include "listaLibros.h"
using namespace std;

void buscar(const tListaLibros &lista, const string &fecha, bool &encontrado, int &pos)
{
	int ini = 0, final = lista.cont - 1, mitad;
	encontrado = false;

	while((ini < final) && !encontrado)
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
}

void insertar(const tLibro &libro, tListaLibros lista, bool &ok)
{
	bool encontrado;
	int pos;
	ok = true;

	if(lista.cont == MAXLIBROS)
	{
		ok = false;
	}
	else
	{
		buscar(lista, libro.fecha, encontrado, pos);
		if(!encontrado)
		{
			for (int i = lista.cont; i > pos; i--)
			{
				lista.libros[i] == lista.libros[i - 1];
			}
			lista.libros[pos] = new tLibro(libro);
			lista.cont++;
		}
	}
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

void destruir(tListaLibros lista)
{
	for (int i = 0; i < lista.cont; i++) 
	{
		delete lista.libros[i];
	}
	lista.cont = 0;
}