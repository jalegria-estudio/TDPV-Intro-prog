/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Laboratorio
 * Consigna: Generar un programa que permita ingresar 2 números, valorReferencia y n y que muestre los n siguientes números a partir del valorReferencia.
 *    Ejemplo:
 *        Ingreso: 
 *            - valorReferencia: 100
 *            - n: 5 
 *        Resultado: 100 101 102 103 104
 *        
 *        Ingreso: 
 *            - valorReferencia: 7 
 *            - n: 10 
 *        Resultado:7 8 9 10 11 12 13 14 15 16
 * Fecha: 2023/06/04
 */
#include <iostream>

using namespace std;

int main(){
    int refNum{};
    int steps{};

    cin>>refNum;
    cin>>steps;

    for (int i = 0; i < steps; i++)
    {
        cout<<refNum+i<<" ";
    }
    
}