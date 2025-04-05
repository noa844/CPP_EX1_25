#include "Stack.hpp"
#include <stdexcept>
using std::runtime_error;

namespace graph {

    // Constructor: allocate the array and initialize indices.
    Stack::Stack(int size) : capacity(size), top(-1) {
        arr = new int[capacity];
    }

    // Destructor: release the allocated array.
    Stack::~Stack() {
        delete[] arr;
    }

    // Adds a new element to the top of the stack.
    void Stack::push(int value) {
        if (isFull()) {
            throw runtime_error("Stack overflow");
        }
        top= top+1;
        arr[top] = value;
    }

    // Removes and returns the top element of the stack.
    int Stack::pop() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow");
        }
        return arr[top--];
    }

    // Returns the top element without removing it.
    int Stack::peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return arr[top];
    }

    // Checks if the stack is empty.
    bool Stack::isEmpty() const {
        return (top < 0);
    }

    // Checks if the stack is full.
    bool Stack::isFull() const {
        return (top >= capacity - 1);
    }

}