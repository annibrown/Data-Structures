// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA4
// class to represent a single DNA sequence

#include <iostream>
#include <string>
#include "DNASeq.h"

// default constructor
DNASeq::DNASeq() {
}

// default destructor
DNASeq::~DNASeq() {
}

// overloaded constructor that creates a sequence from a character string
DNASeq::DNASeq(std::string charString) {
    for (int i = 0; i < charString.size(); i++) {
        DNA.add(i, charString[i]);
    }
}

// complement method
// returns a DNA Sequence representing the complement
DNASeq DNASeq::complement() {
    DNASeq DNAcomplement;
    for (int i = 0; i < DNA.size(); i++) {
        if (DNA.get(i) == 'A') {
            DNAcomplement.DNA.add(i, 'T');
        } else if (DNA.get(i) == 'T') {
            DNAcomplement.DNA.add(i, 'A');
        } else if (DNA.get(i) == 'C') {
            DNAcomplement.DNA.add(i, 'G');
        } else if (DNA.get(i) == 'G') {
            DNAcomplement.DNA.add(i, 'C');
        }
    }
    return DNAcomplement;
}

// substring method
// returns a DNA Sequence based on the substring from position s (inclusive) to position e (exclusive)
DNASeq DNASeq::substring(int s, int e) {
    DNASeq DNAsubstring;
    for (int i = s; i < e; i++) {
        DNAsubstring.DNA.add(i, DNA.get(i));
    }
    return DNAsubstring;
}

// isGeneticPalindrome method
// returns true if the sequence is a genetic palindrome and false otherwise
bool DNASeq::isGeneticPalindrome() {
    int i = 0;
    int j = DNA.size()-1;
    while (i < DNA.size() && j >= 0) {
        if (DNA.get(i) != complement().DNA.get(j)) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}