#ifndef listaUsuarios_h
#define listaUsuarios_h

#include <string>
#include "usuario.h"
using std::string;

const int MAX_USUARIOS = 10;

typedef tUsuario tUsuarios[MAX_USUARIOS];

typedef struct {
	tUsuarios lista;
	int cont;
} tListaUsuarios;

void inicializar(tListaUsuarios &usuarios);
bool cargar(tListaUsuarios &usuarios, string dominio);
void guardar(const tListaUsuarios &usuarios, string dominio);
bool aniadir(tListaUsuarios &usuarios, const tUsuario &usuario);
bool buscarUsuario(const tListaUsuarios &usuarios, string id, int &posicion);

#endif