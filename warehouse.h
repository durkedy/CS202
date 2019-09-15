/*
Dylan Durkee - Assignment 3
Dr. Jimi Vasko
warehouse header file
 */
//Only need to include <string> in this header file.
#include <string>
using namespace std;

//Declaring class-type "warehouse" to be implemented in program.
class warehouse
{
 public:
  warehouse();
  void addItem(string, int, string, int, double, double);
  void displayProducts();
  int search(int) const;
  int getItemPrice(int) const;
  int getItemDiscount(int) const;
  bool updateItemQuantity(int, int);

 private:
  void sortByQuantity();
  string productNames[20];
  int ids[20];
  string manufacturers[20];
  int quantities[20];
  double prices[20];
  double discounts[20];
  int productCounter;
};
