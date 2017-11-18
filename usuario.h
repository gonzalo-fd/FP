#ifndef usuario_h
#define usuario_h

#include <string>
#include "listaRegistros.h"

using std::string;

#include <fstream>

typedef struct {
	tListaRegCorreo registros;
	int cont;
} tListaRecibidos;

typedef struct {
	tListaRegCorreo registros;
	int cont;
} tListaEnviados;

typedef struct {
	string nombre;
	string contrasenia;
	tListaRecibidos listaRecibidos;
	tListaEnviados listaEnviados;
} tUsuario;

bool cargar(tUsuario &usuario, ifstream &archivo);
void guardar(const tUsuario &usuario, ofstream &archivo);
void inicializar(tUsuario &usuario, string id, string contrasenia);
bool validarContrasenia(const tUsuario &usuario, string contrasenia);
#endif