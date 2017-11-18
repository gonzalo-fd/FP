#include <iostream>
#include <string>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <fstream>
#include <conio.h>

const int N = 4, WIN = 2048, NUEVO = 1, CARGAR = 2, SALIR = 0, INICIO = 0, TABNUEVO = 1, ERRORCARGA = 2, CARGATAB = 3, PERDIDA = 4, GANADA = 5, ABANDONO = 6;
typedef int tTablero[N][N];

typedef enum {arriba, abajo, izq, der, esc} tAccion;

void inicializa(tTablero tablero);
void visualiza(const tTablero tablero, int puntos, int totalPuntos);
int log2(int num);
int digAleatorio();
void carga(tTablero tablero, int &puntos, bool &ok);
void colorFondo(int X);
void pintarBordeArriba();
void pintarBordeVacio(int fila, int col, const tTablero tablero);
void pintarBordeInter();
void pintarBordeNumero(int fila, int col, const tTablero tablero);
void pintarBordeAbajo();
tAccion leeAccion();
void mueveFichas(tTablero tablero, tAccion accion);
void obtenerParametro(tAccion accion, int &fila, int &columna, int &incrementoFila, int &incrementoColumna, int cont);
void combinarCeldas(tTablero tablero, tAccion accion, int &puntos);
int menu();
void nuevaFicha(tTablero tablero);
bool tabLleno(const tTablero tablero);
bool posibles(const tTablero tablero);
void getEstadoPartida(const tTablero tablero, bool &lleno, bool &movPosibles);
int mayor(const tTablero tablero);
void mensaje(int codigo);

int main() //funcion principal que lleva el juego en sí, inicializa el tablero, lo carga, y llama a las funciones necesarias para el desarrollo y estado de la partida, asi como a la funcion encargada de mostrar mensajes
{
	tTablero tablero;
	tAccion accion;
	bool ok, lleno, movPosibles, fin = false;
	int puntos = INICIO, totalPuntos, opcion;
	srand(time(NULL)); // establece la semilla para numeros aleatorios
	system("COLOR 0F");
	do
	{
		totalPuntos = INICIO;
		opcion = menu();
		if (opcion == NUEVO)
		{
			mensaje(TABNUEVO);
			inicializa(tablero);
			system("pause");
		}		
		else if (opcion == CARGAR)
		{
			carga(tablero, totalPuntos, ok);
			if(!ok)
			{
				mensaje(ERRORCARGA);
				inicializa(tablero);
				system("pause");
			}
			else
			{
				mensaje(CARGATAB);
				system("pause");
			}
		}
		do
		{
			visualiza(tablero, puntos, totalPuntos);
			accion = leeAccion();
			mueveFichas(tablero, accion);
			puntos = INICIO;
			combinarCeldas(tablero, accion, puntos);
			mueveFichas(tablero, accion);
			getEstadoPartida(tablero, lleno, movPosibles);
			totalPuntos = totalPuntos + puntos;
			if(!lleno)
			{
				nuevaFicha(tablero);
			}
			visualiza(tablero, puntos, totalPuntos);
			if (accion == esc)
			{
				mensaje(ABANDONO);
				system("pause");
				system("CLS");
			}
			else if (mayor(tablero) == WIN)
			{
				fin = true;
				mensaje(GANADA);
				system("pause");
				system("CLS");
			}
			else if (!movPosibles)
			{
				fin = true;
				mensaje(PERDIDA);
				system("pause");
				system("CLS");
			}
		} while (accion != esc && !fin);
	} while (opcion != SALIR);
	system("pause");
	return 0;
}

void mensaje(int codigo) //muestra los mensajes escritos a partir de un codigo de mensaje
{
	switch (codigo)
	{
	case TABNUEVO: cout << "Se ha creado un tablero nuevo..." << endl; break;
	case ERRORCARGA: cout << "No se ha podido cargar el archivo, creando tablero nuevo..." << endl; break;
	case CARGATAB: cout << "Se ha cargado el tablero y la puntuacion..." << endl; break;
	case PERDIDA: cout << "No quedan jugadas posibles." << endl << "FIN DE LA PARTIDA" << endl << endl; break;
	case GANADA: cout << "Enhorabuena, has llegado a 2048!!!" << endl << endl; break;
	case ABANDONO: cout << "Has abandonado la partida..." << endl << endl; break;
	}
} 

