#pragma once

namespace graph {

    //Imlementation for fixed-size Queue 
    class Queue {
        private:
          
            int capacity;    // Maximum number of elements.
            int size;       // Current number of elements in the queue.

            int front;       // Index of the front element.
            int rear;        // Index of the rear element.
            
            int* arr;        // Array to store elements.
        
        public:
            // Constructor
            Queue(int size);

            // Destructor
            ~Queue();

            // Adds an element to the rear of the queue.
            void enqueue(int value);

            // Removes and returns the front element from the queue.
            int dequeue();

            // Returns true if the queue is empty.
            bool isEmpty() const;

            // Returns true if the queue is full.
            bool isFull() const;
        };

    }
