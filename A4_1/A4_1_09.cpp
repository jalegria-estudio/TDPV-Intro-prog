/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 9
 * Consigna: Realiza un arreglo que al recorrerlo por fila y columna muestre en pantalla la siguiente grilla:
 * 0 0 0 0 0 0
 * 1 1 1 1 1 1
 * 2 2 2 2 2 2
 * 3 3 3 3 3 3
 * 4 4 4 4 4 4
 * 5 5 5 5 5 5
 * Deben usarse sólo los indices de la estructura para llenar el arreglo.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */

#include <iostream>

using namespace std;

int main()
{
    const size_t SIZE = 6;

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
