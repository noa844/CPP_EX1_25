#include "src/Graph/Graph.hpp"
#include "src/Algorithms.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;
using namespace graph;

int main() {
   
        // Create graph with 6 vertices
        Graph g(6);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 4);
        g.addEdge(1, 2, 2);
        g.addEdge(1, 3, 5);
        g.addEdge(2, 3, 1);
        g.addEdge(3, 4, 3);
        g.addEdge(4, 5, 2);
    
        cout << "Original graph:" << endl;
        g.print_graph();
    
        Algorithms algo;
    
        // BFS
        try {
            Graph bfsTree = algo.bfs(g, 0);
            cout << "\nBFS tree from vertex 0:" << endl;
            bfsTree.print_graph();
        } catch (const exception& e) {
            cout << "\nBFS error: " << e.what() << endl;
        }
    
        // DFS
        try {
            Graph dfsForest = algo.dfsForest(g, 0);
            cout << "\nDFS forest from vertex 0:" << endl;
            dfsForest.print_graph();
        } catch (const exception& e) {
            cout << "\nDFS error: " << e.what() << endl;
        }
    
        // Dijkstra
        try {
            Graph shortestPathTree = algo.dijkstra(g, 0);
            cout << "\nDijkstra shortest path tree from vertex 0:" << endl;
            shortestPathTree.print_graph();
        } catch (const exception& e) {
            cout << "\nDijkstra error: " << e.what() << endl;
        }
    
        // Prim
        try {
            Graph mstPrim = algo.prim(g);
            cout << "\nPrim's MST:" << endl;
            mstPrim.print_graph();
        } catch (const exception& e) {
            cout << "\nPrim error: " << e.what() << endl;
        }
    
        // Kruskal
        try {
            Graph mstKruskal = algo.kruskal(g);
            cout << "\nKruskal's MST:" << endl;
            mstKruskal.print_graph();
        } catch (const exception& e) {
            cout << "\nKruskal error: " << e.what() << endl;
        }
    
    
    
    return 0;
}
