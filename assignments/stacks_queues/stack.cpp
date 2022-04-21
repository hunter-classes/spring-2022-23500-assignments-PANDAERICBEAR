#pragma once
#include "Node.h"
#include "List.h"

class Stack : public List{
  public:
    Stack();
    ~Stack();
    //insert data to beginning of list
    void push(int x);
    //return a string representation of the full list
    std::string toString();
    //insert node w/ data at location
    void locate(int location, std::string data);
    //removes node at location
    void remove(int location);
};
