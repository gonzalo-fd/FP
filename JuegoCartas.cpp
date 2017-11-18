#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <locale.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

typedef enum {a, dos, tres, cuatro, cinco, seis, siete, ocho, nueve, diez, j, q, k} tNumero;
typedef enum {picas, treboles, diamantes, corazones} tPalo;

const int CENTINELA = 52, CARTASPORPALO = 13, MAXCARTAS = 53, CARGAR = 1, SALIR = 0, ICONPICAS = 6, ICONTREBOLES = 5, ICONDIAMANTES = 4, ICONCORAZONES = 3, INICIO = 0;
const int NEGRO = 32, AZUL = 33, VERDE = 34, AGUAMARINA = 35, ROJO = 36, PURPURA = 37, AMARILLO = 38, BLANCO = 39, GRIS = 40, AZULCLARO = 41, VERDECLARO = 42, AGUAMARINACLARO = 43, ROJOCLARO = 44, PURPURACLARO = 45, AMARILLOCLARO = 46, BLANCOBRILLANTE = 47; //constantes colores

typedef int tCarta;
typedef tCarta tMazo[MAXCARTAS];

void crearMazoVacio(tMazo mazo);
int cuantasEnMazo(const tMazo mazo);
tPalo darPalo(tCarta carta);
tNumero darNumero(tCarta carta);
void escribirCarta(tCarta carta);
void escribirMazo(const tMazo mazo);
bool cargarMazo(tMazo mazo);
bool opcionCargar(tMazo mazo);
void barajarMazo(tMazo mazo);
void opcionBarajar(tMazo mazo);
bool unirMazos(tMazo mazoOriginal, const tMazo nuevoMazo);
void opcionUnir(tMazo mazo);
bool partirMazo(tMazo mazoOrigen, int cuantasCoger, tMazo mazoDestino);
void cortarMazo(tMazo mazo, int cuantas);
void opcionCortar(tMazo mazo);
void guardarMazo(const tMazo mazo);
int menu();
void repartirNegroRojo(const tMazo mazo, tMazo mazoRojo, tMazo mazoNegro);
void opcionSepararNR(tMazo mazo);
void repartirBajaAlta(const tMazo mazo, tMazo mazoAltas, tMazo mazoBajas);
void opcionSepararBA(tMazo mazo);
void repartirIntercalando(const tMazo mazo, int enCuantosMazos, int queMazoPido, tMazo mazoNuevo); 
void opcionRepartir3Montones(tMazo mazo);
void trucoTresMontones();
void trucoPosada();
void mostrarMazoPosada(tMazo mazo, tMazo mazo1, tMazo mazo2, tMazo mazo3, tMazo mazo4);
//OPCIONALES
void color(int X);

int main()
{
	int opcion;
	bool mazoCargado = false;
	tMazo mazo;
	srand(time(NULL)); // establece la semilla para numeros aleatorios
	setlocale(LC_ALL, "spanish"); // funciona con <locale.h>, permite usar caracteres del teclado español
	system("COLOR 20");
	
	do
	{
		opcion = menu();
		
		if (!mazoCargado && opcion > 1 && opcion < 8)
		{
			color(PURPURACLARO);
			cout << "No hay ningún mazo cargado. Cárguelo primero desde un archivo." << endl << '\n';
			opcion = CARGAR;
		}

		switch(opcion)
		{

			case 1: // cargar
			{
				mazoCargado = opcionCargar(mazo);
				break;
			}
			case 2: // barajar
			{
				opcionBarajar(mazo);
				break;
			}
			case 3: // añadir mazo
			{
				opcionUnir(mazo);
				break;
			}
			case 4: // cortar mazo
			{
				opcionCortar(mazo);
				break;
			}
			case 5: //guardar mazo
			{
				guardarMazo(mazo);
				break;
			}
			case 6: //separar negras y rojas
			{
				opcionSepararNR(mazo);
				break;
			}
			case 7: //separar altas y bajas
			{
				opcionSepararBA(mazo);
				break;
			}
			case 8: // repartir 3 montones
			{
				opcionRepartir3Montones(mazo);
				break;
			}
			case 9: // truco1
			{
				trucoTresMontones();
				break;
			}
			case 10: // truco2
			{
				trucoPosada();
				break;
			}
			default: // acabar
			{
				system("pause");
				break;
			}
		}
	}while (opcion != SALIR);

	return 0;
}

