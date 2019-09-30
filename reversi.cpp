/****************************
Assignment 4
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
 ***************************/

//Include relevant headers/libraries/
#include "reversi.h"
#include <iostream>
#include <string>
using namespace std;

/*Default constructor sets the characters '#' and '$' to appropriate positions
  in the middle of the board, based on the DIMENSION size.
  Also initializes player scores to 2.
*/
reversi::reversi() 
{
  game();
  
  int midRow = DIMENSION/2;
  int midCol = DIMENSION/2;
  bool p1pos1Update;
  bool p1pos2Update;
  bool p2pos1Update;
  bool p2pos2Update;

  p1pos1Update = updateBoard(midRow-1, midCol-1, '#');
  p1pos2Update = updateBoard(midRow, midCol, '#');
  p2pos1Update = updateBoard(midRow, midCol-1, '$');
  p2pos2Update = updateBoard(midRow-1, midCol, '$');
  
  p1Score = 2;
  p2Score = 2;

}

/**********************************************************
FUNCTION: Move can be made.
PARAMETERS: One bool parameter representing p1 or p2.
RETURN: True if player can make a move, otherwise return false.
DESCRIPTION: Pass in bool variable representing player 1 if true,
or player 2 if false. Double for loop checks all possible (8) directions
for every coordinate of the board to determine if the player can make a move.
Local variable "canMakeMove" becomes true if the player passed in can make a move.
Local variable "charCounter" is used to count possible flips, if moves can be made.
Loca variable "j" is used as a counter for diagonal directions.
If after checking all directions for all coordinates "canMakeMove" is true,
return true. If player cannot make a move, return false.
 *********************************************************/
bool reversi::moveCanBeMade(bool turn) const
{
  bool canMakeMove = false;
  int charCounter = 0;
  int j;
  
  for (int x = 0; x < DIMENSION; x++){
    for (int y = 0; y < DIMENSION; y++){
  if (getCharacterOnBoard(x, y) == '_')
    {
      if (turn == true)
        {

          //check board down direction
          canMakeMove = false;
	  for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y) == '_' || getCharacterOnBoard(x+1, y) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, y) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, y) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                }
              else if (getCharacterOnBoard(i, y) == '_' && i > x+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }
	  charCounter = 0;

	  //Check board in up direction for possible flips
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x-1, y) == '_' || getCharacterOnBoard(x-1, y) == '#')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, y) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, y) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(i, y) == '_' && i < x-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
	    }
	  charCounter = 0;

	  //Check board in left direction for possible flips
          for (int i = y-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y-1) == '_' || getCharacterOnBoard(x, y-1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                }
              else if (getCharacterOnBoard(x, i) == '_' && i < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }

            }
	  charCounter = 0;

	  //Check board in right direction for possible flips
          for (int i = y+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y+1) == '_' || getCharacterOnBoard(x, y+1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                }
	      else if (getCharacterOnBoard(x, i) == '_' && i > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }

            }
	  charCounter = 0;

	  //Check board in up-right diagonal direction for possible flips
          j = y + 1;
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x-1, y+1) == '_' || getCharacterOnBoard(x-1, y+1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                   
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j++;
            }
	  charCounter = 0;

	  //Check board in down-left diagonal direction for possible flips
          j = y - 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y-1) == '_' || getCharacterOnBoard(x+1, y-1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
	      j--;
            }
	  charCounter = 0;
	  
	  //check board up-left diagonal direction for possible flips
          j = y - 1;
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x-1, y-1) == '_' || getCharacterOnBoard(x-1, y-1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j--;
            }
	  charCounter = 0;

	  //check board down-right diagonal direction for possible flips
          j = y + 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y+1) == '_' || getCharacterOnBoard(x+1, y+1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
	      else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j++;
            }
	  charCounter = 0;

          if (canMakeMove == true)
            return true;
        }
      else if (turn == false)
        {
          charCounter = 0, canMakeMove = false;
	  //check board down direction
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y) == '_' || getCharacterOnBoard(x+1, y) == '$')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, y) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, y) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(i, y) == '_' && i > x+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }
	  charCounter = 0;

	  //Check up-direction for possible flips
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x-1, y) == '_' || getCharacterOnBoard(x-1, y) == '$')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, y) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, y) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, y) == '_' && i < x-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }
	  charCounter = 0;

	  //Check left-direction for possible flips
          for (int i = y-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y-1) == '_' || getCharacterOnBoard(x, y-1) == '$')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(x, i) == '_' && i < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }
	  charCounter = 0;

	  //Check right direction for possible flips
          for (int i = y+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y+1) == '_' || getCharacterOnBoard(x, y+1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(x, i) == '_' && i > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }
	  charCounter = 0;

	  //Check up-right diagonal direction for possible flips
          j = y + 1;
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x-1, y+1) == '_' || getCharacterOnBoard(x-1, y+1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
		{
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j>y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j++;
            }
	  charCounter = 0;

	  //Check down-left diagonal direction for possible flips
          j = y - 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x+1, y-1) == '_' || getCharacterOnBoard(x+1, y-1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j<y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j--;
            }
	  charCounter = 0;

	  //Check up-left diagonal direction for possible flips
          j = y - 1;
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x-1, y-1) == '_' || getCharacterOnBoard(x-1, y-1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
		{
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j<y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j--;
            }
	  charCounter = 0;

	  //Check down-right diagonal direction for possible flips
          j = y + 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x+1, y+1) == '_' || getCharacterOnBoard(x+1, y+1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j>y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j++;
            }
	  charCounter = 0;
	  if (canMakeMove == true)
            return true;
        }
    }
    }
  }
  if (canMakeMove == false)
    return false;
}

