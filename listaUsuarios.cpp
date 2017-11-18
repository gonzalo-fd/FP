#include <iostream>
#include <fstream>

#include "listaUsuarios.h"

using namespace std;

void inicializar(tListaUsuarios &usuarios)
{
	usuarios.cont = 0;
}

bool cargar(tListaUsuarios &usuarios, string dominio)
{
	ifstream archivo;
	bool cargado = true;
	string aux;
	int i = 0;
	archivo.open(dominio + "_usuarios.txt");
	if (!archivo.is_open())
	{
		cargado = false;
	}
	else
	{
		archivo >> usuarios.lista[usuarios.cont].nombre;
		while (usuarios.lista[usuarios.cont].nombre != "XXX" && usuarios.cont < MAX_USUARIOS)
		{
			cargar(usuarios.lista[usuarios.cont], archivo);
			usuarios.cont++;
		}
		archivo.close();
	}
	return cargado;
}

void guardar(const tListaUsuarios& usuarios, string dominio)
{
	ofstream archivo;
	archivo.open(dominio + "_usuarios.txt");
	for (int i = 0; i < usuarios.cont; i++)
	{
		guardar(usuarios.lista[i], archivo);
	}
	archivo << "XXX";
	archivo.close();
}

bool buscarUsuario(const tListaUsuarios &usuarios, string id, int &posicion)
{
	int ini = 0, fin = usuarios.cont - 1, mitad;
	bool encontrado = false;

	while ((ini <= fin) && !encontrado) 
	{
		mitad = (ini + fin) / 2;
		if (id == usuarios.lista[mitad].nombre)
			encontrado = true;
		else
			if (id < usuarios.lista[mitad].nombre)
				fin = mitad - 1;
			else
				ini = mitad + 1;
	}
		posicion = mitad;

	return encontrado;
}

bool aniadir(tListaUsuarios &usuarios, const tUsuario &usuario)
{
	bool ok = true;
	int posicion;
	if(usuarios.cont == MAX_USUARIOS)
	{
		ok = false;
	}
	else
	{
		if(buscarUsuario(usuarios, usuario.nombre, posicion))
		{
		for (int j = usuarios.cont; j > posicion; j--)
		{
			usuarios.lista[j] = usuarios.lista[j - 1];
		}	
		usuarios.lista[posicion] = usuario;
		usuarios.cont++;
		}
		else
			ok = false;
	}
	return ok;
}