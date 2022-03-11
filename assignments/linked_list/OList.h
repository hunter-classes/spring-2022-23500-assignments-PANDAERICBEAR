#pragma once
#include "Node.h"
#include "List.h"

class OList: public List{
private:
  Node *head;
public:
  OList();
  ~OList();
  //insert a new node with value into the list in its proper location
  void insert(int data);
  //return a string representation of the full list
  std::string toString();
  //returns true if value is in the list, false otherwise
  bool contains(int value);
  //returns the value at loc
  int get(int loc);
  void remove(int location);
  // This should “reverse” the list - that is reverse the pointers
  void reverse();
};
