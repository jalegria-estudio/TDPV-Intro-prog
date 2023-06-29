/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 8
 * Consigna: Realiza un arreglo que al recorrerlo por fila y columna muestre en pantalla la siguiente grilla:
 * 0 1 2 3 4 5
 * 0 1 2 3 4 5
 * 0 1 2 3 4 5
 * 0 1 2 3 4 5
 * 0 1 2 3 4 5
 * 0 1 2 3 4 5
 * Deben usarse sólo los indices de la estructura para llenar el arreglo.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/18
 */

#include <iostream>

using namespace std;

int main()
{
    size_t size = 6;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout<<j<<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}
