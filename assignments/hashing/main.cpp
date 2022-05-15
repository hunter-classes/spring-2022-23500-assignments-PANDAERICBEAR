#include <iostream>
#include "Dictionary.h"
int main(){
  Dictionary *myDict = new Dictionary();
  std::cout << "---insert---" << '\n';
  Person *eric = new Person("Eric", "Li", 0);
  Person *john = new Person("John", "Adam", 1);
  myDict->insert(eric);
  myDict->insert(john);
  std::cout << myDict->getKeys() << '\n';

  std::cout << "---getPerson---" << '\n';
  Person *max = new Person("Max", "Stein", 2);
  std::cout << myDict->getPerson(max) << '\n';
  myDict->insert(max);

  std::cout << "---destructor---" << '\n';
  delete myDict;
  // std::cout << myDict->getKeys() << '\n';
  
  Person *carl = new Person("Carl", "Jar", 3);
  Person *jack = new Person("Jack", "Gil", 4);
  Person *kadin = new Person("Kadin", "Gentry", 5);
  Person *coco = new Person("Coco", "Bean", 6);
  Person *tyler = new Person("Tyler", "Wong", 7);

  return 0;
}
