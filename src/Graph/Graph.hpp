#pragma once

#include "Node.hpp"

namespace graph {
    class Graph{
        private:
            int V;
            Node* nodes;

            void addNeighbor(int src, int dest, int weight);
            void removeNeighbor(int src, int dest);
            
          
        
        public:
        
        Graph(int vertices);
        ~Graph();
        int getSize() const;
        Node* getNodes() const;
        Neighbor* getAdjList(int vertex) const;
        int getWeight(int src, int dest) const;
        
        
        
        bool hasNegativeEdge() const;// Returns true if there is at least one edge with a negative weight in the graph.
        bool isValidIndex(int index) const;
        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph() const;
    };
    


        
    
}