// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA1
// encodes the rules of the Robber language

#if !defined(MODEL_H)
#define MODEL_H
#include <string>

class Model {
    public:
        Model(); // default constructor
        ~Model(); // default destructor
        std::string translateSingleConsonant(char c); // takes a single consonant character as input, returns a string representing its encoding in Rövarspråket, capitalization preserved
        std::string translateSingleVowel(char v); // takes a single vowel character as input, returns a string representing its encoding in Rövarspråket, capitalization preserved
    private:
        std::string cOut; //stores output for translateSingleConsonant()
        std::string vOut; //stores output for translateSingleVowel()
};
#endif