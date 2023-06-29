/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 5
 * Consigna: Ingresa un nombre e informa cuántas vocales tiene.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */

#include <iostream>

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

int countVocals(string word)
{
    const char VOWELS[]{'a', 'e', 'i', 'o', 'u'};
    int counter{0};

    for (size_t iVowel = 0; iVowel < size(VOWELS); iVowel++)
    {
        // SOLUCION FORMATO ANIDADO
        //  for (size_t iChar = 0; iChar < word.length(); iChar++) //recorre toda la palabra buscando una vocal determinada
        //  {
        //     if(VOWELS[iVowel] == word[iChar]) counter++
        //  }

        counter += findChar(word, VOWELS[iVowel]);
    }

    return counter;
}

int main()
{
    int vowelsQuantity;
    string word{};

    cout << "Enter a word >";
    cin >> word;

    vowelsQuantity = countVocals(word);

    cout << "Found " << vowelsQuantity << " vowels.\n";

    return 0;
}
