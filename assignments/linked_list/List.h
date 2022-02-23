#pragma once
#include "Node.h"

class List{
  private:
    Node *head;
    int size;

  public:
    List();
    ~List();
    void insert(std::string data);
    std::string toString();
    void locate(int location, std::string data);
    void remove(int location);
};
