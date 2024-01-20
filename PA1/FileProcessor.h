// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA1
// takes txt files containing English text
// produces a html file containing the equivalent Rövarspråket translation
// can be viewed in a standard web browser

#if !defined(PROCESSOR_H)
#define PROCESSOR_H

#include <string>
#include "Translator.h"

class FileProcessor {
    public:
        FileProcessor(); // default constructor
        ~FileProcessor(); // default destructor
        // takes a string representing the input file (English)
        // and a string representing the output file (where the Rövarspråket translation will be written)
        // produces a html file that has the original English text in bold followed by an empty line
        // followed by the Rövarspråket translation in italics
        void processFile(std::string input, std::string output);
};
#endif