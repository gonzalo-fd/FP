#ifndef gestor_h
#define gestor_h

#include <string>
#include "listaCorreos.h"
#include "listaUsuarios.h"
#include "correo.h"
using std::string;


typedef struct {
	string dominio;
	int usuario_activo;
	tListaCorreos listaCorreos;
	tListaUsuarios listaUsuarios;
} tGestor;

bool arrancar(tGestor &gestor, string dominio);
void apagar(const tGestor &gestor);
bool crearCuenta(tGestor &gestor);
bool iniciarSesion(tGestor &gestor);
void leerCorreo(tGestor &gestor, tListaRegCorreo &listaReg);
void enviarCorreo(tGestor &gestor, const tCorreo &correo);
void borrarCorreo(tGestor &gestor, tListaRegCorreo &listaReg);
void lecturaRapida(tGestor &gestor, tListaRegCorreo &listaReg);

#endif