#include <iostream>
#include <string>
#include "correo.h"
using namespace std;
#include <fstream>
#include <ctime>
#include <sstream>

string mostrarFecha(tFecha fecha)
{
	stringstream resultado;
	tm ltm;
	localtime_s(&ltm, &fecha);
	resultado << 1900 + ltm.tm_year << "/" << 1 + ltm.tm_mon <<"/"<< ltm.tm_mday;
	resultado<<" ("<<ltm.tm_hour<< ":" <<ltm.tm_min<< ":" << ltm.tm_sec << ")";
	return resultado.str();
}

void correoNuevo(tCorreo &correo, string emisor)
{
	stringstream identificador, aux;
	string cuerpo;
	correo.fecha = time(0);
	correo.emisor = emisor;
	
	identificador << correo.emisor << "_" << correo.fecha;
	correo.identificador = identificador.str();

	cout << "De: " << correo.emisor << "              " << mostrarFecha(correo.fecha) << endl;
	cout << "Para: ";
	cin >> correo.destinatario;
	cout << "Asunto: ";
	cin.sync();
	getline(cin, correo.asunto);
	cout << '\n';
	do
	{
		getline(cin, cuerpo);
		aux << cuerpo;
	} while (cuerpo != "X");
	correo.cuerpo = aux.str();
}

void correoContestacion(const tCorreo &correoOriginal, tCorreo &correo, string emisor)
{
	stringstream identificador, aux;
	string cuerpo;
	correo.fecha = time(0);
	correo.emisor = emisor;

	identificador << correo.emisor << "_" << correo.fecha;
	correo.identificador = identificador.str();

	cout << "De: " << correo.emisor << "              " << mostrarFecha(correo.fecha) << endl;
	correo.destinatario = correoOriginal.destinatario;
	cout << "Para: " << correo.destinatario;
	correo.asunto = "Re: " + correoOriginal.asunto;
	cout << "Asunto: " << correo.asunto;
	cout << '\n';
	cout << aCadena(correoOriginal) << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << '\n';
	correo.cuerpo += aCadena(correoOriginal);
	cin.sync();
	do
	{
		getline(cin, cuerpo);
		aux << cuerpo;
	} while (cuerpo != "X");
	correo.cuerpo = aux.str();
}

string aCadena(const tCorreo &correo)
{
	string cadenaCorreo;

	cadenaCorreo = obtenerCabecera(correo) + '\n' + correo.cuerpo;
	return cadenaCorreo;
}

string obtenerCabecera(const tCorreo &correo)
{
	string cabecera;

	cabecera = "De: " + correo.emisor + "              " + mostrarFecha(correo.fecha) + '\n' + "Para: " + correo.destinatario + '\n' + "Asunto: " + correo.asunto;
	return cabecera;
}

bool cargar(tCorreo &correo, ifstream &archivo)
{
	bool ok = true;
	string aux;

	archivo >> correo.emisor;
	archivo >> correo.fecha;
	archivo >> correo.destinatario;
	getline (archivo, correo.asunto);
	getline(archivo, aux);
	while(aux != "X")
	{
		correo.cuerpo += aux;
		getline(archivo, aux);
	}

	return ok;
}

void guardar(const tCorreo &correo, ofstream& archivo)
{
	archivo << correo.emisor << "              " << correo.fecha << endl;
	archivo << correo.destinatario << endl;
	archivo << correo.asunto << endl;
	archivo << correo.cuerpo << endl;
}