/**************************************
Dylan Durkee
Dr. Jimi Andro-Vasko
CS 202 - sec 1003
Assignment 8 - Linked Lists

myString.cpp file
 *************************************/
#include "myString.h"
#include <iostream>
using namespace std;

//Default constructor initializes an empty node, sets node link to NULL.
myString::myString()
{
  head = new node;
  head->item = '\0';
  head->link = NULL;
  //head = NULL;
}

//Constructor that takes in a string literal and assigns
//each character to a node in the linked list.
myString::myString(const char arr[])
{
  int count = 1;
  node *assign;

  head = new node;
  assign = head;
  head->item = arr[0];
  head->link = NULL;

  while(arr[count] != '\0')
    {
      assign->link = new node;
      assign = assign->link;
      assign->item = arr[count];
      assign->link = NULL;
      count++;
    }
}

//Constructor that takes in a char character and assigns it
//to one node in the linked list.
myString::myString(char letter)
{
  head = new node;

  head->item = letter;
  head->link = NULL;
}

//Constructor that takes in another myString object
//and performs a deep copy of that object.
myString::myString(const myString& myStr)
{
  head = new node;
  head->item = myStr.head->item;
  head->link = NULL;

  node *t1 = myStr.head->link;
  node *t2 = head;

  while (t1 != NULL)
    {
      t2->link = new node;
      t2 = t2->link;
      t2->item = t1->item;
      t2->link = NULL;
      t1 = t1->link;
    }
}

/**************************************************
FUNCTION: Overload bracket [] operator.
PARAMETERS: Integer representing the index location in the list.
RETURNS: Value of charcter at char address.
DESCRIPTION: Pass in the an of the linked list.
Traverse through the myString object's linked list
nodes until the index passed in is reached. Return the 
character contained in the item field of that node.
 *************************************************/
char& myString::operator[](int index) const
{
  node *find;
  char value;
  int count = 0;
  find = head;

  while (count != index)
    {
      find = find->link;
      count++;
      if (count < index && find->link == NULL)
	break;
    }

  //value = find->item;
  //find = NULL;
  return find->item;
  
}

/************************************************
FUNCTION: Get length of myString object.
PARAMETERS: None.
RETURN: Int value (length) of myString linked list.
DESCRIPTION: Call function in main from myString
object. Create local counter, traverse through the nodes
of the linked list and increment counter until
link=NULL. Return the count value.
 ***********************************************/
int myString::length() const
{
  int count = 0;
  node *temp = head;

  while (temp != NULL)
    {
      count++;
      temp = temp->link;
    }

  temp = NULL;
  return count;
}

/***********************************************
FUNCTION: Erase nodes in linked list.
PARAMETERS: Index to start erasing nodes, amount
of nodes to be erased.
RETURN: void.
DESCRIPTION: Pass in the starting location (index)
of node deletion and the amount of nodes from that
location to erase. Local pointers d1 and d2 traverse
through the linked list to the index location,
and delete *amount* number of nodes from that location.
 **********************************************/
void myString::erase(int index, int amount)
{
  int count = 0;
  int delAmount = amount;
  node *d1;
  node *d2;
 
  d1 = head;
  while (count < index-1)
    {
      d1 = d1->link;
      count++;
    }

  while (delAmount != 0)
    {
      d2 = d1->link;
      d1->link = d2->link;
      d2->link = NULL;
      delete d2;
      delAmount--;
    }

  d1 = d2 = NULL;
      
}

/***************************************************
FUNCTION: Overload = operator between myString object and
string literal.
PARAMETERS: char array on rhs.
RETURN: *this, after deep copying rhs into lhs object.
DESCRIPTION: First, deallocate lhs myString object's
linked list. Then, perform deep copy of string literal
rhs into lhs object. Return *this.
 **************************************************/
const myString& myString::operator=(const char rhs[])
{
  node *tmp;
  int count = 0;
  node *del;
  
  while (head != NULL)
    {
      del = head;
      head = head->link;
      delete del;
    }

  head = del = NULL;
  
  tmp = new node;
  head = tmp;
  tmp->item = rhs[count];
  while (rhs[count] != '\0')
    {
      count++;
      tmp->link = new node;
      tmp = tmp->link;
      tmp->item = rhs[count];
      tmp->link = NULL;
    }
    
  tmp = NULL;

  return (*this);
}

/********************************************
FUNCTION: Overload = operator between lhs
myString object and rhs char variable.
PARAMETERS: Char character on rhs.
RETURN: *this, new myString object
DESCRIPTION: Deallocate lhs myString object's
current linked list. Perform deep copy of
rhs character into lhs object. Return *this.
 *******************************************/
const myString& myString::operator=(char rhs)
{
  node *tmp;
  int count = 0;
  
  node *del;
  
  while (head != NULL)
    {
      del = head;
      head = head->link;
      delete del;
    }
  
  head = del = NULL;
  
  tmp = new node;
  head = tmp;
  tmp->item = rhs;
  tmp->link = NULL;
  tmp = NULL;

  return (*this);

}

