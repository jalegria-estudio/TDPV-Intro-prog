/**
* Introducción a C++.
* Practica Unidad 2 - Actividad 11.
* Consigna: 
*   Ingresar por consola, Nombre, apellido y edad y mostrarlo en pantalla con la salida:
*   =====================
*   Ingrese nombre: ------
*   Mi Nombre es: <nombre>
*   Ingrese apellido:-----
*   Mi apellido es <apellido>
*   Ingrese edad: --------
*   Tengo <anios> de edad
*   ======================
* Fecha: 2023/05/17
*/
#include <iostream>
#include <limits>
using namespace std;

const string CLI_SEPARATOR = "==========================================";
const string CLI_INTRFC = "\tMy name is %name%.\n\tMy surname is %surname%.\n\tI'm %age% years old.";
constexpr auto max_size = std::numeric_limits<std::streamsize>::max(); //ver aclaraciones en el main.

/**
 * isInt - Valida un string numerico.
 * La idea es recorrer caracter por caracter del string numerico y validar usando ctype que sea un digito decimal. Similar ctype_digit() de PHP.
*/
bool isInt(string age)
{
    int i = 0;
    int qDigits = age.size();

    while ( i < qDigits){

        /**
         * std::isdigit
         * 
         * Defined in header <cctype>
         * int isdigit( int ch );
         * Checks if the given character is one of the 10 decimal digits: 0123456789.
         * 
         * Parameters
         *   ch	-	character to classify
         * Return value
         *   Non-zero value if the character is a numeric character, zero otherwise.
        */
        if ( !isdigit(age[i]) ) return false;

        ++i;
    }

    return true;
}

string replaceData(string strInterface, string data, string wildcard)
{
    /**
     * std::basic_string (!) No confundir con std:replace.
     * The class template basic_string stores and manipulates sequences of character-like objects
     * 
     * constexpr size_type find( const basic_string& str, size_type pos = 0 ) const noexcept;===>find characters in the string
	 * constexpr basic_string& replace( size_type pos, size_type count, const basic_string& str ); ===>replaces specified portion of a string  
     *   pos	-	start of the substring that is going to be replaced
     *   count	-	length of the substring that is going to be replaced
     *   str	-	string to use for replacement
     */
    return strInterface.replace(strInterface.find(wildcard), wildcard.size(), data);
}

string formatOutputData(string name, string surname, string age)
{
    string output = CLI_INTRFC;
    //formatear el string
    output = replaceData(output, name, "%name%");
    output = replaceData(output, surname, "%surname%");
    output = replaceData(output, age, "%age%");

    return CLI_SEPARATOR + "\n" + output + "\n" + CLI_SEPARATOR + "\n";
}

int main()
{
    string name;
    string surname;
    string age;
    
    cout<<"Enter your name >";
    getline(cin, name);
    cout<<"Enter your surname >";
    getline(cin, surname);
    cout<<"Enter your age >";
    getline(cin, age);

    if ( !isInt(age) )
    {
        cout<<"(!) The age is incorrect or not validate and It will be replacement.\n Press enter to continue."<<endl;
        age = "-";
        /**
         * Para hacer el presione cualquier tecla para continuar y limpiar el buffer, falta verificar(!). =>ignore(void)=>extracts and discards characters until the given character is found. Extracts and discards characters from the input stream until and including delim.
         * - max_size =>fué obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>
         * Ver https://en.cppreference.com/w/cpp/io/basic_istream/ignore
         */
        cin.ignore(max_size, '\n');  // skip bad input
    }
    
    
    cout<<formatOutputData(name, surname, age);

    return 0;
}