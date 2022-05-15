#include <iostream>
#include "Dictionary.h"

//initialize List arr[20]
Dictionary::Dictionary(){
  for(int i = 0; i < 20; i++){
    arr[i] = new List();
  }
}

Dictionary::~Dictionary(){
  for(int i = 0; i < 20; i++){
    delete arr[i];
  }
}

int Dictionary::hash(Person *p, int size){
  std::string name = p->get_name();
  return name.length() % size;
}

void Dictionary::insert(Person *p){
  int hash = this->hash(p, 20);
  arr[hash]->insert(p);
}

Person* Dictionary::getPerson(Person *p){
  int hash = this->hash(p, 20);
  std::cout << hash << '\n';
  List *list = arr[hash];
  std::cout << list->toString() << '\n';
  Node *currNode = list->getHead();

  while(currNode != nullptr){
    if (p->get_name() == currNode->getData()->get_name()){
      std::cout << "found person" << '\n';
      return currNode->getData();
    }
    currNode = currNode->getNext();
  }

  return nullptr;
}

std::string Dictionary::getKeys(){
  std::string returnString = "";
  for(int i = 0; i < 20; i++){
    if (arr[i]->toString() != "nullptr"){
      returnString += arr[i]->toString();
      returnString += ", ";
    }
  }
  return returnString;
}
