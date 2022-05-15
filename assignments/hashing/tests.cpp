#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

TEST_CASE("Dictionary"){
  Dictionary *myDict = new Dictionary();
  SUBCASE("Insertion and Getting All Keys"){
    Person *eric = new Person("Eric", "Li", 0);
    Person *john = new Person("John", "Adam", 1);
    myDict->insert(eric);
    myDict->insert(john);
    CHECK(myDict->getKeys() == "Li, Eric-->nullptr, Adam, John-->nullptr, ");
  }

  SUBCASE("Retrieval"){
    Person *eric = new Person("Eric", "Li", 0);
    Person *john = new Person("John", "Adam", 1);
    Person *max = new Person("Max", "Stein", 2);
    CHECK(myDict->getPerson(max) == nullptr);
    CHECK(myDict->getPerson(eric) == nullptr);
    CHECK(myDict->getPerson(john) == nullptr);
    myDict->insert(max);
    myDict->insert(eric);
    myDict->insert(john);
    CHECK(myDict->getPerson(eric) == eric);
    CHECK(myDict->getPerson(john) == john);
    CHECK(myDict->getPerson(max) == max);
  }

  SUBCASE("Hashing"){
    Person *carl = new Person("Carl", "Jar", 3);
    Person *jack = new Person("Jack", "Gil", 4);
    Person *kadin = new Person("Kadin", "Gentry", 5);
    Person *coco = new Person("Coco", "Bean", 6);
    Person *tyler = new Person("Tyler", "Wong", 7);
    CHECK(myDict->hash(carl, 20) == 9);
    CHECK(myDict->hash(jack, 20) == 9);
    CHECK(myDict->hash(kadin, 20) == 13);
    CHECK(myDict->hash(coco, 20) == 10);
    CHECK(myDict->hash(tyler, 20) == 11);
  }
}
