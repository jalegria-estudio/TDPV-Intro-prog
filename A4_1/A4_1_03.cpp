/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 3
 * Consigna: Genera un arreglo de 100 elementos con valores que vayan
 * progresivamente del 1 al 100 (1, 2, 3, 4, … 100). Almacena en otro arreglo
 * solo aquellos valores pares y en otro solo aquellos impares. Al final deben
 * quedar dos arreglos de 50 valores cada uno. Informa el contenido de ambos
 * arreglos.
 * Autor: Juan P. Alegria 
 * Fecha: 2023/06/16
 */

#include <iostream>

using namespace std;

/**
 * PRACTICA DE PUNTEROS
 *
 * >>& "get address to" => el operador retorna la direccion en memoria de una
 * variable.
 * >>* "direction or point to" => EN DECLARACIONES/ARGUMENTOS refiere a que va
 * almacenar una direccion de la memoria; EN VARIABLES accede al valor al que
 * apunta esa direccion de la memoria.
 *
 * Ejemplos:
 * int myNumber = 2;
 * int *direction;
 * direction = &myNumber;
 * cout<<direction; //0x7ffc19964cb4;
 * cout<<*direction; // 2;
 */

/**
 * Filter a array by Odd numbers (%2==1) or Even number (%2==0).
 *
 * const int *arrPtr - Pointer to array with numbers.
 *
 * const size_t len - Lenght of array with numbers.
 *
 * bool odd - Indicate filter by odd => impar => 1 or even => par => 0.
 *
 * int newArr - Array container where put filtered numbers.
 *
 * const size_t - newArrLen Lenght of array container.
 *
 * return void
 */
void filterArrayNumsBy(const int *arrPtr, const size_t len, bool odd,
                       int *newArr, const size_t newArrLen) {
  size_t newIndex = 0;

  for (size_t i = 0; i < len; i++) {
    if (arrPtr[i] % 2 == odd && newIndex < newArrLen) {
      newArr[newIndex] = arrPtr[i];
      newIndex++;
    }
  }
}

void filterArrayByOdd(const int *arrPtr, const size_t len, int *newArr,
                      const size_t newArrLen) {
  cout << *arrPtr << endl;
  filterArrayNumsBy(arrPtr, len, true, newArr, newArrLen);
}

void filterArrayByEven(const int *arrPtr, const size_t len, int *newArr,
                       const size_t newArrLen) {
  filterArrayNumsBy(arrPtr, len, false, newArr, newArrLen);
}

void printArrayNums(const int *arrPtr) {
  size_t i = 0;

  while (arrPtr[i]) {
    cout << arrPtr[i] << " ";
    i++;
  }
  cout << endl;
}

int main() {
  int arr100[100]{0};
  int arrEven[50]{0};
  int arrOdd[50]{0};

  for (size_t i = 0; i < 100; i++) {
    arr100[i] = i + 1;
  }

  filterArrayByOdd(arr100, 100, arrOdd, 50);
  filterArrayByEven(arr100, 100, arrEven, 50);

  printArrayNums(arrEven);
  printArrayNums(arrOdd);

  return 0;
}
