#include "Algorithms.hpp"
#include "../src/Graph/Graph.hpp"
#include "../datastructures/Queue.hpp"     
#include "../datastructures/Stack.hpp"   
#include "../datastructures/PriorityQueue.hpp"
#include "../datastructures/UnionFind.hpp"  
#include <limits>
#include <iostream>
#include <stdexcept>
#include <cstdlib>  //rand()
using std::runtime_error;
using namespace std;


namespace graph {

    const int INF = std::numeric_limits<int>::max();

    bool Algorithms::isConnected(const Graph &g) {

        Algorithms algo;

        Graph bfsTree = algo.bfs(g, 0);

        int n = g.getSize();  
        if(n==0) {return false;} 

        // For a connected graph (with more than one vertex),
        // every vertex must have at least one neighbor in the BFS tree.
        for (int i = 0; i < n; i++) {
            if (bfsTree.getAdjList(i) == nullptr) {
                // If a vertex has no neighbors, it was not reached during BFS, meaning the graph is not connected.
                return false;
            }
        }
        
        return true;


    }

    Graph Algorithms::bfs(const Graph &g, int start) {
        if (!g.isValidIndex(start)) {
            throw runtime_error("Invalid starting vertex");
        }
        // Create a new graph to represent the BFS traversal tree.
        int n = g.getSize(); 
        Graph tree(n);
        
        bool* visited = new bool[n](); //initialized to false.
        
        Queue q(n);
        visited[start] = true;
        q.enqueue(start); //Inserting s in queue until all its neighbour vertices are marked.

        while(!q.isEmpty()){

            int v = q.dequeue();

            Neighbor* neighbor = g.getAdjList(v);
            while (neighbor != nullptr) {
                int neighborNum = neighbor->dest;
                if(visited[neighborNum]== false){
                    q.enqueue(neighborNum);
                    visited[neighborNum] = true;
                     // Add the edge from 'v' to 'neighbor' to the BFS tree
                     tree.addEdge(v, neighborNum, neighbor->weight);
                }
                neighbor = neighbor->next; //progress to the next neighbor.
            }
        }

        delete[] visited;
        
        return tree;
    }


    void Algorithms::dfsTree(const Graph &g, int start, bool* visited, Graph &forest, int capacity) {

        Stack s(capacity);
        s.push(start);
        visited[start] = true;

        while (!s.isEmpty()) {
            // Look at the top element and removing it.
            int v = s.pop();    
            Neighbor* neighbor = g.getAdjList(v);
            //Push all the neighbours of v in stack that are not visited   
            while (neighbor != nullptr) {
                int neighborNum = neighbor->dest;
                if (!visited[neighborNum]) {
                    visited[neighborNum] = true;
                    forest.addEdge(v, neighborNum, neighbor->weight);  
                    s.push(neighborNum);
                }
                neighbor = neighbor->next;
            }
           
            
        }

    }
    Graph Algorithms::dfsForest(const Graph &g, int start){

        if (!g.isValidIndex(start)) {
            throw runtime_error("Invalid starting vertex");
        }
        // Create a new graph to represent the DFS traversal forest.
        int n = g.getSize();  
        Graph forest(n); 
        
        bool* visited = new bool[n](); //initialized to false.

        
        // First loop: from the starting vertex to the end.
        for (int i = start; i < n; i++) {
            if (!visited[i]) {
                dfsTree(g, i, visited, forest, n);
            }
        }
        
        // Second loop: from the beginning to the starting vertex.
        for (int i = 0; i < start; i++) {
            if (!visited[i]) {
                dfsTree(g, i, visited, forest, n);
            }
        }
        

        delete[] visited;
        return forest; 

    }
    
    Graph Algorithms::dijkstra(const Graph &g, int start) {
        if (!g.isValidIndex(start)) {
            throw runtime_error("Invalid starting vertex");
        }
        if (g.hasNegativeEdge()) {
            throw runtime_error("Negative weight isn't allowed in graph");
        }

        int n = g.getSize();       
        int* dist = new int[n];  // Stores the current shortest distance from 'start' to each node
        int* previous = new int[n];  // Stores the previous node of each node

        // Initialisation
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            previous[i] = -1;
        }

        dist[start] = 0;

        PriorityQueue pqueue(n);
        pqueue.insert(start, 0);

         // Main loop of Dijkstra's algorithm
        while (!pqueue.isEmpty()) {
            Element element = pqueue.extractMin();
            int u = element.node;
            int dist_su = element.dist;

            Neighbor* neig = g.getAdjList(u);

            while(neig != nullptr){
                int v = neig->dest;
                int weight_uv = neig->weight;
                int relax = dist_su + weight_uv;

               // Relaxation step: update if there is a known path from S to U and if the path from S to V through U is shorter
                if (dist_su!= INF && dist[v] > relax){
                    pqueue.decreaseKey(v,relax);
                    dist[v] = relax;
                    previous[v] = u;
                }
                neig = neig->next;

            }
        }
        // Create a new graph to store the Shortest Path Tree
        Graph sPT(n); 

