/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 10
 * Consigna: Generar un número al azar entre 1 y 20 y proponer al jugador adivinarlo ingresando números que se acerquen al número dado por la computadora.
 *  En el primer intento se le debe informar si es mayor o menor que el número al azar obtenido por la computadora.
 *  A partir del segundo intento debe decir caliente o frío si el número ingresado está más cerca, misma distancia o más lejos del número a adivinar (comparado con el número anterior).
 *  Ej:
 *      Número a adivinar 15. 
 *      Ingresa 10. Informar menor (está a 5 de distancia del 15)
 *      Ingresa el 12, informar caliente (está a 3 de distancia del 15, y 3 es menor que 5)
 *      Ingresa 9, informar frío (está a 6 de distancia del 15, y 6 es mayor que 3 -> distancia del 12 al 15).
 * Fecha: 2023/06/03
 */

#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <conio_am.h>

using namespace std;

const int INITIAL_ATTEMPT = 5;
constexpr auto MAX_SIZE = std::numeric_limits<std::streamsize>::max(); //- max_size =>fué obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>

const string MSG_WINNER = "Congratulation!!! Your win! The number was %n.";
const string MSG_LOSER = "Sorry... You've 0 attemps... Game over! The number was %n.";
const string MSG_MINOR_THAN = "Your number <%n> is minor than my number...";
const string MSG_BIGGER_THAN = "Your number <%n> is bigger than my number...";
const string MSG_WARN = "Warn! :P";
const string MSG_COLD = "Cold! :S";




int getRandomNum(int base, int limit){

    srand(time(nullptr));
    
    return (rand()%(limit-base)) + base;
}

bool isInt(string num){

    for(auto c : num){
        if(!isdigit(c)){
            return false;
        }
    }

    return true;
}

void cleanBuffer()
{
    cin.ignore(MAX_SIZE, '\n');//Limpia el buffer stream in porque queda '\n' y salta la funcion; Ojo! con llamar está función sin haber llamado previamente a cin>>XX, queda a la espera.
}

int calculateDistance(int center, int position)
{
    int distance = center - position;

    if( distance < 0){
        distance = -distance;
    }

    return distance;
}

int readInputNum(){
    int input{};

    printf("Enter a integer number between 1 and 20 >");
    cin>>input;


    /**
     * Error-handler for invalid input in std:::cin
     * When cin is waiting a double or int and the user enters a char like 'a', that character is placed in the buffer.
     * Then operator>> tries to extract ‘a’ to variable x, which is of type double. Since ‘a’ can’t be converted to a double, operator>> can’t do the extraction. 
     * Two things happen at this point: 
     *  1. ‘a’ is left in the buffer.
     *  2. std::cin goes into “failure mode”.
     * 
     * Once in “failure mode”, future requests for input extraction will silently fail.
     * Thus in our programs, the output prompts still print, but any requests for further extraction are ignored.
     * This means that instead waiting for us to enter an operation, the input prompt is skipped, and we get stuck in an infinite loop because there is no way to reach one of the valid cases.
     * 
     * Soruce and More info: https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
    */
    //My Error-Handler for std::cin
    if(!cin || cin.fail()){
        cin.clear();
    }

    if(!isInt(to_string(input)) or input < 1 or input > 20){
        input = false;
    }

    //wrapper para cin.ignore();
    cleanBuffer(); //stdcin-and-handling-invalid-input: In the above case, std::cin goes immediately into “failure mode”, but also assigns the closest in-range value to the variable. Consequently, the var is left with the assigned value of 32767. Additional inputs are skipped, leaving other vars with the initialized value of 0.

    return input;
}


int main()
{
    int number = getRandomNum(1, 21);
    int previousInput{};
    int life = INITIAL_ATTEMPT;
    bool winner = false;
    string msg, clue;
    number=15;

    textbackground(COLORS::MAGENTA);
    printf("Adivina adivinador II... What number did I generate?\n");

    while (life > 0){ //MAIN LOOP
        cout<<"<You have "<<life<<" attemps yet.>"<<endl;
        int input = readInputNum();

        if(input == 0){
            cout<<"Oops! Your input is invalid. Please try again.\n"<<endl;
            continue;
        }

        if(input == number){
            winner = true;
            break;
        }

        if(previousInput != 0){
            //warn o cold
            int previousDistance = calculateDistance(number, previousInput);
            int currentDistance = calculateDistance(number, input);

            if(currentDistance < previousDistance){
                clue = MSG_WARN;
            }else{
                clue = MSG_COLD;
            }

        }else if( number < input){
            clue = MSG_BIGGER_THAN;
            clue.replace(clue.find_first_of('%'), 2, to_string(input));

        }else{
            clue = MSG_MINOR_THAN;
            clue.replace(clue.find_first_of('%'), 2, to_string(input));
        }

        cout<<clue<<endl;
        life--;
        previousInput = input;
    }

    if(winner){
        msg = MSG_WINNER;
        msg.replace(msg.find_first_of('%'), 2, to_string(number));

    }else{
        msg = MSG_LOSER;
        msg.replace(msg.find_first_of('%'), 2, to_string(number));
    }

    textbackground(COLORS::GREEN);
    cout<<msg<<endl;

    return 0;
}