void color(int X)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),X);
}

void crearMazoVacio(tMazo mazo) //correcto
{
	mazo[INICIO] = CENTINELA;
}

int cuantasEnMazo(const tMazo mazo) //correcto
{
	int cont = INICIO, leido;
	do
	{
		leido = mazo[cont];
		cont++;
	}while(leido != CENTINELA);
	return cont - 1;
}

tPalo darPalo(tCarta carta) //correcto
{
	return tPalo(carta / CARTASPORPALO);
}

tNumero darNumero(tCarta carta) //correcto
{
	return tNumero(carta % CARTASPORPALO);
}

void escribirCarta(tCarta carta) // esta funcion es más larga, debido a que hemos usado un formato más trabajado, estético y complejo de elaborar
{
	short int paloIcon;
	string num;
	if (darPalo(carta) == picas)
	{
		color(NEGRO);
		paloIcon = ICONPICAS;
	}
	else if (darPalo(carta) == treboles)
	{
		color(NEGRO);
		paloIcon = ICONTREBOLES;
	}
	else if (darPalo(carta) == diamantes)
	{
		color(ROJOCLARO);
		paloIcon = ICONDIAMANTES;
	}
	else
	{
		color(ROJOCLARO);
		paloIcon = ICONCORAZONES;
	}
	
	switch(darNumero(carta)) // como extra hemos añadido los iconos de cada palo junto al numero de la carta, pero lo tratamos como string para lograr este formato, por lo que no se puede hacer directamente usando la posicion del enumerado
	{
	case a:
		{
			num = "A";
			cout << num << (char)paloIcon << "  As ";
			break;
		}
	case dos:
		{
			num = "2";
			cout << num << (char)paloIcon << "  Dos ";
			break;
		}
	case tres:
		{
			num = "3";
			cout << num << (char)paloIcon << "  Tres ";
			break;
		}
	case cuatro:
		{
			num = "4";
			cout << num << (char)paloIcon << "  Cuatro ";
			break;
		}
	case cinco:
		{
			num = "5";
			cout << num << (char)paloIcon << "  Cinco ";
			break;
		}
	case seis:
		{
			num = "6";
			cout << num << (char)paloIcon << "  Seis ";
			break;
		}
	case siete:
		{
			num = "7";
			cout << num << (char)paloIcon << "  Siete ";
			break;
		}
	case ocho:
		{
			num = "8";
			cout << num << (char)paloIcon << "  Ocho ";
			break;
		}
	case nueve:
		{
			num = "9";
			cout << num << (char)paloIcon << "  Nueve ";
			break;
		}
	case diez:
		{
			num = "10";
			cout << num << (char)paloIcon << " Diez ";
			break;
		}
	case j:
		{
			num = "J";
			cout << num << (char)paloIcon << "  Jota ";
			break;
		}
	case q:
		{
			num = "Q";
			cout << num << (char)paloIcon << "  Reina ";
			break;
		}
	default:
		{
			num = "K";
			cout << num << (char)paloIcon << "  Rey ";
			break;
		}
	}

	cout << "de ";

	switch(darPalo(carta))
	{
	case picas:
		{
			cout << "picas.";
			break;
		}
	case treboles:
		{
			cout << "tréboles.";
			break;
		}
	case diamantes:
		{
			cout << "diamantes.";
			break;
		}
	default:
		{
			cout << "corazones.";
			break;
		}
	}
}

void escribirMazo(const tMazo mazo)
{
	int i = INICIO;
	while(mazo[i] != CENTINELA)
	{
		escribirCarta(mazo[i]);
		cout << endl;
		i++;
	}
	cout << endl;
}

