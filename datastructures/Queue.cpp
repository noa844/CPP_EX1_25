//noa.honigstein@gmail.com
#include "Queue.hpp"
#include <stdexcept>
using std::runtime_error;

namespace graph {


    // Constructor
    Queue::Queue(int size) :  capacity(size), size(0),front(0), rear(-1) {
        arr = new int[capacity];// allocates an array of the given size.
    }

    // Destructor
    Queue::~Queue() {
        delete[] arr;//deletes the allocated array.
    }

     // Checks if the queue is empty.
     bool Queue::isEmpty() const {
        return (size == 0);
    }

    // Checks if the queue is full.
    bool Queue::isFull() const {
        return (size == capacity);
    }


    // Adds an element to the rear of the queue. Throws an exception if the queue is full.
    void Queue::enqueue(int value) {
        if (isFull()) {
            throw runtime_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    // Removes and returns the front element from the queue. Throws an exception if the queue is empty.
    int Queue::dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

   
}
