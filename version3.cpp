#include <iostream>
using namespace std;
  
#include <iomanip>
  
#include <cstdlib> // para numeros aleatorios 
  
#include <ctime> // para srand(time(NULL))
  
#include <string>
 
#include <Windows.h>

#include <fstream>
  
int pasaCalculadora();
int quienEmpieza();
bool mismaFila();
bool mismaColumna();
bool digitoValido(int ultimo, int nuevo);
int digitoAleatorio();
int digitoAutomata(int ultimo);
int digitoPersona();
int digitoPersona(int ultimo);
int menu();
bool mostrar(string nombArch);
void actInforme(int jugadas, int ganadas, int abandonos, int utilizado);
void color(int X);
  
int main()
  
{
    srand(time(NULL));
	const int ROJOBLANCO = 124, GRIS = 8, AMARILLO = 14, OCRE = 6, ROJO = 12, NEGROBLANCO = 240, VERDE = 10, JUGAR = 1, ABANDONO = 0, ACERCADE = 2, JUGADOR = 2, MAQUINA = 1;
	int opcion, ganajuego = 0, utilizado = 0, abandonadas = 0, jugadas = 0;
	
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
			utilizado++;
			color (NEGROBLANCO);
			system("pause");
		}

		else if (opcion == JUGAR)
		{
			jugadas++;
			switch (pasaCalculadora())
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
						cout << '\n' << "Has abandonado la partida" << endl;
						abandonadas++;
						break;
					}
				}
		}
	
		else 
		{
			if(mostrar(nombArch) == false)
			{
				color (ROJO);
				cout << "Error: el archivo no se ha encontrado o no ha podido abrirse." << endl;
			}
		}
	} while(opcion == JUGAR || opcion == ACERCADE);

	actInforme(jugadas, ganajuego, abandonadas, utilizado);

    return 0;
}
 
void color(int X)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),X); 
}
 
int pasaCalculadora()
{
    int ganador, ultimo, turno, usuario, suma = 0, maquina, empieza = quienEmpieza(), aleatorio = digitoAleatorio();
    bool abandono = false;
	const int GRIS = 8, TURQUESA = 11, PURPURA = 13, JUGADOR = 2, PROGRAMA = 1, ABANDONAR = 0, SUMAMAX = 31;
  
    if (empieza == PROGRAMA)
    {
        color (GRIS);
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
        if (abandono == false)
        {
            cout << '\n' << "Suma: " << suma << endl << '\n';
        }
        
        usuario = ultimo;
    }
  
    while (suma < SUMAMAX && abandono == false)
    {
        if (turno == PROGRAMA)
        {
            color (GRIS);
            maquina = digitoAutomata(ultimo);
            color(TURQUESA);
            cout << "Yo pulso " << maquina << endl << '\n';
            turno = JUGADOR;
            ultimo = maquina;
            suma = suma + maquina;
            color(PURPURA);
            cout << "Suma: " << suma << endl << '\n';
        }
  
        else if (turno == JUGADOR)
        {
            color (GRIS);
            cout << "Tu turno: " << endl << '\n';
            usuario = digitoPersona(ultimo);
            turno = PROGRAMA;
            ultimo = usuario;
            suma = suma + usuario;
            if (ultimo == ABANDONAR)
            {
                abandono = true;
            }
            color (PURPURA);
			if (abandono == false)
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
  
    else if (abandono == true)
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
	const int ABANDONAR = 0;
  
    if (nuevo == ABANDONAR)
    {
        valido = true;
    }
  
    else if( (mismaColumna(ultimo, nuevo) == true || mismaFila(ultimo, nuevo) == true) && nuevo != ultimo) 
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
  
    while (digitoValido(ultimo, nuevo) == false);
  
    return nuevo;
}
  
int digitoPersona(int ultimo)
{
    int nuevo = digitoPersona();
	const int ROJO = 12;
  
    while (digitoValido(ultimo, nuevo) == false)
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
	const int VERDE = 10, GRIS = 8, AMARILLO = 14, ANCHURA = 16, ROJO = 12;
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
	const int AMARILLO = 14, ROJO = 12, VERDEOSC = 2;
	
	color(VERDEOSC);
	cout << '\n' << "Selecciona una opcion: " << endl;
	cout << "1.- Jugar" << endl;
	cout << "2.- Acerca de" << endl; 
	cout << "0.- Salir" << endl;
	cout << "Opcion: ";
	color(AMARILLO);
	cin >> opcion;

	while (opcion < 0 || opcion > 2)
	{
		color(ROJO);
		cout << "Error. Opcion incorrecta, seleccione una opcion valida: "; 
		color(AMARILLO);
		cin >> opcion;
	}

	return opcion;
}

bool mostrar(string nombArch)
{
	ifstream archivo;
	bool encontrado;
	string linea;
	const int BLANCO = 15, TURQUESA = 11;

	archivo.open ("versionPc.txt");

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

void actInforme(int jugadas, int ganadas, int abandonos, int utilizado)
{
	ofstream archout;
	ifstream archin;
	int utilizadoread, jugadasread, ganadasread, abandonosread, utilizadowrite, jugadaswrite, ganadaswrite, abandonoswrite;

	archin.open ("informePC.txt");

	if (archin.is_open())
	{
		archin >> jugadasread;
		archin >> ganadasread;
		archin >> abandonosread;
		archin >> utilizadoread;
		
		archin.close();
	}

	else
	{
		cout << "No se ha encontrado el archivo del historial" << endl;
	}
		
	utilizadowrite = utilizadoread + utilizado;
	abandonoswrite = abandonosread + abandonos;
	jugadaswrite = jugadasread + jugadas;
	ganadaswrite = ganadasread + ganadas;

	archout.open ("informePC.txt");

	if (archout.is_open())
	{
		archout << jugadaswrite << endl;
		archout << ganadaswrite << endl;
		archout << abandonoswrite << endl;
		archout << utilizadowrite << endl;

		archout.close();
	}

	else
	{
		cout << "No se ha encontrado el archivo del historial" << endl;
	}
}