/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 03
 * Consigna: Mostrar la cuenta regresiva del 100 al -100, con paso 1. Es decir: 100, 99, 97, etc..
 * Fecha: 2023/06/01
 */
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    /*
        //ALTERNATIVE:
        int counter = 100;
        while(counter >= -100){
            cout<<counter<<endl;
            counter--;
        }
    */

    for (int i = 100; i >= -100; i--)
    {
        cout << i << endl;
    }

    return 0;
}