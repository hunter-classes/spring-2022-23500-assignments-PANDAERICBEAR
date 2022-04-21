#pragma once
#include "Node.h"

class List{
  private:
    Node *head;
    int size;

  public:
    List();
    ~List();
    //insert data to beginning of list
    void insert(std::string data);
    //return a string representation of the full list
    std::string toString();
    //insert node w/ data at location
    void locate(int location, std::string data);
    //removes node at location
    void remove(int location);
};
