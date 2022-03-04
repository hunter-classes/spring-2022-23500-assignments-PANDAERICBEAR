#include <iostream>
#include "List.h"
#include "Node.h"
#include "OList.h"
void Nodes();
void LinkedList();

int main(){
  OList *alist = new OList();
  alist->insert(5);
  alist->insert(10);
  alist->insert(30);
  alist->insert(25);
  alist->insert(2);
  alist->insert(7);
  alist->insert(-10);
  alist->insert(-5);
  std::cout << alist->toString() << "\n";
  return 0;
}

void LinkedList(){
  List *list = new List();
  list->insert("a");
  list->insert("b");
  list->insert("c");
  list->insert("d");
  list->insert("e");
  list->insert("f");

  list->locate(0, "z");
  std::cout << list->toString() << "\n";

  list->remove(2);
  std::cout << list->toString() << "\n";


  //destruct list
  list->~List();
  std::cout << list->toString() << "\n";
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