/*******************************************************
FUNCTION: Make move.
PARAMETERS: Two int "x' and "y" representing coordinates, and
one bool representing either player 1 or player 2.
RETURN: Returns true if the move was able to be made and the board
was updated, otherwise return false.
DESCRIPTION: Pass in coordinates (x, y) and player 1 or 2 as a bool "turn".
Check all directions around coordinate (x,y) if a move can be made.
Local var "charCounter" keeps track of amount of characters to update,
and "canMakeMove" keeps track if a move can be made in a given direction.
If conditions are met, update board in each possible direction.
If invalid input, or if local variable "makingMove" is false, return false.
"makingMove" becomes true if characters were flipped in a direction.
 ******************************************************/
bool reversi::makeMove(int x, int y, bool turn)
{
  bool canMakeMove;
  bool makingMove = false;
  int charCounter = 0;
  int j;

  if (x < 0 || x > DIMENSION || y < 0 || y > DIMENSION)
    return false;
  else if (getCharacterOnBoard(x, y) == '$' || getCharacterOnBoard(x, y) == '#')
    return false;
  else if (getCharacterOnBoard(x, y) == '_')
    {
      if (turn == true)
	{
	 
	  //check board down direction
	  canMakeMove = false;
	  for (int i = x+1; i < DIMENSION; i++)
	    {
	      if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y) == '_' || getCharacterOnBoard(x+1, y) == '#')
		{
		  charCounter = 0;
		  break;
		}
	      else if (getCharacterOnBoard(i, y) == '$')
		{
		  charCounter++;
		}
	      else if (getCharacterOnBoard(i, y) == '#')
		{
		  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		   
		}
	      else if (getCharacterOnBoard(i, y) == '_' && i > x+1 && canMakeMove != true)
		{
		  charCounter = 0;
		  break;
		}
	    }

	  //update board down direction
	  if (charCounter > 0 && canMakeMove == true)
	    {
	      if (getCharacterOnBoard(x, y) != '#')
		{
		  updateBoard(x, y, '#');
		  p1Score++;
		}
	      for (int i = x+1; i < DIMENSION; i++)
		{
		  if (getCharacterOnBoard(i, y) == '$')
		    {
		      updateBoard(i, y, '#');
		      charCounter--;
		      p1Score++;
		      p2Score--;
		    }
		  else if (getCharacterOnBoard(i, y) == '#' || charCounter == 0)
		    break;
		}
	      makingMove = true;
	    }

	  charCounter = 0, canMakeMove = false;

	  //Check board in up direction for possible flips
	  for (int i = x-1; i < DIMENSION; i--)
	    {
	      if (i > DIMENSION || i < 0 || getCharacterOnBoard(x-1, y) == '_' || getCharacterOnBoard(x-1, y) == '#')
		{
		  break;
		}
	      else if (getCharacterOnBoard(i, y) == '$')
		{
		  charCounter++;
		}
	      else if (getCharacterOnBoard(i, y) == '#')
		{
		  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
		}
	      else if (getCharacterOnBoard(i, y) == '_' && i < x-1 && canMakeMove != true)
		{
		  charCounter = 0;
		  break;
		}
	    }

	  //update board in up direction
	  if (charCounter > 0 && canMakeMove == true)
            {
	      if (getCharacterOnBoard(x,y) != '#')
		{
		  updateBoard(x, y, '#');
		  p1Score++;
		}
              for (int i = x-1; i < DIMENSION; i--)
                {
                  if (getCharacterOnBoard(i, y) == '$')
                    {
                      updateBoard(i, y, '#');
                      charCounter--;
                      p1Score++;
                      p2Score--;
                    }
                  else if (getCharacterOnBoard(i, y) == '#' || charCounter == 0)
                    break;
                }
              makingMove = true;
            }
	  charCounter = 0, canMakeMove = false;
	 
	  
	  //Check board in left direction for possible flips
          for (int i = y-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y-1) == '_' || getCharacterOnBoard(x, y-1) == '#')
                {
		  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(x, i) == '_' && i < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }

	  //update board left direction
	  if (charCounter > 0 && canMakeMove == true)
	    {
	      if (getCharacterOnBoard(x, y) != '#')
		{
		  updateBoard(x, y, '#');
		  p1Score++;
		}
	      for (int i = y-1; i < DIMENSION; i--)
		{ 
		  if (getCharacterOnBoard(x, i) == '$')
		    {
		      updateBoard(x, i, '#');
		      charCounter--;
		      p1Score++;
		      p2Score--;
		    }
		  else if (getCharacterOnBoard(x, i) == '#' || charCounter == 0)
		    break;
		}
	      makingMove = true;
	    }
	  charCounter = 0, canMakeMove = false;

	  //Check board in right direction for possible flips
          for (int i = y+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y+1) == '_' || getCharacterOnBoard(x, y+1) == '#')
                {
		  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(x, i) == '_' && i > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }

	  //update board right direction
          if (charCounter > 0 && canMakeMove == true)
            {
	      if (getCharacterOnBoard(x, y) != '#')
		{
		  updateBoard(x, y, '#');
		  p1Score++;
		}
              for (int i = y+1; i < DIMENSION; i++)
                {
                  if (getCharacterOnBoard(x, i) == '$')
                    {
                      updateBoard(x, i, '#');
                      charCounter--;
                      p1Score++;
                      p2Score--;
                    }
                  else if (getCharacterOnBoard(x, i) == '#' || charCounter == 0)
                    break;
                }
              makingMove = true;
            }
	  charCounter = 0, canMakeMove = false;
	  	  
	  //Check board in up-right diagonal direction for possible flips
          j = y + 1;
	  for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x-1, y+1) == '_' || getCharacterOnBoard(x-1, y+1) == '#')
                {
		  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
	      j++;
            }

	  //update board up-right diagonal direction
          if (charCounter > 0 && canMakeMove == true)
            {
	      if (getCharacterOnBoard(x, y) != '#')
		{
		  updateBoard(x, y, '#');
		  p1Score++;
		}
              j = y + 1;
              for (int i = x-1; i < DIMENSION; i--)
                {
                  if (getCharacterOnBoard(i, j) == '$')
                    {
                      updateBoard(i, j, '#');
                      charCounter--;
                      p1Score++;
                      p2Score--;
                    }
                  else if (getCharacterOnBoard(i, j) == '#' || charCounter == 0)
                    break;
		  j++;
                }
              makingMove = true;
	    }
	  charCounter = 0, canMakeMove = false;
	  
	  //Check board in down-left diagonal direction for possible flips
	  j = y - 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y-1) == '_' || getCharacterOnBoard(x+1, y-1) == '#')
                {
		  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
	      j--;
            }

	  //update board down-left diagonal direction
	  if (charCounter > 0 && canMakeMove == true)
	    {
	      if (getCharacterOnBoard(x, y) != '#')
		{
		  updateBoard(x, y, '#');
		  p1Score++;
		}
	      j = y - 1;
	      for (int i = x+1; i < DIMENSION; i++)
		{
		  if (getCharacterOnBoard(i, j) == '$')
		    {
		      updateBoard(i, j, '#');
		      charCounter--;
		      p1Score++;
		      p2Score--;
		    }
		  else if (getCharacterOnBoard(i, j) == '#' || charCounter == 0)
		    break;
		  j--;
		}
	      makingMove = true;
	    }
	  charCounter = 0, canMakeMove = false;
	  
	  //check board up-left diagonal direction for possible flips
	  j = y - 1;
	  for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x-1, y-1) == '_' || getCharacterOnBoard(x-1, y-1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j--;
            }

	  //update board up-left diagonal direction
          if (charCounter > 0 && canMakeMove == true)
            {
              if (getCharacterOnBoard(x, y) != '#')
                {
                  updateBoard(x, y, '#');
                  p1Score++;
                }
              j = y - 1;
              for (int i = x-1; i < DIMENSION; i--)
                {
                  if (getCharacterOnBoard(i, j) == '$')
                    {
                      updateBoard(i, j, '#');
                      charCounter--;
                      p1Score++;
                      p2Score--;
                    }
                  else if (getCharacterOnBoard(i, j) == '#' || charCounter == 0)
                    break;
                  j--;
                }
              makingMove = true;
            }
          charCounter = 0, canMakeMove = false;

	  //check board down-right diagonal direction for possible flips
          j = y + 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y+1) == '_' || getCharacterOnBoard(x+1, y+1) == '#')
                {
                  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
	      else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j++;
            }
	  //update board down-right diagonal direction
          if (charCounter > 0 && canMakeMove == true)
            {
              if (getCharacterOnBoard(x, y) != '#')
                {
                  updateBoard(x, y, '#');
                  p1Score++;
                }
              j = y + 1;
              for (int i = x+1; i < DIMENSION; i++)
                {
                  if (getCharacterOnBoard(i, j) == '$')
                    {
                      updateBoard(i, j, '#');
                      charCounter--;
                      p1Score++;
                      p2Score--;
                    }
                  else if (getCharacterOnBoard(i, j) == '#' || charCounter == 0)
                    break;
                  j++;
                }
              makingMove = true;
            }
          charCounter = 0, canMakeMove = false;

	  if (makingMove == true)
	    return true;
	  else
	    return false;
	}	  
      else if (turn == false)
	{
	  makingMove = false;
	  //check board down direction
          charCounter = 0, canMakeMove = false;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x+1, y) == '_' || getCharacterOnBoard(x+1, y) == '$')
                {
		  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, y) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, y) == '$')
                {
                  if (charCounter > 0)
                    canMakeMove = true;
                  break;
                }
              else if (getCharacterOnBoard(i, y) == '_' && i > x+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }


          //update board down direction
          if (charCounter > 0 && canMakeMove == true)
            {
	      if (getCharacterOnBoard(x, y) != '$')
		{
		  updateBoard(x, y, '$');
		  p2Score++;
		}
	      
              for (int i = x+1; i < DIMENSION; i++)
                {
                  if (getCharacterOnBoard(i, y) == '#')
                    {
                      updateBoard(i, y, '$');
                      charCounter--;
		      p1Score--;
		      p2Score++;
                    }
                  else if (getCharacterOnBoard(i, y) == '$' || charCounter == 0)
                    break;
                }
              makingMove = true;
            }

          charCounter = 0, canMakeMove = false;

	  //Check up-direction for possible flips
	  for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x-1, y) == '_' || getCharacterOnBoard(x-1, y) == '$')
                {
		  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(i, y) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, y) == '$')
                {
		  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(i, y) == '_' && i < x-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }

	  //update board up direction
          if (charCounter > 0 && canMakeMove == true)
            {
	      if (getCharacterOnBoard(x, y) != '$')
		{
		  updateBoard(x, y, '$');
		  p2Score++;
		}

              for (int i = x-1; i < DIMENSION; i--)
                {
                  if (getCharacterOnBoard(i, y) == '#')
                    {
                      updateBoard(i, y, '$');
                      charCounter--;
                      p1Score--;
                      p2Score++;
                    }
                  else if (getCharacterOnBoard(i, y) == '$' || charCounter == 0)
                    break;
                }
              makingMove = true;
            }
	  charCounter = 0, canMakeMove = false;

	  
	  //Check left-direction for possible flips
          for (int i = y-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y-1) == '_' || getCharacterOnBoard(x, y-1) == '$')
                {
		  charCounter = 0;
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
		  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(x, i) == '_' && i < y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
            }

	  //update board left direction
          if (charCounter > 0 && canMakeMove == true)
            {
              if (getCharacterOnBoard(x, y) != '$')
                {
                  updateBoard(x, y, '$');
                  p2Score++;
                }

              for (int i = y-1; i < DIMENSION; i--)
                {
                  if (getCharacterOnBoard(x, i) == '#')
                    {
                      updateBoard(x, i, '$');
                      charCounter--;
                      p1Score--;
                      p2Score++;
                    }
                  else if (getCharacterOnBoard(x, i) == '$' || charCounter == 0)
                    break;
                }
              makingMove = true;
            }
	  charCounter = 0, canMakeMove = false;

	  //Check right direction for possible flips
          for (int i = y+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || getCharacterOnBoard(x, y+1) == '_' || getCharacterOnBoard(x, y+1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(x, i) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(x, i) == '$')
                {
		  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(x, i) == '_' && i > y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
		}
            }

	  //update board right direction
          if (charCounter > 0 && canMakeMove == true)
            {
              if (getCharacterOnBoard(x, y) != '$')
                {
                  updateBoard(x, y, '$');
                  p2Score++;
                }

              for (int i = y+1; i < DIMENSION; i++)
                {
                  if (getCharacterOnBoard(x, i) == '#')
                    {
                      updateBoard(x, i, '$');
                      charCounter--;
                      p1Score--;
                      p2Score++;
                    }
                  else if (getCharacterOnBoard(x, i) == '$' || charCounter == 0)
                    break;
                }
              makingMove = true;
            }
	  charCounter = 0, canMakeMove = false;
	  
	  //Check up-right diagonal direction for possible flips
	  j = y + 1;
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x-1, y+1) == '_' || getCharacterOnBoard(x-1, y+1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j>y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
	      j++;
            }

	  //update board up-right diagonal direction
          if (charCounter > 0 && canMakeMove == true)
            {
              if (getCharacterOnBoard(x, y) != '$')
                {
                  updateBoard(x, y, '$');
                  p2Score++;
                }
	      j = y + 1;
              for (int i = x-1; i < DIMENSION; i--)
                {
                  if (getCharacterOnBoard(i, j) == '#')
                    {
                      updateBoard(i, j, '$');
                      charCounter--;
                      p1Score--;
                      p2Score++;
                    }
                  else if (getCharacterOnBoard(i, j) == '$' || charCounter == 0)
                    break;
		  makingMove = true;
		  j++;
		}
	    }
	  charCounter = 0, canMakeMove = false;
	  
	  //Check down-left diagonal direction for possible flips
	  j = y - 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x+1, y-1) == '_' || getCharacterOnBoard(x+1, y-1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
		    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j<y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
	      j--;
            }

	  //update board down-left diagonal direction
	  if (charCounter > 0 && canMakeMove == true)
	    {
	      if (getCharacterOnBoard(x, y) != '$')
		{
		  updateBoard(x, y, '$');
		  p2Score++;
	        }

	      j = y - 1;
	      for (int i = x+1; i < DIMENSION; i++)
		{
		  if (getCharacterOnBoard(i, j) == '#')
		    {
		      updateBoard(i, j, '$');
		      charCounter--;
		      p1Score--;
		      p2Score++;
		    }
		  else if (getCharacterOnBoard(i, j) == '$' || charCounter == 0)
		    break;
		  makingMove = true;
		  j--;
		}
	    }
	  charCounter = 0, canMakeMove = false;
	  
	  //Check up-left diagonal direction for possible flips
          j = y - 1;
          for (int i = x-1; i < DIMENSION; i--)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x-1, y-1) ==  '_' || getCharacterOnBoard(x-1, y-1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
              else if (getCharacterOnBoard(i, j) == '_' && i < x-1 && j<y-1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j--;
            }

	  //update board up-left diagonal direction
          if (charCounter > 0 && canMakeMove == true)
            {
              if (getCharacterOnBoard(x, y) != '$')
                {
                  updateBoard(x, y, '$');
                  p2Score++;
                }

              j = y - 1;
              for (int i = x-1; i < DIMENSION; i--)
                {
                  if (getCharacterOnBoard(i, j) == '#')
                    {
                      updateBoard(i, j, '$');
                      charCounter--;
                      p1Score--;
                      p2Score++;
                    }
		  else if (getCharacterOnBoard(i, j) == '$' || charCounter == 0)
                    break;
                  makingMove = true;
                  j--;
                }
            }
          charCounter = 0, canMakeMove = false;

	  //Check down-right diagonal direction for possible flips
          j = y + 1;
          for (int i = x+1; i < DIMENSION; i++)
            {
              if (i > DIMENSION || i < 0 || j > DIMENSION || j<0 || getCharacterOnBoard(x+1, y+1) == '_' || getCharacterOnBoard(x+1, y+1) == '$')
                {
                  break;
                }
              else if (getCharacterOnBoard(i, j) == '#')
                {
                  charCounter++;
                }
              else if (getCharacterOnBoard(i, j) == '$')
                {
                  if (charCounter > 0)
		    canMakeMove = true;
		  break;
                    
                }
	      else if (getCharacterOnBoard(i, j) == '_' && i > x+1 && j>y+1 && canMakeMove != true)
                {
                  charCounter = 0;
                  break;
                }
              j++;
            }

	  //update board down-right diagonal direction
          if (charCounter > 0 && canMakeMove == true)
            {
              if (getCharacterOnBoard(x, y) != '$')
                {
                  updateBoard(x, y, '$');
                  p2Score++;
                }

              j = y + 1;
              for (int i = x+1; i < DIMENSION; i++)
                {
                  if (getCharacterOnBoard(i, j) == '#')
                    {
                      updateBoard(i, j, '$');
                      charCounter--;
                      p1Score--;
		    }
                  else if (getCharacterOnBoard(i, j) == '$' || charCounter == 0)
                    break;
                  makingMove = true;
                  j++;
                }
            }
          charCounter = 0, canMakeMove = false;

	  if (makingMove == true)
	    return true;
	  else
	    return false;
	}
    }
  
}

