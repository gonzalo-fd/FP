#include <iostream>
#include <string>
using namespace std;
#include <fstream>

const int NPO = 8;

typedef struct{
	string denominacion;
	int cantidad;
	int precio;
} tPescado;

typedef tPescado tArray[NPO];

typedef struct{
	tArray elementos;
	int contador;
} tLista;

void cargar(tLista &lista, bool &ok);
void guardar(const tLista lista);
int menu();

int main()
{


	system("pause");
	return 0;
}

void cargar(tLista &lista, bool &ok)
{
	tPescado pescado;
	ifstream leer;

	lista.contador = 0;
	leer.open("almacen.txt");

	if(!leer.is_open()){
		ok = false;
	}
	else{
		ok = true;
		getline( leer, pescado.denominacion);
	
		while((pescado.denominacion != "XXX") && lista.contador < NPO){
			leer >> pescado.cantidad;
			leer >> pescado.precio;
			lista.contador++;
			getline( leer, pescado.denominacion);
			lista.elementos[lista.contador] = pescado;
		}
	leer.close();
	}
}

void guardar(const tLista lista)
{
	ofstream escribir;

	escribir.open("almacen.txt");
	for (int i = 0; i < lista.contador; i++){

		escribir << lista.elementos[i].denominacion << endl;
		escribir << lista.elementos[i].cantidad << endl;
		escribir << lista.elementos[i].precio << endl;
	}
	escribir << "XXX" << endl;
}

int menu()
{
	int opcion;

	cout << "1 - Realizar la compra de un pescadero." << endl;
	cout << "2 - Visualizar los productos agotados." << endl;
	cout << "0 - Salir." << endl;
	cin >> opcion;

	while(opcion < 0 || opcion > 2)
	{
		cout << "Opcion incorrecta, seleccione otra opcion: ";
		cin >> opcion;
	}

	return opcion;
}
