/**
 * Introducción a C++.
 * Practica Unidad 3 - Actividad 06
 * Consigna: Ingresar un número por teclado y escribir si cumple o no las siguientes condiciones: sea par, entre 1 y 25 o 75 y 100.
 * Fecha: 2023/05/26
 */

#include <iostream>

using namespace std;

bool isEven(int num)
{
    return num % 2 == 0;
}

bool isBetween(int init, int limit, int num)
{
    return (num >= init && num <= limit);
}

int main()
{
    int number;
    cout << "Enter a integer number >";
    cin >> number;

    if (isEven(number) and (isBetween(1, 25, number) || isBetween(75, 100, number)))
    {
        cout << "The number is even and It's 1 between 25 or 75 and 100." << endl;
    }
    else if (isEven(number))
    {
        cout << "The number is even only!" << endl;
    }
    else if (isBetween(1, 25, number))
    {
        cout << "The number is between 1 and 25 only." << endl;
    }
    else (isBetween(75, 100, number))
    {
        cout << "The number is between 75 and 100 only." << endl;
    }
    else
    {
        cout << "It's only a number..." << endl;
    }

    return 0;
}