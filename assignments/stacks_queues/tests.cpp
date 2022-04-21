#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "Node.h"
#include "Stack.h"

//Stack
TEST_CASE("STACK"){
  Stack *stack = new Stack();

  SUBCASE("Push"){
    stack->push(5);
    CHECK(stack->toString() == "5-->nullptr");
    stack->push(1);
    CHECK(stack->toString() == "1-->5-->nullptr");
    stack->push(3);
    CHECK(stack->toString() == "3-->1-->5-->nullptr");
    stack->push(7);
    CHECK(stack->toString() == "7-->3-->1-->5-->nullptr");
    stack->push(10);
    CHECK(stack->toString() == "10-->7-->3-->1-->5-->nullptr");
    stack->push(13);
    CHECK(stack->toString() == "13-->10-->7-->3-->1-->5-->nullptr");
  }

  SUBCASE("POP"){
    stack->push(5);
    stack->push(1);
    stack->push(3);
    stack->push(7);
    stack->push(10);
    stack->push(13);

    stack->pop();
    CHECK(stack->top() == 10);
    stack->pop();
    CHECK(stack->top() == 7);
    stack->pop();
    CHECK(stack->top() == 3);
    stack->pop();
    CHECK(stack->top() == 1);
    stack->pop();
    CHECK(stack->top() == 5);

    //exception handling
    try {
        stack->top();
    } catch(int error) {
        CHECK(error == STACK_EMPTY);
    }
    try {
        stack->pop();
    } catch(int error) {
        CHECK(error == STACK_EMPTY);
    }
  }

  SUBCASE("EMPTY"){
    stack->push(35);
    CHECK(!stack->is_empty());
    stack->pop();
    CHECK(stack->is_empty());
  }
}
