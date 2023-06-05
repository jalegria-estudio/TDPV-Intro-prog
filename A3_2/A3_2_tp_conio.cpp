/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Laboratorio
 * Consigna: El juego debe esperar ingresar de 1 a 10 monedas. Luego permitir tirar la palanca n veces (n es la cantidad de monedas ingresadas).
 * La palanca se tira con la letra P. La tirada representa generar 3 valores entre 1 y 3, si los 3 valores son iguales se cuenta como ganada esa tirada.
 * Al final de las n tiradas debe decir cuántas veces ganó.
 * Fecha: 2023/06/03
 */
#include <iostream>
#include <limits>
#include <conio_am.h>

using namespace std;

constexpr auto MAX_SIZE = std::numeric_limits<std::streamsize>::max(); //- max_size =>fué obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>
const int REEL_QUANTITY = 3;
const string MSG_TITLE = "***SLOT-MACHINE***";
const string MSG_INSTRUCTIONS = "-INTRUCTIONS-\n- Press <p> key to insert a gambling credit and spin the reels.\n- Press <q> key to quit and exit game.\n- Press <i> key to read this instructions again.";
const string MSG_PAYTABLE = "$PAY TABLE$\n-Three (ONEs): Win 1 coin.\n-Three (TWOs): Win 2 coins;\n-Three (THREEs): Win 3 coins\n-Three (ZEROs): Tilt! Lose 1 coin.";
const string MSG_OPTIONS = "Press a key to <p> play, <q> quit or <i> read instructions. >";
const string MSG_OPTIONS_ERROR = "Oops! That option doesn't exist... Please try again.";
const string MSG_COINS = "Insert between 1 to 10 coins in the slot-machine >";
const string MSG_COINS_ERROR = "Oops! Maybe your coins are fake. Please try again.";
const char * MSG_COINS_PAYOUT = "You won %i coins!";
const string MSG_TILT_FAILURE = "OMG! Something was wrong... The slot-machine is tilt!!! You lose an additional credit.";
const char* MSG_GRETTINGS = "\nGAME OVER! You won %i times and slot-machine tilts %i times. You've %i coins. Thanks for playing!\n";
const string CODE_TILT_FAILURE = "000";
const int TILT_PROBABILITY = 4;

/**
 * Get random number between a rangue.
 * int base - base number included.
 * int limit - limit number not included.
 *
 * return int - random number
 */
int getRandNum(int base, int limit)
{
    srand(time(nullptr) + rand()); // Sumo el rand() para generar mas entropia al seed entre llamadas recursivas.

    return rand() % (limit - base) + base;
}

/**
 * Read input for get credits (coins) between 1 and 10.
 * Note: This function will loop until the user provides valid input, close the game or turns-off their computer.
 */
int readCoinSlot()
{
    int coins{};

    do
    {
        cout << MSG_COINS;
        cin >> coins;

        /**
         * C++  Input/output library std::basic_ios
         * Note: std:cin is a std:istream => std::basic_istream.
         *
         * bool fail() const; => checks if an error has occurred. Specifically, returns true if badbit or failbit is set in rdstate().
         * Returns true if an error has occurred on the associated stream.
         *
         * void clear( std::ios_base::iostate state = std::ios_base::goodbit ); => modifies state flags. Sets the stream error state flags by assigning them the value of state. By default, assigns std::ios_base::goodbit which has the effect of clearing all error state flags.
         * Parameters
         *   state	-	new error state flags setting. It can be a combination of the following constants:
         *   Constant	Explanation
         *   goodbit	no error
         *   badbit	irrecoverable stream error
         *   failbit	input/output operation failed (formatting or extraction error)
         *   eofbit	associated input sequence has reached end-of-file
         *
         * basic_istream& ignore( std::streamsize count = 1, int_type delim = Traits::eof() )=>Extracts and discards characters from the input stream until and including delim (until the given character is found).
         * Parameters
         *      count 	- 	number of characters to extract
         *      delim 	- 	delimiting character to stop the extraction at. It is also extracted.
         *
         * Source: C++ Reference.
         */
        if (!cin || cin.fail()){ //Chequea si el cin esta en failure mode. Mas info en: A3_2_10.cpp
            cin.clear();
        }

        cin.ignore(MAX_SIZE, '\n');//Descarta lo que queda en el buffer stream

        if (coins < 1 || coins > 10)
        {
            textbackground(4);
            cout << MSG_COINS_ERROR << endl;
            normvideo();
            coins = false;
        }

    } while (!coins);

    return coins;
}

