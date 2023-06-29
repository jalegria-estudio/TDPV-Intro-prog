/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 13 -Autovaluable
 * Consigna: Juego 7 y 1/2.
 * En este juego de cartas al jugador se le reparten cartas mientras no se pase de 7 y 1/2. 
 * El objetivo es acercarse a 7 y medio sin pasarse. Cada carta vale su valor, 
 * las figuras valen 1/2 y se juega con un mazo de 40 cartas (es decir, sin 8 ni 9, ni comodines).
 * Ejemplo:
 *    Sale un 3, acumula 3. Pide otra carta.
 *    Sale un 10, acumula 3 y 1/2. Pide otra carta. 
 *    Sale un 11, acumula 4.
 *    Etcétera.
 *    Si el jugador decide plantarse antes de pasarse de 7 y 1/2, juega la Computadora que hace lo mismo.
 *    Si la computadora empata o le gana al jugador, entonces la PC es quien gana.
 * Contemplaciones:
 * -No hace falta que hagan el juego de la computadora,
 *    si hacen que un juegador saque 7 ½ hasta quedarse o plantarse y mostrar lo que sacó, está bien.
 * -No hace falta que digan de qué palo es la carta, pero tengan en cuenta que una vez que se sacan una carta,
 *    esa ya está en el mazo (pueden marcar el mazo o contar los índices).
 * -No hace falta que la partida sea eterna, puede hacerse 1 sola vez, 
 *    aunque si la hacen hasta que el juegador decida dejar de jugar, mejor.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/18
 */

#include <iostream>
#include <limits>
//Para incluir al compilar usar: g++ ./A4_1_13.cpp -o A4_1_13.app -Wall -I ../libs/
#include <libtools.hpp> //biblioteca propia, ver carpeta: /libs/, tiene que estar dps del include de iostream.
//#include "../libs/libtools.hpp" //FOR DEBBUGER ONLY


using namespace std;

/* MESSAGES */
const string MSG_TITLE = "********************************\n\t JUEGO 7 Y 1/2 \n********************************\n";
const string MSG_NEW_GAME = "\n*** [NEW GAME] ***\n";
const string MSG_CONTINUE = "Press <enter> key to continue.";
const string MSG_STOP_QUESTION = "\nDo you want continue or stop? Press <q> to quit. Press <c> to continue. Press <s> to stop. >";
const string MSG_WHO_WIN = "\n***** Who win? *****\n";
const char* MSG_PLAYER_LOST = "Game Over! You lost! Your score is %.1f.";
const char* MSG_PLAYER_WIN = "Congratulation! You win! Your score is %.1f.";
const char* MSG_PLAYER_SCORE = "Your score is: %.1f";
const string MSG_PLAYER_MAX_CORE = "(!) Great! You get 7 and 1/2!!!!!";
const string MSG_PLAYER_BUST = "(!) Your busted!";
const char* MSG_COMPUTER_SCORE = "Computer's score is: %.1f";
const string MSG_COMPUTER_TURN = "* Now It's computer's turn...! *";

/*UTILS*/
const char OPTIONS_AVAILABLE[]{'c','s','q'};
constexpr auto MAX_SIZE = std::numeric_limits<std::streamsize>::max(); //- max_size =>fue obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>

/*GAME*/
const string SUIT[]{"oro", "espada", "copa", "basto"};
const string SUIT_NUMBER[]{"1", "2", "3", "4", "5", "6", "7", "10", "11", "12"};
const double MAX_SCORE = 7.5;
const int STATUS_LOST = 0;
const int STATUS_WIN = 1;
const int STATUC_STUCK = 2;

/**** FUNCTIONS ****/
/* LOW LEVEL */
bool in_array(auto *arr, size_t size, auto target){

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return true;
    }
    
    return false;
}

void showArray(auto *arr, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    
    cout<<"\n\r";
}

