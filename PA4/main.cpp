// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA4
// main method

#include <iostream>
#include "ListNode.h"
#include "DblList.h"
#include "DNASeq.h"
#include "PalindromeFinder.h"
#include "Substring.h"

// takes the input specification file as a command line argument
int main(int argc, char* argv[]) {
    // runs the program
    PalindromeFinder* find = new PalindromeFinder(argv[1]);
    delete find;
    return 0;
}