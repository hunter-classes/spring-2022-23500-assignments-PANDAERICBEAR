#include <iostream>
#include "Queue.h"

Queue::Queue(){
  //size 10 vector
  for(int i = 0; i < 10; i++){
    queue.push_back(0);
  }
  head = 0;
  tail = 0;
  lengthOfQueue = 0;
}

Queue::~Queue(){
  queue.clear();
}
std::string Queue::toString(){
  std::string returnString = "[";

  for(int i = 0; i < 10; i++){
    returnString += std::to_string(queue[i]) + ",";
  }

  returnString += "]";

  return returnString;
}

// add an item to the back of the queue
void Queue::enqueue(int x){
  //exception handling
  if(is_full()){
    throw QUEUE_FULL;
  }

  //add item to tail pointer
  queue[tail%10] = x;
  //move tail pointer forward
  tail++;
  //add 1 to length
  lengthOfQueue++;
}

// remove and return the item from the front of the queue
int Queue::dequeue(){
  if(is_empty()){
    throw QUEUE_EMPTY;
  }
  //save item
  int item = queue[head%10];
  //remove item from vector
  queue[head%10] = 0;
  //move head pointer forward
  head++;
  //subtract 1 from length
  lengthOfQueue--;
  //return item;
  return item;
}

// return but do not remove the item from the front of the queue
int Queue::front(){
  return queue[head];
}

//return true if empty, false otherwise
bool Queue::is_empty(){
  if((head%10 == tail%10) && lengthOfQueue == 0){
    return true;
  }
  return false;
}

// return true if queue is full (head == tail)
bool Queue::is_full(){
  if((head%10 == tail%10) && lengthOfQueue > 0){
    return true;
  }
  return false;
}
