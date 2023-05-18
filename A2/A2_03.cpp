/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 3.
 * Consigna: Mostrar en consola tu nombre y tu edad.
 * Fecha: 2023/05/15
 */

#include <iostream>
using namespace std;
 
const string NAME = "Juan";
const int AGE = -5;

int checkAge(int age)
{
	if (age < 0) return 1;
	
	return 0;
}

void showPersonalData(string name, int age)
{
	if (checkAge(age) > 0) cout<<"La edad no es correcta";
	else
		cout<<name + "(" << age << ")\n"; //El ``+`` no concatena string ni convierte la salida de entero a string
}	

int main()
{
	showPersonalData(NAME, AGE);
	return 0;
}
