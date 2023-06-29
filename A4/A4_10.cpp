/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 10
 * Consigna: Genere un arreglo con 100 valores al azar (el rango del los valores es a gusto de cada uno). Muestrelo en pantalla y luego inviértalo y vuelta a informarlo.
 *  Ej: [5, 7, 10, 15, 8, 9] → [9, 8, 15, 10, 7, 5]
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */

#include <iostream>
#include "../libs/libtools.hpp"

using namespace std;

void fillArray(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = libtools::grandnum(0, 10);
    }
}

void showArray(int *arr, size_t size){
    int columns = 10;
    int counter = 0;

    for (size_t i = 0; i < size; i++)
    {
        if(counter >= columns){
            counter = 0;
            cout<<endl;
        }

        cout<<arr[i]<< " ";
        counter++;
    }
}

void invertArray(int *arr, int *target, size_t size){
    size_t j{0};

    //recordar size_t no toma valores menores a cero, por eso uso int. Alternativa de corte: j < size;
    for (int i = size-1; i >= 0; i--, j++)
    {
        target[j] = arr[i];
    }
}

int main()
{
    const size_t size = 100;
    int arr[size]{};
    int arrInverted[size]{};
    
    fillArray(arr, size);
    invertArray(arr, arrInverted, size);
    showArray(arr, size);
    cout<<endl<<endl;
    showArray(arrInverted, size);

    return 0;
}
