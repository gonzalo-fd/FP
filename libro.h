#ifndef libro_h
#define libro_h

#include <string>
using std::string;

typedef struct tLibro
{
	int codigo;
	string fecha;
	int dias;
};

void mostrar(const tLibro &libro);

#endif