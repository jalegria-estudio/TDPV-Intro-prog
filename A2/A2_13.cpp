/**
* Introducción a C++.
* Practica Unidad 2 - Actividad 13.
* Consigna: 
*   Ingresar 3 numeros enteros x, y, z e informar por consola la suma de x, el doble de y, todo más el triple de z, dividido 6: ((x + 2*y)+3*z)/6
* Nota: la suma es asociativa => [x + (2*y) + (3*z)]/6
* Fecha: 2023/05/17
*/
#include <iostream>
using namespace std;

/**
 * Practica de punteros
 * >>& "get address to"
 * >>* "direction or point to" => int *direction; direction = &myNumber; cout<<direction; //0x7ffc19964cb4 ; cout<<*direction; // 2;
 * void readValueFor(int& varValue, int *point, string varName) === readValueFor(intX, &intX, "X");
*/
void readValueFor(int& varDirection, string varName) //Paso por referencia sino pasa por valor
{
    cout<<"Enter a integer value for "<<varName<<"\n";
    cin>>varDirection;
}

/**
 * Reglas de conversion aritmetica para c++
 * 
 * When binary operator+ is invoked, it is given two operands, both of type int. Because both operands are of the same type, that type will be used to perform the calculation and to return the result.
 * 
 * The usual arithmetic conversion rules
 * 
 * The usual arithmetic conversion rules are pretty simple. The compiler has a prioritized list of types that looks something like this:
 * 
 *     long double (highest)
 *     double
 *     float
 *     unsigned long long
 *     long long
 *     unsigned long
 *     long
 *     unsigned int
 *     int (lowest)
 * 
 * There are only two rules:
 * 
 *     - If the type of at least one of the operands is on the priority list, the operand with lower priority is converted to the type of the operand with higher priority.
 *     - Otherwise (the type of neither operand is on the list), both operands are numerically promoted.
 * Fuente: https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/
*/
float calculate(int x, int y, int z)
{
    return (x + (2 * y) + (3*z))/6.0;
}

int main()
{
    int iX, iY, iZ;
    //Practica de punteros:
        //int *direX;
        //cout<<"My pointer "<<direX<<endl;
        //cout<<"My value: "<<intX<<endl;
        //direX = &intX;
        //cout<<"My pointer "<<direX<<endl;

    readValueFor(iX, "X");
    readValueFor(iY, "Y");
    readValueFor(iZ, "Z");
    
    // cout<<"DEBUG ValueX>"<<iX<<endl;
    // cout<<"DEBUG ValueY>"<<iY<<endl;
    // cout<<"DEBUG ValueZ>"<<iZ<<endl;

    cout<<"El resultado para calculo de [x + (2*y) + (3*z)]/6 es >"<<calculate(iX, iY, iZ)<<endl;

    //Practica de punteros:
        //cout<<"My value now: "<<intX<<endl;
        //cout<<"My pointer "<<direX<<endl;
        //cout<<"My pointed value "<<*direX<<endl;

    return 0;
}