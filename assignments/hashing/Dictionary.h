#pragma once
#include <iostream>
#include "List.h"
#include "Person.h"

class Dictionary{
private:
  List *arr[20];
public:
  Dictionary();
  ~Dictionary();
  int hash(Person *p, int size);
  void insert(Person *p);
  Person* getPerson(Person *p);
  std::string getKeys();
};
