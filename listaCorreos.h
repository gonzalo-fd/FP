#ifndef listaCorreos_h
#define listaCorreos_h

#include <string>
#include "correo.h"
using std::string;

const int MAX_CORREOS = 10;

typedef tCorreo tCorreos[MAX_CORREOS];

typedef struct {
	tCorreos lista;
	int cont;
} tListaCorreos;

void inicializar(tListaCorreos &correos);
bool cargar(tListaCorreos &correos, string dominio);
void guardar(const tListaCorreos &correos, string dominio);
bool insertar(tListaCorreos &correos, const tCorreo &correo);
bool buscar(const tListaCorreos &correos, string id, int &pos);
void ordenar_AF(tListaCorreos &correos);
bool operator> (tCorreo opIzq, tCorreo opDer);

#endif