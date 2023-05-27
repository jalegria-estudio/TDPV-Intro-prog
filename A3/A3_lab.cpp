/**
 * Introducción a C++.
 * Practica Unidad 3 - Laboratorio
 * Consigna: 
 *  Generar un programa que muestre el mayor de 3 numeros ingresados por consola.
 *    No muestren nada más en pantalla que el resultado ya que el valor esperado es sólo un número. Es decir:
 *
 *    Respuesta como:
 *
 *    "El mayor es el XX" 
 *
 *    "Ingrese un numero: "
 *
 *    Son tomadas como incorrectas. Sólo ingresen 3 números por cin y muestren en consola el mayor de los 3.
 * Fecha: 2023/05/27
 */

#include <iostream>

using namespace std;

int main()
{
    const int MAX_INPUTS = 3;
    int highest, num;

    for(int i=0; i < MAX_INPUTS; ++i){
        cin>>num;
        
        if(i == 0){
            highest = num;
        }else if(highest < num){
            highest = num;
        }
    }
    
    cout<<highest;

    return 0;
}