#ifndef listaLibros_h
#define listaLibros_h

#include "libro.h"
#include <string>
using std::string;

const int MAXLIBROS = 20;

typedef tLibro *tLibroPunt;

typedef tLibroPunt tLista[MAXLIBROS];

typedef struct tListaLibros
{
	tLista libros;
	int cont;
};

void buscar(const tListaLibros &lista, const string &fecha, bool &encontrado, int &pos);
void insertar(const tLibro &libro, tListaLibros lista, bool &ok);
void mostrar(const tListaLibros lista);
void mostrar(const tListaLibros lista, int pos);
void destruir(tListaLibros lista);

#endif