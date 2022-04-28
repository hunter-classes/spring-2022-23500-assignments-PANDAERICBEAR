#include <iostream>
#include "BSTree.h"
#include "Node.h"

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int d){

}

std::string BSTree::get_debug_string(){
  return get_debug_string_Rhelper(root);
}

std::string BSTree::get_debug_string_Rhelper(Node *n){
  if(n == nullptr){
    return "";
  } else {
    if (n->getLeft() == nullptr && n->getRight() == nullptr){
      return std::to_string(n->getData());
    }
    return std::to_string(n->getData()) + "\n" + get_debug_string_Rhelper(n->getLeft()) + "\n" + get_debug_string_Rhelper(n->getRight());
  }
}

void BSTree::setup(){
  Node *n =  new Node(10);
  root = n;
  n = new Node(20);
  root->setLeft(n);
  n = new Node(30);
  root->setRight(n);
  n = new Node(40);
  root->getLeft()->setLeft(n);
}