/**
 * This function generates a random number between base and limit (not include) numbers.
 */
int grandnum(int base, int limit){
    std::srand(time(nullptr)+std::rand());

     return std::rand()%(limit - base) + base;
 }

/* GAME ELEMENTS */
void discardCard(bool deck[][10], int card[]){
    deck[card[0]][card[1]] = true;
}

void getCard(bool deck[][10], int *card){
    int suit, value;

    do
    {
        suit = libtools::grandnum(0,4);
        value = libtools::grandnum(0,10);
    } while (deck[suit][value]);//si esta en el mazo como true, quiere decir que ya fue sacada

    card[0] = suit;
    card[1] = value;
    discardCard(deck, card);
}

void showCard(int *card){
    cout<<"<"<<SUIT_NUMBER[card[1]]<<" de "<<SUIT[card[0]]<<">\n\r";
}

double getCardScore(int *card){
    switch(card[1]){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6: //equivale a 1,2,3,4,5,6,7 en nro de carta
            return card[1]+1;
        case 7:
        case 8:
        case 9:
            return 0.5;
        default:
            return 0.0;
    }
}

/**
 * Passing two dimensional array to a C++ function
 * C++ does not allow to pass an entire array as an argument to a function. 
 * However, You can pass a pointer to an array by specifying the array's name without an index.
 * There are three ways to pass a 2D array to a function:
 *
 *    - Specify the size of columns of 2D array:
 *        void processArr(int a[][10]) {  // Do something }
 *
 *    - Pass array containing pointers:
 *        void processArr(int *a[10]) {  // Do Something  }
 *
 *        // When callingint *array[10];
 *        for(int i = 0; i < 10; i++){
 *            array[i] = new int[10];
 *        }
 *        processArr(array);
 *
 *    - Pass a pointer to a pointer:
 *        void processArr(int **a) {  // Do Something  }
 *
 *        // When calling:
 *        int **array;
 *        array = new int *[10];
 *        for(int i = 0; i <10; i++){
 *            array[i] = new int[10];
 *        }
 *        processArr(array);
 *
 *    Source: https://www.tutorialspoint.com/Passing-two-dimensional-array-to-a-Cplusplus-function
*/
void showDeck(bool deck[4][10]){
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            cout<< deck[i][j]<<" ";
        }
        cout<<"\n\r";
    }
}

void resetDeck(bool deck[4][10]){
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            deck[i][j] = false;
        }
    }
}

/* UI */
void confirmContinue(){
    cout<<MSG_CONTINUE;
    cin.ignore(MAX_SIZE, '\n');//limpia el buffer basura.
}

void showTitle(){
    cout<<MSG_TITLE;
}

void showNewGame(){
    cout<<MSG_NEW_GAME;
    //confirmContinue();
}

void showEndGame(double scorePlayer, double scoreComputer){
    cout<<MSG_WHO_WIN;
    if( scorePlayer <= MAX_SCORE && (scorePlayer > scoreComputer || scoreComputer > MAX_SCORE)
    ){
        printf(MSG_PLAYER_WIN, scorePlayer);
        cout<<"\n\r";
        printf(MSG_COMPUTER_SCORE, scoreComputer);

    }else if(scorePlayer > MAX_SCORE){
        printf(MSG_PLAYER_LOST, scorePlayer);

    }else{
        printf(MSG_PLAYER_LOST, scorePlayer);
        cout<<"\n\r";
        printf(MSG_COMPUTER_SCORE, scoreComputer);
    }

    cout<<"\n\r--------------------------\n\r";
    confirmContinue();
}

char readOption(){
    char option{};

    //Basado en el ejemplo del uso de clear(): https://en.cppreference.com/w/cpp/io/basic_ios/clear
    while ( (cout<<MSG_STOP_QUESTION &&
           !(std::cin>>option)) ||
           !in_array(OPTIONS_AVAILABLE, size(OPTIONS_AVAILABLE), option)
    ){
        std::cin.clear();
        string line;
        std::cin>>line;//limpia el buffer de entrada ya que toma el resto del buffer que quedo.
        cout<<"This option "<<option+line<<" doesn't exist!\n";
    }

    cin.ignore(MAX_SIZE, '\n');//limpia el buffer basura.

    return option;
}

