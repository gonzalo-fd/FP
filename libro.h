#ifndef libro_h
#define libro_h

#include <string>
using std::string;

typedef struct 
{
	int codigo;
	string fecha;
	int dias;
}tLibro;

void mostrar(const tLibro &libro);

#endif