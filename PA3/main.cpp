// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA3
// takes the input file name as a command line argument 
// uses the SpeakerView class to compute the output

#include <iostream>
#include "MonoStack.h"
#include "SpeakerView.h"

// main method
int main(int argc, char* argv[]) {

    //creates new SpeakerView Object
    SpeakerView* view = new SpeakerView(argv[1]);
    // processes object
    view->processFile();
    delete view;
    return 0;
}