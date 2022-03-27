#include "Labyrinth.h"
#include <iostream>
bool isPathToFreedom(MazeCell* start, const std::string& moves) {
  //1: the path is legal, in the sense that it never takes a step that isn't permitted in the current MazeCell
  for(int i = 0; i < moves.length(); i++){
    std::cout << moves[i] << std::endl;
  }
  return true;
}
