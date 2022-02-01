#include <iostream>
using namespace std;

int stepPerms(int n){
  /*
    Fails test cases 5, 6, 8 because of program run time.

    Explanation:
    Recursively subtract n steps to reach base cases of 3, 2, and 1;
    add the maximum sequence of steps from each base case.
  */
  if (n < 0){ //exception case
    return 0;
  }

  if(n == 1){
    return 1;//max sequence of steps for a case of 1 stair is 1
  } else if (n == 2){
    return 2;//max sequence of steps for a case of 2 stairs is 2
  } else if (n == 3){
    return 4;//max sequence of steps for a case of 3 stairs is 4
  } else {
    return (stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3)) % 10000000007;
  }

}
int main(){
  cout << stepPerms(1) << endl;
  cout << stepPerms(3) << endl;
  cout << stepPerms(5) << endl;
  cout << stepPerms(7) << endl;
}
