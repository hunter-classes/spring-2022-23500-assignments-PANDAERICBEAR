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
}
