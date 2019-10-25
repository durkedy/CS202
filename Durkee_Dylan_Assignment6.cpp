/****************************************
Assignment 6 - Triangle Matrices
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003

Due date: 24 October 2019
****************************************/

//Include appropriate libraries.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  //Create variables to open file/filestream.
  ifstream infile;
  string filename;
  int **trianglePtr;
  int *subMatrixPtr;
  int numTestCases;
  int numRows;
  int numSubTriangles;
  
  //Attempt to open file.
  do
    {
      cout << "Enter filename: ";
      cin >> filename;
      cout << endl;

      infile.open(filename.c_str());
    }
  while(!infile.is_open());

  //Store the first number in file, the number of test cases.
  infile >> numTestCases;

  //Read in from file and make calculations for smallest sub-matrices
  //until the end of file.
  int triangleNum = 1;
  while (numTestCases > 0)
    {
      //Store in number of rows and sub triangles from file.
      infile >> numRows >> numSubTriangles;

      //Allocate memory to trianglePtr pointer which stores the triangle array,
      //and to subMatrixPtr which stores the lowest number sub matrices
      trianglePtr = new int*[numRows];
      subMatrixPtr = new int[numSubTriangles];

      //Initialize all elements of subMatrixPtr = 0 
      for (int x=0; x<numSubTriangles; x++)
	subMatrixPtr[x] = 0;

      //Make jagged array for trianglePtr.
      for (int i=0; i < numRows; i++)
	trianglePtr[i] = new int[i+1];

      //Populate entire trianglePtr array from file.
      for (int i=0; i<numRows; i++)
	{
	  for (int j=0; j<i+1; j++)
	    infile >> trianglePtr[i][j];
	}

     
      //initialize sum and accountedFor variables.
      int sum=0;
      bool accountedFor = false;
      
      //Case 1: check individual indices in trianglePtr array
      for (int i=0; i<numRows; i++)
        {
          for (int j=0; j<i+1; j++)
            {
              for (int y=0; y<numSubTriangles; y++)
                {
                  if (trianglePtr[i][j] < subMatrixPtr[y] && accountedFor != true)
                    {
		      subMatrixPtr[y] = trianglePtr[i][j];
		      accountedFor = true;
                    }
                }
              accountedFor = false;
            }
        }
                  
      
      //Case 2: start from 0th index of 0th row, increasing size of matrix.
      for (int i=0; i<numRows; i++)
	{
	  for (int j=0; j<i+1; j++)
	    {
	      sum = sum + trianglePtr[i][j];
	    }

	  if (i>0){
	  for (int x=0; x<numSubTriangles; x++)
	    {
	      if (sum < subMatrixPtr[x] && accountedFor != true)
		{
	   
		  subMatrixPtr[x] = sum;
		  accountedFor = true;

		}
	    }
	  }
	  accountedFor = false;
	}
      
      
      //Case 3: Start at index 1 of matrix decrease size until reaching
      //the last index of the last row.
      for (int i=1; i<numRows; i++)
	{
	  sum = 0, accountedFor = false;

	  for (int j=i; j<numRows; j++)
	    {
	      for (int k=i; k<j+1; k++)
		sum = sum + trianglePtr[j][k];
	      
	      for (int x=0; x<numSubTriangles; x++)
		{
		  if (sum < subMatrixPtr[x] && accountedFor != true)
		    {
		      
		      for (int y=0; y<numSubTriangles; y++)
			{
			  
			  if(subMatrixPtr[x] < subMatrixPtr[y] && subMatrixPtr[x-1] != subMatrixPtr[x-2])
			    {
			      subMatrixPtr[y] = subMatrixPtr[x];
			      break;
			    }
			}
		      
		      if (accountedFor!=true){
		      subMatrixPtr[x] = sum;
		      accountedFor = true;}
		    }
		}
	      accountedFor = false;
	    }
	}
      
      //Case 4: Check from bottom left index to middle of triangle.
      int counter = 0;
      for (int n=1; n<numRows; n++)
	{
	  accountedFor = false;
	  sum = 0;
	  for (int i=n; i<numRows; i++)
	    {
  
	      for (int j=0; j<i-counter; j++)
		sum = sum + trianglePtr[i][j];
	      
	      for (int y=0; y<numSubTriangles; y++)
		{
		  if (sum<subMatrixPtr[y] && accountedFor != true)
		    {
		      subMatrixPtr[y] = sum;
		      accountedFor = true;
		    }
		}
	      accountedFor = false;
	    }
	  if (n>0)
	    counter++;
	}
      
      //Output the lowest sub triangles.
      cout << "Triangle " << triangleNum << ": " << endl;
      for (int l=0; l<numSubTriangles; l++)
	cout << subMatrixPtr[l] << " " << endl;
      cout << endl;
      
      //Deallocate memory before moving on to next test case
      for (int i=0; i<numRows; i++)
	delete[] trianglePtr[i];

      //Deallocate memory.
      delete[] trianglePtr;
      delete[] subMatrixPtr;
      
      //Increment triangle number, decrement number of test cases left.
      numTestCases--;
      triangleNum++;
    }

  //Before program terminates, set pointers to NULL.
  trianglePtr = NULL;
  subMatrixPtr = NULL;

  return 0;
}
