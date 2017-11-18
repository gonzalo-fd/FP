#include <string>
#include "usuario.h"

using namespace std;
#include <fstream>

bool cargar(tUsuario &usuario, ifstream &archivo)
{
	archivo >> usuario.nombre;
	archivo >> usuario.contrasenia;
	cargar(usuario.listaRecibidos.registros, archivo);
	cargar(usuario.listaEnviados.registros, archivo);
}

void guardar(const tUsuario &usuario, ofstream &archivo)
{
	archivo << usuario.nombre << endl;
	archivo << usuario.contrasenia << endl;
	guardar(usuario.listaRecibidos.registros, archivo);
	guardar(usuario.listaEnviados.registros, archivo);
}

void inicializar(tUsuario &usuario, string id, string contrasenia)
{
	usuario.nombre = id;
	usuario.contrasenia = contrasenia;
}

bool validarContrasenia(const tUsuario &usuario, string contrasenia)
{
	bool correcta = false;

	if (contrasenia == usuario.contrasenia)
	correcta = true;

	return correcta;
}