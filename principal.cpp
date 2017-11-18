#include <iostream>
#include <string>
using namespace std;

#include "correo.h"
#include "gestor.h"
#include "listaCorreos.h"
#include "listaRegistros.h"
#include "usuario.h"

using namespace std;

int main()
{
	tCorreo correo;
	string emisor = "patata";
	correoNuevo(correo, emisor);

	system("pause");
	return 0;
}