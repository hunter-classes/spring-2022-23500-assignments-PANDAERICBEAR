#include <iostream>
#include "List.h"
#include "Node.h"
#include "Stack.h"

int main(){
  Stack *stack = new Stack();
  stack->push(5);
  stack->push(1);
  stack->push(3);
  std::cout << stack->toString() << std::endl;
  std::cout << stack->pop() << std::endl;
  std::cout << stack->toString() << std::endl;
  stack->push(2);
  std::cout << stack->top() << std::endl;
  std::cout << stack->toString() << std::endl;
  std::cout << stack->is_empty() << std::endl;

  stack->pop();
  stack->pop();
  stack->pop();

  try{
    stack->pop();
  } catch(int error){
    std::cout << error << std::endl;
  }
  return 0;
}
