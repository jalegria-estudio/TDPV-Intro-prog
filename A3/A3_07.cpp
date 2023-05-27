/**
 * Introducción a C++.
 * Practica Unidad 3 - Actividad 07
 * Consigna: 
 * Ingresar un año, mes y día y escribir en pantalla: Usted nació el día: --- de --- de ---- y tiene ---- años. Por ejemplo: 1990, 3, 30. "Usted nació el día: 30 de marzo de 1993 y tiene 33 años".
 *     Importante:
 *         Debe contemplarse:
 * + Que el año no supere el actual
 * + Que el mes exista (entre 1 – 12)
 * + Que el mes tenga esa cantidad correcta de días (enero: 31, febrero 28, marzo 31, etc). No vamos a contemplar años bisiestos.
 * Fecha: 2023/05/26
 */

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

constexpr auto MAX_SIZE = std::numeric_limits<std::streamsize>::max(); //- max_size =>fué obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>

/**
 * ARRAYS: 2.2.5 Pointers, Arrays, and Loops (p59)
 * An array of elements of type char can be declared like this:
 * char v[6];
 * // array of 6 characters
 * Similarly, a pointer can be declared like this:
 * char∗ p;
 * // pointer to character
 * In declarations, [] means ‘‘array of’’ and ∗ means ‘‘pointer to.’’
*/

void readVar(int& ref, string name)
{
    cout<<"Enter "<<name<<" >";
    cin >> ref;
}

int getSize(int *array) //In declarations, [] means ‘‘array of’’ and ∗ means ‘‘pointer to.’’
{
    int i = 0;
    while (array[i] != 0)
    {
        i++;
    }

    return i;
}

bool findValue(int *list, int value)
{
    int listSize = getSize(list);

    for(int i = 0; i < listSize; i++){
        if (list[i] == value)
        {
            return true;
        }
    }

    return false;
}

bool validateDay(int day, int month)
{
    int month31[] = {1, 3, 5, 7, 8, 10, 12};
    int month30[] = {4, 6, 9, 11};
    int month2 = 2;

    if(day < 1){
        return false;
    }
    else if(findValue(month30, month) && day > 30){
        return false;
    }
    else if(findValue(month31, month) && day > 31){
        return false;
    }
    else if(month2 == month && day > 28){
        return false;
    }

    return true;
}

int calculateYearOlds(tm birthday, tm currentDate)
{

    int yearsOld = currentDate.tm_year - birthday.tm_year;

    if( (currentDate.tm_mon < birthday.tm_mon) || (currentDate.tm_mon == birthday.tm_mon && currentDate.tm_mday < birthday.tm_mday) ){
        --yearsOld;
    }

    return yearsOld;
}

int main()
{
    int day, month, year;
    time_t currentTime = time(nullptr); //Returns the current calendar time encoded as a std::time_t object, and also stores it in the object pointed to by arg, unless arg is a null pointer.
    tm *currentDate = localtime(&currentTime); //localtime => converts time since epoch to calendar time expressed as local time.
    int currentYear = currentDate->tm_year+1900; //int tm_year; /* Year - 1900. */ los anios desde 1900

    readVar(year, "birth's year");
    if(year > currentYear || year < 1900){
        cout<<"Birth's year is invalid. Enter year between 1900 and "<<currentYear<<". Press <enter> key.";
        /**
         * Para hacer el presione cualquier tecla para continuar y limpiar el buffer, falta verificar(!). =>ignore(void)=>extracts and discards characters until the given character is found. Extracts and discards characters from the input stream until and including delim.
         * - max_size =>fué obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>
         * Ver https://en.cppreference.com/w/cpp/io/basic_istream/ignore
         */
        cin.ignore(MAX_SIZE, '\n');//Limpia el buffer stream in porque queda '\n' y salta la funcion;
        cin.ignore(MAX_SIZE, '\n');//queda a la espera

        return 1;
    }

    readVar(month, "birth's month");
    if(month <0 || month >12){
        cout<<"Birth's month is invalid. Enter month between 1 and 12. Press <enter> key.";
        cin.ignore(MAX_SIZE, '\n');//Limpia el buffer stream in porque queda '\n' y salta la funcion;
        cin.ignore(MAX_SIZE, '\n');//queda a la espera

        return 1;
    }

    readVar(day, "birth's day");
    if(!validateDay(day, month)){
        cout<<"Birth's day is invalid. Press <enter> key.";
        cin.ignore(MAX_SIZE, '\n');
        cin.ignore(MAX_SIZE, '\n');
        return 1;
    }

    /**
     * Example how to use datetime: _obsoleto_
     *      time_t birthday = time(nullptr);
     *      tm *ltm = localtime(&birthday);
     *      ltm->tm_year = year -1900;
     *      ltm->tm_mday = day;
     *      ltm->tm_mon = month-1;
     *      cout<<asctime(ltm)<<endl;
    */
    //Construccion de la fecha en ISO C `broken-down time' structure.
    tm birth; // std::tm (ctime-C-style date and time utilities) => struct tm; => Structure holding a calendar date and time broken down into its components.
    birth.tm_year = year-1900; //Years since 1900.
    birth.tm_mon = month -1; //Month [0-11].
    birth.tm_mday = day; //Day of month [1-31].
    cout << "You were birth at "<< put_time(&birth, "%B%e of %Y") << "and You are "<< calculateYearOlds(birth, *currentDate) << " years old.\n"; //Le paso el valor de lo que apunta el puntero currentDate;

    return 0;
}