/***************************************************
FUNCTION: (game) Is Over.
PARAMETERS: none
RETURN: Integer, the value of which is determined by
the player scores and whether or not a move can be made.
DESCRIPTION: Determine player scores and whether or not
a move can be made for each player through local variables.
If at least one player can make a move, return "2". If no
moves can be made, return 1, -1, or 0 if player 1 wins,
player 2 wins, or the game ends in a tie.
 **************************************************/
int reversi::isOver() const
{
  bool player1 = true;
  bool player2 = false;
  int player1Score = getScore(player1);
  int player2Score = getScore(player2);
  bool p1CanMakeMove;
  bool p2CanMakeMove;

  p1CanMakeMove = moveCanBeMade(player1);
  p2CanMakeMove = moveCanBeMade(player2);

  if (p1CanMakeMove == true || p2CanMakeMove == true)
    return 2;
  else if (p1CanMakeMove == false && p2CanMakeMove == false)
    {
      if (player1Score > player2Score)
	return 1;
      else if (player2Score > player1Score)
	return -1;
      else if (player2Score == player1Score)
	return 0;
    }


  
}

/***********************************************
FUNCTION: Get board.
PARAMETERS: none.
RETURN: String containing the board characters.
DESCRIPTION: Create local string variable and populate
that with the characers currently on the board.
Return the string to main.
 **********************************************/
string reversi::getBoard() const 
{
  string strBoard = "";

  for (int x = 0; x < DIMENSION; x++)
    {
      for (int y = 0; y < DIMENSION; y++)
	{
	  strBoard = strBoard + getCharacterOnBoard(x, y);
	}
    }

  return strBoard;
}

/**********************************************
FUNCTION: Get score.
PARAMETERS: Bool variable representing a player.
RETURN: Int containg either player 1's score or 
player 2's score.
DESCRIPTION: Pass in bool variable representing
either p1 or p2. Then, depending on whether p1 or p2,
return that player's score.
 *********************************************/
int reversi::getScore(bool turn) const
{

  if (turn == true)
    return p1Score;
  else if (turn == false)
    return p2Score;
}
