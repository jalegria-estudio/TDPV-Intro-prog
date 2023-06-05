/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 04
 * Consigna: Ingresar por teclado números hasta haber mostrado 5 números impares. Luego terminar programa.
 * Fecha: 2023/06/01
 */
#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    int number;
    const int MAX = 5;

    while (counter < MAX)
    {
        cout << "Enter a integer odd number >";
        cin >> number;

        if (number%2 != 0)
        {
            ++counter;
            cout << "Your odd number is " << number << endl;
        }

        printf("You enter (%i) odd numbers!\n", counter);
    }

    return 0;
}