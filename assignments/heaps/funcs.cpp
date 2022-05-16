#include <iostream>
#include "funcs.h"

void heapsort(int data[], int size){
  // rearranges array | builds a max heap
  buildHeap(data, size);

  // swap top node to the bottom of the array
  // rearrange and rebuild max heap, incrementally decreasing subtrees
  for (int i = size-1; i > 0; i--){
    std::swap(data[0], data[i]);
    heapify(data, i, 0);
  }
}

void buildHeap(int arr[], int size){
  for(int i = size / 2 - 1; i >= 0; i--){
    heapify(arr, size, i);
  }
}

void heapify(int arr[], int size, int n){
  int largestValue = n;
  int leftNode = 2*n+1;
  int rightNode = 2*n+2;

  if (leftNode >= size && rightNode >= size){
    return;
  }

  if (leftNode < size && arr[leftNode] > arr[largestValue]){
    largestValue = leftNode;
  }
  if (rightNode < size && arr[rightNode] > arr[largestValue]){
    largestValue = rightNode;
  }

  // If largestValue was changed --> inbalanced heap, swap nodes
  if (largestValue != n) {
   // std::cout << "swapping: " << arr[n] << " " << arr[largestValue] << '\n';
   std::swap(arr[n], arr[largestValue]);
   heapify(arr, size, largestValue);
  }

}
