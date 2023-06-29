/**
 * strtolower.h - Convert a string to lower.
*/
//#include guard
#ifndef STRTOLOWER_H
#define STRTOLOWER_H

/**
 * This function converts a string to lower cases.
 */
std::string strtolower(std::string word){
    std::string lower_word{word};

    for (std::size_t i = 0; i < word.length(); i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    
    return lower_word;
 }
#endif /* STRTOLOWER_H */
