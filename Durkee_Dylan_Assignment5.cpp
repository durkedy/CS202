/*************************
Dylan Durkee
Assignment 5 - Hamburglar
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
*************************/

//Include relevant libraries.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{

  /*Declare variables to store and open file. My pointer to create dynamic arrays in main
    is burgerPtr. "numTestCases" stores the number of test cases in file, and "testCaseNum"
    is initialized to 1 and incremented by 1 for each successive test case in the file. "Capacity"
    stores the capacity of the dynamic array, and "size" represents an element of the dynamic array.
   */
  ifstream infile;
  string filename;
  int *burgerPtr;
  int numTestCases;
  int testCaseNum = 1;
  int capacity;
  int size;
  
  //Open file.
  do
    {
      cout << "Enter filename: ";
      cin >> filename;
      cout << endl;
      
      infile.open(filename.c_str());
      
    }
  while (!infile.is_open());
  
  //Store the number of test cases (first number in file).
  infile >> numTestCases;

  int *tempBurgerPtr;
  //End of file loop.
  while(!infile.eof())
    {
      //At the start of each test case iteration, initialize variables.
      //Store first number in new dynamic array.
      size = 0;
      capacity = 1;
      
      burgerPtr = new int[capacity];
      infile >> burgerPtr[size];

      //Read in numbers from file until "-1" is read.
      //If size of dynamic array reaches the array's capacity,
      //resize array.
      while ( burgerPtr[size] 1= -1)
	{
	  size++;
	
	  if (size == capacity)
	    {
      	      
	      tempBurgerPtr = new int[capacity+1];

	      for (int x = 0; x < capacity; x++)
		tempBurgerPtr[x] = burgerPtr[x];

	      capacity = capacity + 1;

	      delete[] burgerPtr;

	      burgerPtr = tempBurgerPtr;

	      //tempBurgerPtr = NULL;

	    }
	 
	  infile >> burgerPtr[size];
	}
      
  
      /*
      for (int i = 0; i < capacity; i++)
	cout << "burgerPtr[" << i << "} = " << burgerPtr[i] << " ";
      cout << endl;
      */

      //If there are still test cases, calculate max burgers hamburglar can steal and output it.
      if (numTestCases > 0)
	{
	  
	  int maxBurgers = 0;

	  for (int x = 0; x < capacity; x++)
	    {
	      if (burgerPtr[x] > maxBurgers)
		maxBurgers = burgerPtr[x];
	    }

	  int burgerNum= 0;
	  int tempMaxBurgers = 0;
	  int maxBurgersToSteal = 0;

	  for (int y = 1; y < maxBurgers+1; y++)
	    {
	      burgerNum = y;

	      for (int x = 0; x < capacity; x++)
		{
		  if (burgerPtr[x] >= burgerNum)
		    tempMaxBurgers = tempMaxBurgers + burgerNum;
		}
	      if (maxBurgersToSteal < tempMaxBurgers)
		maxBurgersToSteal = tempMaxBurgers;
	      tempMaxBurgers = 0;
	    }


	  cout << "Case " << testCaseNum << ": " << maxBurgersToSteal << endl;
	}
   
      numTestCases--;
      testCaseNum++;
      
      delete[] burgerPtr;
    }
  
  //delete[] burgerPtr;
  
  burgerPtr = NULL;
  tempBurgerPtr = NULL;
  return 0;
}

