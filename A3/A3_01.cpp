/**
* Introducción a C++.
* Practica Unidad 3 - Actividad 01
* Consigna: Recibir un número y escribir en pantalla si es positivo o negativo
* Fecha: 2023/05/26
*/

#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter a integer number >";
    cin >> number;
   
    if (number > 0)
    {
        cout << "Number is positive!\n";
    }
    else if( number == 0)
    {
        cout << "Number is zero or You didn't enter a number.\n";
    }
    else
    {
        cout << "Number is negative...\n";
    }

    return 0;
}
