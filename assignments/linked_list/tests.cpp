#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "Node.h"
#include "OList.h"

TEST_CASE("Part 1"){
  List *list = new List();
  list->insert("a");
  list->insert("b");
  list->insert("c");
  list->insert("d");
  list->insert("e");
  list->insert("f");

  SUBCASE("List - locate(int location, string data)"){
    list->locate(3, "x");
    CHECK(list->toString() == "f-->e-->d-->x-->c-->b-->a-->nullptr");
    list->locate(2, "y");
    CHECK(list->toString() == "f-->e-->y-->d-->x-->c-->b-->a-->nullptr");
    list->locate(1, "z");
    CHECK(list->toString() == "f-->z-->e-->y-->d-->x-->c-->b-->a-->nullptr");
  }
  SUBCASE("List - remove(int location)"){
    list->remove(2);
    CHECK(list->toString() == "f-->e-->c-->b-->a-->nullptr");
  }

}

TEST_CASE("Part 2"){
  OList *alist = new OList();
  alist->insert(5);
  alist->insert(10);
  alist->insert(30);
  alist->insert(25);
  alist->insert(2);
  alist->insert(7);
  alist->insert(-10);
  alist->insert(-5);
  SUBCASE("OList - insert(value)"){
    alist->insert(-15);
    CHECK(alist->toString() == "-15 --> -10 --> -5 --> 2 --> 5 --> 7 --> 10 --> 25 --> 30 --> nullptr");
    alist->insert(55);
    CHECK(alist->toString() == "-15 --> -10 --> -5 --> 2 --> 5 --> 7 --> 10 --> 25 --> 30 --> 55 --> nullptr");
  }
  SUBCASE("OList - toString()"){
    CHECK(alist->toString() == "-10 --> -5 --> 2 --> 5 --> 7 --> 10 --> 25 --> 30 --> nullptr");
  }
  SUBCASE("OList - contains()"){
    CHECK(alist->contains(-10));
    CHECK(alist->contains(5));
    CHECK(alist->contains(10));
    CHECK(!alist->contains(100));
    CHECK(!alist->contains(130));
  }
  SUBCASE("OList - get(int loc)"){
    CHECK(alist->get(4) == 7);
    CHECK(alist->get(2) == 2);
    CHECK(alist->get(7) == 30);
    CHECK(alist->get(0) == -10);
    CHECK_THROWS_AS(alist->get(-10), std::out_of_range);
    CHECK_THROWS_AS(alist->get(100), std::out_of_range);
  }
  SUBCASE("OList - remove(int loc)"){
    CHECK(alist->toString() == "-10 --> -5 --> 2 --> 5 --> 7 --> 10 --> 25 --> 30 --> nullptr");
    alist->remove(4);
    CHECK(alist->toString() == "-10 --> -5 --> 2 --> 5 --> 10 --> 25 --> 30 --> nullptr");
    CHECK_THROWS_AS(alist->remove(-10), std::out_of_range);
    CHECK_THROWS_AS(alist->remove(100), std::out_of_range);
  }
  SUBCASE("OList - reverse()"){
    alist->reverse();
    CHECK(alist->toString() == "30 --> 25 --> 10 --> 7 --> 5 --> 2 --> -5 --> -10 --> nullptr");
  }
}