/**
 * Read input to get a option selected.
 * Note: This function will loop until the user provides valid input, close the game or turns-off their computer.
*/
char readOption()
{
    char option{};

    do
    {
        cout << MSG_OPTIONS;
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
        }

        cin.ignore(MAX_SIZE, '\n');

        switch (option)
        {
            case 'p':
            case 'q':
            case 'i':
                break;
            default:
                textbackground(4);
                cout << MSG_OPTIONS_ERROR << endl;
                normvideo();
                option = false;
                break;
        }

    } while (option == false);

    return option;
}

/**
 * Show result of rafle slot-machine's reels.
*/
void printPayline(string payline)
{
    textbackground(COLORS::MAGENTA);
    for (int i = 0; i < REEL_QUANTITY; i++)
    {
        cout << payline[i] << " ";
    }
    normvideo();
}

/**
 * Spin a reel to get a number between 1 and 3.
 */
int spinReel()
{
    return getRandNum(1, 4);
}

/**
 * Emulate a random failure of slot-machine:
 * Tilt's Conditions: Tilt Conditions: payline is a winner line (all symbols are equal) and the first symbol or number is equal to a random number (1:TILT_PROBABILITY).
*/
bool hasTiltFailure(string payline){
    bool payload{false};
    char prevSymbol{payline[0]};

    //Chequeo si los simbolos de los reels son iguales
    for (char i : payline){
        payload = (prevSymbol == i);

        if(!payload) return false;
    }

    //return prevSymbol == to_string(1)[0]; //only DEBUG

    return prevSymbol == to_string(getRandNum(1, TILT_PROBABILITY))[0]; //Para comparar char con char

}

/**
 * Spin all reel of slot-machine.
 * return string - Payline winning combination number.
*/
string raffleReels()
{
    string payline{};

    for (int i = 0; i < REEL_QUANTITY; i++)
    {
        payline += to_string(spinReel()); //casteo para que no guarde payline con salida en octal(? ej"\002\001\002") sino como un conjunto de chars
    }

    if(hasTiltFailure(payline)){
        payline = CODE_TILT_FAILURE;
    }

    return payline;
}

/**
 * Payout Tablet of slot-machine: returns how many coins get from payline (symbols combinations).
*/
int getPayout(string payline)
{
    int payout;

    if (payline == "111")
        payout = 1;
    else if (payline == "222")
        payout = 2;
    else if (payline == "333")
        payout = 3;
    else if (payline == CODE_TILT_FAILURE)
        payout = -1;
    else
        payout = 0;

    return payout;
}

/**
 * Spin three reels for gambling a chance on slot-machine.
 * return int - quantity credits (coins) player win.
 */
int gambling()
{
    string payline{};

    payline = raffleReels();
    printPayline(payline);

    return getPayout(payline);
}

int main()
{
    /**
     * C++ offers a variety of notations for expressing initialization, such as the = used above, and a universal form based on curly-brace-delimited initializer lists:
     *   double d1 = 2.3;
     *   double d2 {2.3};
     * The = form is traditional and dates back to C, but if in doubt, use the general {}-list form.
     * If nothing else, it saves you from conversions that lose information:
     *   int i1 = 7.2; // i1 becomes 7
     *   int i2 {7.2}; // error: floating-point to integer conversion
     *   int i3 = {7.2}; // error: floating-point to integer conversion (the = is redundant)
     * Source: the C++ programming language Handbook.
     */

    int coins{};
    int wins{};
    int tilts{};
    int payout{};
    string msg{};
    char option{};

    clrscr();
    textbackground(COLORS::CYAN);
    cout << MSG_TITLE << endl<<endl;
    normvideo();

    coins = readCoinSlot();

    while (coins > 0 && option != 'q')
    {
        printf("\n\nCredits: %i.\n", coins);
        option = readOption();
       
        switch (option)
        {
            case 'p':
                coins--;
                payout = gambling();

                if(payout>0){
                    wins++;
                    textcolor(COLORS::YELLOW);
                    printf(MSG_COINS_PAYOUT, payout); //Ahorra codigo => msg = MSG_COINS_PAYOUT; msg.replace(msg.find_first_of('%'), 2, to_string(payout)); =>Se debe pasar const string a char* (array de chars).
                    normvideo();

                }else if(payout < 0){
                    tilts++;
                    textcolor(COLORS::LIGHTRED);
                    cout<<MSG_TILT_FAILURE<<endl;
                    normvideo();
                    if(coins == 0) payout = 0; //para no descontar menos que cero.
                }
                coins += payout;
                break;

            case 'i':
                textbackground(COLORS::GREEN);
                cout<<endl << MSG_INSTRUCTIONS << endl<<endl<< MSG_PAYTABLE;
                normvideo();
                break;

            default:
                break;
        }

    }

    textbackground(COLORS::CYAN);
    printf(MSG_GRETTINGS, wins, tilts, coins);

    return 0;
}