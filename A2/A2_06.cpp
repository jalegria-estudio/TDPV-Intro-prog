/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 6.
 * Consigna:  Mostrar en Consola la edad y la edad que vas a tener dentro de 10 años
 * Fecha: 2023/05/16
 */

#include <iostream>
using namespace std;

const int AGE = 37;

int calculateMyAgeIn(int years)
{
	return AGE + years;
}

int main()
{
	cout<<"My years old are "<<AGE<<" and in ten years I will be "<<calculateMyAgeIn(10);

	return 0;
}
