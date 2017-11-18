#ifndef Peliculas_h
#define Peliculas_h

using std::string;

const int N = 100;
typedef struct{
	string titulo;
	int anio;
	double calificacion;
}tPelicula;
typedef tPelicula tArray [N];

typedef struct{
	tArray info;
	int contador;
}tLista;
	

void insertar(tLista &lista, tPelicula estreno);
bool cargar(tLista &lista);
void mostrarPeliculas(const tLista &lista);
void importarEstrenos(tLista &lista);
bool buscar(const tLista &lista, int &pos, tPelicula estreno);

#endif