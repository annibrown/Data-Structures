// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA1
// takes txt files containing English text
// produces a html file containing the equivalent Rövarspråket translation
// can be viewed in a standard web browser

#include <iostream>
#include <fstream>
#include "FileProcessor.h"

// default constructor
FileProcessor::FileProcessor() { 
}

// default destructor
FileProcessor::~FileProcessor() {
}

// processFile function
// @param string input file to input
// @param string output file to output the translation to
// @return void
void FileProcessor::processFile(std::string input, std::string output) {
    Translator translate;
    std::string translation;
    translation = "";
    std::string text;
    std::ifstream In(input);
    std::ofstream Out(output);
    Out << "<!DOCTYPE html>" << std::endl;
    Out << "<html>" << std::endl;
    Out << "<head>" << std::endl;
    Out << "<title>English to Robber Translation</title>" << std::endl;
    Out << "</head>" << std::endl;
    Out << "<body>" << std::endl;
    while (getline (In, text)) {
        Out << "<p><b>" << text << "</b><br></p>" << std::endl;
        translation += "<p><i>";
        translation += translate.translateEnglishSentence(text);
        translation += "</i><br></p>\n";
    }
    Out << "<p><b></b><br></p>" << std::endl;
    Out << translation;
    Out << "<p><i></i><br></p>" << std::endl;
    Out << "</body>" << std::endl;
    Out << "</html>" << std::endl;
    In.close();
    Out.close();
}