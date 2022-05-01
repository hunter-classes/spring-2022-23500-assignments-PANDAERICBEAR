#pragma once
#include <iostream>
#include "Node.h"

#define TREE_NULL 1
#define VALUE_NOT_FOUND 2
#define VALUE_EXISTS 4

class BSTree{
private:
  Node *root;
public:
  BSTree();
  std::string get_debug_string();
  std::string get_debug_string_Rhelper(Node *n);
  void insert(int d);
  void rinsert(int d);
  void rinsert(int d, Node *root, Node *trailer);
  int rsearch(int value);
  int rsearch(int value, Node *p);
  void setup();
};
