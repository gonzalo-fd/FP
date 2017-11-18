#ifndef listaEstudiantes_h
#define listaEstudiantes_h

#include "estudiante.h"
#include "listaLibros.h"
#include "libro.h"
#include <string>
using std::string;

const int MAX_ESTUDIANTES = 300;

typedef tEstudiante *tEstPtr;

typedef tEstPtr tListaEst[MAX_ESTUDIANTES];

typedef struct
{
	tListaEst estudiantes;
	int cont;
}tListaEstudiantes;

bool buscar(const tListaEstudiantes &lista, string nif, int &pos);
bool insertar(tListaEstudiantes &lista, string nif, const tLibro &libro);
void cargar(tListaEstudiantes &lista);
void mostrar(const tListaEstudiantes &lista);
void destruir(tListaEstudiantes &lista);
void inicializarEstudiantes(tListaEstudiantes &lista);

#endif
