/*********************
Assignment 4
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
 ********************/

//Include appropriate header files/libraries
#include "game.h"
#include <iostream>
#include <string>
using namespace std;

//Default constructor sets board characters to '_'.
game::game()
{
  int x;
  int y;
  
  for (x = 0; x < DIMENSION; x++)
    {
      for (y = 0; y < DIMENSION; y++)
	{
	  board[x][y] = '_';
	}
    }

}

/*******************************************
FUNCTION: Update board.
Parameters: Two int parameters and one char,
pass value.
RETURN: True if can update board to item,
otherwise return false.
DESCRIPTION: Pass in coordinates "r" and "c",
as well as "item" you wish to update board with.
Check if coordinates are valid, and if so, update
the board with item passed in.
 *******************************************/
bool game::updateBoard(int r, int c, char item)
{
  if (r < DIMENSION && c < DIMENSION)
    {
      board[r][c] = item;
      return true;
    }
  else
    return false;

}

/********************************************
FUNCTION: Get character on board (const).
PARAMETERS: Two integers represent coordinates.
RETURN: Character of board position (r,c) if
coordinates are valid, otherwise return null character.
DESCRIPTION: Pass in board coordinates (r,c),
and if they match coordinates on the board, return
the character that is in that position.
 *******************************************/
char game::getCharacterOnBoard(int r, int c) const
{
  if (r < DIMENSION && c < DIMENSION)
    {
      return board[r][c];
    }
  else
    return '\0';
}