/*****************************************************
FUNCTION: Overload = operator between two myString objects.
PARAMETERS: myString object on rhs.
RETURN: *this after deep copy.
DESCRIPTION: Deallocate lhs linked list. Perform deep copy
of rhs object into lhs object. Return *this.
 ****************************************************/
const myString& myString::operator=(const myString& rhs)
{
  node *tmp;
  node *tmp2;
  
  node *del;

  while (head != NULL)
    {
      del = head;
      head = head->link;
      delete del;
    }

  head = del = NULL;
  
  tmp2 = rhs.head;
  tmp = new node;
  head = tmp;
  tmp->item = tmp2->item;
  while (tmp2->link != NULL)
    {
      tmp->link = new node;
      tmp = tmp->link;
      tmp2 = tmp2->link;
      tmp->item = tmp2->item;
      tmp->link = NULL;
    }

  tmp = tmp2 = NULL;

  return (*this);

}

/*****************************************************
FUNCTION: Overload + operator between two myString objects.
PARAMETERS: myString object rhs.
RETURN: Appended myString object.
DESCRIPTION: Create temporary myString objects of lhs
and rhs. Perform deep copy of rhs linked list into
lhs linked list. Return the new string.
 ****************************************************/
myString myString::operator+(const myString& rhs) const
{
  myString str1(*this);
  myString str2(rhs);

  node *tmp1 = str1.head;
  
  while (tmp1->link != NULL)
    {
      tmp1 = tmp1->link;
    }

  node *tmp2 = str2.head;

  while (tmp2->link != NULL)
    {
      tmp1->link = new node;
      tmp1 = tmp1->link;
      tmp1->item = tmp2->item;
      tmp1->link = NULL;
      tmp2 = tmp2->link;
    }

  tmp1->link = new node;
  tmp1 = tmp1->link;
  tmp1->item = tmp2->item;
  tmp1->link = NULL;
  
  tmp1=tmp2=NULL;  
  return str1;
}

/*************************************************
FUNCTION: Overload + operator between myString object
and string literal.
PARAMETERS: Character array (string literal)
RETURN: str1+str2 (call above function).
DESCRIPTION: Create local myString objects from lhs
and rhs objects. Call above overload + function to
perform deep copy of rhs into lhs.
 *************************************************/
myString myString::operator+(const char rhs[]) const
{
  myString str1(*this);
  myString str2(rhs);

  return str1+str2;
}

/*************************************************
FUNCTION: Overload + operator between myString object
and char.
PARAMETERS: Character.
RETURN: str1+str2 (call above function).
DESCRIPTION: Create local myString objects from lhs
and rhs objects. Call above overload + function to
perform deep copy of rhs into lhs.
*************************************************/
myString myString::operator+(char rhs) const
{
  myString str1(*this);
  myString str2(rhs);

  return str1+str2;
}

/**************************************************
FUNCTION: Overload != operator between two myString objects.
PARAMETERS: myString object on rhs.
RETURN: True, if objects are not equal, false otherwise.
DESCRIPTION: Create local myString objects of lhs
and rhs. Traverse each linked list and compare item values
in each node. Maintain a counter to count dissimilar nodes.
If at least one character in each linked list is not equal,
then the objects are not equal, and return true. If all
characters are equal, objects are equal, return false.
 *************************************************/
bool myString::operator!=(const myString& rhs) const
{
  myString LHS(*this);
  myString RHS(rhs);
  node *tmp1 = LHS.head;
  node *tmp2 = RHS.head;
  int count = 0;

  if (LHS.length() != RHS.length())
    return true;
  else if (LHS.length() == RHS.length())
    {
      while (tmp1->link != NULL)
	{
	  if (tmp1->item != tmp2->item)
	    count++;
	  tmp1 = tmp1->link;
	  tmp2 = tmp2->link;
	}
    }

  tmp1 = tmp2 = NULL;

  if (count > 0)
    return true;
  else if (count == 0)
    return false;
 
}

/**************************************************
FUNCTION: Overload != operator between myString object
and string literal.
PARAMETERS: Char array on rhs.
RETURN: True, if objects are not equal, false otherwise.
DESCRIPTION: Create local myString objects of lhs
and rhs. Traverse each linked list and compare item values
in each node. Maintain a counter to count dissimilar nodes.
If at least one character in each linked list is not equal,
then the objects are not equal, and return true. If all
characters are equal, objects are equal, return false.
*************************************************/
bool myString::operator!=(const char rhs[]) const
{
  myString LHS(*this);
  myString RHS(rhs);
  node *tmp1 = LHS.head;
  node *tmp2 = RHS.head;
  int count = 0;

  if (LHS.length() != RHS.length())
    return true;
  else if (LHS.length() == RHS.length())
    {
      while (tmp1->link != NULL)
        {
          if (tmp1->item != tmp2->item)
            count++;
          tmp1 = tmp1->link;
          tmp2 = tmp2->link;
        }
    }

  tmp1 = tmp2 = NULL;

  if (count > 0)
    return true;
  else if (count == 0)
    return false;

}

