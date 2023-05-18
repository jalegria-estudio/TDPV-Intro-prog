/**
* Introducción a C++.
* Practica Unidad 2 - Actividad 12.
* Consigna: 
*   Ingresar un número entero y decir si es mayor o menor a 100 informando con 1 o 0 (Spoiler, no usar estructura IF).
*   ======================
*   Ingrese numero del 1 al 100 =>>>>>> WTF(?)
*   Su numero es mayor al 100?: <1 o 0>
*   ======================
* Fecha: 2023/05/17
*/
#include <iostream>
using namespace std;

int main()
{
    int number;
    cout<<"Enter a interger number >";
    cin>>number; //Intenta extraer un numero desde el istream, si los primeros chars encontrados son digitos los retorna (truncando) pero si no, retorna 0 al hacer la conversion a int. Si se usa unsigned usa otro patron de conversion. 
    // cout<<"DEBUG >"<<number;

    cout<<"Is your number greather than 100?: "<< (number > 100) <<endl;

    return 0;
}