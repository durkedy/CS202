/*
Dylan Durkee - Assigment 3
Dr. Jimi Vasko
warehouse main.cpp file
 */
//include appropriate libraries to be used in program.
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "warehouse.h"
using namespace std;

int main()
{

  //declare variable of type "warehouse" which stores inventory information from file,
  //and contains all of the relevant member functions.
  //Also declare ifstream variable to store file and string to store the file's name.
  warehouse invList;
  ifstream infile;
  string filename;

  //Declare relevant variables to pass as parameters to the function displayProducts
  string name;
  int id;
  string manu;
  int quantity;
  double price;
  double discount;

  //Store number of shipments (orders) that the user wants.
  int numShipments;

  //Prompt user to enter file and open file.
 do
  {
    cout << "Enter a file: ";
    cin >> filename;
    cout << endl;
    
    infile.open(filename.c_str());
  }
 while (!infile.is_open());

 //Read in information from file, and store into the relevant variables/
 //Then, pass the variables as parameters to the warehouse function "addItem"
 //which will then store the information in the relevant members of the class.
 //Repeat this process until end of file is reached.
 do
   {
     infile >> name; 
     infile >> id;
     infile >> manu;
     infile >> quantity;
     infile >> price;
     infile >> discount;
     
     invList.addItem(name, id, manu, quantity, price, discount);
   }
 while (!infile.eof());

 //Prompt user to enter amount of shipments in their order.
 cout << endl;
 cout << "Enter amount of shipments: ";
 cin >> numShipments;
 cout << endl;

 //Check for input failure.
 while (cin.fail() || numShipments <= 0)
   {
     cin.clear();
     cin.ignore(100, '\n');

     cout << "Enter amount of shipments: ";
     cin >> numShipments;
     cout << endl;
   }

 //Declare relevant variables to store information.
 //orderNum and amountToShip will store the user's current order number
 //and the amount of the item the user wants to order, respectively.
 //itemNum stores the user's entered item id number, itemLocation
 //stores the index of the id if the entered id is valid, and itemPrice
 //and itemDiscount store the price and discount, respectively.

 int orderNum = 1;
 int itemNum;
 int itemLocation;
 int itemPrice;
 int itemDiscount;
 int amountToShip;
 double totalCost = 0;
 double totalDiscounts = 0;
 int updateQuantity;

 //Iterate through while loop until the user's number of shipments equals zero.
 //In other words, complete amount of orders that the user entered.
while (numShipments != 0)
   {
     //Call class function to display the warehouse inventory menu to user.
     invList.displayProducts();

     //Prompt user to enter id number. Store id number in itemNum.
     cout << "(order " << orderNum << ") Enter item no: ";
     cin >> itemNum;
     cout << endl;
     
     //Get index location of user's itemNum. Call warehouse class "search" function.
     itemLocation = invList.search(itemNum);
     
     //Check for input failure.
     while (cin.fail() || itemLocation == -1)
       {
	 cin.clear();
	 cin.ignore(100, '\n');

	 cout << "Item not found or out of stock, please try again" << endl;
	 cout << "(order " << orderNum << ") Enter item no: ";
	 cin >> itemNum;
	 cout << endl;
	 
	 itemLocation = invList.search(itemNum);
       }
     
     //Once proper item id is entered and found in warehouse inventory,
     //prompt user to enter amount of that item.
     cout << "Enter amount to ship: ";
     cin >> amountToShip;
     cout << endl;
     
     //Check for input failure.
     while (cin.fail() || amountToShip < 1)
       {
	 cin.clear();
	 cin.ignore(100, '\n');

	 cout << "Enter amount to ship: ";
	 cin >> amountToShip;
	 cout << endl;
       }
     
     //Call updateItemQuantity function, which will update the quantity
     //or return false if user requested a number of that item that is greater
     //than the amount in stock.
     updateQuantity = invList.updateItemQuantity(itemLocation, amountToShip);
     
     //Check for input failure and if updateQuantity was returned as false.
     //If updateQuantity was returned false, then the user requested too much
     //of an item.
     while (cin.fail() || updateQuantity == false || amountToShip < 1)
       {
	 cin.clear();
	 cin.ignore(100, '\n');
	 
	 cout << "That quantity is greater than the amount in stock" << endl;
	 cout << "Enter amount to ship: ";
	 cin >> amountToShip;
	 cout << endl;
	 
	 updateQuantity = invList.updateItemQuantity(itemLocation, amountToShip);
       }
     
     //Now that itemlocation is known and user has requested amount of item,
     //store item's price and discount amounts.
     itemPrice = invList.getItemPrice(itemLocation);
     itemDiscount = invList.getItemDiscount(itemLocation);

     cout << "Ok shipment will be on the way shortly" << endl << endl;

     //Update total cost and discount.
     totalCost = totalCost + float((amountToShip*itemPrice)/1000.0);
     totalDiscounts = totalDiscounts + float((amountToShip*itemDiscount)/1000.0*(itemPrice/1000.0));

     //update counters for numShipments and orderNum.
     numShipments--;
     orderNum++;
     
   }

//Rest of code outputs the user's order summary.
 cout << fixed;
 cout << setprecision(2);

 double costAfterDiscounts = totalCost - totalDiscounts;

 cout << "Invoice summary" << endl;
 cout << setw(35) << setfill(' ') << left << "Total cost" << right << totalCost << endl;
 cout << setw(35) << setfill(' ') << left << "Discounts" << right << totalDiscounts << endl;
 cout << setw(35) << setfill(' ') << left << "Total cost after discounts" << right << costAfterDiscounts << endl;
 cout << endl;


  return 0;
}

