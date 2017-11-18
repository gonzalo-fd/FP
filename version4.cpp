#include <iostream>
using namespace std;
  
#include <iomanip>
#include <cstdlib> // para numeros aleatorios 
#include <ctime> // para srand(time(NULL))
#include <string>
#include <Windows.h>
#include <fstream>
  
int pasaCalculadora(int nivel);
int quienEmpieza();
bool mismaFila();
bool mismaColumna();
bool digitoValido(int ultimo, int nuevo);
int digitoAleatorio();
int digitoAutomata(int ultimo);
int digitoAutomataMedio(int ultimo, int suma);
int digitoAutomataDificil(int ultimo, int suma);
int digitoPersona();
int digitoPersona(int ultimo);
int menu();
int menuNivel();
bool mostrar(string nombArch);
void actInforme(int jugadas, int ganadas, int abandonos);
void estadisticas();
void color(int X);

const int VERDEOSC = 2, AZUL = 9, BLANCO = 15, TURQUESA = 11, PURPURA = 13, ROJOBLANCO = 124, GRIS = 8, AMARILLO = 14, OCRE = 6, ROJO = 12, NEGROBLANCO = 240, VERDE = 10;
const int ANCHURA = 16, ABANDONAR = 0, PROGRAMA = 1, SUMAMAX = 31, VOLVERMENU = 1, FINPARTIDA = 2, JUGAR = 1, ABANDONO = 0, ACERCADE = 2, ESTADISTICAS = 3, JUGADOR = 2, MAQUINA = 1, FACIL = 1, NORMAL = 2, DIFICIL = 3;

int main()
  
{
	srand(time(NULL));
	int opcion, ganajuego = 0, abandonadas = 0, jugadas = 0, nivel, calculadora, fin = FINPARTIDA;
	bool abandonar = false, abandonarNivel = true;
	
    string nombrejug, nombArch = "versionPc.txt";
    color (ROJOBLANCO);
    cout << "¡Bienvenido a pasa la calculadora!" << endl << '\n';
    color (GRIS);
    cout << "Como te llamas?: ";
    color (AMARILLO);
    getline(cin, nombrejug);
    color (GRIS);
    cout << "Hola " << nombrejug << endl << '\n';
	
	do
	{
		opcion = menu();
		
		if (opcion == ABANDONO)
		{
			color (OCRE);
			cout << '\n' << "Has salido del juego" << endl;
			cout << "Hasta la proxima, " << nombrejug << endl << '\n';
			color (NEGROBLANCO);
			system("pause");
		}

		else if (opcion == JUGAR)
		{
			nivel = menuNivel();

			if (nivel == ABANDONO)
			{
				abandonarNivel = true;
				fin = VOLVERMENU;
				calculadora = ABANDONO;
			}	
			
			else if (!abandonar)
			{
				calculadora = pasaCalculadora(nivel);
				jugadas++;
			}

			switch (calculadora)
			{
				case MAQUINA:
					{
						color (ROJO);
						cout << "Mala suerte, has perdido!" << endl;
						cout << "Mas suerte en la proxima, " << nombrejug << endl << '\n';
						ganajuego++;
						color (NEGROBLANCO);
						break;
					}
          
				case JUGADOR:
					{
						color (VERDE);
						cout << "Enhorabuena, has ganado!" << endl;
						cout << "Hasta la proxima, " << nombrejug << endl << '\n';
						break;
					}
          
				case ABANDONO:
					{
						color (AMARILLO);
						switch(fin)
						{
							case FINPARTIDA:
							{
								cout << '\n' << "Has abandonado la partida" << endl;
								abandonadas++;
								break;
							}
							case VOLVERMENU:
							{
								cout << '\n' << "Has vuelto al menu principal" << endl;
								break;
							}
						}
					break;
					}
			}
		}
		else if (opcion == ESTADISTICAS)
		{
			estadisticas();
		}

		else 
		{
			if(!mostrar(nombArch))
			{
				color (ROJO);
				cout << '\n' << "Error: el archivo no se ha encontrado o no ha podido abrirse." << endl;
			}
		}
	} while(opcion != ABANDONO);

	actInforme(jugadas, ganajuego, abandonadas);

    return 0;
}
 
