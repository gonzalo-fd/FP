#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM_PLAYERS = 5;
const string CENTINELA = "XXX";
typedef struct {
	string nombre;
	string equipo;
	int partidos;
	int minutos;
	int goles;
}tJugador;
typedef tJugador tLista[NUM_PLAYERS];

typedef struct{
	string nombre;
	int minutos;
	int goles;
}tActualizar;

typedef enum { BCN, RMA, ATM, VIL, ATB, TODOS }tCodigo;

int menu();
void cargar(tLista lista, bool &ok);
void filtrarLista(const tLista lista, string codigo);
string solicitarEquipo();
void opcionFiltrarLista(const tLista lista);
void opcionActualizarJugador(tLista lista);
void solicitarDatosActualizados(tActualizar &actualizada);
void actualizarJugador(tLista lista, tActualizar actualizada);
void consultarMaxGolaedor(const tLista lista);
void mostrarJugador(tJugador jugador);
int main()
{
	tLista lista;
	bool ok;
	int opcion;
	cargar(lista, ok);
	do
	{
		opcion = menu();
		switch (opcion)
		{
			case 1:
			{
				opcionFiltrarLista(lista);
			}break;
			case 2:{
				opcionActualizarJugador(lista);
			}break;
			case 3:{
				consultarMaxGolaedor(lista);
			}break;
			case 0:
			{
				cout << "ADIOS" << endl;
			}
		}
	} while (opcion != 0);
	
	system("pause");
	return 0;
}
int menu()
{
	int opcion;
	cout << "1 - filtrar lista" << endl;
	cout << "2 - actualizar jugador" << endl;
	cout << "3 - consultar maximo goleador" << endl;
	cout << "0 - SALIR" << endl;
	cout << "elige una opcion: ";
	cin >> opcion;
	//Comprobar que la opción introducida es correcta
	return opcion;
}

void cargar(tLista lista, bool &ok)
{
	ifstream archivo;
	int i = 0;
	string nombre;
	archivo.open("players.txt");
	if(archivo.is_open())
	{
		ok = true;
		archivo >> nombre;
		while (nombre != CENTINELA)//Controlar que no llegais al número máximo de jugadores
		{
			lista[i].nombre = nombre;
			archivo >> lista[i].equipo;
			archivo >> lista[i].partidos;
			archivo >> lista[i].minutos;
			archivo >> lista[i].goles;
			archivo >> nombre;
			i++;
		}
		archivo.close();
		//Comprobar si se han insertado los MAX_JUGADORES
	}
	else
	{
		ok = false;
	}
}

void opcionFiltrarLista(const tLista lista){
	filtrarLista(lista, solicitarEquipo());
}

void filtrarLista(const tLista lista, string codigo)
{
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		if ((lista[i].equipo == codigo) || (codigo == "TODOS"))
		{
			cout << lista[i].nombre << endl;
		}
	}
}

string solicitarEquipo()
{
	string codigo;
	cout << "Introduce el codigo de equipo: ";
	cin >> codigo;
	return codigo;
}

void opcionActualizarJugador(tLista lista){
	tActualizar actualizada;
	solicitarDatosActualizados(actualizada);
	actualizarJugador(lista, actualizada);
}

void solicitarDatosActualizados(tActualizar &actualizada)
{
	cout << "Introduzca el nombre del jugador a actualizar: ";
	cin >> actualizada.nombre;
	cout << "Cuantos minutos ha jugado?";
	cin >> actualizada.minutos;
	cout << "Cuantos goles ha metido?";
	cin >> actualizada.goles;
}

void actualizarJugador(tLista lista, tActualizar actualizada)
{
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		if (lista[i].nombre == actualizada.nombre)
		{
			if ((actualizada.minutos >=0) && (actualizada.goles >= 0))
			{
				lista[i].minutos = lista[i].minutos + actualizada.minutos;
				lista[i].goles = lista[i].goles + actualizada.goles;
				lista[i].partidos++;
				cout << "Jugador modificado:" << endl;
				mostrarJugador(lista[i]);
			}
			else
			{
				cout << "ERROR";
			}
		}
	}
}

int getMaxGoles(const tLista lista){
	int goles = 0;
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		if (lista[i].goles > goles)
		{
			goles = lista[i].goles;
		}
	}
	return goles;
}

void consultarMaxGolaedor(const tLista lista)
{
	int goles = getMaxGoles(lista);
	for (int j = 0; j < NUM_PLAYERS; j++)
	{
		if (goles == lista[j].goles)
		{
			mostrarJugador(lista[j]);
		}
	}
}

void mostrarJugador(tJugador jugador){
	cout << jugador.nombre << endl;
	cout << "EQUIPO: " << jugador.equipo << endl;
	cout << "PARTIDOS: " << jugador.partidos << endl;
	cout << "MINUTOS: " << jugador.minutos << endl;
	cout << "GOLES: " << jugador.goles << endl;
}
