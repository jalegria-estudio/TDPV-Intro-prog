/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 08
 * Consigna: Ingresar números por teclado hasta haber ingresado 3 números iguales consecutivos. Luego que aparezca la ocurrencia de 3 números consecutivos, cortar. Ejemplo: 1, 2, 7, 7, 5, 3, 2, 9, 9, 9 Finaliza el programa.
 * Fecha: 2023/06/02
 */
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int counter = 0;
    int num, previousNum;

    while (counter < 2)//cortar bucle si se repite
    {
        if(kbhit()){
           num = getchar();

           if(num >='0' and num <='9'){ //detectar char numericos
                if (previousNum != '\000') printf(", "); //Para no imprimir la coma y espacio al final   
                printf("%c", num);

                if(previousNum == num){ //contador
                    counter++;
                }else{
                    counter = 0;
                }

                previousNum = num; //almacena el ultimo nro ingresado
           }
        }
    }
    
    return 0;
}