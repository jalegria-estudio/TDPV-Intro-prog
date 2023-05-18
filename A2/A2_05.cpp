/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 5.
 * Consigna:  Mostrar en consola tu nombre, tu apellido y tu edad pero con la siguiente interfaz: , y  son las variables a mostrar: 
 *	Salida en consola
 * =====================
 *	Mi Nombre es: <Nombre>
 *	Mi Apellido es: <Apellido>
 *	Tengo <anios> de edad
 *	======================	
 * Fecha: 2023/05/15
 */

#include <iostream>
using namespace std;

const string NAME = "Juan";
const string SURNAME = "Alegría";
const int AGE = 37;

string cliDataInterface = "==========================================\n\tMy name is %name%.\n\tMy surname is %surname%.\n\tI'm %age% years old.\n==========================================";

string replaceData(string oldStr, string newStr, string wildcard)
{
	int lenghtWildcard = wildcard.size();
	////constexpr size_type find( const basic_string& str, size_type pos = 0 ) const noexcept;===>find characters in the string
	////constexpr basic_string& replace( size_type pos, size_type count, const basic_string& str ); ===>replaces specified portion of a string 
	oldStr.replace(oldStr.find(wildcard), lenghtWildcard, newStr);

	return oldStr;
}

void showPersonalData(string name, string surname, int age)
{
	string dataPersonal = cliDataInterface;
	dataPersonal = replaceData(dataPersonal, name, "%name%");
	dataPersonal = replaceData(dataPersonal, surname, "%surname%");
	dataPersonal = replaceData(dataPersonal, to_string(age), "%age%");//Converts a numeric value to std::string.
	cout<<dataPersonal;
//	cout<<cliDataInterface;
}

int main()
{
	showPersonalData(NAME, SURNAME, AGE);

	return 0;
}
