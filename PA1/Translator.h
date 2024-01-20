// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA1
// translates English sentences to Rövarspråket sentences using the Model class

#if !defined(TRANSLATOR_H)
#define TRANSLATOR_H
#include <string>
#include "Model.h"

class Translator {
    public:
        Translator(); // default constructor
        ~Translator(); // default destructor
        std::string translateEnglishWord(std::string word); // takes a single string representing a single English word as input, returns a string representing the Rövarspråket translation
        std::string translateEnglishSentence(std::string sentence); // takes a single string representing a single English sentence as input and returns a string representing the Rövarspråket translation, accounts for punctuation
    private:
        std::string wOut; //stores output for translateEnglishWord()
        std::string sOut; //stores output for translateEnglishSentence()
        Model model;
};
#endif