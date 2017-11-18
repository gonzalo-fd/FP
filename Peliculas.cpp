#include <iostream>
#include<fstream>
#include <string>
#include "Peliculas.h"
using namespace std;
bool cargar(tLista &lista)
{
	bool ok = false;
	string cadena;
	ifstream archivo;
	tPelicula peliAux;
	archivo.open("peliculas.txt");
	if(archivo.is_open())
	{
		ok = true;
		getline(archivo, cadena);
		while (cadena != "XXX" && lista.contador <= N)
		{
			peliAux.titulo = cadena;
			archivo >> peliAux.anio;
			archivo >> peliAux.calificacion;
			lista.info[lista.contador] = peliAux;
			archivo.ignore();
			getline(archivo,cadena);
			lista.contador++;
		}
			/*lista.info[lista.contador].titulo = cadena;
			archivo >> lista.info[lista.contador].anio;
			archivo >> lista.info[lista.contador].calificacion;
			cin.sync();
			getline(archivo, cadena);
			lista.contador++;*/
		archivo.close();
	}
	else
		ok = false;
	return ok;
}

void mostrarPeliculas(const tLista &lista)
{
	for(int i = 0; i< lista.contador; i++){
		cout << lista.info[i].titulo << endl;
		cout << lista.info[i].anio << endl;
		cout << lista.info[i].calificacion << endl;
	}
}

void importarEstrenos(tLista &lista)
{
	ifstream archivo;
	tPelicula estreno;
	bool encontrado = false;
	string cadena;
	archivo.open("estrenos.txt");
	if (archivo.is_open()){
		
		getline(archivo, cadena);
		while(cadena != "XXX" && lista.contador <= N)
		{
			estreno.titulo = cadena;
			archivo >> estreno.anio;
			estreno.calificacion = 0;
			insertar(lista, estreno);
			archivo.ignore();
			getline(archivo, cadena);
		}
	}
}


bool buscar(const tLista &lista, int &pos, tPelicula estreno)
{
	int mitad, fin = lista.contador-1;
	bool encontrado = false;
	int ini = 0;
	while((ini <= fin) && !encontrado){
		mitad = (ini + fin)/2;
		if (estreno.titulo == lista.info[mitad].titulo){
			encontrado = true;
			ini = mitad;
		} else{
			if (estreno.titulo < lista.info[mitad].titulo){
				fin = mitad - 1;
			}else{
				ini = mitad +1;
			}
		}
		if (!encontrado){
			pos = ini;
		}
	}
	return encontrado;
}
void insertar(tLista &lista, tPelicula estreno)
{
	int pos;
	lista.contador++;
	if(lista.contador <N){
		if(!buscar(lista, pos, estreno)){
			for(int i = lista.contador; i >= pos; i--){
				lista.info[i+1] = lista.info[i];
			}

			lista.info[pos] = estreno;
		}
	}
}