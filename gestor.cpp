#include <iomanip>
#include "gestor.h"

using namespace std;

bool arrancar(tGestor &gestor, string dominio)
{
	bool ok = true;
	
	if (true)
	{
	
	}
}

void apagar(const tGestor &gestor)
{

}

bool crearCuenta(tGestor &gestor)
{
	tUsuario usuario;
	bool ok = true;

	if(!aniadir(gestor.listaUsuarios, usuario))
	ok = false;

	return ok;
}
