/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 1
 * Consigna: Genera aleatoriamente 10 valores (o lee 10 valores que ingrese el
 * usuario) del 1 a 10 y luego informa si se encuentra el valor 5. Utiliza
 * arreglos. Informalo en pantalla. Ejemplo: 4, 1, 2, 4, 5, 6, 4, 4, 7, 8 ->
 * Salida: Se encuentra el 5.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/16
 */

#include <iostream>

using namespace std;

int gen_rand_num(int base, int limit) {

  srand(time(nullptr) + rand());

  return rand() % (limit - base) + base;
}

int main() {
  const int len = 10;
  int arr[len];
  bool exist_5num = false;

  /**
   * REFERENCE ABOUT: size_t
   * size_t is an unsigned integral data type. size_t or any unsigned type might
   * be seen used as loop variable as loop variables are typically greater than
   * or equal to 0.
   *
   * it’s a type which is used to represent the size of objects in bytes and is
   * therefore used as the return type by the sizeof operator. It is guaranteed
   * to be big enough to contain the size of the biggest object the host system
   * can handle. Basically the maximum permissible size is dependent on the
   * compiler: if the compiler is 32 bit then it is simply a typedef(i.e.,
   * alias) for unsigned int but if the compiler is 64 bit then it would be a
   * typedef for unsigned long long. The size_t data type is never negative.
   *
   * Main advantages of using size_t in C programming:
   *  - Portability: The size_t data type is defined in the stddef.h header,
   * which is part of the C standard library. By using size_t, you can ensure
   * that your code is portable across different platforms and compilers.
   *  - Standardization: By using size_t, you are following a widely used and
   * accepted standard, which makes your code more readable and maintainable for
   * other programmers.
   *
   * Source: https://www.geeksforgeeks.org/size_t-data-type-c-language/
   */
  for (size_t i = 0; i < size(arr); i++) {
    arr[i] = gen_rand_num(1, 11);

    // imprime el nro;
    cout << arr[i];
    if (i != (len - 1))
      cout << ", ";
  }

  int i = 0;

  while (arr[i] && !exist_5num) {
    if (arr[i] == 5) {
      exist_5num = true;
      break;
    }

    i++;
  }

  if (exist_5num)
    cout << endl << "There is a 5." << endl;
  else
    cout << endl << "There isn't a 5." << endl;

  return 0;
}
