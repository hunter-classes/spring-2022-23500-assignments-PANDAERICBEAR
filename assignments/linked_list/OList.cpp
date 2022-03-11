#include <iostream>
#include "OList.h"

OList::OList(){
  head = nullptr;
}

OList::~OList(){
  return;
}

//insert a new node with value into the list in its proper location
void OList::insert(int data){
  //new Node with data
  Node *new_node = new Node(std::to_string(data));

  //pointers
  Node *pointerOne = nullptr;
  Node *pointerTwo = head;
  int p1Data = 0;
  int p2Data = 0;
  bool added = false;

  while(pointerTwo != nullptr){
    //increment pointers
    pointerOne = pointerTwo;
    pointerTwo = pointerTwo->getNext();
    p1Data = std::stoi(pointerOne->getData());

    if (pointerTwo != nullptr){//pointer2 node still valid
      p2Data = std::stoi(pointerTwo->getData());
      if(p1Data <= data && p2Data >= data){ //found in between to add node
        // std::cout << "add between " << p1Data << " and " << p2Data << '\n';
        new_node->setNext(pointerTwo);
        pointerOne->setNext(new_node);
        added = true;
      }
    }
  }

  //list contains no items, add in first item || data is less than curr head item
  if(pointerOne == nullptr || (data <= std::stoi(head->getData()))){
    new_node->setNext(head);
    head = new_node;
    // std::cout << "added in beginning node" << '\n';
    return;
  }

  //data is bigger than all current items, append to end
  if (pointerTwo == nullptr && !added){
    pointerOne->setNext(new_node);
  }

}

//*need new toString because of private head variable*
std::string OList::toString(){
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + " --> ";
    walker = walker->getNext();
  }
  s = s + "nullptr";
  return s;
}

//returns true if value is in the list, false otherwise
bool OList::contains(int value){
  Node *walker = head;
  while(walker != nullptr){
    if (std::stoi(walker->getData()) == value){
      return true;
    }
    walker = walker->getNext();
  }
  return false;
}

//returns the value at loc
int OList::get(int loc){
  Node *walker = head;
  while(walker != nullptr && loc > 0){
    walker = walker->getNext();
    loc -= 1;
  }
  if (loc < 0){
    throw std::out_of_range("Out of range");
  } else if (walker == nullptr && (loc > 0)){
    throw std::out_of_range("Out of range");
  }
  return std::stoi(walker->getData());
}

void OList::remove(int location){
  Node *walker = head;
  Node *tempNode = new Node();

  while(walker != nullptr && location > 1){
    walker = walker->getNext();
    location-=1;
  }

  if (location < 0){
    throw std::out_of_range("Out of range");
  } else if (walker == nullptr && (location > 0)){
    throw std::out_of_range("Out of range");
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

// This should “reverse” the list - that is reverse the pointers
void OList::reverse(){
  Node *p1 = head;
  Node *p2 = head->getNext();
  Node *p3 = head->getNext()->getNext();
  p1->setNext(nullptr);

  while(p3 != nullptr){
    p2->setNext(p1);

    p1=p2;
    p2=p3;
    p3=p3->getNext();
  }

  head = p2;
  head->setNext(p1);
  return;
}
