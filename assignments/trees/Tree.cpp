#include <iostream>
#include "Tree.h"
#include "Node.h"

BSTree::BSTree(){
  root = nullptr;
}

//insert nodes as leaves
void BSTree::insert(int d){
  // make a new node
  Node *newnode = new Node(d);
  Node *p = root;
  Node *trailer;

  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;
    if (p->getData() == d){
      // do the stuff when the node is already in the tree
      return;
    }
    else if (p->getData() < d){
      p = p->getRight();
    } else {
      p = p->getLeft();
    }
  }

  // handle the special case of the tree
 // being empty (null)
 if (root==nullptr){
   root=newnode;
 } else {
   // trailer points to the node ABOVE where the new node
   // will go.
   // we have to figure out if newnode goes on the
   // left of trailer or on the right of trailer
   if (trailer->getData() < d){
     trailer->setRight(newnode);
   } else {
     trailer->setLeft(newnode);
   }

 }
}

void BSTree::rinsert(int d){
  Node *p = root;
  Node *trailer;

  //if empty tree
  if (root == nullptr){
    Node *newnode = new Node(d);
    root = newnode;
    return;
  }

  //traverse left tree
  if (p->getData() > d){
    trailer = p;
    p = p->getLeft();
    rinsert(d, p, trailer);
  //traverse right tree
  } else {
    trailer = p;
    p = p->getRight();
    rinsert(d, p, trailer);
  }
}

void BSTree::rinsert(int d, Node *currNode, Node *trailerNode){
  Node *nextNode = currNode;
  Node *prevNode = trailerNode;

  //base case
  if (currNode == nullptr){ //currNode has reached end of tree
    Node *newNode = new Node(d);
    //if trailerNode is less than d, place node to the right
    if (trailerNode->getData() < d){
      trailerNode->setLeft(newNode);
    } //if trailerNode is greater than d, place node to the left
    else if (trailerNode->getData() > d) {
      trailerNode->setRight(newNode);
    } //else value already exists in tree
    else {
      throw VALUE_EXISTS;
    }
  }

  //traverse left tree, if current Node is greater than value (d)
  if(nextNode->getData() > d){
    //move trailer forward
    prevNode = nextNode;
    nextNode = nextNode->getLeft();
    rinsert(d, nextNode, prevNode);
  } //traverse right tree
  else {
    //move trailer forward
    prevNode = nextNode;
    nextNode = nextNode->getRight();
    rinsert(d, nextNode, prevNode);
  }
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

int BSTree::rsearch(int value){
  return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p){
  if(p == nullptr) {
    throw TREE_NULL;
  }

  if(p->getData() == value) {
    return value;
  }

  if (p->getData() < value){
    return rsearch(value, p->getRight());
  } else {
    return rsearch(value, p->getLeft());
  }

  //if we get here, then the value was not found in the tree
  throw VALUE_NOT_FOUND;
}

void BSTree::setup(){
  Node *n =  new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n2 = new Node(3);
  root->getLeft()->setLeft(n2);
  n2 = new Node(7);
  root->getLeft()->setRight(n2);
}
