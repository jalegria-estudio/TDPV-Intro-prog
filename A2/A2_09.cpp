/**
* Introducción a C++.
* Practica Unidad 2 - Actividad 9.
* Consigna: Ingresar por teclado un número entero y mostrarlo en pantalla.
* Fecha: 2023/05/16
*/

#include <iostream>
using namespace std;

/**
 * isInt - Valida un string numerico.
 * Ver ejercicio A2_11 para más info.
*/
bool isInt(string nro){
	int i = 0;
	int size = nro.length();
	
	while (i < size){
		if (!isdigit(nro[i])) return false;

		++i;
	}
	
	return true;
}

int main()
{
    string nro;
    cout<<"Ingrese un nro >";
    cin>>nro; //Solo lee una entrada, si se ingresa un espacio no lo asigna a la variable.
	//cout<<endl<<"debug>>ingreso: "<<nro<<endl;

    if (isInt(nro)) cout<<"El nro ingresado es: "<<nro;
    else
		cout<<"No ingreso un nro";

	cout<<endl;

    return 0;
}
