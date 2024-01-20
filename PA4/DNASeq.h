// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA4
// class to represent a single DNA sequence

#ifndef DNA_SEQ_H
#define DNA_SEQ_H
#include <string>
#include "DblList.h"

class DNASeq {
    public:
        // default constructor
        DNASeq();

        // default destructor
        ~DNASeq();

        // overloaded constructor that creates a sequence from a character string
        DNASeq(std::string charString);

        // method DNASeq complement()
        // returns a DNA Sequence representing the complement
        DNASeq complement();

        // method DNASeq substring(int s, int e)
        // returns a DNA Sequence based on the substring from position s (inclusive) to position e (exclusive)
        DNASeq substring(int s, int e);

        // method bool isGeneticPalindrome()
        // returns true if the sequence is a genetic palindrome and false otherwise
        bool isGeneticPalindrome();

        DblList<char> DNA;
};

#endif