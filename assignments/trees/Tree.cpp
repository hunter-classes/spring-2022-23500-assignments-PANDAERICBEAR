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
    return "null";
  } else {
    if (n->getLeft() == nullptr && n->getRight() == nullptr){
      return std::to_string(n->getData());
    }
    return std::to_string(n->getData()) + " " + get_debug_string_Rhelper(n->getLeft()) + " " + get_debug_string_Rhelper(n->getRight());
  }
}

void BSTree::deleteVal(int value){
  Node *walker = root;
  Node *trailer = nullptr;

  //loop till value is found
  while(walker){
    //move trailer forward
    trailer = walker;
    if(walker->getData() > value){
      walker = walker->getLeft();
    } else if (walker->getData() < value){
      walker = walker->getRight();
    }

    if (walker->getData() == value) { //current node is the value we're looking for
      std::cout << "value found" << std::endl;
      std::cout << "trailerNode is at: " << trailer->getData() << std::endl;
      std::cout << "walkerNode is at: " << walker->getData() << std::endl;
      break;
    }
  }

  //case 1: Node is a leaf
  //using the parent node (trailer), set its child to null
  //remove/delete walker node
  if (walker->getLeft() == nullptr && walker->getRight() == nullptr){
    std::cout << "case 1: Node is a leaf" << std::endl;
    if(trailer->getData() > walker->getData()){
      trailer->setLeft(nullptr);
    } else {
      trailer->setRight(nullptr);
    }
    walker = nullptr;
    delete walker;
    return;
  }

  //case 2: Node has 1 child
  //relink the parent to its remaining child
  //get a pointer to it's parent, set the parent's pointer to the child
  //delete's only child
  if (walker->getLeft() == nullptr && walker->getRight()){
    std::cout << "case 2: Node has 1 child" << '\n';
    if(trailer->getData() > walker->getData()){
      trailer->setLeft(walker->getRight());
    } else {
      trailer->setRight(walker->getRight());
    }
    walker = nullptr;
    delete walker;
    return;
  } else if (walker->getRight() == nullptr && walker->getLeft()){
    std::cout << "case 2: Node has 1 child" << '\n';
    if(trailer->getData() > walker->getData()){
      trailer->setLeft(walker->getLeft());
    } else {
      trailer->setRight(walker->getLeft());
    }
    walker = nullptr;
    delete walker;
    return;
  }

  //case 3: Node has 2 children
  //pull out the node
  //replace walkerNode with the biggest one on the left subtree (keep going right until the next one is null)
  //the replacement node will either have 0 or 1 children so you can delete using either case 1 or 2
  if(walker->getLeft() && walker->getRight()){
    std::cout << "case 3: Node has 2 children" << '\n';
    Node *smallNode = walker->getLeft(); //smallest node on right subtree
    //find smallest node by traversing all the way right
    while(smallNode->getRight() != nullptr){
      std::cout << smallNode->getData() << std::endl;
      smallNode = smallNode->getRight();
    }

    int tempVal = smallNode->getData();
    deleteVal(tempVal);
    walker->setData(tempVal);
    return;
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
