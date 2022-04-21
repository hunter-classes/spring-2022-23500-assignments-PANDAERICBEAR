#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);

    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;

  }
  return a;
}

/*
  left and right are already sorted
  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here
  int l = 0;
  int r = 0;

  while (l < left.size() &&
	 r < right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  // add any extra elements in left
  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }

  // add any extra elements in right
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }

  return merged;

}

std::vector<int> msort(std::vector<int> list){
  // base case
  // if the list is size 0 or 1 it's sorted
  // so return it
  if (list.size() <= 1){
    return list;
  }

  // split into two halves (doesn't matter how)
  int mid = list.size() / 2;

  std::vector<int> a,b;

  int i;
  for (i = 0; i < mid; i++){
    a.push_back(list[i]);
  }

  for (i=mid;i<list.size();i++){
    b.push_back(list[i]);
  }

  // recursively msort the two halves
  a = msort(a);
  b = msort(b);

  // merge them together
  list = merge(a,b);
  return list;
}

//Regular Quick Sort
std::vector<int> qsort(std::vector<int> list){
  int i,j;
  // base case
  if (list.size() <= 1){
    return list;
  }
  // select a pivot value.
  // for now, just pick list[0]
  // bad pivot
  int pivot = list[0];
  // good pivot: Median of Three (first, mid, last)
  int first = list[0];
  int mid = list[list.size()/2];
  int last = list[list.size()-1];
  int goodPivot;
  if (first>mid){
    if (first<last)
      goodPivot = 0;
    else if (mid>last)
      goodPivot = list.size()/2;
    else
      goodPivot = list.size()-1;
  }
  else{
    if (last > mid)
      goodPivot = list.size()/2;
    else if (first > last)
      goodPivot = 0;
    else
      goodPivot = list.size()-1;
  }

  goodPivot = list[goodPivot];
  // make 2 new vectors
  std::vector<int> lower,higher;
  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  for (i=1; i < list.size(); i++){
    if (list[i] < goodPivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }
  lower = qsort(lower);
  higher = qsort(higher);
  // copy everything back into list
  for (i=0 ; i < lower.size(); i++){
    list[i]=lower[i];
  }
  list[i] = goodPivot;
  i++;
  for (j=0;j<higher.size();j++){
    list[i] = higher[j];
    i++;
  }
  // return the sorted list
  return list;
}

void swap(std::vector<int>& list, int i, int j){
  int temp = list[i];
  list[i] = list[j];
  list[j] = temp;
}

//In-place quick sort
//Median Number Collaborated w/ Jubayer
void qsort2(std::vector<int>& list, int low, int high) {
  // int pIndex = low + (high-low) / 2;
  // int p = list[pIndex];
  int p = list[low];
  int goodPivot;
  int first = list[low];
  int mid = list[low + (high-low) / 2];
  int last = list[high];
  if (first>mid){
    if (first<last)
      goodPivot = first;
    else if (mid>last)
      goodPivot = mid;
    else
      goodPivot = last;
  }
  else{
    if (last > mid)
      goodPivot = mid;
    else if (first > last)
      goodPivot = first;
    else
      goodPivot = last;
  }
  int l = low;
  int h = high;

  while(l <= h){
    //move l forward if l is less than pivot:
    //if l is greater than pivot, value belongs on right side
    while(list[l] < goodPivot){
      l++;
    }
    //move h backward if h is greater than pivot:
    //if h is less than pivot, value belongs on left side
    while(list[h] > goodPivot){
      h--;
    }
    //once l and h are done. if current indices l < h, swapping needs to occur
    if(l <= h){
      swap(list, l, h);
      //move l forward
      l++;
      //move h backward
      h--;
    }
  }

  if(low < high){
    //arr from low to l-1
    qsort2(list, low, l-1);
    //arr from l to high
    qsort2(list, l, high);
  }

}

void print_help(char *command_name){
  std::cout << "Usage: "<< command_name;
  std::cout << " [-h|-p|-m N|-s N|-a algorithm]\n\n";
  std::cout << " -m MAX_ELEMENT_SIZE\n";
  std::cout << " -s DATA_SET_SIZE\n";
  std::cout << " -a[s|m]: s - selection, m - merge, q - quick, qq - quick2\n";
}

extern char *optarg;

int main(int argc, char *argv[])
  {
    int size = 25000; // default vector size
    int max_val = 200; // default max value for entries

    char algorithm = 's' ; //default to selection sort
    bool print = false; // do we print before and after sorting?
    char c;


    while ( ( c = getopt(argc, argv, "phs:m:a:")) != -1){

      switch (c) {
      case 'h' :
	print_help(argv[0]);
	exit(0);
	break;
      case 'p' :
	print = true;
	break;
      case 's' :
	size = std::stoi(optarg);
	break;
      case 'm' :
	max_val = std::stoi(optarg);
	break;
      case 'a':
	algorithm = optarg[0]; // or *optarg
      }
    }

    srand(time(nullptr));
    std::vector<int> a(size);
    int i;
    for (i=0;i<size; i++){
      a[i] = rand()%max_val;
    }


    if (print) {
      print_vector(a);
      std::cout << "\n";
    }

    std::cout << "Starting the sort!\n";
    struct timeval tp;

    gettimeofday(&tp,NULL);
    long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    if (algorithm == 's'){
      a = ssort(a);
    } else if (algorithm == 'm'){
      a = msort(a);
    } else if (algorithm == 'q'){
      a = qsort(a);
    } else if (algorithm == 'Q'){
      qsort2(a, 0, size);
    }


    gettimeofday(&tp,NULL);
    long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    long elapsed = current_time - start_time;

    if (print) {
      print_vector(a);
    }
    std::cout << "Algorithm: " << algorithm << "\n";
    std::cout << "Time: " << elapsed << "\n";

    return 0;
  }
