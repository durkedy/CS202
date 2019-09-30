/*************************
Assignment 4 main.cpp file
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
 ************************/

//Include appropriate header/libraries.
#include "reversi.h"
#include <iostream>
#include <string>
using namespace std;

//Main function prototypes, one to output board and
//one to output player scores.
void outputBoard(reversi, game, string);
void outputPlayerScores(bool, bool, reversi);


int main()
{

  //Declare variables of type reversi, game, and string.
  //String variable "reversiBoard" contains the game board.
  reversi newReversi;
  game newGame;
  string reversiBoard;

  cout << endl;

  /*Declare two variables to represent p1 and p2, one int that
    determines if the game is over and who wins, two wints to store
    the coordinates typed in by user, and another bool to determine
    if a player can make a move.
   */
  bool player1 = true;
  bool player2 = false;
  int gameIsOver = 2;
  int coord1;
  int coord2;
  bool canMakeMove;
  
  //While game is not over (gameIsOver == 2), keep playing game.
  while (gameIsOver == 2)
    {
      //Output board and player scores (these are user-defined functions in main)
      outputBoard(newReversi, newGame, reversiBoard);
      outputPlayerScores(player1, player2, newReversi);

      
      /*Determine if player1 can make a move by calling moveCanBeMade function from
	reversi class. If p1 can make a move, prompt for coordinates and check 
	validity of the coordinates. If coords are valid, update board.
	If p1 can't make move, prompt player2 instead.
       */
      if (newReversi.moveCanBeMade(player1) == true){
      cout << "Player 1: ";
      cin >> coord1 >> coord2;
      cout << endl;

      canMakeMove = newReversi.makeMove(coord1, coord2, player1);
  
      while (canMakeMove == false || cin.fail())
	{
	  cin.clear();
	  cin.ignore(100, '\n');

	  cout << "Player 1: ";
	  cin >> coord1 >> coord2;
	  cout << endl;

	  canMakeMove = newReversi.makeMove(coord1, coord2, player1);
	  }
      }
      else if (newReversi.moveCanBeMade(player2) == true)
	{
	  cout << endl;
	  cout << "Player 1 passes" << endl;
	  
	  cout << "Player 2: ";
	  cin >> coord1 >> coord2;
	  cout << endl;

	  canMakeMove = newReversi.makeMove(coord1, coord2, player2);
	  while (canMakeMove == false || cin.fail())
	    {
	      cin.clear();
	      cin.ignore(100, '\n');

	      cout << "Player 2: ";
	      cin >> coord1 >> coord2;
	      cout << endl;

	      canMakeMove = newReversi.makeMove(coord1, coord2, player2);
	    }
	}
	  
      //output board and scores.
      outputBoard(newReversi, newGame, reversiBoard);
      outputPlayerScores(player1, player2, newReversi);
         
      /*Determine if player2 can make a move by calling moveCanBeMade function from
        reversi class. If p2 can make a move, prompt for coordinates and check
        validity of the coordinates. If coords are valid, update board.
        If p2 can't make move, prompt player1 instead.
      */

      if (newReversi.moveCanBeMade(player2) == true){  
      cout << "Player 2: ";
      cin >> coord1 >> coord2;
      cout << endl;
      
      canMakeMove = newReversi.makeMove(coord1, coord2, player2);
      while (canMakeMove == false || cin.fail())
	{
	  cin.clear();
	  cin.ignore(100, '\n');

	  cout << "Player 2: ";
	  cin >> coord1 >> coord2;
	  cout << endl;

	  canMakeMove = newReversi.makeMove(coord1, coord2, player2);
	}
      }
      else if (newReversi.moveCanBeMade(player1) == true)
	{
	  cout << "Player 2 passes" << endl;
	  
	  cout << "Player 1: ";
	  cin >> coord1 >> coord2;
	  cout << endl;

	  canMakeMove = newReversi.makeMove(coord1, coord2, player1);

	  while (canMakeMove == false || cin.fail())
	    {
	      cin.clear();
	      cin.ignore(100, '\n');

	      cout << "Player 1: ";
	      cin >> coord1 >> coord2;
	      cout << endl;

	      canMakeMove = newReversi.makeMove(coord1, coord2, player1);
	    }
	}

      //Check if game is over.
      gameIsOver = newReversi.isOver();
    }
  //Output final board and final player scores.
  cout << endl;
  outputBoard(newReversi, newGame, reversiBoard);
  outputPlayerScores(player1, player2, newReversi);

  //Output who wins depending on the value of "gameIsOver".
  if (gameIsOver == 1)
    cout << "Player 1 wins!" << endl << endl;
  else if (gameIsOver == -1)
    cout << "Player 2 wins!" << endl << endl;
  else if (gameIsOver == 0)
    cout << "Game ends in a tie!" << endl << endl;

  return 0;
}

/****************************************************
FUNCTION: Output game board.
PARAMETERS: Reversi type, game type, and string type.
RETURN: void.
DESCRIPTION: User-defined function to make board output easier.
Call reversi member function "getBoard" to store the board in
"board." Then, double for loop outputs the board.
 ***************************************************/
void outputBoard(reversi newReversi, game newGame, string board)
{
  board = newReversi.getBoard();

  for (int x = 0; x < newGame.DIMENSION; x++)
    {
      if (x == 0)
        {
          cout << "   ";
          for(int i = 0; i < newGame.DIMENSION; i++)
            {
              cout << i << " ";
            }
          cout << endl;
        }

      cout << x;
      cout << "  ";

      for (int y = 0; y < newGame.DIMENSION; y++)
        {
          cout << board[newGame.DIMENSION*x + y];
          cout << " ";
        }


      cout << endl;
    }
}

/*************************************************
FUNCTION: Output player scores.
PARAMETERS: Two bools representing player 1 and player2,
and one reversi parameter.
RETURN: void.
DESCRIPTION: Pass is p1 and p2 bools and the reversi class variable.
Call "getScore" function from reversi class to output the score
of each player.
 ************************************************/
void outputPlayerScores(bool player1, bool player2, reversi newReversi)
{
  cout << endl;
  cout << "Player1 Score = ";
  cout << newReversi.getScore(player1);
  cout << endl;
  cout << "Player2 Score = ";
  cout << newReversi.getScore(player2);
  cout << endl << endl;
}

