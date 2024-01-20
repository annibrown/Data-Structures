// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA3
// SpeakerView header file
// reference SpeakerView.cpp

#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include <string>
#include <sstream>
#include <fstream>
#include "Monostack.h"

class SpeakerView {
    public:
        SpeakerView(); // default constructor
        SpeakerView(std::string input); // overload constructor
        ~SpeakerView(); // default destructor
        void processFile();
        void resetFile();
        std::string text;
        std::string processText;
        MonoStack<double> **monostackArr;
        std::ifstream inFS;
        double **valArr;
    private:
        int cols;
        int rows;
        double d;
        int currCol;
        int currRow;
        int arrRow;
        int arrCol;
};
#endif