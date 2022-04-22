#include <iostream>
#include "List.h"
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

int main(){
  std::cout << "Stack Tests" << std::endl;
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

  std::cout << "Queue Tests" << std::endl;
  Queue *queue = new Queue();
  for(int i = 1; i <= 10; i++){
    queue->enqueue(i);
    std::cout << queue->toString() << std::endl;
  }

  queue->dequeue();
  std::cout << queue->toString() << std::endl;
  queue->enqueue(11);
  std::cout << queue->toString() << std::endl;

  try{
    queue->enqueue(12);
  } catch(int error){
    if(error == 1)
      std::cout << "queue is full; cant enqueue" << std::endl;
  }

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
  std::cout << queue->toString() << std::endl;
  std::cout << queue->is_empty() << std::endl;
  try{
    queue->dequeue();
  } catch(int error){
    if(error == 2)
      std::cout << "queue is empty; cant dequeue" << std::endl;
  }
  return 0;
}
