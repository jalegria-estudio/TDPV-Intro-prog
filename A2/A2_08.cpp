/**
 * Introducción a C++.
 * Practica Unidad 2 - Actividad 8.
 * Consigna:  Mostrar en consola los números del 1 al 10 utilizando una variable para el conteo y actualizando su valor (Spoiler, no usar estructura FOR) 
 *
 * Salida en consola: 
 * 
 * ======================
 *  1 2 3 4 5 6 7 8 9 10
 * ========================
 * Fecha: 2023/05/16
 */

#include <iostream>
using namespace std;

string countRangue(int from, int to)
{
    string rangue = to_string(from) + " ";

    while (from < to){
        rangue += to_string(++from) + " ";
    }

    return rangue;
}

string formatRangue(string rangue)
{
    string output;

    output = "==========================================\n\t" + rangue + "\n==========================================\n";

    return output;
}

int main()
{
    cout<<formatRangue(countRangue(1, 10));

    return 0;
}
