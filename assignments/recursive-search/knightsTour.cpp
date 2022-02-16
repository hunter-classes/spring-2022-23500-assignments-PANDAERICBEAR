#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>

char me = 'N';
char wall = '#';
char path = ' ';

int loadBoard(std::string filename, std::string *board){
  std::ifstream infile(filename);
  int i = 0;
  while(std::getline(infile, board[i])){
    i++;
  }
  return i;
}

void printBoard(std::string board[]){
  // std::cout << "[0;0H\n";
  for(int i = 0; i < 9; i++){
    std::cout << board[i] << "\n";
  }
}

void solveSequence(std::vector<std::vector<int>> steps){
  for(int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      if (steps[i][j] > 9){
        std::cout << steps[i][j] << " ";
      } else {
        std::cout << 0 << steps[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
  std::cout << "---------------" << "\n";
}

bool isBoardSolved(std::vector<std::vector<int>> steps){
  for(int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      if (steps[i][j] == 0){
        return false;
      }
    }
  }
  return true;
}
void solve(std::string board[], int row, int col, bool &solved, std::vector<std::vector<int>> steps, int num){
  //(Goal) if board is solved then done
  if (isBoardSolved(steps)){
    solved = true;
    return;
  }
  //backtracking base cases
  if((board[row][col] == wall) ||
      (board[row][col] == me) ||
     steps[row-2][col-2] > 0){
    return;
  }

  board[row][col] = me;
  // std::cout << row << " " << col << std::endl;
  steps[row-2][col-2] = num;
  num += 1;
  // usleep(800000);
  // printBoard(board);
  solveSequence(steps);

  if (!solved) solve(board, row-1,col+2,solved, steps, num); //1 left 2 up
  if (!solved) solve(board, row-2,col+1,solved, steps, num); //2 left 1 up
  if (!solved) solve(board, row+1,col+2,solved, steps, num); //1 right 2 up
  if (!solved) solve(board, row-2,col-1,solved, steps, num); //2 left 1 down
  if (!solved) solve(board, row+2,col+1,solved, steps, num); //2 right 1 up
  if (!solved) solve(board, row+2,col-1,solved, steps, num); //2 right 1 down
  if (!solved) solve(board, row-1,col-2,solved, steps, num); //1 left 2 down
  if (!solved) solve(board, row+1,col-2,solved, steps, num); //1 right 2 down
  if (!solved){ //replace previous steps with 0s and backtrack path
    steps[row-2][col-2] = 0;
    board[row][col] = path;
  }
}

int main(){
  std::string board[10];
  std::vector<std::vector<int>> steps{
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };

  int totalLines = loadBoard("board.dat", board);
  printBoard(board);
  bool solved = false;
  int counter = 0;
  int num = 1;
  solve(board, 2, 2, solved, steps, num);
  return 0;
}
