// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA6
// Edge class

#include "Edge.h"

// default constructor
Edge::Edge() {
    startNode = 0;
    endNode = 0;
    weight = 0.0;
}

// overload constructor
Edge::Edge(int start, int end, double weight) {
    startNode = start;
    endNode = end;
    weight = weight;
}

// default destructor
Edge::~Edge() {

}