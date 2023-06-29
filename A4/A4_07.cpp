/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 7
 * Consigna: Realiza un arreglo que al recorrerlo por fila y columna muestre en
 * pantalla la siguiente grilla: 10 guiones en 10 filas. 
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */

#include <iostream>

using namespace std;

int main() {
  size_t size = 10;

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      cout << "- ";
    }

    cout << endl;
  }
}
