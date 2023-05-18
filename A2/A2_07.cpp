/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 6.
 * Consigna:  Mostrar en Consola la edad y si tu edad es mayor a 50 (debe ser aclarada con 1 o 0) (Spoiler, no usar estructura IF) 
 *
 *Salida en consola: 
 *
 * ======================
 * Tengo <anios> de edad
 * Soy mayor de 50?: <1 o 0>
 * ======================
 * Fecha: 2023/05/16
 */
#include <iostream>

using namespace std;

const int AGE = 37;

string cliDataInterface = "==========================================\n\tI'm %age% years old.\n\tAm I over 50 years old?:  %old%\n==========================================";

string replaceData(string oldStr, string newStr, string wildcard)
{
	//std::basic_string ---> constexpr basic_string& replace( size_type pos, size_type count, const basic_string& str );
	oldStr.replace(oldStr.find(wildcard), wildcard.size(), newStr);
	
	return oldStr;
}

string getPersonalData()
{
	string personalData = cliDataInterface;
	personalData = replaceData(personalData, to_string(AGE), "%age%");
	personalData = replaceData(personalData, to_string(AGE > 50), "%old%");
	
	return personalData;
}

int main(int argc, char **argv)
{
	cout<<getPersonalData();
	
	return 0;
}
