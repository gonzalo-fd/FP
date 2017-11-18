#include <iostream>
#include <fstream>

#include "listaCorreos.h"

using namespace std;

void inicializar(tListaCorreos &correos)
{
	correos.cont = 0;
}

bool cargar(tListaCorreos &correos, string dominio)
{
	int i = 0;
	bool cargado = true;
	string auxCuerpo;
	ifstream leer;
	tCorreo correoAux;
	leer.open(dominio + "_correos.txt");
	if(!leer.is_open())
	{
		cargado = false;
	}
	else
	{
		leer >> correoAux.identificador;
		while(correoAux.identificador != "XXX")
		{
			leer >> correoAux.fecha;
			leer >> correoAux.emisor;
			leer >> correoAux.destinatario;
			getline (leer, correoAux.asunto);
			getline (leer, auxCuerpo);
			while (auxCuerpo != "X")
			{
				correoAux.cuerpo += auxCuerpo;
				getline (leer, auxCuerpo);
			}
			leer >> correoAux.identificador;
		}
	}
	leer.close();
	return cargado;
}

void guardar(const tListaCorreos &correos, string dominio)
{

	ofstream guardar;

	guardar.open(dominio + "_correos.txt");
	
	for (int i = 0; i < correos.cont; i++)
	{
		guardar << correos.lista[i].identificador << endl;
		guardar << correos.lista[i].fecha << "              ";
		guardar << correos.lista[i].emisor << endl;
		guardar << correos.lista[i].destinatario << endl;
		guardar << correos.lista[i].asunto << endl;
		guardar << correos.lista[i].cuerpo << endl;
		guardar << "X" << endl;
	}
	guardar << "XXX" << endl;
	guardar.close();
}

bool insertar(tListaCorreos &correos, const tCorreo &correo)
{
	bool ok = true;
	int pos;
	if(correos.cont == MAX_CORREOS)
	{
		ok = false;
	}
	else
	{
		if(buscar(correos, correo.identificador, pos))
		{
		for (int j = correos.cont; j > pos; j--)
		{
			correos.lista[j] = correos.lista[j - 1];
		}	
		correos.lista[pos] = correo;
		correos.cont++;
		}
		else
			ok = false;
	}
	return ok;
}

bool buscar(const tListaCorreos &correos, string id, int &pos)
{
	int ini = 0, fin = correos.cont - 1, mitad;
	bool encontrado = false;

	while ((ini <= fin) && !encontrado) 
	{
		mitad = (ini + fin) / 2;
		if (id == correos.lista[mitad].identificador)
			encontrado = true;
		else
			if (id < correos.lista[mitad].identificador)
				fin = mitad - 1;
			else
				ini = mitad + 1;
	}
		pos = mitad;
	return encontrado;
}

void ordenar_AF(tListaCorreos &correos)
{
	bool inter = true;
	int i = 0;
	while ((i < MAX_CORREOS - 1) && inter) 
	{
		 inter = false;
		 for (int j = MAX_CORREOS - 1; j > i; j--) 
		 {
			 if (correos.lista[j - 1] > correos.lista[j]) 
			 {
				 tCorreo tmp;
				 tmp = correos.lista[j];
				 correos.lista[j] = correos.lista[j - 1];
				 correos.lista[j - 1] = tmp;
				 inter = true;
			 }
		 }
		 if (inter) {
		 i++;
		 }
	}
}

bool operator> (tCorreo opIzq, tCorreo opDer)
{
	bool mayorQue = true;

	if( opIzq.asunto < opDer.asunto)
	{
		mayorQue = false;
	}
	else if( opIzq.asunto == opDer.asunto)
	{
		if( opIzq.fecha <= opDer.fecha)
		{
			mayorQue = false;
		}
	return mayorQue;
}

