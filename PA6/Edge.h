// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA6
// Edge header file

#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Edge {
    public:
        // default constructor
        Edge();
        // overload constructor
        Edge(int start, int end, double weight);
        // default destructor
        ~Edge();

        // overloaded <,>,== operators based on edge weight 
        bool operator== (const Edge& other) const {return this->weight == other.weight;}
        bool operator< (const Edge& other) const {return this->weight < other.weight;}
        bool operator> (const Edge& other) const {return this->weight > other.weight;}
        
        int startNode;
        int endNode;
        double weight;
        
};

#endif