//para emular una estrategia basica
double getComputerStrategy(double scorePlayer, double firstScore){
    double strategyScore{};
    //Los jugadores deben apostar antes de recibir su primera carta, que se reparte boca abajo.
    int minSearchedScore = scorePlayer - firstScore;

    //Si se obtiene 7 y 1/2 o se pasa el jugador debe mostrar su carta boca-abajo. La computadora debe ir a buscar un 7.5 para no perder.
    if(scorePlayer == MAX_SCORE) strategyScore = MAX_SCORE;
    //Sino la computadora tiene que ir a buscar un nro tentativo alto, si las cartas en mesa del jugador son mayor igual a 6, significa que tiene un valor menor 7.5 pero mas grande que seis, la computadora tiene que conseguir un nro mayor a las cartas en mesa para ganar
    else if (minSearchedScore >= 6 ) strategyScore = 6.5;
    //Si hay mesa un nro muy bajo puede ser tenga una carta alta o no en mano, la computadora intentara buscar un nro alto entre mayor o igual 6.
    else if (minSearchedScore < 3) strategyScore = libtools::grandnum(6, 8);
    //Para simplificar: busque un nro aceptable
    else strategyScore = libtools::grandnum(5, 8);

    //cout<<"strategyScore: "<<strategyScore<<endl; //DEBUG ONLY

    return strategyScore;
}

/* MAIN */
int main()
{
    bool deck[4][10]{};
    int card[2]{};
    char option{};
    double scorePlayer{0.0};
    double scoreComputer{0.0};
    double firstScore{0.0};

    showTitle();

    //MAIN LOOP
    while (true)
    {
        showNewGame();
        //RESET VARS
        resetDeck(deck);
        scorePlayer = 0.0;
        scoreComputer = 0.0;
        firstScore = 0.0;

        //PLAYER GAME
        do
        {
            getCard(deck, card);
            showCard(card);
            //IA
            if(scorePlayer == 0.0) firstScore = getCardScore(card);

            scorePlayer += getCardScore(card);
            printf(MSG_PLAYER_SCORE, scorePlayer);
            cout<<"\n\r";

            if(scorePlayer > MAX_SCORE){
                cout<<MSG_PLAYER_BUST<<"\n\r";
                confirmContinue();
                break;
            }else if(scorePlayer == MAX_SCORE){
                cout<<MSG_PLAYER_MAX_CORE<<"\n\r";
                confirmContinue();
                break;
            }
            option = readOption();
        } while (option == 'c');

        //BRIGDE
        if(option == 'q'){
            exit(EXIT_SUCCESS);
        }else if(option == 's' || scorePlayer == MAX_SCORE){
            cout<<"\n\r"<<MSG_COMPUTER_TURN<<"\n\r";
            confirmContinue();
        }

        //COMPUTER GAME
        while( scorePlayer <= MAX_SCORE && scoreComputer < MAX_SCORE  && scoreComputer < getComputerStrategy(scorePlayer, firstScore)){
            getCard(deck, card);
            discardCard(deck, card);
            showCard(card);
            scoreComputer += getCardScore(card);
        }
        
        if(scoreComputer > 0.0){//No hace falta mostrar puntaje final del juego de la computadora
            printf(MSG_COMPUTER_SCORE, scoreComputer);
            cout<<"\n\r";
            confirmContinue();
        }
        cout<<"\n\r";

        //WHO WIN?
        showEndGame(scorePlayer, scoreComputer);
        //showDeck(deck); //DEBUG ONLY

    }//END MAIN LOOP

    return 0;
}

