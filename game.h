/**********************
Assignment 4
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
 *********************/
//Header file contains "game" class definition
using namespace std;

//Class definition of "game". Can change dimension size here.
class game
{
 public:
  const static int DIMENSION = 8;
  game();
  bool updateBoard(int, int, char);
  char getCharacterOnBoard(int, int) const;
 
 private:
  char board [DIMENSION][DIMENSION];
};

