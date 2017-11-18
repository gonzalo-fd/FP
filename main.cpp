#include <iostream>
#include "libro.h"
#include "listaLibros.h"
#include "estudiante.h"
#include "listaEstudiantes.h"
using namespace std;

int main()
{
	tListaEstudiantes lista;

	inicializarEstudiantes(lista);
	cargar(lista);
	mostrar(lista);
	system("pause");
	destruir(lista);
	
	system("pause");
	return 0;
}