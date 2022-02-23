#include <iostream>
#include "List.h"
#include "Node.h"
void Nodes();
void LinkedList();

int main(){
  LinkedList();


  return 0;
}

void LinkedList(){
  List *l1 = new List();

  std::cout << l1->toString() << "\n";
  l1->insert("a");
  l1->insert("b");
  l1->insert("c");
  std::cout << l1->toString() << "\n";
}

void Nodes(){
  Node *p1 = new Node(); //creates a p1 memory block that points to a blank Node
  p1->setData("hello"); // (*p1.setData()) -- refers to what p1 is pointing to, a blank Node. set its data

  Node *p2 = new Node("World"); //creates a p2 memory block that points to a blank Node, with its data set as "World"

  p1->setNext(p2); //points the p1 head Node to the p2 Node

  std::cout << p1->getData() << "\n";
  std::cout << p2->getData() << "\n";
  //(p1 pointer) --> head Node --> (p2 pointer) --> Node's Data
  std::cout << p1->getNext()->getData() << "\n";

  p2 = new Node("!");
  p1->getNext()->setNext(p2);

  Node *walker = p1;
  std::cout << "\n" << walker->getData() << "\n";
  walker = walker->getNext();
  std::cout << walker->getData() << "\n";
  walker = walker->getNext();
  std::cout << walker->getData() << "\n";

}
