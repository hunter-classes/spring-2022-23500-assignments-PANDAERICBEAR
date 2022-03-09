#include <iostream>
#include <vector>
#include <map>

int count(std::vector<int> v, int value);
int largest(std::vector<int> v);
int mode(std::vector<int> v);

//A main routine that builds a std::vector<int>
//of random values and tests the above routines.
int main(){
  std::vector<int> vect = {3,3,7,7,7,7,8,12,16,19,20};
  std::cout << count(vect, 7) << '\n';
  std::cout << largest(vect) << '\n';
  std::cout << mode(vect) << '\n';
}

//this will return the number of times value appears in the unsorted vector v.
int count(std::vector<int> v, int value){
  int counter = 0;
  for(int i = 0; i < v.size(); i++){
    if (value == v[i]){
      counter += 1;
    }
  }
  return counter;
}

//this will return the largest value in vector v
int largest(std::vector<int> v){
  int max = 0;
  for (int i = 0; i < v.size(); i++){
    if (v[i] > max){
      max = v[i];
    }
  }
  return max;
}

//returns the item that appears the most frequently
int mode(std::vector<int> v){
  int maxOcc = 0;
  int maxOccNum;
   std::map<int, int> dict;
   for(int i = 0; i < v.size(); i++){
     if (dict.count(v[i]) > 0){
       dict[v[i]] += 1;
     } else {
       //key does not exist in dict
       //add key to dict
       dict[v[i]] = 1;;
     }

     if (dict[v[i]] > maxOcc){
       maxOcc = dict[v[i]];
       maxOccNum = v[i];
     }
   }

   return maxOccNum;
}
