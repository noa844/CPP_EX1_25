#pragma once

namespace graph {

    // A simple Stack implementation based on a fixed-size array.
    class Stack {
    private:
        int* arr;         // Array to store elements.
       
        int capacity;     // Maximum capacity of the stack.
        int top;     // Index of the top element.
    public:
        // Constructor
        Stack(int size);

        // Destructor
        ~Stack();

        // Pushes an element onto the stack.
        void push(int value);

        // Remove and returns the top element from the stack.
        int pop();

        // Returns the top element without removing it.
        int peek() const;

        // Returns true if the stack is empty.
        bool isEmpty() const;

        // Returns true if the stack is full.
        bool isFull() const;
    };

}
