#pragma once
#include <iostream>
#include "Node.h"

class BSTree{
private:
  Node *root;
public:
  BSTree();
  std::string get_debug_string();
  std::string get_debug_string_Rhelper(Node *n);
  void insert(int d);
  void setup();
};
