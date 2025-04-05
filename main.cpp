#include "src/Graph/Graph.hpp"
#include "src/Algorithms.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;
using namespace graph;

int main() {
    try {
        // Create a graph with 5 vertices
        Graph g(6);

        // Add edges between vertices
        g.addEdge(0, 1, 2);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 4);
        g.addEdge(4, 5, 5);

        // Print the graph after adding edges
        cout << "Graph after adding edges:" << endl;
        g.print_graph();

        Graph bfsTree = Algorithms::bfs(g, 0);

        // Print the BFS tree
        cout << "BFS tree starting from vertex 0:" << endl;
        bfsTree.print_graph();

        Graph dfsForest = Algorithms::dfsForest(g, 0);

        // Print the BFS tree
        cout << "DFS forest starting from vertex 0:" << endl;
        bfsTree.print_graph();


    }
    catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    
    return 0;
}
