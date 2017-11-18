#include <iostream>
using namespace std;
  
#include <iomanip>
  
#include <cstdlib> // para numeros aleatorios 
  
#include <ctime> // para srand(time(NULL))
  
#include <string>
 
#include <Windows.h>
  
int pasaCalculadora();
int quienEmpieza();
bool mismaFila();
bool mismaColumna();
bool digitoValido(int ultimo, int nuevo);
int digitoAleatorio();
int digitoAutomata(int ultimo);
int digitoPersona();
int digitoPersona(int ultimo);
void color(int X);
  
int main()
  
{
    srand(time(NULL));
	const int ROJOBLANCO = 124, GRIS = 8, AMARILLO = 14, ROJO = 12, NEGROBLANCO = 240, VERDE = 10;
  
    string nombrejug;
    color (ROJOBLANCO);
    cout << "¡Bienvenido a pasa la calculadora!" << endl << '\n';
    color (GRIS);
    cout << "Como te llamas?: ";
    color (AMARILLO);
    getline(cin, nombrejug);
    color (GRIS);
    cout << "Hola " << nombrejug << endl << '\n';
      
        switch (pasaCalculadora())
        {
  
        case 1:
            {
                color (ROJO);
                cout << "Mala suerte, has perdido!" << endl;
                cout << "Mas suerte en la proxima, " << nombrejug << endl << '\n';
                color (NEGROBLANCO);
                system("pause");
                break;
            }
          
        case 2:
            {
                color (VERDE);
                cout << "Enhorabuena, has ganado!" << endl;
                cout << "Hasta la proxima, " << nombrejug << endl << '\n';
                color (NEGROBLANCO);
                system("pause");
                break;
            }
          
        case 0:
            {
                color (AMARILLO);
                cout << '\n' << "Has abandonado el juego" << endl;
                cout << "Hasta la proxima, " << nombrejug << endl << '\n';
                color (NEGROBLANCO);
                system("pause");
                break;
            }
        }
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
        cout << "Empiezo yo" << endl << '\n';
        color(TURQUESA);
        cout << "Yo pulso " << aleatorio << endl << '\n';
        ultimo = aleatorio;
        suma = aleatorio;
        turno = JUGADOR;
    }

    else
    {
        color (GRIS);
        cout << "Empiezas tu" << endl << '\n';
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
            cout << '\n' << "Suma: " << suma << endl << '\n';
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