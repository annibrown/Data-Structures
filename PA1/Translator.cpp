// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA1
// translates English sentences to Rövarspråket sentences using the Model class

#include <iostream>
#include "Translator.h"

// default constructor
Translator::Translator() { 
}

// default destructor
Translator::~Translator() {
}

// translateEnglishWord function
// @param string word word to translate
// @return string wOut translated word
std::string Translator::translateEnglishWord(std::string word) {
    wOut = "";
    for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                wOut += model.translateSingleVowel(c);
                break;
            default:
                wOut += model.translateSingleConsonant(c);
        }
    }
    return wOut;
}


// translateEnglishSentence function
// @param string sentence sentence to translate
// @return string sOut translated sentence
std::string Translator::translateEnglishSentence(std::string sentence) {
    sOut = "";
    std::string temp = "";
    for (int i = 0; i < sentence.size(); i++) {
        if (isalpha(sentence[i])) {
            temp += sentence[i];
            if (i == sentence.size()-1) {
                sOut += translateEnglishWord(temp);
                temp = "";
            }
        } else {
            sOut += translateEnglishWord(temp);
            temp = "";
            sOut += sentence[i];
        }
    }
    return sOut;
}