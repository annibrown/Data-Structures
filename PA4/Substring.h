// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA4
// substring class
// stores a substring's data and length
// allows comparison

#ifndef SUBSTRING_H
#define SUBSTRING_H
#include "PQueue.h"
#include "DNASeq.h"

class Substring {
    public:
        // default constructor
        Substring();

        // overload constructor
        Substring(DNASeq sub);

        // default destructor
        ~Substring();

        // defines <
        bool operator< (const Substring& other){return this->length < other.length;}

        // member variables
        DNASeq substring;
        int length;
};
#endif