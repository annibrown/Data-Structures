// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA6
// weighted graph header file

#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits> // allows us to get min and max

#include "PQueue.h"
#include "Edge.h"
#include "DblList.h"

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public: 
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w); // now includes a double for the weight of the edge
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j); // will give us the cheapest path between two vertices
  void calcFW(); // will calculate the Floyd-Warshall algo and create a connectivity matrix that gives us the shortest path from every node to every other node 
  void computeMST(int N, PQueue<Edge> edges);
  std::set<int> **setArr;
  DblList<std::set<int>>* sets;
  DblList<Edge>* MST;
  Edge nextEdge;
  std::set<int> startSet;
  int startIndex;
  std::set<int> endSet;
  int endIndex;
  std::set<int> merged;
  double MSTcost;
  double** MSTarr;

private:
  double** m_adj; // Adjacency matrix: is there an edge between two vertices and what's the weight of the edge
  double** m_conn; // Connectivity matrix: more general, is there a path between a start and a finish and what's the cost (all parts summed)
  unsigned int m_size; // number of nodes in WGraph (fixed) 
  bool recalcFW;

};

#endif