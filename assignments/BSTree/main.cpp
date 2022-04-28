#include <iostream>
#include "Node.h"

int main(){
  //Root
  Node *childA = new Node(20);
  Node *childB = new Node(50);
  Node *root = new Node(10, childA, childB);

  //Left Side
  Node *n = new Node(30);
  childA->setLeft(n);
  Node *n2 = new Node(40);
  n->setLeft(n2);

  //Right Side
  Node *n3 = new Node(60);
  Node *n4 = new Node(70);
  childB->setLeft(n3);
  childB->setRight(n4);


  /*Printing Tree*/

  //Root
  std::cout << root->getData() << "\n";//10

  //Left
  std::cout << root->getLeft()->getData() << "\n";//20
  std::cout << root->getLeft()->getLeft()->getData() << "\n";//30
  std::cout << root->getLeft()->getLeft()->getLeft()->getData() << "\n";//40

  //Right
  std::cout << root->getRight()->getLeft()->getData() << "\n";//60
  std::cout << root->getRight()->getRight()->getData() << "\n";//70

  return 0;
}
