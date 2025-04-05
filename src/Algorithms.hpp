#pragma once
#include "Graph/Graph.hpp"

namespace graph {

    class Algorithms {
    public:
        // BFS algorithm that returns a BFS tree (Graph) starting from the vertex 'start'
        static Graph bfs(const Graph &g, int start);

         
        // Helper function that returns a DFS tree as a Graph
        static void dfsTree(const Graph &g, int start, bool* visited, Graph &forest, int capacity);
        
        // DFS algorithm that returns a DFS Forest as a Graph
        static Graph dfsForest(const Graph &g, int start);
        
        
    };

}


