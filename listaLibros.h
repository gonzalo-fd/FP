#ifndef listaLibros_h
#define listaLibros_h

#include "libro.h"
#include <string>
using std::string;

const int MAX_LIBROS = 20;

typedef tLibro *tLibroPtr;

typedef tLibroPtr tLista[MAX_LIBROS];

typedef struct 
{
	tLista libros;
	int cont;
}tListaLibros;

bool buscar(const tListaLibros &lista, const string &fecha, int &pos);
bool insertar(tLibro libro, tListaLibros &lista);
void mostrar(const tListaLibros lista);
void mostrar(const tListaLibros lista, int pos);
void destruir(tListaLibros &lista);
void inicializar(tListaLibros &lista);

#endif