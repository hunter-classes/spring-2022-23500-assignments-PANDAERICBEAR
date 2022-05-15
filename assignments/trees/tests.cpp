#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "Tree.h"

//Tree
TEST_CASE("Tree"){
  BSTree *t = new BSTree();
  SUBCASE("Recursive Search"){
    try {
      t->rsearch(10);
    } catch (int error){
      CHECK(error == TREE_NULL);
    }

    t->setup();

    try {
      CHECK(t->rsearch(15) == 15);
    } catch (int error){
      CHECK(error == VALUE_NOT_FOUND);
    }
  }

  SUBCASE("Delete Value"){
    //Case 1: Leaf Node
    t->setup();
    try {
      t->deleteVal(7);
      t->deleteVal(30);
    } catch (int error){
      CHECK(error == TREE_NULL);
    }
    CHECK(t->get_debug_string() == "10 5 3 null 20 15 null");

    // Case 2: 1 Child
    t->setup();
    t->insert(4);
    t->insert(8);
    CHECK(t->get_debug_string() == "10 5 3 null 4 7 null 8 20 15 30");
    try {
      t->deleteVal(3);
      t->deleteVal(7);
    } catch (int error){
      CHECK(error == TREE_NULL);
    }
    CHECK(t->get_debug_string() == "10 5 4 8 20 15 30");

    //Case 3: 2 Children
    t->setup();
    CHECK(t->get_debug_string() == "10 5 3 7 20 15 30");
    try {
      t->deleteVal(20);
      t->deleteVal(5);
    } catch (int error){
      CHECK(error == TREE_NULL);
    }
    CHECK(t->get_debug_string() == "10 3 null 7 15 null 30");
  }

  SUBCASE("Counting Leaves"){
    t->setup();
    t->insert(14);
    try{
      CHECK(t->countLeaves() == 4);
    } catch (int error){
      CHECK(error == TREE_NULL);
    }
    t->insert(32);
    t->insert(28);
    try{
      CHECK(t->countLeaves() == 5);
    } catch (int error){
      CHECK(error == TREE_NULL);
    }
  }

  SUBCASE("Height of Tree"){
    t->setup();
    t->insert(14);
    try{
      CHECK(t->height() == 4);
    } catch (int error){
      CHECK(error == TREE_NULL);
    }
  }

  SUBCASE("Sum At Level"){
    t->setup();
    t->insert(14);
    CHECK(t->sumAtLevel(4) == 104);
    t->insert(28);
    t->insert(32);
    CHECK(t->sumAtLevel(4) == 164);
  }

  SUBCASE("Cousins"){
    t->setup();
    t->insert(14);
    t->insert(28);
    t->insert(32);

    try{
      CHECK(t->cousins(3, 30));
      CHECK(t->cousins(14, 32));
    } catch (int error){
      CHECK(error == VALUE_NOT_FOUND);
    }
  }
}
