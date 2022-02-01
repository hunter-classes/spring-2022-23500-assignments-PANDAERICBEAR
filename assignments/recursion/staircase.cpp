#include <iostream>
using namespace std;

int stepPerms(int n){
  if (n < 0){ //exception case
    return 0;
  }

  if(n == 1){
    return 1;
  } else if (n == 2){
    return 2;
  } else if (n == 3){
    return 4;
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
