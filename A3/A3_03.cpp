/**
* Introducción a C++.
* Practica Unidad 3 - Actividad 03
* Consigna: Recibir dos números e indicar cuál es el mayor y cuál es el menor.
* Fecha: 2023/05/26
*/

#include <iostream>

using namespace std;

void readVar(int &ref, string name)
{
    cout << "Enter " << name << " >";
    cin >> ref;
}

int main()
{
    int num1;
    int num2;

    readVar(num1, "First Number");
    readVar(num2, "Second Number");

    if (num1 > num2)
    {
        printf("First Number(%i) is highter than Second Number(%i)\n", num1, num2);
    }
    else if (num1 < num2)
    {
        printf("First Number(%i) is minor than Second Number(%i)\n", num1, num2);
    }
    else
    {
        cout << ("Both numbers are equals!\n");
    }

    return 0;
}