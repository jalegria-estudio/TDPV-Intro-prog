/**
 * Introducción a C++.
 * Practica Unidad 3 - Actividad 05
 * Consigna: Generar un número al azar del 1 al 5 e y mostrar en pantalla su valor ordinal: 1: primero, 2: segundo, 3: tercero, 4: cuarto, 5:quinto
 * Fecha: 2023/05/26
 */

#include <iostream>

using namespace std;

int getRandomNum(int init, int limit)
{
    srand(time(nullptr));

    return (rand()%(limit - init)) + init;
}

int main()
{
    int number = getRandomNum(1, 6);
    string ordinal;

    switch (number)
    {
        case 1:
            ordinal = "first";
            break;

        case 2:
            ordinal = "second";
            break;
        
        case 3:
            ordinal = "third";
            break;
        
        case 4:
            ordinal = "forth";
            break;
        
        case 5:
            ordinal = "fifth";
            break;
    
        default:
            ordinal = "unknown";
            break;
    }

    cout<<"The number is " << number <<" and the ordinal is " << ordinal << endl;

    return 0;
}