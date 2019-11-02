//main.cpp file for fraction class operations.
/*****************************************
Dylan Durkee
CS 202 - sec 1003
Dr. Jimi Andro-Vasko
Assignment 7 - operator overloading w/ fractions
 ****************************************/
#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
  fraction f1(3, 5);
  fraction f2(2);
  fraction f3(3, 0);
  fraction f4(8, 10);
  fraction f5, f6;
 
  cout << "Please enter a fraction in the form => numerator / denominator: ";
  cin >> f5;

  cout << "Please enter another fraction in the form => numerator / denominator: ";
  cin >> f6;
  
  cout << "f1 = " << f1 << endl;
  cout << "f2 = " << f2 << endl;
  cout << "f3 = " << f3 << endl;
  cout << "f4 = " << f4 << endl;
  cout << "f5 = " << f5 << endl;
  cout << "f6 = " << f6 << endl << endl;

  
  if (f4 == f5)
    cout << "f4 and f5 are equal" << endl;
  else 
    cout << "f4 and f5 are not equal" << endl;
  

  f2 = f1 - (f5 + f6 + 2 + (f1 - f3) + 1 - f5);
  cout << "Large arithmetic expression evaluates to: " << f2 << endl;

  
  f2 = -(f5 ^ 3);

  cout << "-(f5 ^ 3) = " << f2 << endl;
  
  cout << "f2 + 2.2 = " << f2 + 2.2 << endl;
  cout << "1.1 + f5 = " << 1.1 + f5 << endl;
  cout << "f2 - 2.2 = " << f2 - 2.2 << endl;
  cout << "1.1 - f5 = " << 1.1 - f5 << endl;
  
  
  return 0;
}
