//Including appropriate header files for program.
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//Map is a 10x10 grid, so I declare two constants for maximum rows and columns in map.
const int MAXROWS = 10;
const int MAXCOLUMNS = 10;

//function prototypes
void readandstore(ifstream&, char[][MAXCOLUMNS]);
int findlargestarea(char[][MAXCOLUMNS]);

int main()
{
  /*Declaring variables for file input, and a char array
    to store the characters in the map file.*/
  ifstream infile;
  string filename;
  char map[MAXROWS][MAXCOLUMNS];

  //Prompt user for map file input until a correct file is entered
  do
    {
      cout << "Please enter map: ";
      cin >> filename;
      
      infile.open(filename.c_str());
    }
  while (!infile.is_open());
  
  cout << endl;
  
  //Call function to read and store characters in map file into character array.
  readandstore(infile, map);

  //Output max area in the police station by calling function "findlargestarea."
  cout << "Max area in the police station is " << findlargestarea(map) << endl;
  
  
  return 0;
}

/***********************************************************
FUNCTION: Read (map file) and store into character array "map"
PARAMETERS: One reference parameter for input file of type
ifstream, and one parameter for the 2D char array that will
contain the map file data.
RETURN: Void.
DESCRIPTION: File is initially opened in main. Then, readandstore
function is called, which, while the end of file is not yet
reached, stores the 0's and 1's from the map input file into
the appropriate indexes of the 2d map array.  
***********************************************************/
void readandstore(ifstream& infile, char map[][MAXCOLUMNS])
{
  int maxRows = 10;
  int maxColumns = 10;
  
  while (!infile.eof())
    {
      for (int x = 0; x < maxRows; x++)
	{
	  infile >> map[x][0];
	  for (int y = 1; y < maxColumns; y++)
	    {
	      infile >> map[x][y];
	    }
	}
    }
  
  return;
}

/************************************************************
FUNCTION: Find largest area (of square sub-matrix of 0's).
PARAMETERS: One 2D character array.
RETURN: Integer value containg maximum area of 0's in the map.
DESCRIPTION: Pass in 2D array containing 10x10 map. Then,
cycle through rows and columns until the character '0' is read.
Once a character '0' is read, cycle through the row and column
to detect for adjacent 0s. Store the number of 0's in that column,
and the number of 0's in that row, in the appropriate local 
variables (rowZeroCount and columnZeroCount). Cases are present
to compare tha value of rowZeroCount and columnZeroCount so that
if they are equal, the program has found the largest square
sub-matrix of 0's. Calculate the area from these values, and
return the area as an integer.
 ***********************************************************/
int findlargestarea(char map[][MAXCOLUMNS])
{
  int rowZeroCount;
  int columnZeroCount;
  int maxArea = 0;
  
  int maxRows = 10, maxColumns = 10;
  
  for (int x = 0; x < maxRows; x++)
    {
      rowZeroCount = 0;
      for (int y = 0; y < maxColumns; y++)
	{
	  if (map[x][y] == '0')
	    {
	      columnZeroCount = 0;
	      for (int z = x; z < maxRows; z++)
		{
		  if (map[z][y] == '0')
		    {
		      columnZeroCount++;
		    }
		  else
		    break;
		}

	      if (columnZeroCount > 1)
		{
		  for (int w = y; w < maxColumns; w++)
		    {
		      if (map[x][w] == '0')
			{
			  rowZeroCount++;
			}
		      else
			break;
		    }
		}
	       
	      if (columnZeroCount == rowZeroCount)
		break;
	      else
		{
		  rowZeroCount = 0;
		  rowZeroCount++;
		}
	    }
	}
      
      if (columnZeroCount == rowZeroCount && rowZeroCount > 1)
	break;
    }
  
  maxArea = pow(rowZeroCount, 2);
  maxArea = int(maxArea);
  
  return maxArea;
}




