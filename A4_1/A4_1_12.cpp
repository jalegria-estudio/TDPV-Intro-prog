/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 12
 * Consigna: Genere dos arreglos con 20 valores al azar entre 1 y 10.
 * Genere un tercer arreglo que sea el resultado de la suma de ambos arreglos. La suma de vectores es elemento a elemento, ejemplo: [5, 8, 4, 2] y [3, 4, 2, 9] → [5+3, 8+4, 4+2, 2+9] → [8, 12, 6, 11]
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */
#include <iostream>
#include "../libs/libtools.hpp" //biblioteca propia, ver carpeta: /libs/, tiene que estar dps del include de iostream

using namespace std;

void fillArray(int *arr, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = libtools::grandnum(1, 11);
    }
}

void equalArrays(int *arr1, int *arr2, int *target, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        target[i] = arr1[i] + arr2[i];
    }
}

void showArray(int *arr, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    
    cout<<endl;
}


int main()
{
    const size_t SIZE = 20;
    int arr1[SIZE]{};
    int arr2[SIZE]{};
    int arrEqual[SIZE]{};

    fillArray(arr1, SIZE);
    fillArray(arr2, SIZE);

    equalArrays(arr1, arr2, arrEqual, SIZE);

    cout<<"array 1: ";
    showArray(arr1, SIZE);
    cout<<"array 2: ";
    showArray(arr2, SIZE);
    cout<<"array-suma: ";
    showArray(arrEqual, SIZE);

    return 0;
}
