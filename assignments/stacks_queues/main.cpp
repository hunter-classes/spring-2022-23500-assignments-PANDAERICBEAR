#include <iostream>
#include "List.h"
#include "Node.h"
#include "Stack.h"

int main(){
  Stack *stack = new Stack();
  stack->push(5);
  stack->push(1);
  stack->push(3);
  std::cout << stack->pop() << std::endl;
  stack->push(2);
  std::cout << stack->top() << std::endl;
  std::cout << stack->is_empty() << std::endl;
  return 0;
}
