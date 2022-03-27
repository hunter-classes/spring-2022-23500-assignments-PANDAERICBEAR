#include "Labyrinth.h"
#include <iostream>
bool isPathToFreedom(MazeCell* start, const std::string& moves) {
  bool s = false;
  bool w = false;
  bool p = false;

  for(int i = 0; i < moves.length(); i++){
    //1: the path is legal, in the sense that it never takes a step that isn't permitted in the current MazeCell
    if(moves[i] == 'N'){
      if(start->north == nullptr){
        return false;
      } else {
        start = start->north;
      }
    }
    else if(moves[i] == 'S'){
      if(start->south == nullptr){
        return false;
      } else {
        start = start->south;
      }
    }
    else if(moves[i] == 'E'){
      if(start->east == nullptr){
        return false;
      } else {
        start = start->east;
      }
    }
    else if(moves[i] == 'W'){
      if(start->west == nullptr){
        return false;
      } else {
        start = start->west;
      }
    }

    //2: the path picks up the SPELLBOOK, WAND, and POTION. Where order does not matter.
    if(start->whatsHere == Item::SPELLBOOK){
      s = true;
    }
    if(start->whatsHere == Item::POTION){
      p = true;
    }
    if(start->whatsHere == Item::WAND){
      w = true;
    }
  }

  if(s && p && w){
    return true;
  } else {
    return false;
  }
}
