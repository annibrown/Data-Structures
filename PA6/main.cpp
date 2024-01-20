// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA6
// main method

#include "WGraph.h"
#include "Edge.h"
#include "PQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <iomanip>

int main(int argc, char* argv[]) {
    // open input file
    std::ifstream inFS;
    inFS.open(argv[1]);
    // if input file is open it's very sad
    if (!inFS.is_open()) {
        std::cout << "Could not open file :(" << std::endl;
        return 0;
    }
    // nodes in the graph
    int N;
    PQueue<Edge> edges(true);
    Edge newEdge;
    int line = 0;
    int currNode = 0;
    int currCol = 0;
    double d;
    std::string text;
    while(getline(inFS, text)) {
        line++;
        if(line == 1) {
            N = stoi(text);
        } else if(text == "END." || text == "END") {
            break;
        } else {
            std::istringstream stream(text);
            while(stream >> d) {
                if (d != 0) {
                    if(currCol > currNode) {
                        newEdge.startNode = currNode;
                        newEdge.endNode = currCol;
                        newEdge.weight = d;
                        edges.add(newEdge);
                    }
                }
                currCol++;
            }
            currCol = 0;
            currNode++;
        }
    }

    WGraph* graph = new WGraph();
    graph->computeMST(N, edges);
    return 1;
}