void color(int X)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),X); 
}
 
int pasaCalculadora(int nivel)
{
    int ganador, ultimo, nuevo, turno, suma = 0, empieza = quienEmpieza(), aleatorio = digitoAleatorio();
    bool abandono = false;

	if (nivel == FACIL)
	{
		color(VERDE);
		cout << '\n' << "-NIVEL FACIL-" << endl;
	}

	else if (nivel == NORMAL)
	{
		color(AMARILLO);
		cout << '\n' << "-NIVEL MEDIO-" << endl;
	}

	else
	{
		color(ROJO);
		cout << '\n' << "-NIVEL DIFICIL-" << endl;
	}

    if (empieza == PROGRAMA)
    {
        color(GRIS);
        cout << '\n' << "Empiezo yo" << endl << '\n';
        color(TURQUESA);
        cout << "Yo pulso " << aleatorio << endl << '\n';
        ultimo = aleatorio;
        suma = aleatorio;
        turno = JUGADOR;
    }

    else
    {
        color (GRIS);
        cout <<  '\n' << "Empiezas tu" << endl << '\n';
        turno = JUGADOR;
        ultimo = digitoPersona();
        suma = ultimo;
        turno = PROGRAMA;
        if (ultimo == ABANDONAR)
        {
            abandono = true;
        }
        color(PURPURA);
        if (!abandono)
        {
            cout << '\n' << "Suma: " << suma << endl << '\n';
        }
        
        nuevo = ultimo;
    }
  
    while (suma < SUMAMAX && !abandono)
    {
        if (turno == PROGRAMA)
        {
            color (GRIS);
			switch(nivel)
			{
				case FACIL:
				{
					nuevo = digitoAutomata(ultimo);
					break;
				}

				case NORMAL:
				{
					nuevo = digitoAutomataMedio(ultimo, suma);
					break;
				}
	
				case DIFICIL:
				{
					nuevo = digitoAutomataDificil(ultimo, suma);
					break;
				}
			}

            color(TURQUESA);
            cout << "Yo pulso " << nuevo << endl << '\n';
            turno = JUGADOR;
            ultimo = nuevo;
            suma = suma +nuevo;
            color(PURPURA);
            cout << "Suma: " << suma << endl << '\n';
        }
  
        else if (turno == JUGADOR)
        {
            color (GRIS);
            cout << "Tu turno: " << endl << '\n';
            nuevo = digitoPersona(ultimo);
            turno = PROGRAMA;
            ultimo = nuevo;
            suma = suma + nuevo;
            if (ultimo == ABANDONAR)
            {
                abandono = true;
            }
            color (PURPURA);
			if (!abandono)
			{
				cout << '\n' << "Suma: " << suma << endl << '\n';
			}
        }
  
    }
  
    if (suma >= SUMAMAX && turno == PROGRAMA)
    {
        ganador = PROGRAMA;
    }
  
    else if (suma >= SUMAMAX && turno == JUGADOR)
    {
        ganador = JUGADOR;
    }
  
    else if (abandono)
    {
        ganador = ABANDONAR;
    }
  
    return ganador;
}
  
int quienEmpieza()
{
    return (rand() % 2) + 1;
}
  
bool mismaFila(int ultimo, int nuevo)
{
    bool correcto;
    int lineault = (ultimo - 1) / 3;
    int lineanuevo = (nuevo - 1) / 3;
  
    if(lineanuevo == lineault)
    {
        correcto = true;
    }
  
    else
    {
        correcto = false;
    }
  
    return correcto;    
}
  
bool mismaColumna(int ultimo, int nuevo)
{
    bool correcto;
    int columnault = (ultimo - 1) % 3;
    int columnanuevo = (nuevo - 1) % 3;
  
    if(columnanuevo == columnault)
    {
        correcto = true;
    }
  
    else
    {
        correcto = false;
    }
  
    return correcto;    
}
  
bool digitoValido(int ultimo, int nuevo)
{
    bool valido;
  
    if (nuevo == ABANDONAR)
    {
        valido = true;
    }
  
    else if( (mismaColumna(ultimo, nuevo) || mismaFila(ultimo, nuevo)) && nuevo != ultimo) 
    {
        valido = true;
    }

    else
    {
        valido = false;
    }
  
    return valido;
}
  
