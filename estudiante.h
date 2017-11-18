#ifndef estudiante_h
#define estudiante_h

#include "libro.h"
#include "listaLibros.h"
#include <string>
using std::string;

typedef struct
{
	string nif;
	tListaLibros prestamos;
}tEstudiante;

void mostrar(const tEstudiante &estudiante);
void crearEstudiante(string nif, const tLibro &libro, tEstudiante &estudiante);

#endif