bool cargarMazo(tMazo mazo) //correcto
{
	ifstream leer;
	string nombArch;
	bool abierto = true;
	char palo;
	short int carta, palonum;
	int cont = INICIO, cartanum;

	cin.sync();
	color(AGUAMARINACLARO);
	cout << "Escribe el nombre del archivo a cargar ('mazo' por defecto): ";
	color(AMARILLOCLARO);
	cin >> nombArch;
	cout << '\n';
	nombArch = nombArch + ".txt";

	leer.open(nombArch);
 
    if (!leer.is_open())
    {
		abierto = false;
	}
	else
	{
		leer >> palo;
		leer >> carta;
		while(palo != 'x')
		{
			switch(palo)
			{
				case 'p':
				{
					cartanum = carta - 1;
					break;
				}
				case 't':
				{
					cartanum = (CARTASPORPALO + carta - 1);
					break;
				}
				case 'd':
				{
					cartanum = (2 * CARTASPORPALO + carta - 1);
					break;
				}
				case 'c':
				{
					cartanum = (3 * CARTASPORPALO + carta - 1);
					break;
				}
			}
			mazo[cont] = cartanum;
			leer >> palo;
			leer >> carta;
			cont++;
		}
		mazo[cont] = CENTINELA;
		leer.close();
	}
	return abierto;
}

bool opcionCargar(tMazo mazo)
{
	bool mazoCargado = false;

	if (!cargarMazo(mazo))
	{
		color(PURPURACLARO);
		cout << "No se ha podido cargar el mazo. Compruebe que el archivo existe." << endl << '\n';
	}
	else
	{
		color(VERDECLARO);
		cout << "Se ha cargado el mazo: " << endl << '\n';
		escribirMazo(mazo);
		mazoCargado = true;
	}
	return mazoCargado;
}

void barajarMazo(tMazo mazo) //correcto
{
	int aux, intercambios, pos1, pos2;
	intercambios = cuantasEnMazo(mazo) * 3;

	for (int i = INICIO; i < intercambios; i++)
	{
		pos1 = (rand()%(cuantasEnMazo(mazo)));
		pos2 = (rand()%(cuantasEnMazo(mazo)));
		aux = mazo[pos1];
		mazo[pos1] = mazo[pos2];
		mazo[pos2] = aux;
	}
}

void opcionBarajar(tMazo mazo)
{
		color(VERDECLARO);
		barajarMazo(mazo);
		cout << "Se ha barajado el mazo. El nuevo mazo es: " << endl << '\n';
		escribirMazo(mazo);
}

bool unirMazos(tMazo mazoOriginal, const tMazo nuevoMazo)
{
	bool posible = true;
	int cartasMazo1 = cuantasEnMazo(mazoOriginal), cartasMazo2 = cuantasEnMazo(nuevoMazo), contador, contadorNuevo = INICIO;
	if (cartasMazo1 + cartasMazo2 > 52)
	{
		posible = false;
	}
	else
	{
		contador = cartasMazo1;
		do
		{
			mazoOriginal[contador] = nuevoMazo[contadorNuevo];
			contador++;
			contadorNuevo++;
		} while (contadorNuevo <= cartasMazo2);
	}
	return posible;
}

void opcionUnir(tMazo mazo)
{
	tMazo nuevoMazo;

	if (!cargarMazo(nuevoMazo))
	{
		color(PURPURACLARO);
		cout << "No se ha podido cargar el mazo. Compruebe que el archivo existe." << endl << '\n';
	}
	else if (!unirMazos(mazo, nuevoMazo))
	{
		color(PURPURACLARO);
		cout << "Se ha superado el máximo número de cartas en un mazo, que es 52." << endl << '\n';
	}
	else
	{
		color(VERDECLARO);
		cout << "Se han unido los mazos. El nuevo mazo es: " << endl << '\n';
		escribirMazo(mazo);
	}
}

