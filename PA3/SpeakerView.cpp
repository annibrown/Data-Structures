// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA3
// takes in text file
// The first line of the file will be the string  “BEGIN.” 
// The last line of the file will be the string “END.” 
// Each of the N lines between the first and last will consist of P doubles (representing heights) separated by spaces. 
// uses a monotonically decreasing stack to determine 
// the number of people in each column of seats that are able to see the speaker clearly, 
// as well as the heights of those people. 
// output prints to the terminal


#include <iostream>
#include <string>
#include <fstream>
#include "SpeakerView.h"

// default constructor
SpeakerView::SpeakerView() {
}

// overload constructor
SpeakerView::SpeakerView(std::string input) {
    // open input file
    inFS.open(input);
    resetFile();
    // if input file is open it's very sad
    if (!inFS.is_open()) {
        std::cout << "Could not open file :(" << std::endl;
        return;
    }

    cols = 0;
    rows = 0;
    currRow = 0;
    while(getline(inFS, text)) {
        char c = text[text.size()-1];
        if(c == '\r') {
            text.pop_back();
        }
        if (text == "BEGIN.") {
            continue;
        } else if (text == "END.") {
            break;
        } else {
            std::istringstream stream(text);
            while (stream >> d) {
                if (currRow < 1) {
                    cols++;
                }
            }
            rows++;
            currRow++;
        }
    }
    resetFile();
}

// default destructor
SpeakerView::~SpeakerView() {
    inFS.close();
}

// processFile method
// @return void
void SpeakerView::processFile() {
    // creates 2D double array
    valArr = new double*[rows];
    for (int i = 0; i < rows; i++) {
        valArr[i] = new double[cols];
    }
    
    arrRow = 0;
    arrCol = 0;
    // populates array with input
    while(getline(inFS, text)) {
        char c = text[text.size()-1];
        if(c == '\r') {
            text.pop_back();
        }
        if (text == "BEGIN.") {
            continue;
        } else if (text == "END.") {
            break;
        } else {
            std::istringstream stream(text);
            while (stream >> d) {
                valArr[arrRow][arrCol] = d;
                arrCol++;
            }
            arrCol = 0;
            arrRow++;
        }
    }

    // creates array of monoStacks
    monostackArr = new MonoStack<double>*[cols];
    for (int i = 0; i < cols; i++) {
        monostackArr[i] = new MonoStack<double>(rows, 'd');
    }

    // populates MonoStack array
    currCol = 0;
    for (int i = rows - 1; i > -1; i--) {
        for (int j = 0; j < cols; j++) {
            monostackArr[currCol]->push(valArr[i][j]);
            currCol++;
        }
        currCol = 0;
    }

    // prints output to terminal
    for (int i = 0; i < cols; i++) {
        std::cout << "In column " << i << " there are " << monostackArr[i]->size() << " that can see. Their heights are: ";
        while (monostackArr[i]->isEmpty() == false){
            std::cout << monostackArr[i]->pop();
            if (monostackArr[i]->isEmpty() == false) {
                std::cout << ", ";
            }
        }
        std::cout << " inches." << std::endl;
    }
}

// resetFile method
// @return void
void SpeakerView::resetFile() {
    inFS.clear();
    inFS.seekg(0);
}