//Include relevant libraries that program uses.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Declare constant that represents the maximum size of the warehouse's product list.
const int MAXELEMENTS = 20;

//Declare struct productType, which contains the relevant fields for each piece of inventory.
struct productType
{
  string productName;
  int id;
  string manufacturer;
  int quantitiesInStock;
  double price;
  double discount;
};

//prototype functions
productType readAndStore(ifstream&);
void displayInventory(productType list[], int);
bool searchID(int, productType list[], int);
int retrieveItemLocation(int, productType list[], int);
void swap(productType&, productType&);
void bubbleSort(int, productType list[]);
void outputTotalCosts(double, double);

int main()
{
  //Declare array of structs of type productType to store inventory info.
  //Also declare relevant variables to store file and filename.
  //Finally, int variable numShipments is used to store the number of
  //    shipments that user will order from warehouse.
  productType productList[MAXELEMENTS];
  ifstream infile;
  string filename;
  int numShipments;
  
  //Prompt use to enter a data file.
  do
    {
      cout << "Enter data file: ";
      cin >> filename;
      
      cout << endl;
      
      infile.open(filename.c_str());
    }
  while ( !infile.is_open());
  
  //Counter to store the actual size of the productList array (max size 20).
  int invCount = 0;
  
  //Initialize 0th element of productList array, calling function readAndStore.
  productList[invCount] = readAndStore(infile);
  
  //Populate the rest of the inventory into the rest of the productList array
  //    by calling the function readAndStore and passing in the file.
  while (!infile.eof())
    {
      invCount++;
      
      productList[invCount] = readAndStore(infile);
    }
  
  //Prompt user to enter number of shipments.
  cout << endl;
  cout << "Enter amount of shipments: ";
  cin >> numShipments;
  cout << endl;
  
  //Loop user prompt for number of shipments until valid input entered.
  while (cin.fail() || numShipments < 1)
    {
      cin.clear();
      cin.ignore(100, '\n');

      cout << "Enter amount of shipments: ";
      cin >> numShipments;
      cout << endl;
    }
  
  //Call function which displays the warehouse inventory to the user
  displayInventory (productList, invCount);
    
  /*
    Relevant variables for rest of code in int main: "orderNum" stores
    the user's current order number, and increments with each successive
    order. "itemNum" stores the ID number that the user enters. "itemLocation"
    stores the index location of the desired item by calling the function retrieveItemLocation.
    "amountToShip" stores the quantity of the item that the user wishes to purchase.
    "totalCost," and "discounts" update and store the total cost, and discounts of the order
    respectively. "itemNumExists" stores true or false according to whether the user entered
    a valid item ID - it does so by calling the function searchID.
   */
  int orderNum = 1;
  int itemNum;
  int itemLocation;
  int amountToShip;
  double totalCost = 0;
  double discounts = 0;
  bool itemNumExists;
  
  //Loop the following code until number of desired shipments equals 0.
  while (numShipments != 0)
    {
      //Prompt user for item number, store into itemNum.
      cout << "(order " << orderNum << ") Enter item no: ";
      cin >> itemNum;
      cout << endl;
      
      //Check if user's entered item number exists, 
      //  and if so retrieve the index location in the array.
      itemNumExists = searchID(itemNum, productList, invCount);
      itemLocation = retrieveItemLocation(itemNum, productList, invCount);

      //Prompt user for item number until a valid input is entered.
      while (cin.fail() || itemNumExists == false || productList[itemLocation].quantitiesInStock == 0)
	{
	  cin.clear();
	  cin.ignore(100, '\n');

	  cout << "Item not found or out of stock, please try again" << endl;
	  cout << "(order " << orderNum << ") Enter item no: ";
	  cin >> itemNum;
	  
	  itemNumExists = searchID(itemNum, productList, invCount);
	  itemLocation = retrieveItemLocation(itemNum, productList, invCount);

	  cout << endl;
	}
      
      //Once a valid item number is entered, prompt user for amount they wish to purchase.
      cout << "Enter amount to ship: ";
      cin >> amountToShip;
      cout << endl;
      
      //Prompt user for amount of item they wish to purchase until valid input entered.
      while (cin.fail() || amountToShip < 1 || amountToShip > productList[itemLocation].quantitiesInStock)
	{
	  cin.clear();
	  cin.ignore(100, '\n');

	  cout << "Enter amount to ship: ";
	  cin >> amountToShip;
	  cout << endl;
	}
      
      //Calculate and/or update totalCost and applied discounts of user's order.
      totalCost = totalCost + (amountToShip*productList[itemLocation].price);
      discounts = discounts + (amountToShip*productList[itemLocation].price*productList[itemLocation].discount);
      cout << "Ok shipment will be on the way shortly" << endl << endl;
      
      productList[itemLocation].quantitiesInStock = productList[itemLocation].quantitiesInStock - amountToShip;
      
      numShipments--;
      orderNum++;
      
      if (numShipments != 0)
	displayInventory(productList, invCount);
    }
  
  //Once user's order is complete, output the total costs and discounts.
  outputTotalCosts(totalCost, discounts);
  
  return 0;
}

