/***********************************
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
Assignment 8 - myString (Linked Lists)

myString.h header file
 **********************************/
#include <iostream>
using namespace std;

class myString
{
 public:
  myString();
  myString(const char[]);
  myString(char);
  myString(const myString&);
  char& operator[](int) const;
  int length() const;
  void erase(int, int);
  const myString& operator=(const char[]);
  const myString& operator=(char);
  const myString& operator=(const myString&);
  myString operator+(const myString&) const;
  myString operator+(const char[]) const;
  myString operator+(char) const;
  bool operator!=(const myString&) const;
  bool operator!=(const char[]) const;
  bool operator==(const myString&) const;
  bool operator==(const char[]) const;
  ~myString();
  friend myString operator+(const char[], const myString&);
  friend myString operator+(char, const myString&);
  friend ostream& operator<<(ostream&, const myString&);
  friend istream& operator>>(istream&, myString&);
 private:
  struct node
  {
    char item;
    node *link;
  };
 
  node *head;
};
