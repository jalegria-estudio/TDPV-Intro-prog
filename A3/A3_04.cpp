/**
 * Introducción a C++.
 * Practica Unidad 3 - Actividad 04
 * Consigna: Generar un número al azar entre 1 y 20, introducir un número entre 1 y 20, imprimir ambos y decir si es mayor, menor o igual.
 * Fecha: 2023/05/26
 */

#include <iostream>

using namespace std;

int getRandomNumber(int init, int limit)
{
    srand(time(nullptr)); // Genera la seed para el nro aleatorio

    return (rand() % (limit - init)) + init; // limit-init = distancia entre el nro base y el limite. Calculo: se calcula el resto que siempre es mayor o igual a cero y menor a la distancia, dps se suma el nro base para obtener un nro entre el init (incluido) y el limite (no incluido).
}

void readVar(int &ref, string name) // Otra manera de hacer readVar: void readVar(int* ref, string name){ .. cin >> *ref;}, la llamada es: readVar(&number, "integer number");
{
    cout << "Enter " << name << " >";
    cin >> ref;
}

string getResult(int humanNum, int computerNum)
{
    if (computerNum > humanNum)
    {
        return "Computer";
    }
    else if (computerNum < humanNum)
    {
        return "Human";
    }
    else
    {
        return "nobody :S";
    }

}

int main()
{
    int randNumber = getRandomNumber(1, 21);
    int number;
    string result;

    readVar(number, "integer number between 1 and 20");

    if(number < 1 || number >20){
        cout<<"The computer doesn't play with cheater humans... :/\n";
        return 1;
    }

    printf("Your number is %i, the computer number is %i.\n", number, randNumber);

    cout << "The winner is " << getResult(number, randNumber) << endl;

    return 0;
}