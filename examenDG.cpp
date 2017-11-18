#include <iostream>
using namespace std;
#include <cctype>
#include <fstream>
#include <string>

const int NP = 6;

typedef struct{
	string cif;
	int proveedor;
	int pedidos;
	int euros;
}tInfo;

typedef tInfo tLista[NP];

typedef enum {papeleria, alimentacion, limpieza, informatica} tProveedor;

int menu();
bool cargarLista(tLista lista);
void guardar(const tLista lista);
int buscarProveedor(const tLista lista);
string getCif();
void nuevoPedido(tLista lista);
int getEuros();

int main(){
	int opcion;
	tLista lista;
	cargarLista(lista);
	do{
		 opcion = menu();
		switch (opcion){
	
			case 1:{
				nuevoPedido(lista);
				   }break;
			case 0:{
				cout << "Hasta luego!" << endl;
				   }
		}
	}while(opcion !=0);
	guardar(lista);
	system ("pause");
	return 0;
}

int menu(){
	int opcion;
	cout << "1.- Nuevo pedido" << endl;
	cout << "0.- Salir" << endl;
	cout << "Elige una opcion: ";
	cin >> opcion;

	return opcion;
}

bool cargarLista(tLista lista){
	bool cargar;
	ifstream archivo;
	int i = 0;
	string cif;
	archivo.open("proveedores.txt");
	if (archivo.is_open()){
		cargar = true;
		archivo >> cif;
		while(cif != "X" && i < NP){
			lista[i].cif = cif;
			archivo >> lista[i].proveedor >> lista[i].pedidos >> lista [i].euros;
			i++;
			archivo >> cif;
		}
		if( i < NP){
			cout << "Error: no hay suficientes proveedores" << endl;
		}
		archivo.close();
	}else{
		cargar = false;
		cout << "Archivo no encontrado." << endl;
	}
	return cargar;
}

void guardar(const tLista lista){
	ofstream archivo;
	int i=0;

	archivo.open("provedores.txt");
	while(i <NP){
		archivo << lista[i].cif << " " << lista[i].proveedor << " " << lista[i].pedidos <<" " << lista[i].euros << endl;
		i++;
	}
	archivo << "X" <<endl;
	archivo.close();
}

int buscarProveedor(const tLista lista){
	string cif = getCif();
	int i=0, posicion;
	while(((cif != lista[i].cif) || (lista[i].cif =="X")) && (i < NP)){
		i++;
	}
	if(i==NP){
		posicion = -1;
	}else{
		posicion = i;
	}
	return posicion;
}

string getCif(){
	string cif;
	cout << "Introduce CIF para actualizar datos: ";
	cin >> cif;

	return cif;
}

void nuevoPedido(tLista lista){
	int posicion = buscarProveedor(lista);
	if (posicion != -1){
		int euros = getEuros();
		lista[posicion].pedidos++;
		lista[posicion].euros = lista[posicion].euros + euros;
	}
}

int getEuros(){
	int euros;
	cout <<"Introduce el coste del pedido: ";
	cin >> euros;
	return euros;
}