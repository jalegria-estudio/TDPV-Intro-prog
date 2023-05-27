/**
* Introducción a C++.
* Practica Unidad 3 - Actividad 02
* Consigna: Recibir un número y escribir en pantalla si es par o impar (resto 0).
* Fecha: 2023/05/26
*/
#include <iostream>

using namespace std;

int main()
{
    int number;

    cout << "Enter a integer number >";
    cin >> number;

    if (number % 2)
    {
        cout << "It's odd number\n";
    }
    else
    {
        cout << "It's even number\n";
    }

    return 0;
}