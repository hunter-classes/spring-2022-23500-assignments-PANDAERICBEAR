#pragma once
#include "Node.h"
#include "List.h"

class Stack : private List{
  private:
  List *list;
  int stackLength;
  public:
    Stack();
    ~Stack();
    //insert data to top of list
    void push(int x);
    //remove and return the top item
    int pop();
    //return but do not remove the top item
    int top();
    //return true if rempty, false otherwise
    bool is_empty();
};