/**********************************************************
FUNCTION: Read and store (inventory data)
PARAMETERS: One ifstream parameter, passed by reference.
RETURN TYPE: Returns value "r" of type productType.
DESCRIPTION: Pass in file by reference, declare local variable
r of type productType. Populate r from a line in the file,
and return r.
**********************************************************/
productType readAndStore(ifstream& infile)
{
  productType r;
  
  infile >> r.productName;
  infile >> r.id;
  infile >> r.manufacturer;
  infile >> r.quantitiesInStock;
  infile >> r.price;
  infile >> r.discount;
  
  return r;
}

/*********************************************************
FUNCTION: Display (warehouse) inventory.
PARAMETERS: One array of type productType, one integer, both 
are value parameters.
RETURN TYPE: void
DESCRIPTION: Pass inventory list (array) of type productType,
containing the warehouse inventory info. Also pass in the size
of the array (parameter "count"). Call function "bubbleSort"
to sort the parameter "list" by the quantity of each item.
Finally, format and output the update and sorted warehouse
inventory.
 *********************************************************/
void displayInventory(productType list[], int count)
{
  cout << fixed;
  cout << setprecision(2);
  
  bubbleSort(count, list);
  
  cout << setw(40) << setfill(' ') << left << "Name" << "  " << right << "ID";
  cout << setw(15) << setfill(' ') << right << "Quantity";
  cout << setw(10) << setfill(' ') << right << "Price" << endl;
  
  for (int x = 0; x < count; x++)
    {
      cout << setw(40) << setfill(' ') << left << list[x].productName << right << list[x].id;
      cout << setw(15) << setfill(' ') << right << list[x].quantitiesInStock;
      cout << setw(10) << setfill(' ') << right << list[x].price;
      cout << endl;
    }
  
  return;
}

/**********************************************************
FUNCTION: Search ID (search through inventory stored in list)
PARAMETERS: One type int, one array of type productType, and one
type int which stores size of array. All value-type.
RETURN: bool type
DESCRIPTION: Pass in user's ID number input, inventory array,
and the array size. Create local bool variable and initialize to false
Then, search through array and compare user's entered ID number
to the inventory ID numbers, setting bool variable equal to true
if the ID number exists. If the ID exists, store the index 
of the ID into variable "location." Check to see if there is
still quantity in stock of that item. If not, return false.
Otherwise, still return true.
 *********************************************************/
bool searchID(int itemNumber, productType list[], int count)
{
  bool itemNumberExists = false;
  int location;
  
  for (int x = 0; x < count; x++)
    {
      if (list[x].id == itemNumber)
	{
	  itemNumberExists = true;
	  location = x;
	  break;
	}
    }
  
  if (itemNumberExists == true)
    {
      if (list[location].quantitiesInStock <= 0)
	itemNumberExists == false;
    }
  return itemNumberExists;
}

/*********************************************************
FUNCTION: Retrieve item location.
PARAMETERS: One int of user's item ID input, inventory list
array of type productType, and that list's size (count) of type
int.
RETURN: Integer value (index location of ID number)
DESCRIPTION: Check to see if user's item ID input exists,
and if so, store the index of that item into local variable
"location." Return item location.
 ********************************************************/
int retrieveItemLocation(int itemNumber, productType list[], int count)
{
  bool itemNumberExists = false;
  int location;
  
  for (int x = 0; x < count; x++)
    {
      if (list[x].id == itemNumber)
	{
	  itemNumberExists = true;
	  location = x;
	  break;
	}
    }
  
  if (itemNumberExists == true)
    {
	return location;
    }
}

/*****************************************************
FUNCTION: Swap.
PARAMETERS: Reference parameters x and y of type productType.
RETURN: void
DESCRIPTION: Swap x and y through local variable temp of type
productType.
 ****************************************************/
void swap(productType& x, productType& y)
{
  productType temp = x;
  x = y;
  y = temp;
  
  return;
}

/***********************************************************
FUNCTION: Bubble sort.
PARAMETERS: Size of productType array of type int, and inventory
list parameter of type productType.
RETURN: void.
DESCRIPTION: Search through array parameter, and compare each item's
quantity. Call the "swap" function to swap items in the inventory
list, sorting by quantity from greatest quantity in inventory,
to least quantity.
 **********************************************************/
void bubbleSort(int size, productType list[])
{
  for (int i = 0; i < size - 1; i++)
    {
      for (int j = 0; j < size - 1; j++)
	{
	  if (list[j].quantitiesInStock < list[j+1].quantitiesInStock)
	    {
	      swap(list[j], list[j+1]);
	    }
	}
    }
  
  return;
}

/************************************************************
FUNCTION: Output total costs.
PARAMETERS: Total cost and discount parameters passed from function
main.
RETURN: void.
DESCRIPTION: Calculate the cost after discount from the parameters
that are passed in. Then, format and output the invoice summary 
to the user: the user's total cost, discounts applied, and the
total cost after discounts.
 ***********************************************************/
void outputTotalCosts(double totalCost, double discounts)
{
  cout << fixed;
  cout << setprecision(2);
  
  double costAfterDiscount = totalCost - discounts;
  
  cout << "Invoice summary" << endl;
  cout << setw(30) << setfill(' ') << left << "Total cost" << right << totalCost << endl;
  cout << setw(30) << setfill(' ') << left << "Discounts" << right << discounts << endl;
  cout << setw(30) << setfill(' ') << left << "Total cost after discounts" << right << costAfterDiscount << endl;
  cout << endl;
  
  return;
  
}

