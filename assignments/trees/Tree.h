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
  void deleteVal(int d);
  void insert(int d);
  void rinsert(int d);
  void rinsert(int d, Node *root, Node *trailer);
  int rsearch(int value);
  int rsearch(int value, Node *p);
  int countLeaves();
  int countLeaves(Node *node);
  int height();
  int height(Node *node);
  int heightAtValue(Node *node, int value);
  int sumAtLevel(int level);
  int sumAtLevel(Node *node, int currLevel, int level);
  bool cousins(int valOne, int valTwo);
  bool cousins(Node *root, int valOne, int valTwo);
  std::string prettyPrint();
  std::string prettyPrint(Node *root, int currTabs);
  void setup();
};
