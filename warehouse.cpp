/*
Dylan Durkee - Assignment 3
Dr. Jimi Vasko
warehouse implementation file
 */

//Include relevant libraries and warehouse header file.
#include "warehouse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//default constructor initializes productCounter to zero when class type is created.
warehouse::warehouse()
{
  productCounter = 0;
}

/**********************************************************
FUNCTION: add item
PARAMETERS: Value parameters name, id, manu, quantity, price,
discount, of appropriate types.
RETURN: Void.
DESCRIPTION: Pass in all parameters which contain information
from inventory file. Update/store inventory info into 
the relevant private members of the class type variable.
After each time function is called, increment the productCounter.
 *********************************************************/
void warehouse::addItem(string name, int id, string manu, int quantity, double price, double discount)
{
  
  productNames[productCounter] = name;
  ids[productCounter] = id;
  manufacturers[productCounter] = manu;
  quantities[productCounter] = quantity;
  prices[productCounter] = price;
  discounts[productCounter] = discount;

  productCounter++;

  return;


}

/*********************************************************
FUNCTION: Display products.
PARAMETERS: None.
RETURN: Void.
DESCRIPTION: First, set decimal precision. Then, update inventory
list by calling sortByQuantity function, which is a bubble
sort that will sort the inventory list by quantity (described
below). Then, format and output the inventory list.
 ********************************************************/
void warehouse::displayProducts()
{
  
  int x;

  cout << fixed;
  cout << setprecision(2);

  sortByQuantity();

  cout << setw(40) << setfill(' ') << left <<"Name" << "  " << right << "ID";
  cout << setw(15) << setfill(' ') << right << "Quantity";
  cout << setw(10) << setfill(' ') << right << "Price" << endl;
  
  for (x = 0; x < productCounter-1; x++)
    {
      cout << setw(40) << setfill(' ') << left << productNames[x] << right << ids[x];
      cout << setw(15) << setfill(' ') << right << quantities[x];
      cout << setw(10) << setfill(' ') << right << prices[x];
      cout << endl;
    }
    
}

/********************************************************
FUNCTION: Search.
PARAMETERS: Int id, the user's entered item id number.
RETURN: Integer.
DESCRIPTION: Pass in user's entered item id number.
Create local counter variable x. Local bool variable
itemFound is initialized as false, and becomes true if the
user's entered item id number matches an item's id number.
Local variable locationIndex then stores the index of this
item's location. Finally, if the item is found, return the
index location.
 *******************************************************/
int warehouse::search(int id) const
{
  int x;
  bool itemFound = false;
  int locationIndex;
  
  for (x = 0; x < productCounter-1; x++)
    {
      if (ids[x] == id)
	{
	  itemFound = true;
	  locationIndex = x;
	}
    }
  
  if (itemFound == true && quantities[locationIndex] > 0)
    return locationIndex;
  else
    return -1;

}

/*************************************************
FUNCTION: Get item price.
PARAMETERS: Pass in one integer parameter.
RETURN: Integer (price of item)
DESCRIPTION: First, the function is constant since we
don't want to update anything in the class about the item price.
In main, pass in the index of the id that the user enters.
This function then returns the price of the index.
Because we are returning an integer, I do some manipulation 
by typecasting float and multipliying by 1000 in order
to retain any decimals that would otherwise be 
truncated.
 ************************************************/
int warehouse::getItemPrice(int index) const
{ 
  return int((float(prices[index])*1000));
}

/************************************************
FUNCTION: Get item discount.
Parameters: Pass in item index of type int.
RETURN: Integer (discount amount of item).
DESCRIPTION: Pass in the index location of the user's
requested item (index). Then, return the discount amount
of this item to main. As in above functions, I
typecast and multiply the amount by 1000 before returning
so the decimal points are retained.
 ***********************************************/
int warehouse::getItemDiscount(int index) const
{ 
  return int((float(discounts[index])*1000));
}

/****************************************************
FUNCTION: Update item quantity.
PARAMETERS: Two ints - one is the index location of 
requested item, one is the amount of requested item.
RETURN: True or false - return true if we have that amount in stock.
Otherwise, return false.
DESCRIPTION: Pass in item index and amount requested.
Check to see if the amount requested is less than
the quantities in stock. If it is, update the quantity
and return true to main. Otherwise, return false.
 ***************************************************/
bool warehouse::updateItemQuantity(int index, int amount)
{
  if (amount <= quantities[index])
    {
      quantities[index] = quantities[index] - amount;
      return true;
    }
  else
    return false;
}

/***************************************************
FUNCTION: Sort by quantity (private member)
PARAMETERS: None.
RETURN: Void.
DESCRIPTION: This function uses the methods of bubble sort
and swap in one function. I declare six variables of the same types
of the private member arrays in my class variable which
store the inventory information. I trace through these arrays
and first compare the values of the neighboring indexes
of the quantities array. If the value stored in the next
index [i+1] is larger than the value stored in index [i],
I swap the two values, using a temporary variable to mediate
the swap. Then, I must swap the values stored in the other
arrays between the same indexes. The two for loops
iterate over all indexes in all of the arrays, so that
the entire inventory will be re-organized and sorted
by most quantity to least quantity.
 **************************************************/
void warehouse::sortByQuantity()
{
  int tempQuantity;
  string tempProductName;
  int tempid;
  string tempManu;
  double tempPrice;
  double tempDiscount;
  int i;
  int j;

  for (j = 0; j < productCounter-2; j++)
    {
      for (i = 0; i< productCounter-2; i++)
	{
	  if (quantities[i] < quantities[i+1])
	    {
	      //swap(list[j], list[j+1])
	      tempQuantity = quantities[i];
	      quantities[i] = quantities[i+1];
	      quantities[i+1] = tempQuantity;
	      
	      tempProductName = productNames[i];
	      productNames[i] = productNames[i+1];
	      productNames[i+1] = tempProductName;
	      
	      tempid = ids[i];
	      ids[i] = ids[i+1];
	      ids[i+1] = tempid;
	      
	      tempManu = manufacturers[i];
	      manufacturers[i] = manufacturers[i+1];
	      manufacturers[i+1] = tempManu;
	      
	      tempPrice = prices[i];
	      prices[i] = prices[i+1];
	      prices[i+1] = tempPrice;
	      
	      tempDiscount = discounts[i];
	      discounts[i] = discounts[i+1];
	      discounts[i+1] = tempDiscount;
	    }
	}
    }
  return;
  
  return;
}
