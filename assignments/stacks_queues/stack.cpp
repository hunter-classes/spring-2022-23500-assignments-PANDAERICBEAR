#include <iostream>
#include "Stack.h"
#include "Node.h"
#include "List.h"

Stack::Stack(){
  list = new List();
  stackLength = 0;
}

Stack::~Stack(){
  delete list;
}

std::string Stack::toString(){
  return list->toString();
}

void Stack::push(int x){
  //exception handling
  if (stackLength > 1000){
    throw STACK_FULL;
  }
  //create a new Node
  list->insert(std::to_string(x));
  stackLength++;
}

int Stack::pop(){
  //exception handling
  if (stackLength == 0){
    throw STACK_EMPTY;
  }
  int data = std::stoi(list->getHead());
  //remove top item
  list->remove(0);
  //get head data
  stackLength--;
  return data;
}

int Stack::top(){
  //exception handling --> returns nullptr
  if (stackLength == 0){
    throw STACK_EMPTY;
  }
  int data = std::stoi(list->getHead());
  return data;
}

bool Stack::is_empty(){
  if (stackLength == 0)
    return true;
  else
    return false;
}
