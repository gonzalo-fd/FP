#include <iostream>
#include <fstream>

#include "listaRegistros.h"

using namespace std;

void inicializar(tListaRegCorreo &listaReg)
{
	listaReg.cont = 0;
}

void cargar(tListaRegCorreo &listaReg, ifstream &archivo)
{
	archivo >> listaReg.cont;
	for (int i = 0; i < listaReg.cont; i++)
	{
		archivo >> listaReg.lista[i].id_correo;
		archivo >> listaReg.lista[i].leido;
	}
}

void guardar(const tListaRegCorreo &listaReg, ofstream &archivo)
{
	archivo << listaReg.cont << endl;
	for (int i = 0; i < listaReg.cont; i++)
	{
		archivo << listaReg.lista[i].id_correo << "   ";
		archivo << listaReg.lista[i].leido << endl;
	}
}

bool insertar(tListaRegCorreo &listaReg, tRegCorreo registro) // const
{
	bool ok = true;
	int pos;
	if(listaReg.cont == MAX_REGS)
	{
		ok = false;
	}
	else
	{
		int i = buscar(listaReg, registro.id_correo);
		for (int j = listaReg.cont; j > i; j--)
		{
			listaReg.lista[j] = listaReg.lista[j - 1];
		}	
		listaReg.lista[i] = registro;
		listaReg.cont++;
	}
	return ok;
}

int buscar(const tListaRegCorreo &listaReg, string id)
{
	
	int ini = 0, fin = listaReg.cont - 1, mitad, pos;
	bool encontrado = false;

	while ((ini <= fin) && !encontrado) 
	{
		mitad = (ini + fin) / 2;
		if (id == listaReg.lista[mitad].id_correo)
			encontrado = true;
		else
			if (id < listaReg.lista[mitad].id_correo)
				fin = mitad - 1;
			else
				ini = mitad + 1;
	}

	if (encontrado)
		pos = mitad;
	else
		pos = -1;
	return pos;
}

bool borrar(tListaRegCorreo &listaReg, string id)
{
	bool ok = true;

	if ((buscar(listaReg, id) != -1))
	{
		for (int i = buscar(listaReg, id); i < listaReg.cont; i++)
		{
			listaReg.lista[i] = listaReg.lista[i + 1];
		}
	}
	else
	{
		ok = false;
	}
	return ok;
}

bool correoLeido(tListaRegCorreo &listaReg, string id)
{
	bool ok = true;

	if ((buscar(listaReg, id) != -1))
	{
		listaReg.lista[buscar(listaReg, id)].leido = true;
	}
	else
	{
		ok = false;
	}
	return ok;
}