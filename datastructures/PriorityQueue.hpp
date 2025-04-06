#pragma once
namespace graph {

    struct Element {
        int node;  
        int dist;  // The current distance value (weight sum)
    };

    
    class PriorityQueue {

        private:
            Element* arr;  // Array to store elements
            int capacity;    // Maximum capacity of the queue
            int size;        // Current number of elements in the queue


        public:
            // Constructor
            PriorityQueue(int capacity);

            // Destructor
            ~PriorityQueue();

            // Returns true if the queue is empty
            bool isEmpty() const;

             // Returns true if the queue is full.
             bool isFull() const;

            // Inserts an element 
            void insert(int node, int dist);

            // Extracts and returns the element with the minimum distance
            Element extractMin();

            // Decreases the distance of a node and inserts it (if not found)
            void decreaseKey(int node, int newDist);

            // Returns the index of a node in the queue; returns -1 if not found
            int findIndex(int node) const;
        };

}