int digitoAleatorio()
{
    return (rand() % 9) + 1;
}
  
int digitoAutomata(int ultimo)
{
    int nuevo;
  
    do
    { 
        nuevo = digitoAleatorio();
    }
  
    while (!digitoValido(ultimo, nuevo));
  
    return nuevo;
}
  
int digitoPersona(int ultimo)
{
    int nuevo = digitoPersona();
  
    while (!digitoValido(ultimo, nuevo))
    {
        color (ROJO);
        cout << '\n' << "Error: tiene que ser distinto de " << ultimo << " y estar en la misma fila o columna" << endl << '\n';
  
        nuevo = digitoPersona();
    }
  
    return nuevo;
}
  
int digitoPersona()
{
    int digito;
    string tablaf1 = "X 7   8   9 X", tablaf2 = "X 4   5   6 X", tablaf3 = "X 1   2   3 X", borde = "XXXXXXXXXXXXX", medio = "X           X";
    color (VERDE);
    cout << fixed << right << setw(ANCHURA) << borde << endl << setw(ANCHURA) << medio << endl << setw(ANCHURA) << tablaf1 << endl << setw(ANCHURA) << medio << endl << setw(ANCHURA) << tablaf2 << endl << setw(ANCHURA) << medio << endl << setw(ANCHURA) << tablaf3 << endl << setw(ANCHURA) << medio << endl << setw(ANCHURA) << borde << endl << '\n';
    color (GRIS);
    cout << "Introduce un digito entre 0 y 9 (0 para terminar): ";
    color (AMARILLO);
    cin >> digito;

    while (digito < 0 || digito > 9)
    {
        color (ROJO);
        cout << "Introduce otro numero que este entre 0 y 9: ";
		color (AMARILLO);
        cin >> digito;
    }
  
    return digito;
}

int menu()
{
	int opcion;
	
	color(VERDEOSC);
	cout << '\n' << "Selecciona una opcion: " << endl;
	cout << "1.- Jugar" << endl;
	cout << "2.- Acerca de" << endl; 
	cout << "3.- Estadisticas" << endl; 
	cout << "0.- Salir" << endl;
	cout << "Opcion: ";
	color(AMARILLO);
	cin >> opcion;

	while (opcion < 0 || opcion > 3)
	{
		color(ROJO);
		cout << "Error. Opcion incorrecta, seleccione una opcion valida: "; 
		color(AMARILLO);
		cin >> opcion;
	}

	return opcion;
}

int menuNivel()
{
	int opcion;
	  
	color(VERDEOSC);
	cout << '\n' << "Selecciona un nivel: " << endl;
	color(VERDE);
	cout << "1.- Facil" << endl;
	color(AMARILLO);
	cout << "2.- Normal" << endl;
	color(ROJO);
	cout << "3.- Dificil" << endl;
	color(AZUL);
	cout << "0.- Volver al menu" << endl;
	color(VERDEOSC);
	cout << "Opcion: ";
	color(AMARILLO);
	cin >> opcion;
	
	while (opcion < 0 || opcion > 3)
	{
		color(ROJO);
		cout << "Error. Opcion incorrecta, seleccione una opcion valida: "; 
		color(AMARILLO);
		cin >> opcion;
	}
 
	return opcion;
}

