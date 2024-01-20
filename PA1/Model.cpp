// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA1
// encodes the rules of the Robber language

#include <iostream>
#include "Model.h"

// default constructor
Model::Model() { 
}

// default destructor
Model::~Model() {
}

// translateSingleConsonant function
// @param char c charcter to translate
// @return string cOut translated character
std::string Model::translateSingleConsonant(char c) {
    cOut = "";
    cOut += c;
    cOut += "o";
    if (c == tolower(c)) {
        cOut += c;
    } else {
        cOut += tolower(c);
    }
    return cOut;
}

// translateSingleVowel function
// @param char v charcter to translate
// @return string vOut translated character
std::string Model::translateSingleVowel(char v) {
    vOut = "";
    vOut += v;
    return vOut;
}