void colorFondo(int X) //modifica solamente el color de fondo, dejando el color de los caracteres en blanco
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (X << 4));
} 

void inicializa(tTablero tablero) //inicializa el tablero a 0 y mete números aleatorios en posiciones aleatorias siguiendo ciertas condiciones
{
	int rand1, rand2, rand3, rand4;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tablero[i][j] = 0;
		}
	}

	rand1 = rand()%N;
	rand2 = rand()%N;

	tablero[rand1][rand2] = digAleatorio();

	if (tablero[rand1][rand2] == 2)
	{
		do{
			rand3 = rand()%N;
			rand4 = rand()%N;
		}while(rand1 == rand3 && rand2 == rand4);
		tablero[rand3][rand4] = 1;
	}
	else
	{
		do{
			rand3 = rand()%N;
			rand4 = rand()%N;
		}while(rand1 == rand3 && rand2 == rand4);
		tablero[rand3][rand4] = digAleatorio();
	}
}

void visualiza(const tTablero tablero, int puntos, int totalpuntos) // visualiza el tablero, la puntuacion, y los colores, llamando a las funciones adecuadas para ello
{
	system("cls");
	cout << right << setw(6) << puntos << setw(12) << "Total:" << setw(6) << totalpuntos << endl;
	int fila = 0;
	pintarBordeArriba();
	while (fila < N)
	{
		for (int col = 0; col < N; col++)
		{
			pintarBordeVacio(fila, col, tablero);
		}
		cout << endl;
		for (int col = 0; col < N; col++)
		{
			pintarBordeNumero(fila, col, tablero);
		}
		cout << endl;
		for (int col = 0; col < N; col++)
		{
			pintarBordeVacio(fila, col, tablero);
		}
		cout << endl;
		fila++;
		if (fila < N)
		{
			pintarBordeInter();
		}
		else
		{
			pintarBordeAbajo();
		}
	}
}

int digAleatorio() // devuelve un digito aleatorio con ciertas probabilidades establecidas
{
	int nuevo;
	
	if (rand()%100 >= 95)
	{
		nuevo = 2;
	}
	else
	{
		nuevo = 1;
	}
	return nuevo;
}

void pintarBordeArriba() // pinta borde arriba sin color de fondo
{
	cout << char(218);
	for (int i = 0; i < N - 1; i++)
	{
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
}

void pintarBordeVacio(int fila, int col, const tTablero tablero) // pinta un borde llamando a la funcion de color, pero sin escribir el numero en la celda
{
	colorFondo(0);
	cout << char(179);
	colorFondo(tablero[fila][col]);
	if (col != N - 1)
	{
		cout << "     ";
	}
	else
	{
		cout << "     ";
		colorFondo(0);
		cout << char(179);
	}
}

void pintarBordeNumero(int fila, int col, const tTablero tablero) // pinta la fila central de las celdas, incluyendo numeros coloreados
{
	if(tablero[fila][col] != 0)
	{
		if (col != N - 1)
		{
			cout << right << char(179);
			colorFondo(tablero[fila][col]);
			cout << setw(5) << pow(2, tablero[fila][col]);
			colorFondo(0);
		}
		else
		{
			cout << right << char(179);
			colorFondo(tablero[fila][col]);
			cout << setw(5) << pow(2, tablero[fila][col]);
			colorFondo(0);
			cout << char(179);
		}
	}
	else
	{
		colorFondo(0);
		if (col != N - 1)
		{
			cout << right << char(179) << setw(4) << "     ";
		}
		else
		{
			cout << right << char(179) << setw(4) << "     " << char(179);
		}
	}
}

void pintarBordeInter() // pinta borde intermedio sin color
{
	cout << char(195);
	for (int i = 0; i < N - 1; i++)
	{
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(197);
	}
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(180) << endl;
}

void pintarBordeAbajo() // pinta borde abajo sin color
{
	cout << char(192);
	for (int i = 0; i < N - 1; i++)
	{
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << endl;
}

int log2(int num) // devuelve la potencia de dos que da como solucion el numero introducido
{
	int cont = 0, soluc;
	do{
		soluc = pow(2, cont);
		cont++;
	}while (soluc != num);
	return cont - 1;
}

void carga(tTablero tablero, int &puntos, bool &ok) // carga una partida desde fichero, modificando el tablero, la puntuacion y devolviendos si se pudo cargar correctamente
{
	string nombArch;
	ifstream leer;
	int aux;
	cout << "Escriba un nombre de archivo ('tablero' por defecto):  ";
	cin >> nombArch;
	nombArch = nombArch + ".txt";
	leer.open(nombArch);

	if(!leer.is_open())
	{
		ok = false;
	}
	else
	{
		ok = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				leer >> tablero[i][j];
			}
		}
		leer >> puntos;
	}
}

