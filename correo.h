#ifndef correo_h
#define correo_h

#include <string>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;

typedef time_t tFecha;

typedef struct {
	string emisor;
	string destinatario;
	string asunto;
	string cuerpo;
	tFecha fecha;
	string identificador;
} tCorreo;

string mostrarFecha(tFecha fecha);
void correoNuevo(tCorreo &correo, string emisor);
void correoContestacion(const tCorreo &correoOriginal, tCorreo &correo, string emisor);
string aCadena(const tCorreo &correo);
string obtenerCabecera(const tCorreo &correo);
bool cargar(tCorreo &correo, ifstream &archivo);
void guardar(const tCorreo &correo, ofstream &archivo);

#endif