bool partirMazo(tMazo mazoOrigen, int cuantasCoger, tMazo mazoDestino)
{
	bool posible = true;
	tMazo mazoAuxiliar;

	if (cuantasEnMazo(mazoOrigen) < cuantasCoger)
	{
		posible = false;
	}
	else
	{
		for(int i = INICIO; i < cuantasCoger; i++)
		{
			mazoDestino[i] = mazoOrigen[i];
		}
		mazoDestino[cuantasCoger] = CENTINELA;

		for(int i = INICIO; i <= (cuantasEnMazo(mazoOrigen) - cuantasCoger); i++)//sino restas cuantas coger se mueven datos inutiles a posiciones despues del centinela, asi es mas eficiente.
		{
			mazoOrigen[i] = mazoOrigen[i + cuantasCoger];
		}
		
		mazoOrigen[cuantasEnMazo(mazoOrigen)] = CENTINELA;
		
	}

	return posible;
}

void cortarMazo(tMazo mazo, int cuantas)
{
	tMazo mazoAuxiliar;
	if (cuantasEnMazo(mazo) > cuantas)
	{
		partirMazo(mazo, cuantas, mazoAuxiliar);
		unirMazos(mazo, mazoAuxiliar);
	}
}

void opcionCortar(tMazo mazo)
{
	int cortar;

	color(AGUAMARINACLARO);
	cout << "¿Cuántas cartas deben ser cortadas?: ";
	cin >> cortar;
	cortarMazo(mazo, cortar);
	escribirMazo(mazo);
}

void guardarMazo(const tMazo mazo)
{
	ofstream escribir;
	string nombArch;
	char palo;
	short int carta, palonum;
	int cont = INICIO, cartanum;
	cin.sync();
	color(AGUAMARINACLARO);
	cout << "Escribe el nombre del archivo a guardar ('mazo' por defecto): ";
	color(AMARILLOCLARO);
	cin >> nombArch;
	nombArch = nombArch + ".txt";
	escribir.open(nombArch);
	while (mazo[cont] != CENTINELA)
	{
		switch(darPalo(mazo[cont]))
		{
		case picas:
			{
				escribir << "p";
				break;
			}
		case treboles:
			{
				escribir << "t";
				break;
			}
		case diamantes:
			{
				escribir << "d";
				break;
			}
		default:
			{
				escribir << "c";
				break;
			}
		}

		escribir << " ";
		escribir << (darNumero(mazo[cont]) + 1);		
		escribir << endl;
		cont++;
	}
	escribir << 'x' << endl;
	escribir.close();
	color(VERDECLARO);
	cout << "Se ha guardado el mazo en el archivo '" << nombArch << "'" << endl << '\n';
}

void repartirNegroRojo(const tMazo mazo, tMazo mazoRojo, tMazo mazoNegro)
{
	tCarta carta;
	int contRojas = INICIO, contNegras = INICIO, cont = INICIO;

	carta = mazo[cont];
	while(carta != CENTINELA)
	{
		if (carta > 25)
		{
			mazoRojo[contRojas] = carta;
			contRojas++;
		}
		else
		{
			mazoNegro[contNegras] = carta;
			contNegras++;
		}
		cont++;
		carta = mazo[cont];
	}
	mazoRojo[contRojas] = CENTINELA;
	mazoNegro[contNegras] = CENTINELA;
}

void opcionSepararNR(tMazo mazo)
{
	tMazo mazoRojo, mazoNegro;

	repartirNegroRojo(mazo, mazoRojo, mazoNegro);
	color(VERDECLARO);
	cout << "Se han separado las cartas en: " << endl << '\n';
	color(VERDECLARO);
	cout << "Mazo rojo: " << endl;
	escribirMazo(mazoRojo);
	color(VERDECLARO);
	cout << "Mazo negro: " << endl;
	escribirMazo(mazoNegro);
}

void repartirBajaAlta(const tMazo mazo, tMazo mazoAltas, tMazo mazoBajas)
{
	tCarta carta;
	int contAltas = INICIO, contBajas = INICIO, cont = INICIO;

	carta = mazo[cont];
	while(carta != CENTINELA)
	{
		if ((carta % CARTASPORPALO) < 7)
		{
			mazoBajas[contBajas] = carta;
			contBajas++;
		}
		else
		{
			mazoAltas[contAltas] = carta;
			contAltas++;
		}
		cont++;
		carta = mazo[cont];
	}
	mazoAltas[contAltas] = CENTINELA;
	mazoBajas[contBajas] = CENTINELA;
}

