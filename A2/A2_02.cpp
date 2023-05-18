/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 2.
 * Consigna: Mostrar en pantalla tu nombre y apellido pero esta vez en distintas líneas: 
 * Salida en consola: 
 *		Mi Nombre 
 *		Mi apellido
 * Fecha: 2023/05/15
 */

#include <iostream>
using namespace std;

const string NAME = "Juan";
const string SURNAME = "Alegría";

void showName(string name, string surname)
{
	cout<<name + "\n" + surname + "\n";
}

int main()
{
	showName(NAME, SURNAME);
	
	return 0;
}
