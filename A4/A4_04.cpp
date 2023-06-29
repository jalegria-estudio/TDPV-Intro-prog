/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 4
 * Consigna: Ingresa un nombre e informa cuántas “a” tiene.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */

#include <iostream>

using namespace std;

int main() {
  string word{};
  char searchar{'a'};
  int counter{0};

  cout << "Write a word >";
  cin >> word;

  for (size_t i = 0; i < word.length(); i++) {
    if (searchar == tolower(word[i]))
      counter++;
  }

  cout << "Your word has (" << counter << ") \'" << searchar << "\'\n";

  return 0;
}
