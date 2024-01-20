// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA4
// substring class
// stores a substring's data and length
// allows comparison

#include <iostream>
#include "Substring.h"

// default constructor
Substring::Substring() {
}

// overload constructor
Substring::Substring(DNASeq sub) {
    substring = sub;
    length = sub.DNA.size();
}

// default destructor
Substring::~Substring() {
}