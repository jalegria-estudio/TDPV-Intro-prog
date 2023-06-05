/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 06
 * Consigna: Ingresar un nombre y decir que longitud tiene. Ejmplo: Luis, 4. El programa debe finalizar cuando se presiona Enter (Ayuda, el Enter es la tecla ASCII 13).
 * Fecha: 2023/06/02
 */

#include <iostream>
// #include <ncurses.h> // g++ -o A3_2_06.app ./A3_2_06.cpp -lncurses -Wall
#include <conio.h>

using namespace std;


const int KEY_ENTER = 10; //return

int main()
{
    char input;
    string word;

    cout << "Enter a word to get its size or press enter exit. >";

    while(true)
    {
        if(kbhit()){
            input = getchar(); 
            //printf("CHAR:%c INT: %i HEX: %x", input, input, input); //DEBUG
            if(KEY_ENTER == input){
                break;
            }else{
                word += input;
                cout<<input;

            }
        }

    }

    cout <<"\n\r" <<word << " has " << size(word) << " letters."<<endl;

    return 0;
}