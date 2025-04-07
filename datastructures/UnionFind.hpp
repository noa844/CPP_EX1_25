//noa.honigstein@gmail.com
#pragma once

namespace graph {

    class UnionFind {

        private:
            int* parent;  // Array of parent pointers.
            int n;        // Number of elements.

        public:
            // Constructor: initializes the union-find structure for n elements.
            UnionFind(int n);
        
            // Destructor: frees allocated memory.
            ~UnionFind();
        
            // Finds the representative of the set that element x belongs to.
            int find(int x);
        
            // Unions the sets containing x and y.
            void union1(int x, int y);
        };
    }    