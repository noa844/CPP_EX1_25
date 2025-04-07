//noa.honigstein@gmail.com
#include "PriorityQueue.hpp"
#include <stdexcept>
#include <climits>
using std::runtime_error;

namespace graph {

    // Constructor: allocate array and initialize size
    PriorityQueue::PriorityQueue(int capacity) : capacity(capacity), size(0) {
        arr = new Element[capacity];
    }

     // Destructor: free allocated array
     PriorityQueue::~PriorityQueue() {
        delete[] arr;
    }

    bool PriorityQueue::isEmpty() const {
        return (size == 0);
    }

    bool PriorityQueue::isFull() const {
        return (size == capacity);
    }

    int PriorityQueue::findIndex(int node) const {
        for (int i = 0; i < size; i++) {
            if (arr[i].node == node) {
                return i;
            }
        }
        return -1;
    }

    // Adds a new element to the end of the array.
    void PriorityQueue::insert(int node, int dist) {
        if (isFull()) {
            throw runtime_error("PriorityQueue overflow");
        }
        arr[size].node = node;
        arr[size].dist = dist;
        size++;
    }

    Element PriorityQueue::extractMin() {
        if (isEmpty()) {
            throw runtime_error("PriorityQueue is empty");
        }
        int min = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i].dist < arr[min].dist) {
                min = i;
            }
        }
        Element minElement = arr[min];

        if(min == size - 1){
            arr[min].node = -1;
            arr[min].dist = INT_MAX;
        }
        else{   // Remove the element by replacing it with the last element
                arr[min] = arr[size - 1];
            }

        size--;
        return minElement;
    }


    void PriorityQueue::decreaseKey(int node, int newDist) {
        int index = findIndex(node);
        if (index == -1) {
            // If the node is not in the queue, insert it.
            insert(node, newDist);
        } else {
            if (newDist < arr[index].dist) {
                arr[index].dist = newDist;
            }
        }
    }




}