        for (int i = 0; i < n; i++) {        
            if (previous[i] != -1) {
                int weight = g.getWeight(previous[i],i);
                sPT.addEdge(previous[i], i, weight);
            }

        }

        delete[] dist;
        delete[] previous;
        return sPT;

    }
    
    // Prim's algorithm here starts from a random vertex,
    // so on graphs with identical weights, the resulting MST may vary between executions.
    // However, in such cases, all MSTs will be structurally valid and equivalent in cost.
    Graph Algorithms::prim(const Graph &g) {
        int n = g.getSize();

        if(n == 0) {
            throw runtime_error("Graph is empty");
        }

        if (!isConnected(g)) {
            throw  runtime_error("Graph is not connected. Prim algorithm requires a connected graph.");
        }
        if (g.hasNegativeEdge()) {
            throw runtime_error("Negative weight isn't allowed in graph");
        }


        int* key = new int[n];   // Stores the minimum weight to connect each vertex to the growing MST
        int* previous = new int[n];  // Stores the parent of each vertex in the MST
        bool* selected = new bool[n];  // Marks whether a vertex is already included in the MST

        //Initialisation
        for (int i = 0; i < n; i++) {
            key[i] = INF;
            previous[i] = -1;
            selected[i] = false;
        }

         // Choose a random starting vertex.
         int start = rand() % n;
         
         PriorityQueue pqueue(n);
         pqueue.insert(start, 0);

        // Main loop of Prim's algorithm.
         while (!pqueue.isEmpty()){
            Element element = pqueue.extractMin();
            int u = element.node;
            selected[u]=true;

            Neighbor* neig = g.getAdjList(u);
              // Iterate over all neighbors of u.
            while (neig!=nullptr){
                int v = neig->dest;
                int weight_v = neig->weight;

                if(!selected[v] && weight_v < key[v] ){
                    previous[v] = u;
                    key[v] = weight_v;
                    pqueue.decreaseKey(v, key[v]);
                }
                neig = neig->next;
            }
        }
        // Build the MST graph from the parent information.
        Graph MST(n);

        for (int i = 0; i < n; i++) {
            if (previous[i] != -1) {
                MST.addEdge(previous[i], i, key[i]);
            }
        }
        
        
        delete[] key;
        delete[] previous;
        delete[] selected;
        
        return MST;
    }


    Graph Algorithms::kruskal(const Graph &g) {

        int n = g.getSize();
        if(n == 0) {
            throw runtime_error("Graph is empty");
        }

        if (!isConnected(g)) {
            throw  runtime_error("Graph is not connected. This kruskal algorithm requires a connected graph.");
        }
        
        if (g.hasNegativeEdge()) {
            throw runtime_error("Negative weight isn't allowed in graph");
        }
         // Structure representing an edge in the graph. for creating an sorted array of edges.
         struct Edge {
            int src;
            int dest;
            int weight;
         };

        // Count unique edges (undirected Graph) for the edges array size.
        int Count = 0;
        for (int i = 0; i < n; i++) {
            Neighbor* neig = g.getAdjList(i);
            while (neig != nullptr) {
                int src = i;
                int dest = neig->dest;
                if (src < dest) { // avoid duplicate edges (for all edges (u,v): u<v)
                    Count++;
                }
                neig = neig->next;
            }
        }
        // Create an array of edges.
        Edge* edges = new Edge[Count];
        int e = 0;
        for (int i = 0; i < n; i++) {
            Neighbor* neig = g.getAdjList(i);
            while (neig != nullptr) {
                int src = i;
                int dest = neig->dest;
                if (src < dest) { // avoid duplicate edges (for all edges (u,v): u<v)
                    edges[e].src = i;
                    edges[e].dest = neig->dest;
                    edges[e].weight = neig->weight;
                    e++;
                }
                neig = neig->next;
            }
        }

        // Sort the edges array by weight.
        for (int i = 0; i < Count - 1; i++) {
            int min = i;
            for (int j = i + 1; j < Count; j++) {
                if (edges[j].weight < edges[min].weight) {
                    min = j;
                }
            }
            if (min != i) {
                Edge temp = edges[i];
                edges[i] = edges[min];
                edges[min] = temp;
            }
        }

        // Create a Union-Find structure 
        UnionFind UF(n);
        // Create a new graph to store the MST.
        Graph MST(n);
    
        //loop all over edges[] in increasing order of weight.
        for (int i = 0; i < Count ; i++) {
            int u = edges[i].src;
            int v = edges[i].dest;
            // If u and v are in different connected components, add the edge to the MST.
            if (UF.find(u) != UF.find(v)) {
                UF.union1(u, v);
                MST.addEdge(u, v, edges[i].weight);
            }
        }

        
        delete[] edges;
        return MST;   

    }
}

       




