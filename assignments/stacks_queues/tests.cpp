#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

//Stack
TEST_CASE("STACK"){
  Stack *stack = new Stack();

  SUBCASE("PUSH"){
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

TEST_CASE("QUEUE"){
  Queue *queue = new Queue();
  for(int i = 1; i <= 10; i++){
    queue->enqueue(i);
  }
  SUBCASE("ENQUEUE"){
    CHECK(queue->toString() == "[1,2,3,4,5,6,7,8,9,10,]");
  }

  SUBCASE("DEQUEUE"){
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    CHECK(queue->toString() == "[0,0,0,4,5,6,7,8,9,10,]");
  }

  SUBCASE("FRONT"){
    CHECK(queue->front() == 1);
    queue->dequeue();
    CHECK(queue->front() == 2);
  }

  SUBCASE("EMPTY"){
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    CHECK(queue->is_empty());

    try{
      queue->dequeue();
    } catch(int error){
      CHECK(error == QUEUE_EMPTY);
    }
  }

  SUBCASE("FULL"){
    CHECK(queue->is_full());
    try{
      queue->enqueue(11);
    } catch(int error){
      CHECK(error == QUEUE_FULL);
    }
  }

  SUBCASE("WrapAround"){
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    CHECK(queue->toString() == "[0,0,0,4,5,6,7,8,9,10,]");
    queue->enqueue(11);
    queue->enqueue(12);
    queue->enqueue(13);
    CHECK(queue->toString() == "[11,12,13,4,5,6,7,8,9,10,]");
    CHECK(queue->is_full());
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    CHECK(queue->toString() == "[11,12,13,0,0,0,0,0,9,10,]");
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    CHECK(queue->toString() == "[0,0,0,0,0,0,0,0,0,0,]");
    CHECK(queue->is_empty());
  }
}
