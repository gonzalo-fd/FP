#include <iostream>
#include <string>
#include "estudiante.h"
using namespace std;

void mostrar(const tEstudiante &estudiante)
{
	cout << "Estudiante: " << estudiante.nif << endl;
	mostrar(estudiante.prestamos);
}

void crearEstudiante(string nif, const tLibro &libro, tEstudiante &estudiante)
{
	inicializar(estudiante.prestamos);

	estudiante.nif = nif;
	estudiante.prestamos.libros[estudiante.prestamos.cont] = new tLibro(libro);
	estudiante.prestamos.cont++;
}
