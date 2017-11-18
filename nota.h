#ifndef nota_h
#define nota_h

#include <string>
using std::string;

typedef struct
{
	string nif;
	int notaNum;
	string notaCual;
}tNota;

void mostrar(const tNota &nota);
string notaCualitativa(int nota);

#endif