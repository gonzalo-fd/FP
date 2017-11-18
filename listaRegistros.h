#ifndef listaRegistros_h
#define listaRegistros_h

#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream; 

const int MAX_REGS = 10;

typedef struct {
	string id_correo;
	bool leido;
} tRegCorreo;

typedef tRegCorreo tListaRegistro[MAX_REGS];

typedef struct{
	tListaRegistro lista;
	int cont;
} tListaRegCorreo;


void inicializar(tListaRegCorreo &listaReg);
void cargar(tListaRegCorreo &listaReg, ifstream &archivo);
void guardar(const tListaRegCorreo &listaReg, ofstream &archivo);
bool insertar(tListaRegCorreo &listaReg, tRegCorreo registro);
bool borrar(tListaRegCorreo &listaReg, string id);
bool correoLeido(tListaRegCorreo &listaReg, string id);
int buscar(const tListaRegCorreo &listaReg, string id);

#endif