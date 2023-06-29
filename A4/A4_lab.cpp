/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Laboratorio
 * Consigna: Generar un programa que permita ingresar 10 números e indique el mayor y el menor de estos. El resultado debe ser primero el menor y luego el mayor
 *  Ejemplo:
 *      Ingreso: 1 -5 -58 15 157 2 56 19 69 47
 *      Resultado:-58 157
 *  Como venimos trabajando, no mostrar en pantalla ningún otro mensaje salvo el resultado.
 *  Los números deben ser separados por un espacio " ", no importa si el último número tiene un espacio atrás.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/18
 */

#include <iostream>

using namespace std;

int main()
{
    int min, max, value;

    for (size_t i = 0; i < 10; i++)
    {
        cin >> value;

        if (i == 0)
            min = max = value;

        if (value > max)
            max = value;
        else if (value < min)
            min = value;
    }

    printf("%i %i", min, max);

    return 0;
}
