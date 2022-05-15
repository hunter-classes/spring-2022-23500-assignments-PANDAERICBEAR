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
    void insert(Person *data);
    //return a string representation of the full list
    std::string toString();
    //insert node w/ data at location
    void locate(int location, Person *data);
    //removes node at location
    void remove(int location);
    //returns head node
    Node *getHead();
};
