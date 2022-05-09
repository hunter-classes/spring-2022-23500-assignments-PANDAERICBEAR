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
}