tAccion leeAccion() //lee la tecla pulsada del teclado y devuelve la posicion del enumerado correspondiente a cada una de las posibles opciones
{
	int dir;
	tAccion devolver;
	bool dirok;
	do{
		dirok = true;
		cin.sync();
		dir = _getch();
		if (dir == 0xe0)
		{
			dir = _getch();
			switch (dir)
			{
				case 72: devolver = arriba; break;
				case 80: devolver = abajo; break;
				case 77: devolver = der; break;
				case 75: devolver = izq; break;
				default: dirok = false;
			}
		}
		else if (dir == 27)
		{
			devolver = esc;
			dirok = true;
		}
		else
		{
			dirok = false;
		}
	}while (dirok != true);
	return devolver;
}

void mueveFichas(tTablero tablero, tAccion accion) // desplaza las fichas dependiendo de la direccion pulsada, de modo que las fichas queden colindantes unas a otras pero sin combinarlas, usa la funcion obtenerParametro
{
	int i, j, incrementoI, incrementoJ, contVacia;

	for (int cont = 0; cont < N; cont++)
	{
		obtenerParametro(accion, i, j, incrementoI, incrementoJ, cont);
		contVacia = 0;
		for (int contFC = 0; contFC < N; contFC++)
		{
			if (tablero[i][j] != 0)
			{
				tablero[i - contVacia * incrementoI][j - contVacia * incrementoJ] = tablero[i][j];

				if ((i - contVacia * incrementoI != i) || (j - contVacia * incrementoJ != j))
				{
					tablero[i][j] = 0;
				}
			}
			else
			{
				contVacia++;
			}
			i = i + incrementoI;
			j = j + incrementoJ;
		}
	}
}

void obtenerParametro(tAccion accion, int &fila, int &columna, int &incrementoFila, int &incrementoColumna, int cont) // devuelve varios parámetros en funcion de la tecla de direccion pulsada, para usarlos en la funcion de desplazamiento
{
	switch (accion)
	{
		case der:
		{
			fila = cont;
			columna = N - 1;
			incrementoFila = 0;
			incrementoColumna = -1;
			break;
		}
		case izq:
		{
			fila = cont;
			columna = 0;
			incrementoFila = 0;
			incrementoColumna = 1;
			break;
		}
		case arriba:
		{
			fila = 0;
			columna = cont;
			incrementoFila = 1;
			incrementoColumna = 0;
			break;
		}
		case abajo:
		{
			fila = N - 1;
			columna = cont;
			incrementoFila = -1;
			incrementoColumna = 0;
			break;
		}
	}
}

