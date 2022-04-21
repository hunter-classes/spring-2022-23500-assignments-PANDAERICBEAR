#include <iostream>
#include "Stack.h"
#include "Node.h"
#include "List.h"

Stack::Stack(){
  list = new List();
  stackLength = 0;
}

void Stack::push(int x){
  //create a new Node
  list->insert(std::to_string(x));
  std::cout << list->toString() << std::endl;
  stackLength++;
}

int Stack::pop(){
  int data = std::stoi(list->getHead());
  //remove top item
  list->remove(0);
  std::cout << list->toString() << std::endl;
  //get head data
  stackLength--;
  return data;
}

int Stack::top(){
  int data = std::stoi(list->getHead());
  return data;
}

bool Stack::is_empty(){
  if (stackLength == 0)
    return true;
  else
    return false;
}
