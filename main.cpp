#include "src/Graph/Graph.hpp"
#include "src/Algorithms.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;
using namespace graph;

int main() {
    // try {
    //     Algorithms algo;
    //     // // Create a graph with 5 vertices
        // Graph g(6);

        // // Add edges between vertices
        // g.addEdge(0, 1, 2);
        // g.addEdge(0, 2, 3);
        // g.addEdge(1, 3, 4);
        // g.addEdge(4, 5, 5);

        // // Print the graph after adding edges
        // cout << "Graph after adding edges:" << endl;
        // g.print_graph();

        // Graph bfsTree = Algorithms::bfs(g, 0);

        // // Print the BFS tree
        // cout << "BFS tree starting from vertex 0:" << endl;
        // bfsTree.print_graph();

        // Graph dfsForest = Algorithms::dfsForest(g, 0);

        // // Print the BFS tree
        // cout << "DFS forest starting from vertex 0:" << endl;
        // dfsForest.print_graph();

        // Graph gr(7);

        // // Composante 1 (0–1–2–0 cycle)
        // gr.addEdge(0, 1, 1);
        // gr.addEdge(1, 2, 1);
        // gr.addEdge(2, 0, 1);
    
        // // Composante 2 (3–4–5 ligne)
        // gr.addEdge(3, 4, 1);
        // gr.addEdge(4, 5, 1);
    
        // // Sommet 6 est isolé
    
        // cout << "==== Original Graph ====" << endl;
        // gr.print_graph();
    
        // // Appel DFS à partir du sommet 0
        // cout << "\n==== DFS Forest from vertex 0 ====" << endl;
        // Graph forest = Algorithms::dfsForest(gr, 0);
        // forest.print_graph();
    //     Graph g(6);
    //     g.addEdge(0, 1, 2);
    //     g.addEdge(0, 3, 8);
    //     g.addEdge(1, 3, 5);
    //     g.addEdge(1, 4, 6);
    //     g.addEdge(4, 3, 3);
    //     g.addEdge(3, 5, 2);
    //     g.addEdge(4, 5, 1);
    //     g.addEdge(4, 2, 9);
    //     g.addEdge(5, 2, 3);

   
       
    //     Graph spt = algo.kruskal(g);

    //     spt.print_graph();

        






    // }
    // catch (const std::exception& e) {
    //     cerr << "Exception: " << e.what() << endl;
    // }
    
    return 0;
}
