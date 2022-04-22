#pragma once
#include <vector>

#define QUEUE_FULL 1
#define QUEUE_EMPTY 2

//First In - First Out
class Queue{
  private:
    std::vector<int> queue;
    int head;
    int tail;
    int lengthOfQueue;
  public:
    Queue();
    ~Queue();
    //string representation of Queue
    std::string toString();
    // add an item to the back of the queue
    void enqueue(int x);
    // remove and return the item from the front of the queue
    int dequeue();
    // return but do not remove the item from the front of the queue
    int front();
    //return true if empty, false otherwise
    bool is_empty();
    // return true if queue is full (head == tail)
    bool is_full();
};
