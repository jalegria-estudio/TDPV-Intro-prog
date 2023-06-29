/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 6
 * Consigna: Ingresa un nombre e informa cuántas vocales de cada tipo tiene.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */
#include <iostream>
#include "../libs/libtools.hpp" //biblioteca propia, ver carpeta: /libs/

using namespace std;

int findChar(string word, char target)
{
    int counter{0};

    for (size_t i = 0; i < word.length(); i++)
    {
        if (word[i] == target)
            counter++;
    }

    return counter;
}

int main()
{
    string word{};
    const char VOWELS[]{'a', 'e', 'i', 'o', 'u'};

    cout << "Enter a word >";
    cin >> word;
    cout << "Vowels' statistics:" << endl;

    for (size_t iVowel = 0; iVowel < size(VOWELS); iVowel++)
    {
        char vowel = VOWELS[iVowel];
        printf("- %c (%i)\n\r", vowel, findChar(libtools::strtolower(word), vowel));
    }

    return 0;
}
