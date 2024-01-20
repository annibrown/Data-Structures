// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA1
// instantiates a FileProcessor
// translates the provided input file to Rövarspråket using the file processor

#include <iostream>
#include <fstream>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

// main method
int main() {
    // instantiates a FileProcessor
    FileProcessor processor;
    // translates the provided input file to Rövarspråket using the file processor
    processor.processFile("original.txt", "Translation.html");
    // exit
    return 0;
}