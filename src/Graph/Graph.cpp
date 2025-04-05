#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

namespace graph {

    // Constructor
    Graph::Graph(int vertices) : V(vertices) {
        nodes = new Node[V];
        for (int i = 0; i < V; i++) {
            nodes[i].number = i;
            nodes[i].adjList = nullptr;
        }
    }
    // Destructor
    Graph::~Graph() {
        for (int i = 0; i < V; i++) {
            Neighbor* current = nodes[i].adjList;
            while (current != nullptr) {
                Neighbor* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] nodes;
    }

    int Graph::getSize() const {
        return V;
    }

    Node* Graph::getNodes() const {
        return nodes;
    }

    Neighbor* Graph::getAdjList(int v) const {
        if (!isValidIndex(v)) {
            throw runtime_error("Invalid index");
        }
        return nodes[v].adjList;
    }

    bool Graph::isValidIndex(int index) const {
        return (index >= 0 && index < V);
    }

    // Helper function - adds a neighbor to the adjacency list of vertex source
    void Graph::addNeighbor(int src, int dest, int weight) {
        Neighbor* newNeighbor = new Neighbor;
        newNeighbor->dest = dest;
        newNeighbor->weight = weight;
        newNeighbor->next = nodes[src].adjList;
        nodes[src].adjList = newNeighbor;
    }
     // Helper function - removes a neighbor from the adjacency list of vertex source. Throws an exception if the edge doesn't exist.
     void Graph::removeNeighbor(int src, int dest) {
        Neighbor* prev = nullptr;
        Neighbor* current = nodes[src].adjList;//Pointer to first neighbor in adjlist (may point to null if src node has no neighbors).
        bool found = false;

        while (current != nullptr) {
            if (current->dest == dest) {
                 // if the neighbor dest is at the beginning of the list.
                if (prev == nullptr) {
                    nodes[src].adjList = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        }
        if (!found) {
            throw runtime_error("There is no edge");
        }
    }

    // Add an undirected edge between src and dest with the specified weight or default weight=1. Throws an exception if there is invalide index.
    void Graph::addEdge(int src, int dest, int weight) {
        if (!isValidIndex(src) || !isValidIndex(dest)) {
            throw runtime_error("Invalid index");
        }
        //undirected edge.
        addNeighbor(src, dest, weight);
        addNeighbor(dest, src, weight);
    }
    // Removes the undirected edge between src and dest. Throws an exception if there is invalide index.
    void Graph::removeEdge(int src, int dest) {
        if (!isValidIndex(src) || !isValidIndex(dest)) {
            throw runtime_error("Invalid index");
        }
        removeNeighbor(src, dest);
        removeNeighbor(dest, src);
    }
    void Graph::print_graph() const {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << nodes[i].number << " : ";
            Neighbor* current = nodes[i].adjList;
            while (current != nullptr) {
                cout << "(connected to vertex: " << current->dest << ", weight: " << current->weight << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }


}