/**
 * libtools.h - Include my library tools for includes
*/
#pragma once //header files have an include guard or a #pragma once directive to ensure that they are not inserted multiple times into a single .cpp file.

namespace libtools //INCLUIR ESTA BIBLIOTECA DESPUES DE UN INCLUDE IOSTREAM
{
    #include "grand.hpp"
    #include "strtolower.hpp"
}

/**
 * In the C and C++ programming languages, "#pragma once" is a non-standard but widely supported preprocessor directive designed to cause the current source file to be included only once in a single compilation.[1] Thus, "#pragma once" serves the same purpose as "include guards".
 * Source: https://en.wikipedia.org/wiki/Pragma_once
 */