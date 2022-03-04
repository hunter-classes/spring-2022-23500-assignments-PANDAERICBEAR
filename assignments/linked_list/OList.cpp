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
  return true;
}

//returns the value at loc
int OList::get(int loc){
  return 0;
}

// This should “reverse” the list - that is reverse the pointers
void OList::reverse(){
  return;
}
