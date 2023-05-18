/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 1.
 * Consigna: Mostrar en pantalla tu nombre y apellido.
 * 2023/05/15
 */

#include <iostream>
using namespace std;

const string NAME="Juan Alegría\n"; //std::basic_string, In <string>, the standard library provides a general string template basic_string.

void showName(string name)
{
	cout<<name;
}

int main()
{
	showName(NAME);
	return 0; //Salida sin error 0; *The int value returned by main(), if any, is the program’s return value to ‘‘the system.’’ If no value is returned, the system will receive a value indicating successful completion. A nonzero value from main() indicates failure. Not every operating system and execution environment make use of that return value: Linux/Unix-based environments often do, but Windows-based environments rarely do.
}