void combinarCeldas(tTablero tablero, tAccion accion, int &puntos) // dependiendo de la direccion pulsada, una vez ejecutado el movimiento de las fichas, comprueba si hay dos fichas colindantes con el mismo valor, y si es asi, las combina en una sola con un grado mayor de potencia de 2
{
	switch (accion)
	{
		case arriba:
		{
			for (int j = 0; j < N; j++)
			{
				for (int i = 0; i < N; i++)
				{
					if(tablero[i][j] == tablero[i + 1][j] && tablero[i][j] != 0)
					{
						tablero[i][j]++;
						puntos = puntos + pow(2, tablero[i][j]);
						tablero[i + 1][j] = 0;
					}
				}
			}
			break;
		}
		case abajo:
		{
			for (int j = 0; j < N; j++)
			{
				for (int i = 1; i < N; i++)
				{
					if(tablero[N - i][j] == tablero[N - (i + 1)][j] && tablero[N - i][j] != 0)
					{
						tablero[N - i][j]++;
						puntos = puntos + pow(2, tablero[N - i][j]);
						tablero[N - (i + 1)][j] = 0;
					}
				}
			}
			break;
		}
		case der:
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 1; j < N; j++)
				{
					if(tablero[i][N - j] == tablero[i][N - (j + 1)] && tablero[i][N - j] != 0)
					{
						tablero[i][N - j]++;
						puntos = puntos + pow(2, tablero[i][N - j]);
						tablero[i][N - (j + 1)] = 0;
					}
				}
			}
			break;
		}
		case izq:
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if(tablero[i][j] == tablero[i][j + 1] && tablero[i][j] != 0)
					{
						tablero[i][j]++;
						puntos = puntos + pow(2, tablero[i][j]);
						tablero[i][j + 1] = 0;
					}
				}
			}
			break;
		}
	}
}

int menu() // menu principal del juego
{
	int op;
	cout << "1.- Partida nueva" << endl;
	cout << "2.- Cargar partida" << endl;
	cout << "0.- Salir" << endl;
	cout << "Opcion: ";
	cin >> op;
	while (op > 2 || op < 0)
	{
		cout << "Elija una opcion valida: ";
		cin >> op;
	}
	return op;
}

void nuevaFicha(tTablero tablero) //crea una nueva ficha en una posicion vacía del tablero
{
	int i, j;
	do
	{
		i = rand()%N;
		j = rand()%N;
	} while (tablero [i][j] != 0);	
	tablero[i][j] = digAleatorio();
}

void getEstadoPartida(const tTablero tablero, bool &lleno, bool &movPosibles) //a partir del tablero, comprueba si hay alguna casilla libre, o si hay movimientos posibles con casillas colindantes y lo devuelve
{
	lleno = tabLleno(tablero);
	if (!lleno)
	{
		movPosibles = true;
	}
	else
	{
		movPosibles = posibles(tablero);
	}
}

int mayor(const tTablero tablero) //devuelve el valor de la ficha mas grande, para comprobar si se ha logrado llegar a 2048
{
	int mayor = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tablero[i][j] > mayor)
			{
				mayor = tablero[i][j];
			} 
		}
	}
	return pow(2, mayor);
}

bool tabLleno(const tTablero tablero) // comprueba si el tablero esta lleno
{
	bool lleno = true;
	int i = 0, j = 0, cont = 0;
	while (j < N && lleno)
	{
		if (tablero[i][j] != 0)
		{
			i++;
			if (i == N)
			{
				j++;
				i = 0;
			}
		}
		else
		{
			lleno = false;
		}
	}
	return lleno;
}

bool posibles(const tTablero tablero) // comprueba si hay dos fichas colindantes, para saber si hay movimientos posibles
{
	bool posibles = false;
	int anterior = -1, i = 0, j = 0;

	while(i < N && posibles == false)
	{
		while(j < N && posibles == false)
		{
			if(anterior == tablero[i][j])
			{
				posibles = true;
			}
			else
			{
				anterior = tablero[i][j];
				j++;
			}
		}
		i++;
		j = 0;
		anterior = -1;
	}
	i = 0;
	while(j < N && posibles == false)
	{
		while(i < N && posibles == false)
		{
			if(anterior == tablero[i][j])
			{
				posibles = true;
			}
			else
			{
				anterior = tablero[i][j];
				i++;
			}
		}
		j++;
		i = 0;
		anterior = -1;
	}
	return posibles;
}