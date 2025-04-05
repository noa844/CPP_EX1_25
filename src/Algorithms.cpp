#include "Algorithms.hpp"
#include "../src/Graph/Graph.hpp"
#include "../datastructures/Queue.hpp"     
#include "../datastructures/Stack.hpp"   
#include <stdexcept>
using std::runtime_error;


namespace graph {

    Graph Algorithms::bfs(const Graph &g, int s) {
        if (!g.isValidIndex(s)) {
            throw runtime_error("Invalid starting vertex");
        }
        // Create a new graph to represent the BFS traversal tree.
        int n = g.getSize(); 
        Graph tree(n);
        
        bool* visited = new bool[n](); //initialized to false.
        
        Queue q(n);
        visited[s] = true;
        q.enqueue(s); //Inserting s in queue until all its neighbour vertices are marked.

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
            // Look at the top element without removing it.
            int v = s.peek();
            s.pop();     
            Neighbor* neighbor = g.getAdjList(v);
            while (neighbor != nullptr) {
                int neighborNum = neighbor->dest;
                if (!visited[neighborNum]) {
                    visited[neighborNum] = true;
                    s.push(neighborNum);
                    forest.addEdge(v, neighborNum, neighbor->weight);  
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



}
