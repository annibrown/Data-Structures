// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350
// PA6
// weighted graph template class

#include "WGraph.h"
#include <set>
#include <iomanip>

WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
}

WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max();
      m_conn[i][j] = std::numeric_limits<double>::max();  
    }
  }

  recalcFW = false;
}

WGraph::~WGraph(){
  // release memory - let's actually do it in class for once
  for (int i = 0; i < m_size; ++ i){
    delete m_adj[i];
    delete m_conn[i];
  }
  delete[] m_adj;
  delete[] m_conn;
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;  
    m_adj[j][i] = w;
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}

void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){
  // set the conn matrix equal to adj matrix 
  for (int i = 0; i < m_size; ++i){
    for (int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j];
    }
  }

  // start FW
  for (int im = 0; im < m_size; ++im){ // intermediate points 
    for (int source = 0; source < m_size; ++source){ // source -> starting point
      for (int sink = 0; sink < m_size; ++sink){ // sink -> ending point 
        if (source == sink){
          continue;
        } else if ( m_conn[source][im] != std::numeric_limits<double>::max() &&
                    m_conn[im][sink] != std::numeric_limits<double>::max() &&
                    m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
                  
                   m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];

        }
      }
    }
  }
	recalcFW = false;
}

double WGraph::cheapestCost(VertexID i, VertexID j){
  if (recalcFW){
    calcFW();
  }
  return m_conn[i][j]; 
}

void WGraph::computeMST(int N, PQueue<Edge> edges) {
  // Identifies a MST for the graph. Note that a given graph may contain several MSTs, but you only need to identify one

    sets = new DblList<std::set<int>>;

    // initializes an array of N sets
    setArr = new std::set<int>*[N];
    for (int i = 0; i < N; i++) {
      setArr[i] = new std::set<int>;
      // adds each node to a set
      setArr[i]->insert(i);
      // add sets to DblList
      sets->addBack(*setArr[i]);
    }

    // resulting DblList of edges
    MST = new DblList<Edge>;

    while (sets->size() > 1 && edges.size() > 0) {
        nextEdge = edges.remove();

        for (int i = 0; i < sets->size(); i++) {
          if(sets->get(i).count(nextEdge.startNode) != 0) {
            startSet = sets->get(i);
            startIndex = i;
          }
          if(sets->get(i).count(nextEdge.endNode) != 0) {
            endSet = sets->get(i);
            endIndex = i;
          }
        }
       
        if (startIndex != endIndex) {
          merged.clear();
          MST->addBack(nextEdge);
          if (startIndex > endIndex) {
            sets->remove(startIndex);
            sets->remove(endIndex);
          } else {
            sets->remove(endIndex);
            sets->remove(startIndex);
          }
          merged.insert(startSet.begin(), startSet.end());
          merged.insert(endSet.begin(), endSet.end());
          sets->addBack(merged);
        }
    }

    MSTarr = new double*[N];
    for (int i = 0; i < N; i++) {
      MSTarr[i] = new double[N];
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        MSTarr[i][j] = 0.0;
      }
    }

    MSTcost = 0;
    for (int i = 0; i < MST->size(); i++) {
      MSTarr[MST->get(i).startNode][MST->get(i).endNode] = MST->get(i).weight;
      MSTarr[MST->get(i).endNode][MST->get(i).startNode] = MST->get(i).weight;
      MSTcost += MST->get(i).weight;
    }

    // Displays the cost of the MST (the sum of all the edges in the MST) to standard output
    std::cout << "The MST Cost is: " << std::fixed << std::setprecision(1) << MSTcost << std::endl;

  // Displays the adjacency matrix representation of the MST (a NxN matrix where all edges are 0 except for the edges that make up the MST) to standard output
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << std::fixed << std::setprecision(1) << MSTarr[i][j] << " ";
    }
    std::cout << std::endl;
  }

}