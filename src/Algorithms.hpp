//noa.honigstein@gmail.com
#pragma once
#include "Graph/Graph.hpp"

namespace graph {

    class Algorithms {
    public:

        // Helper function that returns true if the graph is connected.
        static bool isConnected(const Graph &g);

        // BFS algorithm that returns a BFS tree (Graph) starting from the vertex 'start'
        Graph bfs(const Graph &g, int start);

        // Helper function that returns a DFS tree as a Graph
        void dfsTree(const Graph &g, int start, bool* visited, Graph &forest, int capacity); 
        // DFS algorithm that returns a DFS Forest as a Graph
        Graph dfsForest(const Graph &g, int start);

        // Dijkstra algorithm: returns a shortest path tree as a Graph.
        Graph dijkstra(const Graph &g, int start);

        // Prim's algorithm: computes the Minimum Spanning Tree (MST) of a given graph.
        Graph prim(const Graph &g);

        // Kruskal's algorithm: computes the Minimum Spanning Tree (MST) of a given graph.
        Graph kruskal(const Graph &g);
        
        
    };

}


