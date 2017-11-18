#ifndef listaNotas_h
#define listaNotas_h

#include "nota.h"

const int MAX_NOTAS = 300;

typedef tNota *tNotaPtr;

typedef tNotaPtr arrayNotas[MAX_NOTAS];

typedef struct
{
	arrayNotas lista;
	int cont;
}tListaNotas;

#endif 