int digitoAutomataDificil(int ultimo, int suma)
{
    int nuevo;
	const int SUMAMAX = 30;

    do
    { 
        nuevo = digitoAleatorio();
    }
  
    while (!digitoValido(ultimo, nuevo) && suma < 12);

	if (suma >= 12 && suma < 17)
	{
		if (digitoValido(ultimo, 1))
		{
			nuevo = 1;
		}

		else if (digitoValido(ultimo, 2))
		{
			nuevo = 2;
		}

		else
		{
			nuevo = 3;
		}
	}

	else if (suma == 17 || suma == 19)
	{
		if (digitoValido(ultimo, 1))
		{
			nuevo = 1;
		}

		else if (digitoValido(ultimo, 2))
		{
			nuevo = 2;
		}

		else
		{
			nuevo = 3;
		}
	}

	else if (suma == 18)
	{
		if (digitoValido(ultimo, 7))
		{
			nuevo = 7;
		}

		else if (digitoValido(ultimo, 2))
		{
			nuevo = 2;
		}

		else
		{
			nuevo = 4;
		}
		
	}

	else if (suma == 20)
	{
		if (digitoValido(ultimo, 3))
		{
			nuevo = 3;
		}

		else if (digitoValido(ultimo, 1))
		{
			nuevo = 1;
		}

		else
		{
			nuevo = 5;
		}
	}

	else if (suma > 20)
	{
		if (digitoValido(ultimo, SUMAMAX - suma))
		{
			nuevo = SUMAMAX - suma;
		}

		else if (digitoValido(ultimo, (SUMAMAX - suma) - 1))
		{
			nuevo = (SUMAMAX - suma) - 1;
		}

		else if (digitoValido(ultimo, (SUMAMAX - suma) - 2))
		{
			nuevo = (SUMAMAX - suma) - 2;
		}
	}

	if (nuevo == 0)
	{
		nuevo = digitoAutomata(ultimo);
	}

	return nuevo;
}

int digitoAutomataMedio(int ultimo, int suma)
{
    int nuevo;
	const int SUMAMAX = 30;

    do
    { 
        nuevo = digitoAleatorio();
    }
  
    while (!digitoValido(ultimo, nuevo)&& suma <= 20);

	if (suma > 20)
	{
		if (digitoValido(ultimo, SUMAMAX - suma))
		{
			nuevo = SUMAMAX - suma;
		}

		else if (digitoValido(ultimo, (SUMAMAX - suma) - 1))
		{
			nuevo = (SUMAMAX - suma) - 1;
		}

		else if (digitoValido(ultimo, (SUMAMAX - suma) - 2))
		{
			nuevo = (SUMAMAX - suma) - 2;
		}
	}

	if (nuevo == 0)
	{
		nuevo = digitoAutomata(ultimo);
	}

	return nuevo;
}

bool mostrar(string nombArch)
{
	ifstream archivo;
	bool encontrado;
	string linea;

	archivo.open (nombArch);

	if (archivo.is_open())
	{
		encontrado = true;

		getline(archivo, linea);
		while (linea != "XXX")
		{
			color(BLANCO);
			cout << linea << endl;
			getline(archivo, linea);
		}
		color(TURQUESA);
		archivo.close();
		system("pause");
	}

	else
	{
		encontrado = false;
	}


	return encontrado;
}

void actInforme(int jugadas, int ganadas, int abandonos)
{
	ofstream archout;
	ifstream archin;
	int utilizado= 0, jugadasread = 0, ganadasread = 0, abandonosread = 0, jugadaswrite, ganadaswrite, abandonoswrite;

	archin.open ("informePC.txt");

	if (archin.is_open())
	{
		archin >> jugadasread;
		archin >> ganadasread;
		archin >> abandonosread;
		archin >> utilizado;
		
		archin.close();
	}
		
	utilizado++;
	abandonoswrite = abandonosread + abandonos;
	jugadaswrite = jugadasread + jugadas;
	ganadaswrite = ganadasread + ganadas;

	archout.open ("informePC.txt");

	archout << jugadaswrite << endl;
	archout << ganadaswrite << endl;
	archout << abandonoswrite << endl;
	archout << utilizado << endl;

	archout.close();
}

void estadisticas()
{
	ifstream archin;
	int utilizadoread, jugadasread, ganadasread, abandonosread;
	bool abierto;

	archin.open ("informePC.txt");

	if (archin.is_open())
	{
		archin >> jugadasread;
		archin >> ganadasread;
		archin >> abandonosread;
		archin >> utilizadoread;

		abierto = true;
		
		archin.close();
	}

	else
	{
		color(ROJO);
		cout << "No se ha encontrado el archivo del historial" << endl;
		abierto = false;
	}

	if (abierto)
	{
		color(AZUL);
		cout << '\n' << "Has jugado " << jugadasread << " partidas." << endl;
		cout << "La maquina ha ganado " << ganadasread << " partidas." << endl;
		cout << "Has abandonado " << abandonosread << " partidas." << endl;
		cout << "Has utilizado el programa " << utilizadoread << " veces." << endl << '\n';
	}
}