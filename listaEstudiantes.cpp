#include "listaEstudiantes.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void inicializarEstudiantes(tListaEstudiantes &lista)
{
	lista.cont = 0;
}

bool buscar(const tListaEstudiantes &lista, string nif, int &pos)
{
	bool encontrado = false;
	int cont = 0;

	while (cont < lista.cont && !encontrado)
	{
		if (lista.estudiantes[cont]->nif == nif)
		{
			pos = cont;
			encontrado = true;
		}
		cont++;
	}

	return encontrado;
}

bool insertar(tListaEstudiantes &lista, string nif, const tLibro &libro)
{
	bool ok = true;
	int pos = 0;
	tEstudiante estudiante;

	if (lista.cont == MAX_ESTUDIANTES || buscar(lista, nif, pos) )
	{
		ok = false;
	}
	else
	{
		crearEstudiante(nif, libro, estudiante);
		lista.estudiantes[lista.cont] = new tEstudiante(estudiante);
	}

	return ok;
}

void cargar(tListaEstudiantes &lista)
{
	ifstream archivo;
	string nif;
	int cont = 0, pos = 0;
	tLibro libroAux;
	const tLibro libroAuxConst;

	archivo.open("datos.txt");

	if (archivo.is_open())
	{
		archivo >> nif;

		while (nif != "XXX" && lista.cont < MAX_ESTUDIANTES)
		{
			archivo >> libroAux.codigo;
			archivo >> libroAux.fecha;
			archivo >> libroAux.dias;

			if (buscar(lista, nif, pos))
			{
				

				if (insertar(libroAux, lista.estudiantes[pos]->prestamos)){
				}
			}
			else
			{
				insertar(lista, nif, libroAux);
				lista.cont++;
			}

			archivo >> nif;
		}
	}
	else
	{
		cout << "Error al abrir el archivo" << endl;
	}

	archivo.close();
}

void mostrar(const tListaEstudiantes &lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		cout << "-------------------------" << endl;
		mostrar(*(lista.estudiantes[i]));
	}
}

void destruir(tListaEstudiantes &lista)
{
	

	for (int i = 0; i < lista.cont; i++)
	{
		destruir(lista.estudiantes[i]->prestamos);
		delete lista.estudiantes[i];
	}
	lista.cont = 0;
}