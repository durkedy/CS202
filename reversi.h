/*****************
Assignment 4
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
 ****************/

//include relevant headers/libraries
#include "game.h"
#include <string>
using namespace std;

//"reversi" class definition, private "game" inheritance
class reversi:game
{
 public:
  reversi();

  bool moveCanBeMade(bool) const;
  bool makeMove(int, int, bool);
  int isOver() const;
  string getBoard() const;
  int getScore(bool) const;
 
 private:
  int p1Score;
  int p2Score;
};
