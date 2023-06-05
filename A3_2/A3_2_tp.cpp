/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Laboratorio
 * Consigna: El juego debe esperar ingresar de 1 a 10 monedas. Luego permitir tirar la palanca n veces (n es la cantidad de monedas ingresadas).
 * La palanca se tira con la letra P. La tirada representa generar 3 valores entre 1 y 3, si los 3 valores son iguales se cuenta como ganada esa tirada.
 * Al final de las n tiradas debe decir cuántas veces ganó.
 * Alumno: Juan P. Alegria
 * Fecha: 2023/06/03
 */
#include <iostream>
#include <limits>

using namespace std;

constexpr auto MAX_SIZE = std::numeric_limits<std::streamsize>::max(); //- max_size =>fué obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>
const int REEL_QUANTITY = 3;
const string CODE_TILT_FAILURE = "000";
const int TILT_PROBABILITY = 4;

const string MSG_TITLE = "***SLOT-MACHINE***";
const string MSG_INSTRUCTIONS = "-INTRUCTIONS-\n- Press <p> key to insert a gambling credit and spin the reels.\n- Press <q> key to quit and exit game.\n- Press <i> key to read this instructions again.";
const string MSG_PAYTABLE = "$PAY TABLE$\n-Three (ONEs): Win 1 coin.\n-Three (TWOs): Win 2 coins;\n-Three (THREEs): Win 3 coins\n-Three (ZEROs): Tilt! Lose 1 coin.";
const string MSG_OPTIONS = "Press a key to <p> play, <q> quit or <i> read instructions. >";
const string MSG_OPTIONS_ERROR = "Oops! That option doesn't exist... Please try again.";
const string MSG_COINS = "Insert between 1 to 10 coins in the slot-machine >";
const string MSG_COINS_ERROR = "Oops! Maybe your coins are fake. Please try again.";
const char *MSG_COINS_PAYOUT = "You won %i coins!";
const string MSG_TILT_FAILURE = "OMG! Something was wrong... The slot-machine is tilt!!! You lose an additional credit.";
const char *MSG_GRETTINGS = "\n\nGAME OVER! You won %i times and slot-machine tilts %i times. You've %i coins.\nThanks for playing!\n";

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

        if (!cin || cin.fail())
        { // Chequea si el cin esta en failure mode. Mas info en: A3_2_10.cpp
            cin.clear();
        }

        cin.ignore(MAX_SIZE, '\n'); // Descarta lo que queda en el buffer stream

        if (coins < 1 || coins > 10)
        {
            cout << MSG_COINS_ERROR << endl;
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
            cout << MSG_OPTIONS_ERROR << endl;
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
    for (int i = 0; i < REEL_QUANTITY; i++)
    {
        cout << payline[i] << " ";
    }
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
bool hasTiltFailure(string payline)
{
    bool payload{false};
    char prevSymbol{payline[0]};

    // Chequeo si los simbolos de los reels son iguales
    for (char i : payline)
    {
        payload = (prevSymbol == i);

        if (!payload)
            return false;
    }

    return prevSymbol == to_string(getRandNum(1, TILT_PROBABILITY))[0]; // Para comparar char con char
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
        payline += to_string(spinReel()); // casteo para que no guarde payline con salida en octal(? ej"\002\001\002") sino como un conjunto de chars
    }

    if (hasTiltFailure(payline))
    {
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

/**
 * Main
 */
int main()
{
    int coins{};
    int wins{};
    int tilts{};
    int payout{};
    char option{};
    string msg{};

    cout << MSG_TITLE << endl;
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

            if (payout > 0)
            {
                wins++;
                printf(MSG_COINS_PAYOUT, payout); // Ahorra codigo => msg = MSG_COINS_PAYOUT; msg.replace(msg.find_first_of('%'), 2, to_string(payout)); =>Se debe pasar const string a char* (array de chars).
            }
            else if (payout < 0)
            {
                tilts++;
                cout << MSG_TILT_FAILURE << endl;
                if (coins == 0)
                    payout = 0; // para no descontar menos que cero.
            }
            coins += payout;
            break;

        case 'i':
            cout << endl
                 << MSG_INSTRUCTIONS << endl
                 << endl
                 << MSG_PAYTABLE << endl;
            break;

        default:
            break;
        }
    }

    printf(MSG_GRETTINGS, wins, tilts, coins);

    return 0;
}