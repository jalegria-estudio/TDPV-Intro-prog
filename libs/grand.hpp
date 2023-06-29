/**
 * grand.h - Generator Random number
 */
#ifndef GRAND_H
#define GRAND_H

/**
 * This function generates a random number between base and limit (not include) numbers.
 */
int grandnum(int base, int limit){
    std::srand(time(nullptr)+std::rand());

     return std::rand()%(limit - base) + base;
 }
#endif /* GRAND_H */


//(!) In the implementation file, we can optionally use a using statement to avoid having to qualify every mention of "my_class" or "cout" with "N::" or "std::". Don't put using statements in your header files! Source: https://learn.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-170

/**
 * "#include guard" is a particular construct used to avoid the problem of double inclusion when dealing with the include directive.
 * The addition of "#include guards" to a header file is one way to make that file idempotent. 
 * Another construct to combat double inclusion is "#pragma once", which is non-standard but nearly universally supported among C and C++ compilers. 
 * 
 * Double inclusion example:
 *     The following C code demonstrates a real problem that can arise if #include guards are missing:
 *     -File "grandparent.h":
 * 
 *     struct foo {
 *         int member;
 *     };
 * 
 *     -File "parent.h":
 *     #include "grandparent.h"
 * 
 *     -File "child.c":
 *     #include "grandparent.h"
 *     #include "parent.h"
 * 
 *     --Result:
 *     struct foo {
 *         int member;
 *     };
 *     struct foo {
 *         int member;
 *     };
 * 
 *     Here, the file "child.c" has indirectly included two copies of the text in the header file "grandparent.h". This causes a compilation error.
 *     *_*
 *     Use of "#include guards" Example:
 *         -File "grandparent.h":
 *         #ifndef GRANDPARENT_H
 *         #define GRANDPARENT_H
 * 
 *         struct foo {
 *             int member;
 *         };
 * 
 *         #endif / GRANDPARENT_H /
 * 
 *         -File "parent.h":
 * 
 *         #include "grandparent.h"
 * 
 *         -File "child.c":
 * 
 *         #include "grandparent.h"
 *         #include "parent.h"
 * 
 *         --Result::
 *         struct foo {
 *             int member;
 *         };
 * 
 *         The first inclusion of "grandparent.h" has the macro GRANDPARENT_H defined. When "child.c" includes "grandparent.h" at the second time (while including "parent.h"), as the #ifndef test returns false, the preprocessor skips down to the #endif, thus avoiding the second definition of struct foo. The program compiles correctly. 
 * 
 * Source: https://en.wikipedia.org/wiki/Include_guard.
 */