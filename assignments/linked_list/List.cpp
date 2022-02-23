#include <iostream>
#include "List.h"

List::List(){
  head = nullptr;
  size = 0;
}

List::~List(){
  std::cout << "size is " << size << "\n";
  for(int i = size; i > 0; i--){
    remove(i);
  }
}

void List::insert(std::string data){
  //create a new Node
  Node *new_node = new Node(data);
  //insert the new Node
  new_node->setNext(head);
  head=new_node;
  size = size + 1;
  std::cout << "size is " << size << "\n";

}

std::string List::toString(){
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();
  }
  s = s + "nullptr";
  return s;
}

//inserts a node at location with data
void List::locate(int location, std::string data){
  Node *walker = head;
  Node *newNode = new Node(data);
  int i = 1;
  while(walker != nullptr && i < location-1){
    walker = walker->getNext();
    i+=1;
  }

  //point newNode.next() to walker.next()
  newNode->setNext(walker->getNext());
  //point walker to newNode
  walker->setNext(newNode);
  size = size + 1;
  std::cout << "size is " << size << "\n";

}

void List::remove(int location){
  Node *walker = head;
  Node *tempNode = new Node();
  int i = 1;
  while(walker != nullptr && i < location-1){
    walker = walker->getNext();
    i+=1;
  }

  //set tempNode to Node after the node we want to delete, to save its information
  tempNode=walker->getNext()->getNext();
  //delete the node that we don't want
  delete(walker->getNext());
  //set walker.next() to be the tempNode
  walker->setNext(tempNode);
  size = size - 1;
  std::cout << "size is " << size << "\n";
}