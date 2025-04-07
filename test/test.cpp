#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/Graph/Graph.hpp"
#include "../src/Algorithms.hpp"

using namespace graph;
//compareGraphs(g1, g2) ⇔ g1 ⊆ g2 and g2 ⊆ g1
bool compareGraphs(const Graph& g1, const Graph& g2) {
    if (g1.getSize() != g2.getSize()) return false;
    int n = g1.getSize();

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
            if (!found) return false;
            a = a->next;
        }

        
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
    g.addEdge(3, 4, 1);  // Composante séparée

    Algorithms algo;
    Graph result = algo.dfsForest(g, 0);

    Graph expected(6);
    expected.addEdge(0, 1, 1);
    expected.addEdge(0, 2, 1);
    expected.addEdge(3, 4, 1);

    CHECK(compareGraphs(result, expected));
}

TEST_CASE("Dijkstra shortest path tree from 0") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 7);

    Algorithms algo;
    Graph result = algo.dijkstra(g, 0);

    Graph expected(5);
    expected.addEdge(0, 2, 3);
    expected.addEdge(2, 1, 1);
    expected.addEdge(1, 3, 2);
    expected.addEdge(3, 4, 7);

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
