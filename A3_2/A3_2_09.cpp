/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 09
 * Consigna: Generar un número al azar entre 1 y 20, y proponer al jugador adivinarlo, se le dan 5 intentos, se le debe informar si es mayor o menor que el número al azar obtenido por la computadora.
 * Fecha: 2023/06/02
 */

#include <iostream>
#include <conio_am.h>

using namespace std;

const int INITIAL_ATTEMPT = 5;

int getRandomNum(int base, int max)
{
    srand(time(nullptr));
    return rand()%(max-base)+base;
}

int main()
{
    printf("Adivina adivinador... What number did I generate?\n");
    int life = INITIAL_ATTEMPT;
    int num = getRandomNum(1,21);
    int input;
    bool winner = false;

    do{
        printf("<-You have %i attemps->\n", life);
        printf("Enter a integer number between 1 and 20. >");
            //procesar el nro
            cin>>input;

            if(input == num) winner = true;
            else if(input > num) printf("My number is smaller than %i...\n", input);
            else printf("My number is bigger than %i...\n\n", input);

        life--;

    }while(life > 0 and !winner);

    textbackground(5); //dependencia de conio_am.h
    if (winner) cout<<"\n\nCONGRATULATION!!! My number was "<<num<<". :D"<<endl;
    else cout<<"Sorry... You lost! My number was "<<num<<". Try again! :/"<<endl;
    normvideo();  //dependencia de conio_am.h

    return 0;
}
