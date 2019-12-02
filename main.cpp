/***************************
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
Assignment 8 - Linked lists

main.cpp file
 **************************/

#include "myString.h"
#include <iostream>
using namespace std;

int main()
{
  myString str1('Z');
  myString str2("Im Mr Meeseeks!");
  myString str3;
  cout << "Enter a string for str3: ";
  cin >> str3;

  cout << endl << "Initial strings" << endl;
  cout << "str1 = " << str1 << endl;
  cout << "str2 = " << str2 << endl;
  cout << "str3 = " << str3 << endl << endl;

  for (int i = 0; i < str2.length()-1; i++)
    str2[i] = toupper(str2[i]);

  
  str1 = str2 + " Look at me";

  cout << "str1 = " << str1 << endl;

  myString str4(str1);

  str1 = str1 + str3;
  cout << "str1 = " << str1 << endl;

  str1 = "Whatever" + str3;
  cout << "str1 = " << str1 << endl;

  str1 = "Hi Folk";
  cout << "str1 = " << str1 << endl;

  str1 = str1 + 's';
  cout << "str1 = " << str1 << endl;

  str1 = '_' + str1;
  cout << "str1 = " << str1 << endl;

  str2 = str1;

  str3 = 'Y';

  cout << endl << "Almost done" << endl;
  cout << "str1 = " << str1 << endl;
  cout << "str2 = " << str2 << endl;
  cout << "str3 = " << str3 << endl << endl;

  if (str1 == str2)
    cout << "str1 equals str2" << endl;

  if (str1 != str2)
    cout << "str1 does not equal str3" << endl;

  str1 = "supercalifragilisticexpialiocious";

  str1.erase(11,12);

  cout << "str1.erase(11, 12) = " << str1 << endl;
  return 0;
}
