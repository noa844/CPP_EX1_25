#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/Graph/Graph.hpp"
#include "../src/Algorithms.hpp"

using namespace graph;


// This function compares two graphs and checks if they are structurally identical.
// It does so by verifying that:
// 1. Every edge in g1 is also present in g2 (with the same weight)
// 2. Every edge in g2 is also present in g1 (with the same weight)
// The order of edges in the adjacency list does not matter.
bool compareGraphs(const Graph& g1, const Graph& g2) {
    if (g1.getSize() != g2.getSize()) return false;
    int n = g1.getSize();
// For each vertex, check that all its neighbors in g1 also exist in g2
    for (int i = 0; i < n; i++) {
       
        Neighbor* a = g1.getAdjList(i);
        while (a != nullptr) {
            Neighbor* b = g2.getAdjList(i);
            bool found = false;
            while (b != nullptr) {
                if (a->dest == b->dest && a->weight == b->weight) {
                    found = true;
                    break;
                }
                b = b->next;
            }

            if (!found) {
                return false; // edge missing in g2
            }
            a = a->next;
        }

         // Same, ensure every neighbor in g2 also exists in g1
        Neighbor* b = g2.getAdjList(i);
        while (b != nullptr) {
            Neighbor* a = g1.getAdjList(i);
            bool found = false;
            while (a != nullptr) {
                if (b->dest == a->dest && b->weight == a->weight) {
                    found = true;
                    break;
                }
                a = a->next;
            }
            if (!found) return false;
            b = b->next;
        }
    }

    return true;
}



TEST_CASE("BFS tree from vertex 0") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    Algorithms algo;
    Graph result = algo.bfs(g, 0);

    Graph expected(5);
    expected.addEdge(0, 2, 1);
    expected.addEdge(0, 1, 1);
    expected.addEdge(2, 4, 1);
    expected.addEdge(1, 3, 1);

    CHECK(compareGraphs(result, expected));
}

TEST_CASE("DFS forest from vertex 0") {
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(3, 4, 1);  // non-connected

    Algorithms algo;
    Graph result = algo.dfsForest(g, 0);

    Graph expected(6);
    expected.addEdge(0, 1, 1);
    expected.addEdge(0, 2, 1);
    expected.addEdge(3, 4, 1);

    CHECK(compareGraphs(result, expected));
}

TEST_CASE("Dijkstra shortest path tree from 1") {
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 8);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 6);
    g.addEdge(4, 3, 3);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 2, 9);
    g.addEdge(5, 2, 3);

    Algorithms algo;
    Graph result = algo.dijkstra(g, 1);

    Graph expected(6);
    expected.addEdge(0, 1, 2);
    expected.addEdge(1, 3, 5);
    expected.addEdge(1, 4, 6);
    expected.addEdge(3, 5, 2);
    expected.addEdge(5, 2, 3);
    
    

    CHECK(compareGraphs(result, expected));
}

TEST_CASE("Prim MST for connected graph") {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    Algorithms algo;
    Graph result = algo.prim(g);

    Graph expected(5);
    expected.addEdge(0, 1, 2);
    expected.addEdge(1, 2, 3);
    expected.addEdge(1, 4, 5);
    expected.addEdge(0, 3, 6);

    CHECK(compareGraphs(result, expected));
}

TEST_CASE("Check if graph is connected") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);

    Algorithms algo;
    CHECK(algo.isConnected(g));

    Graph disconnected(4);
    disconnected.addEdge(0, 1, 1);
    disconnected.addEdge(2, 3, 1);
    CHECK_FALSE(algo.isConnected(disconnected));
}
TEST_CASE("BFS throws on invalid start index") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    Algorithms algo;
    CHECK_THROWS_WITH(algo.bfs(g, 5), "Invalid starting vertex");
    CHECK_THROWS_WITH(algo.dfsForest(g, -1), "Invalid starting vertex");
    CHECK_THROWS_WITH(algo.dijkstra(g, 4), "Invalid starting vertex"); 

}

TEST_CASE("Dijkstra throws on negative edge") {
    Graph g(3);
    g.addEdge(0, 1, -2);
    g.addEdge(1, 2, 1);
    Algorithms algo;
    CHECK_THROWS_WITH(algo.dijkstra(g, 0), "Negative weight isn't allowed in graph");
}

TEST_CASE("Prim throws on disconnected graph") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(2, 3, 4);  // disconnected component
    Algorithms algo;
    CHECK_THROWS_WITH(algo.prim(g), "Graph is not connected. Prim algorithm requires a connected graph.");
}

TEST_CASE("Prim throws on negative edge") {
    Graph g(3);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, -10);
    g.addEdge(0, 2, 4);
    Algorithms algo;
    CHECK_THROWS_WITH(algo.prim(g), "Negative weight isn't allowed in graph");
}

TEST_CASE("Prim throws on empty graph") {
    Graph g(0);
    Algorithms algo;
    CHECK_THROWS_WITH(algo.prim(g), "Graph is empty");
}

TEST_CASE("Kruskal throws on disconnected graph") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    // vertex 2 is disconnected
    Algorithms algo;
    CHECK_THROWS_WITH(algo.kruskal(g), "Graph is not connected. This kruskal algorithm requires a connected graph.");
}

TEST_CASE("Kruskal throws on negative weight") {
    Graph g(3);
    g.addEdge(0, 1, -3);
    g.addEdge(1, 2, 2);
    Algorithms algo;
    CHECK_THROWS_WITH(algo.kruskal(g), "Negative weight isn't allowed in graph");
}

TEST_CASE("Kruskal throws on empty graph") {
    Graph g(0);
    Algorithms algo;
    CHECK_THROWS_WITH(algo.kruskal(g), "Graph is empty");
}

