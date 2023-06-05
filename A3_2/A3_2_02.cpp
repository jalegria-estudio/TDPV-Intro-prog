/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 02
 * Consigna: Mostrar las primeras 10 centenas (10, 20, 30, ... , 100)
 * Fecha: 2023/06/01
 */
#include <iostream>

using namespace std;

int main()
{
    for (int i = 10; i <= 100; i += 10)
    {
        cout << i << endl;
    }

    return 0;
}