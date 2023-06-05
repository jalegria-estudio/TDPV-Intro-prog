/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 07
 * Consigna: Implementar un dado de 6 caras (número al azar de 1 al 6), realizar 10 tiradas.
 * Fecha: 2023/06/02
 */
#include <iostream>

using namespace std;

int rolldice(int type){
    srand(time(nullptr)+rand()); //Sumo rand() para darle mas entropia al seed entre llamadas recursivas

    return rand()%type+1;
}

int main(){
    for(int i=1;i<11;i++){
        printf("D6's Roll #%i: %i\n", i, rolldice(6));
    }

    return 0;
}