// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA4
// determine whether a sequence is a palindrome 
// whether it contains substrings that are genetic palindromes

#include <iostream>
#include <string>
#include <fstream>
#include "PalindromeFinder.h"

// defalut constructor
PalindromeFinder::PalindromeFinder() {
}

// default destructor
PalindromeFinder::~PalindromeFinder() {
}

// overload constructor
PalindromeFinder::PalindromeFinder(std::string file) {
    // open input file
    inFS.open(file);
    // if input file is open it's very sad
    if (!inFS.is_open()) {
        std::cout << "Could not open file :(" << std::endl;
        return;
    }

    while(getline(inFS, text)) {
        invalid = false;
        char c = text[text.size()-1];
        if(c == '\r') {
            text.pop_back();
        }
        if (text == "END.") {
            break;
        }
        std::cout << text;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] != 'A' && text[i] != 'T' && text[i] != 'C' && text[i] != 'G') {
                //std::cout << "|" << text[i] << "|" << std::endl;
                std::cout << " - INVALID" << std::endl;
                invalid = true;
                break;
            }
        }
        if (!invalid) {
            DNAtext = DNASeq(text);
            if (DNAtext.isGeneticPalindrome()) {
                std::cout << " - Genetic Palindrome" << std::endl;
            } else {
                std::cout << " - Not a Genetic Palindrome" << std::endl;
            }

            //std::cout << "here" << std::endl;
            PQueue<Substring> SubstringQueue(true);
            if (text.size() > 4) {
                for (int i = 0; i < text.size()-3; i++) {
                    for (int j = i+5; j < text.size()+1; j++) {
                        //std::cout << "i: " << i << " j: " << j << std::endl;
                        if (DNAtext.substring(i,j).isGeneticPalindrome()) {
                            if (!(i == 0 && j == text.size())) {
                                Substring sub = Substring(DNAtext.substring(i,j));
                                SubstringQueue.add(sub);
                            }
                        }
                    }
                }
            }
            while (SubstringQueue.size() > 0) {
                temp = SubstringQueue.remove();
                std::cout << "  Substring ";
                for (int a = 0; a < temp.substring.DNA.size(); a++) {
                    std::cout << temp.substring.DNA.get(a);
                }
                std::cout << " - Genetic Palindrome" << std::endl;
            }
        }
    }
}