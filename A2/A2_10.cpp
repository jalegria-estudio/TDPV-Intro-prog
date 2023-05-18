/**
* Introducción a C++.
* Practica Unidad 2 - Actividad 10.
* Consigna: Ingresar por consola tu nombre y apellido y mostrarlo en pantalla.
* Fecha: 2023/05/17
*/

/**
 * I/O Streams chapter 38.
 * >>>>> 38.4.1.1 Formatted Input >>>>> 
 * Formatted input is primarily supplied by the >> (‘‘input,’’ ‘‘get,’’ or ‘‘extraction’’) operator:
 * in>>x    Read from in into x according to x’s type; x can be an arithmetic type,a pointer, a basic_string, a valarray, a basic_streambuf, or any type for which the user has supplied a suitable operator>>()
 * getline(in,s)    Read a line from in into the string s
 * 
 * 
 * >>>>> 38.4.1.2 Unformatted Input >>>>> 
 * in.getline(p,n,t='\n') Read at most n characters from in into [p:...); consider t a terminator; remove terminator from in.
 * in.get(p,n,t) Read at most n characters from in into [p:...); consider t a terminator.
 * 
 * If you have a choice, use formatted input (§38.4.1.1) instead these low-level input functions.(!)
 * 
 * The simple get(c) is useful when you need to compose your values out of characters. The other get() function and getline() read sequences of characters into a fixed-size area [p:...). They read until they reach the maximum number of characters or find their terminator character (by default '\n').
 * They place a 0 at the end of the characters (if any) written to; getline() removes its terminator from the input, if found, whereas get() does not.
 * 
 * (!)Pone un char: 0 '\000' al final de la lectura en el buffer: creo que es vacio y corta las siguientes lecturas. No es lo mismo que std::getline(<input>, <strin>);
 * 
 * char inputStr[100];
 * std::cin.get(inputStr, 10);
 * cout<<"Su input-get es: "<<inputStr<<endl;
 * std::cin.getline(inputStr, 10); 
 * cout<<"Su input-getline es: "<<inputStr<<endl;
 * 
 */

#include <iostream>
using namespace std;

int main()
{
    string name;
    cout<<"Ingrese su nombre completo >";
    getline(std::cin, name);
    cout<<"Su nombre es: "<<name<<endl;

    return 0;
}