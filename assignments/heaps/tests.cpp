#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Heap Sort"){
  int arr[] = {10, 2, 8, 1, 4, 7, 6, 5, 9, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  heapsort(arr, 10);
  std::string str = "";
  for(int i = 0; i < size; i++){
    str += std::to_string(arr[i]) + ", ";
  }

  CHECK(str == "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ");

  int arr2[] = {17, 13, 15, 11, 12};
  size = sizeof(arr2)/sizeof(arr2[0]);
  heapsort(arr2, size);
  str = "";
  for(int i = 0; i < size; i++){
    str += std::to_string(arr2[i]) + ", ";
  }

  CHECK(str == "11, 12, 13, 15, 17, ");
}
