/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 2
 * Consigna: Genera aleatoriamente 20 valores (o lee 20 valores que ingrese el
 * usuario) del 1 a 100 y luego informa cual es el valor más alto. Si se repite,
 * sólo informalo una vez. Ejemplo: 11, 31, 22, 24, 55, 56, 41, 43, 71, 18,91,
 * 11, 58, 65, 19, 57, 90, 91, 84, 47, 24 -> Salida: El más alto es el 91.
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/16
 */

/**
 * Header files and using namespace:
 * EXAMPLE:
 *  // my_class.cpp
        #include "my_class.h" // header in local directory
        #include <iostream> // header in standard library

        using namespace N;
        using namespace std;

        void my_class::do_something()
        {
            cout << "Doing something!" << endl;
        }
 *
 *  We'll call the file my_class.cpp and provide a definition for the member
 declaration.
 *  We add an #include directive for "my_class.h" file in order to have the
 my_class declaration inserted at this point in the .cpp file,
 *  and we include <iostream> to pull in the declaration for std::cout.
 *
 *  (!) Note that quotes are used for header files in the same directory as the
 source file, and angle brackets are used for standard library headers.
 *  (!) Also, many standard library headers do not have .h or any other file
 extension.
 *  (!) In the implementation file, we can optionally use a using statement to
 avoid having to qualify every mention of "my_class" or "cout" with "N::" or
 "std::".
 *     Don't put using statements in your header files!
 *
 * Source:
 https://learn.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-170
 */
#include <iostream>
#include "../libs/libtools.hpp" //biblioteca propia, ver carpeta: /libs/

using namespace std;

int main() {
  int arr[20];
  int highest;

  for (size_t i = 0; i < size(arr); i++) {
    arr[i] = libtools::grandnum(1, 101);

    if (i < (size(arr) - 1))
      cout << arr[i] << ", ";
    else
      cout << arr[i];
  }

  int i = 0;
  highest = arr[i];

  while (arr[i]) {
    if (arr[i] > highest)
      highest = arr[i];

    i++;
  }

  cout << endl << "The highest number is " << highest << endl;

  return 0;
}
