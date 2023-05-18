/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 4.
 * Consigna: Mostrar en consola tu nombre, tu apellido y tu edad. Pero cada campo debe ser definido como una variable (queda en cada uno elegir el tipo de variable necesaria para cada dato);
 * Fecha: 2023/05/15
 */

#include <iostream>
using namespace std;

const string NAME = "Juan";
const string SURNAME = "Alegría";
const int AGE = 37;

void showPersonalData(string name, string surname, int age)
{
	cout<<NAME + " " + surname + "("<<age<<")";
}

int main()
{
	showPersonalData(NAME, SURNAME, AGE);
	return 0;
}
