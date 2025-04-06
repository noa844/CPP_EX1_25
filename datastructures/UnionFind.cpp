#include "UnionFind.hpp"
#include <stdexcept>
using std::runtime_error;

namespace graph {
    
    // Constructor
    UnionFind::UnionFind(int n) : n(n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;   // Each element is its own parent initially.
           
        }
    }
    // Destructor
    UnionFind::~UnionFind() {
        delete[] parent;
    }
    
    int UnionFind::find(int x) {
        // if x is not its own parent, recursively find the root.
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void UnionFind::union1(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;  // Already in the same set.
        
        //not optimized union.
        parent[rootX] = rootY;
       
    }
    
    } 