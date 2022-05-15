#include <iostream>
#include "List.h"

List::List(){
  head = nullptr;
  size = 0;
}

List::~List(){
  //walker --> last instance of the list of nodes
  Node *walker = head;
  //remove original instance of list of nodes --> set to nullptr
  head = nullptr;

  //delete and de-allocate memory for all nodes in the list
  Node *tempNode;
  //deletes from head to last node;
  //walker traverses while deleting the node behind it to never lose track of the next node
  while (walker != nullptr){
    //tempNode = current walker node
    tempNode = walker;
    //walker node traverses forward
    walker = walker->getNext();
    //delete the previous node --> tempNode
    delete tempNode;
  }
}

void List::insert(Person *data){
  //create a new Node
  Node *new_node = new Node(data);
  //insert the new Node
  new_node->setNext(head);
  head=new_node;
  // size = size + 1;
  // std::cout << "size is " << size << "\n";
}

std::string List::toString(){
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData()->get_name() + "-->";
    walker = walker->getNext();
  }
  s = s + "nullptr";
  return s;
}

//inserts a node at location with data
void List::locate(int location, Person *data){
  Node *walker = head;
  Node *newNode = new Node(data);
  if (location == 0){
    newNode->setNext(head);
    head = newNode;
  }
  while(walker != nullptr && location > 1){
    walker = walker->getNext();
    location-=1;
  }

  //point newNode.next() to walker.next()
  newNode->setNext(walker->getNext());
  //point walker to newNode
  walker->setNext(newNode);
  // size = size + 1;
  // std::cout << "size is " << size << "\n";
}

void List::remove(int location){
  Node *walker = head;
  Node *tempNode = new Node();

  while(walker != nullptr && location > 1){
    walker = walker->getNext();
    location-=1;
  }

  //set tempNode to Node after the node we want to delete, to save its information
  tempNode=walker->getNext()->getNext();
  //delete the node that we don't want
  delete(walker->getNext());
  //set walker.next() to be the tempNode
  walker->setNext(tempNode);
  // size = size - 1;
  // std::cout << "size is " << size << "\n";
}

Node *List::getHead(){
  return head;
}