/**************************************************
FUNCTION: Overload == operator between two myString objects.
PARAMETERS: myString object on rhs.
RETURN: True, if objects are equal, false otherwise.
DESCRIPTION: Create local myString objects of lhs
and rhs. Traverse each linked list and compare item values
in each node. Maintain a counter to count dissimilar nodes.
If at least one character in each linked list is not equal,
then the objects are not equal, and return false. If all
characters are equal, objects are equal, return false.
*************************************************/
bool myString::operator==(const myString& rhs) const
{
  myString LHS(*this);
  myString RHS(rhs);
  node *tmp1 = LHS.head;
  node *tmp2 = RHS.head;
  int count = 0;

  if (LHS.length() != RHS.length())
    return false;
  else if (LHS.length() == RHS.length())
    {
      while (tmp1->link != NULL)
        {
          if (tmp1->item != tmp2->item)
            count++;
          tmp1 = tmp1->link;
          tmp2 = tmp2->link;
        }
    }

  tmp1 = tmp2 = NULL;

  if (count > 0)
    return false;
  else if (count == 0)
    return true;

}

/**************************************************
FUNCTION: Overload == operator between myString object
and char array (string literal).
PARAMETERS: myString object on rhs.
RETURN: True, if objects are equal, false otherwise.
DESCRIPTION: Create local myString objects of lhs
and rhs. Traverse each linked list and compare item values
in each node. Maintain a counter to count dissimilar nodes.
If at least one character in each linked list is not equal,
then the objects are not equal, and return false. If all
characters are equal, objects are equal, return true.
*************************************************/
bool myString::operator==(const char rhs[]) const
{
  myString LHS(*this);
  myString RHS(rhs);
  node *tmp1 = LHS.head;
  node *tmp2 = RHS.head;
  int count = 0;

  if (LHS.length() != RHS.length())
    return false;
  else if (LHS.length() == RHS.length())
    {
      while (tmp1->link != NULL)
        {
          if (tmp1->item != tmp2->item)
            count++;
          tmp1 = tmp1->link;
          tmp2 = tmp2->link;
        }
    }

  tmp1 = tmp2 = NULL;

  if (count > 0)
    return false;
  else if (count == 0)
    return true;

}

//Destructor deallocates all nodes in linked list of
//a myString object.
myString::~myString()
{
  node *del;
  
  while (head != NULL)
    {
      del = head;
      head = head->link;
      delete del;
    }

  head = del = NULL;
}

/******************************************************
FRIEND FUNCTION: Overload + operator between char array on lhs
and myString object on rhs.
PARAMETERS: lhs char array, and rhs myString object.
RETURN: LHS+RHS (call concatenation overload operator function)
DESCRIPTION: Create local myString objects from lhs and
rhs parameters. Return function call to concatenation
overload operator function, which performs deep copy.
 *****************************************************/
myString operator+(const char lhs[], const myString& rhs)
{
  myString LHS(lhs);
  myString RHS(rhs);

  return LHS+RHS;
}

/******************************************************
FRIEND FUNCTION: Overload + operator between char on lhs
and myString object on rhs.
PARAMETERS: lhs char, and rhs myString object.
RETURN: LHS+RHS (call concatenation overload operator function)
DESCRIPTION: Create local myString objects from lhs and
rhs parameters. Return function call to concatenation
overload operator function, which performs deep copy.
*****************************************************/
myString operator+(char lhs, const myString& rhs)
{
  myString LHS(lhs);
  myString RHS(rhs);

  return LHS+RHS;
}

/*****************************************************
FRIEND FUNCTION: Overload ostream << operator.
PARAMETERS: ostream& out, and myString object rhs.
RETURN: out
DESCRIPTION: Create local node variable "tmp". Tmp
traverses through each node in the myString rhs linked list,
and outputs the each character stored in each node's item
field. After all characters in rhs object are output,
set tmp=NULL and return out.
 ****************************************************/
ostream& operator<<(ostream& out, const myString& rhs)
{
  myString::node *tmp;

  tmp = rhs.head;
  out << tmp->item;

  while (tmp->link != NULL)
    {
      tmp = tmp->link;      
      out << tmp->item;
    }

  tmp = NULL;

  return out;
}

/**********************************************
FRIEND FUNCTION: Overload istream >> operator.
PARAMETERS: istream& in on lhs, myString object
rhs.
RETURN: in
DESCRIPTION: Create local char variable to store
one character at a time in rhs object. Traverse
through the string literal that the user inputs,
and append letters one at a time to rhs myString
object. Return in.
 *********************************************/
istream& operator>>(istream& in, myString& rhs)
{
  char letter;
  
  while (letter != '\n')
    {
      in.get(letter);
      rhs = rhs + letter;
    }
  
  return in;
}