void opcionSepararBA(tMazo mazo)
{
	tMazo mazoAltas, mazoBajas;

	repartirBajaAlta(mazo, mazoAltas, mazoBajas);
	color(VERDECLARO);
	cout << "Se han separado las cartas en: " << endl << '\n';
	color(VERDECLARO);
	cout << "Mazo altas: " << endl;
	escribirMazo(mazoAltas);
	color(VERDECLARO);
	cout << "Mazo bajas: " << endl;
	escribirMazo(mazoBajas);
}

void repartirIntercalando(const tMazo mazo, int enCuantosMazos, int queMazoPido, tMazo mazoNuevo)
{
	int cont = INICIO, veces;
	veces = ((cuantasEnMazo(mazo) - queMazoPido) / enCuantosMazos);
	while(cont <= veces)
	{
		mazoNuevo[cont] = mazo[cont * enCuantosMazos + (queMazoPido - 1)];
		cont++;
	}
	mazoNuevo[cont] = CENTINELA;
}

void opcionRepartir3Montones(tMazo mazo)
{
	int enCuantosMazos = 3, queMazoPido;
	tMazo mazoNuevo;

	color(AGUAMARINACLARO);
	cout << "¿Qué mazo pides?: ";
	color(AMARILLOCLARO);
	cin >> queMazoPido;
	while (queMazoPido > enCuantosMazos)
	{
		cout << "Solo puedes pedir mazos entre 1 y " << enCuantosMazos;
		cin >> queMazoPido;
	}
	repartirIntercalando(mazo, enCuantosMazos, queMazoPido, mazoNuevo);
	color(VERDECLARO);
	cout << '\n' << "El mazo que has escogido es: " << endl;
	escribirMazo(mazoNuevo);
}

void trucoTresMontones()
{
	tMazo mazo, mazo1, mazo2, mazo3;
	int monton;

	if (!cargarMazo(mazo))
	{
		color(PURPURACLARO);
		cout << "No se ha podido cargar el mazo. Compruebe que el archivo existe." << endl << '\n';
	}
	else
	{
	color(VERDECLARO);
	cout << "Se ha cargado el mazo." << endl << '\n';
	barajarMazo(mazo);
	cout << "Se ha barajado el mazo." << endl << '\n';
	cout << "Piensa en una carta del mazo: " << endl;
	escribirMazo(mazo);
	color(VERDECLARO);
	system("pause");
	cout << '\n';
	

	for(int i = INICIO; i < 3; i++)
	{
		repartirIntercalando(mazo, 3, 1, mazo1);
		repartirIntercalando(mazo, 3, 2, mazo2);
		repartirIntercalando(mazo, 3, 3, mazo3);
		color(AGUAMARINACLARO);
		cout << "Mazo 1: " << endl;
		escribirMazo(mazo1);
		color(AGUAMARINACLARO);
		cout << "Mazo 2: " << endl;
		escribirMazo(mazo2);
		color(AGUAMARINACLARO);
		cout << "Mazo 3: " << endl;
		escribirMazo(mazo3);
		color(AGUAMARINACLARO);
		cout << "¿En que monton esta la carta? ";
		color(AMARILLOCLARO);
		cin >> monton;
		while(monton < 1 || monton > 3)
		{
			color(PURPURACLARO);
			cout << "Error. Introduzca un valor valido entre 1 y 3: ";
			cin >> monton;
		}

		cout << '\n';
		crearMazoVacio(mazo);
		switch(monton)
		{
			case 1:
			{
				unirMazos(mazo, mazo2);
				unirMazos(mazo, mazo1);
				unirMazos(mazo, mazo3);
				break;
			}
			case 2:
			{
				unirMazos(mazo, mazo1);
				unirMazos(mazo, mazo2);
				unirMazos(mazo, mazo3);
				break;
			}
			case 3:
			{
				unirMazos(mazo, mazo1);
				unirMazos(mazo, mazo3);
				unirMazos(mazo, mazo2);
				break;
			}
		}
	}
	color(AGUAMARINACLARO);
	cout << "Su carta es: ";
	escribirCarta(mazo[10]);
	cout << '\n' << endl;
	}
}

