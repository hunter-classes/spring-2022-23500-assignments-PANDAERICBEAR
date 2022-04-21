#pragma once
#include "Node.h"
#include "List.h"

#define STACK_FULL 1
#define STACK_EMPTY 2

class Stack{
  private:
  List *list;
  int stackLength;
  public:
    Stack();
    ~Stack();
    //string representation of current stack
    std::string toString();
    //insert data to top of list
    void push(int x);
    //remove and return the top item
    int pop();
    //return but do not remove the top item
    int top();
    //return true if rempty, false otherwise
    bool is_empty();
};
