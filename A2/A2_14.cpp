/**
* Introducción a C++.
* Practica Unidad 2 - Actividad 14 - Ejercicio Autoevaluable
* Consigna: 
* Pedir al usuario que ingrese un nombre de personaje. El personaje inicia el programa con 10 puntos de vida. 
* El jugador deberá ingresar 3 números del 1 al 10 que serán sus runas.
* Luego de ingresar, el programador (cada uno de uds) deberá realizar un cálculo matemático para actualizar
* el valor de la vida, quitándole a vida el siguiente valor: runa1 – runa2/2 + runa3/2.
* 
* Aquí el programador se podrá tomar la libertad de acomodar las runas como le plazca,
* de manera que el jugador no sabe cuál runa es la que le suma y cuál es la que le resta vida.
* Este cómputo lo deberá hacer dos veces e indicar si la vida está por debajo de cero o no.
* Salida en consola:
* 
* =======================================
*   Ingrese nombre del personaje: ------
*   Su nombre es: <nombre>
*   Sus puntos de vida son <vida>
*   Ingresar primera runa: -------
*   Ingresar segunda runa: -------
*   Ingresar tercera runa: --------
*   Sus puntos de vida son <vida>
*   Sus puntos de vida son <vida>
*   Tu personaje sigue vivo? <1 o 0>
* ===================================
* Fecha: 2023/05/18
*/
#include <iostream>
#include <cmath>
using namespace std;

const string CLI_SEPARATOR = "==========================================\n";

string name;
int hp = 10;
int runes[3];

int getRandomNum(int limit)
{
    /**
     * Defined in header <cstdlib>
     * int rand();
     * Returns a pseudo-random integral value between ​0​ and RAND_MAX (​0​ and RAND_MAX included).
     * std::srand() seeds the pseudo-random number generator used by rand(). If rand() is used before any calls to std::srand(), rand() behaves as if it was seeded with std::srand(1).
     * Each time rand() is seeded with std::srand(), it must produce the same sequence of values on successive calls.
     * Other functions in the standard library may call rand. It is implementation-defined which functions do so.
     * It is implementation-defined whether rand() is thread-safe.
    */
    srand(time(nullptr)+rand()); //le sumo el rand() para generar mas aleatoriedad respecto al llamada anterior de la funcion
    return rand()%limit;
}

int calculateHP(int rune1, int rune2, int rune3)
{
    //cout<<"DEBUG: Calculated power >"<<rune1 - (rune2 / 2.0) + (rune3 / 2.0);
    return hp - ceil(rune1 - (rune2 / 2.0) + (rune3 / 2.0)); //el rondedeo genera mejor disparidad
}

int applyRunesPower(bool simpleMode)
{
    int life;

    if(simpleMode){
        life = calculateHP(runes[2], runes[0], runes[1]);

    }else{
        life = calculateHP(runes[getRandomNum(3)], runes[getRandomNum(3)], runes[getRandomNum(3)]);
    }

    return life;
}

void readDataFor(auto& varDirection, string varName)
{
    cout<<"Enter "<<varName<<" >";
    cin>>varDirection;
}

int main()
{
    cout<<CLI_SEPARATOR;
    readDataFor(name, "Player name");
    cout<<"Your Player name is "<<name<<endl;
    cout<<"Your Hit Points are "<<hp<<endl;
    readDataFor(runes[0], "1st Rune");
    readDataFor(runes[0], "2nd Rune");
    readDataFor(runes[0], "3rd Rune");
    hp = applyRunesPower(0);
    cout<<"Now your HP are "<<hp<<endl;
    hp = applyRunesPower(0);
    cout<<"Now your HP are "<<hp<<endl;
    cout<<"Is it alive? >"<<(hp > 0)<<endl;
    cout<<CLI_SEPARATOR;

}
