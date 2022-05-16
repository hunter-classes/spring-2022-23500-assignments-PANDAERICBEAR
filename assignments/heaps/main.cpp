#include <iostream>
#include "funcs.h"

int main(){
  int arr[] = {10, 2, 8, 1, 4, 7, 6, 5, 9, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  heapsort(arr, 10);
  for(int i = 0; i < size; i++){
    std::cout << arr[i] << ", ";
  }
  std::cout << '\n';
  return 0;
}