void trucoPosada()
{
	tMazo mazo, mazo1, mazo2, mazo3, mazo4;
	int cortar;
	if (!cargarMazo(mazo))
	{
		color(PURPURACLARO);
		cout << "No se ha podido cargar el mazo. Compruebe que el archivo existe." << endl << '\n';
	}
	else
	{
		color(VERDECLARO);
		cout << "Se ha cargado el mazo." << endl << '\n';			
	}
		mostrarMazoPosada(mazo, mazo1, mazo2, mazo3, mazo4);
		color(VERDECLARO);
		system("pause");
		cout << '\n';
		crearMazoVacio(mazo);
		unirMazos(mazo, mazo1);
		unirMazos(mazo, mazo2);
		unirMazos(mazo, mazo3);
		unirMazos(mazo, mazo4);
		color(AGUAMARINACLARO);
		cout << "Los 4 mazos se han unido en uno solo: " << '\n' << endl;
		escribirMazo(mazo);
		color(AGUAMARINACLARO);
		cout << "¿Por donde quiere cortar el mazo?(1-16) ";
		color(AMARILLOCLARO);
		cin >> cortar;
		while(cortar < 1 || cortar > 16)
		{
			color(PURPURACLARO);
			cout << "Error. Introduzca un valor valido entre 1 y 16: ";
			color(AMARILLOCLARO);
			cin >> cortar;
		}
		cout << '\n';
		cortarMazo(mazo, cortar-1);
		color(AGUAMARINACLARO);
		cout << "El mazo se ha cortado y se ha repartido de manera alterna en 4 mazos:" << '\n' << endl;
		color(VERDECLARO);
		system("pause");
		cout << '\n';
		mostrarMazoPosada(mazo, mazo1, mazo2, mazo3, mazo4);
}

void mostrarMazoPosada(tMazo mazo, tMazo mazo1, tMazo mazo2, tMazo mazo3, tMazo mazo4)
{
	repartirIntercalando(mazo, 4, 1, mazo1);
	repartirIntercalando(mazo, 4, 2, mazo2);
	repartirIntercalando(mazo, 4, 3, mazo3);
	repartirIntercalando(mazo, 4, 4, mazo4);
	color(AGUAMARINACLARO);
	cout << "Mazo 1: " << endl;
	escribirMazo(mazo1);
	color(AGUAMARINACLARO);
	cout << "Mazo 2: " << endl;
	escribirMazo(mazo2);
	color(AGUAMARINACLARO);
	cout << "Mazo 3: " << endl;
	escribirMazo(mazo3);
	color(AGUAMARINACLARO);
	cout << "Mazo 4: " << endl;
	escribirMazo(mazo4);
}

int menu()
{
	int opcion;
	
	color(BLANCOBRILLANTE);
	cout << "1.- Cargar mazo." << endl;
	cout << "2.- Barajar mazo." << endl; 
	cout << "3.- Añadir mazo." << endl; 
	cout << "4.- Cortar mazo." << endl;
	cout << "5.- Guardar mazo" << endl;
	cout << "6.- Separar entre cartas negras y cartas rojas." << endl;
	cout << "7.- Separar entre cartas bajas y cartas altas." << endl;
	cout << "8.- Repartir mazo alternativamente en 3 montones." << endl;
	cout << "9.- Truco de los tres montones." << endl;
	cout << "10.- Truco de la posada." << endl;
	cout << "0.- Salir." << endl;
	color(AGUAMARINACLARO);
	cout << "Opcion: ";
	color(AMARILLOCLARO);
	cin >> opcion;
	cout << '\n';

	while (opcion < 0 || opcion > 10)
	{
		color(PURPURACLARO);
		cout << "Error. Opción incorrecta, seleccione una opcion válida: "; 
		color(AMARILLOCLARO);
		cin >> opcion;
		cout << '\n';
	}

	return opcion;
}