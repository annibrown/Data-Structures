// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA4
// determine whether a sequence is a palindrome 
// whether it contains substrings that are genetic palindromes

#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H
#include <string>
#include <fstream>
#include "DNASeq.h"
#include "PQueue.h"
#include "Substring.h"

class PalindromeFinder {
    public:
        // default constructor
        PalindromeFinder();

        // default destructor
        ~PalindromeFinder();

        // overload constructor
        PalindromeFinder(std::string file);

        std::ifstream inFS;

        std::string text;

        DNASeq DNAtext;

        bool invalid;

        Substring temp;
};
#endif