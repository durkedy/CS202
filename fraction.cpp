//.cpp file for fraction class - function definitions.
#include <iostream>
#include "fraction.h"
using namespace std;

/**********************************************
FUNCTION: Find gcd (greatest common denominator)
PARAMETERS: Two ints representing numerator and denominator 
of fraction.
RETURN: Int (gcd).
DESCRIPTION: User-defined Recursive function whose base case
returns a (numerator) if b (denominator) is 0,
otherwise use recursion to determine gcd,
finally return the gcd.
 *********************************************/
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

//default constructor
fraction::fraction()
{
  numerator = 0;
  denominator = 1;
}

//Constructor with input for numerator of fraction.
fraction::fraction(int n)
{
  numerator = n;
  denominator = 1;
}

//Constructor with input for both numerator and denominator of fraction.
fraction::fraction(int n, int d)
{
  numerator = n;
  denominator = (d == 0) ? 1 : d;

  int GCD = gcd(numerator, denominator);

  if (GCD < 0)
    GCD = (-1)*GCD;
  
  if (GCD != 0)
    {
      numerator = numerator/GCD;
      denominator = denominator/GCD;
    }
  
}

/*********************************************
FUNCTION: Overload + operator.
PARAMETERS: One fraction type.
RETURN: Fraction.
DESCRIPTION: Find common denominator for each fraction,
add the numerators, and return the new fraction.
 ********************************************/
fraction fraction::operator+(const fraction& rhs) const
{
  fraction tmp1(numerator, denominator);
  fraction tmp2(rhs.numerator, rhs.denominator);
  fraction tmp(1, 1);
  tmp.numerator = (tmp1.numerator*tmp2.denominator) + (tmp2.numerator*tmp1.denominator);
  tmp.denominator = tmp1.denominator*tmp2.denominator;

  int a = tmp.numerator;
  int b = tmp.denominator;
  int GCD = gcd(a, b);
  if (GCD < 0)
    GCD = (-1)*GCD;

  
  if (GCD != 0)
    {
      tmp.numerator = tmp.numerator/GCD;
      tmp.denominator = tmp.denominator/GCD;
    }
  
  return tmp;
}

/**********************************************
FUNCTION: Overload + operator for fraction + int.
PARAMETERS: One int on RHS of equation.
RETURN: Fraction.
DESCRIPTION: Multiply rhs int by fraction denominator,
add to fraction numerator, and return new fraction.
 *********************************************/
fraction fraction::operator+(int rhs) const
{
  fraction tmp(numerator, denominator);

  tmp.numerator = tmp.numerator + (rhs*tmp.denominator);

  int a = tmp.numerator;
  int b = tmp.denominator;
  int GCD = gcd(a, b);

  if (GCD < 0)
    GCD = (-1)*GCD;
  
  if (GCD != 0)
    {
      tmp.numerator = tmp.numerator/GCD;
      tmp.denominator = tmp.denominator/GCD;
    }
  
  return tmp;
}

/**************************************************
FUNCTION: Overload + operator between fraction and double.
PARAMETERS: One double on RHS of equation.
RETURN: Double.
DESCRIPTION: Create temp fraction, create doubles of
numerator and denominator. Divide numerator/denominator and
add the resulting decimal to the RHS parameter. Return decimal.
 *************************************************/
double fraction::operator+(double rhs) const
{
  fraction tmp(numerator, denominator);
  double numerator = tmp.numerator;
  double denominator = tmp.denominator;
  double decimal = numerator/denominator;

  decimal = decimal + rhs;

  return decimal;
}

/*************************************************
FUNCTION: Overload - operator in front of a fraction type variable.
PARAMETERS: None.
RETURN: Fraction.
DESCRIPTION: Multiply fraction's numerator by (-1).
Return fraction.
 *************************************************/
fraction fraction::operator-() const
{
  fraction tmp(numerator, denominator);

  tmp.numerator = (-1)*tmp.numerator;

  int a = tmp.numerator;
  int b = tmp.denominator;
  int GCD = gcd(a, b);

  if (GCD < 0)
    GCD = (-1)*GCD;
  
  if (GCD != 0)
    {
      tmp.numerator = tmp.numerator/GCD;
      tmp.denominator = tmp.denominator/GCD;
    }
  
  return tmp;
}

/*****************************************************
FUNCTION: Overload - operator between fraction and fraction.
PARAMETERS: One fraction type.
RETURN: Fraction.
DESCRIPTION: Using temporary fraction variables, find
common denominator and subtract RHS numerator from LHS 
numerator. Return fraction.
 ****************************************************/
fraction fraction::operator-(const fraction& rhs) const
{
  fraction tmp(numerator, denominator);
  fraction tmp2(rhs.numerator, rhs.denominator);

  tmp.numerator = tmp.numerator*rhs.denominator;
  tmp.denominator = tmp.denominator*rhs.denominator;

  tmp2.numerator = rhs.numerator*denominator;
  tmp2.denominator = rhs.denominator*denominator;

  tmp.numerator = tmp.numerator - tmp2.numerator;

  int a = tmp.numerator;
  int b = tmp.denominator;
  int GCD = gcd(a, b);
  
  if (GCD < 0)
    GCD = (-1)*GCD;
  
  if (GCD != 0)
    {
      tmp.numerator = tmp.numerator/GCD;
      tmp.denominator = tmp.denominator/GCD;
    }
  
  return tmp;
}

/*****************************************************
FUNCTION: Overload - operator between fraction and int.
PARAMETERS: One int on RHS of equation.
RETURN: Fraction.
DESCRIPTION: Find common denominator between fraction and int.
Subtract int numerator from fraction numerator. Return fraction.
 ****************************************************/
fraction fraction::operator-(int rhs) const
{
  fraction tmp1(numerator, denominator);
  fraction tmp2(rhs);

  tmp2.numerator = tmp2.numerator*tmp1.denominator;
  tmp2.denominator = tmp2.denominator*tmp1.denominator;

  tmp1.numerator = tmp1.numerator - tmp2.numerator;

  int a = tmp1.numerator;
  int b = tmp1.denominator;
  int GCD = gcd(a, b);

  if (GCD < 0)
    GCD = (-1)*GCD;
  
  if (GCD != 0)
    {
      tmp1.numerator = tmp1.numerator/GCD;
      tmp1.denominator = tmp1.denominator/GCD;
    }
  
  return tmp1;

}

/***************************************************
FUNCTION: Overload - operator between fraction and double.
PARAMETERS: One double on RHS of equation.
RETURN: Double.
DESCRIPTION: Using temp fraction variable, convert fraction
to a decimal value by division. Subtract rhs double from this 
decimal value. Return final decimal.
 **************************************************/
double fraction::operator-(double rhs) const
{
  fraction tmp1(numerator, denominator);
  double numerator1 = tmp1.numerator;
  double denominator1 = tmp1.denominator;

  double decimal1 = numerator1/denominator1;
  double decimal = decimal1 - rhs;

  return decimal;

}

/****************************************************
FUNCTION: Overload ^ operator representing power exponent.
PARAMETERS: One int representing power.
RETURN: Fraction.
DESCRIPTION: Through temp fraction variables, multiply
the numerator by itself "exp" times, and denominator by itself
"exp" times. Return the new fraction raised to "exp" power.
 ****************************************************/
fraction fraction::operator^(int exp) const
{
  fraction tmp(numerator, denominator);

  if (exp == 0)
    {
      tmp.numerator = 1;
      tmp.denominator = 1;
    }
  else if (exp < 0)
    {
      fraction othertmp(denominator, numerator);
      tmp.numerator = denominator;
      tmp.denominator = numerator;

      int counter = exp;
      
      if (exp != -1)
	{
	  for (int i=exp+1; i<0; i++)
	    {
	      tmp.numerator = tmp.numerator*othertmp.numerator;
              tmp.denominator = tmp.denominator*othertmp.denominator;
              cout << tmp.numerator << "/" << tmp.denominator << endl;
	    }
	}
    }
  else if (exp > 0)
    {
      fraction othertmp(numerator, denominator);

      for (int i=1; i<exp; i++)
	{
	  tmp.numerator = tmp.numerator*othertmp.numerator;
	  tmp.denominator = tmp.denominator*othertmp.denominator;
	}
    }
  return tmp;
}

/*******************************************************
FUNCTION: Overload == operator between fraction and fraction.
PARAMETERS: One fraction on RHS.
RETURN: True if fractions are equal, false otherwise.
DESCRIPTION: Compare LHS and RHS fraction's numerators
and denominators. If equal, return true, otherwise return 
false.
 *******************************************************/
bool fraction::operator==(const fraction& rhs) const
{
  if (numerator == rhs.numerator && denominator == rhs.denominator)
    return true;
  else
    return false;
}

/*******************************************************
FUNCTION: Overload == operator between fraction and int.
PARAMETERS: One int on RHS.
RETURN: True if fractions are equal, false otherwise.
DESCRIPTION: Compare LHS and RHS fraction's numerators
and denominators. If equal, return true, otherwise return
false.
*******************************************************/
bool fraction::operator==(int rhs) const
{
  if (numerator/denominator == rhs)
    return true;
  else
    return false;
}

/********************************************************
FUNCTION: Overload outstream << operator.
PARAMETERS: Ostream cout, and one fraction type.
RETURN: out
DESCRIPTION: A series of if/else statements determine the 
output of the fraction: in particular if the fraction
can be reduced to mixed form, output mixed fraction form.
Return out. 
 *******************************************************/
ostream& operator<<(ostream& out, const fraction& f)
{
  
  if (f.denominator == 1)
    out << f.numerator;
  else if (f.numerator == f.denominator)
    out << (f.numerator/f.denominator);
  else if (f.numerator%f.denominator == 0)
    out << (f.numerator/f.denominator);
  else if (f.numerator < f.denominator && f.numerator > 0)
    out << f.numerator << "/" << f.denominator;
  else if (f.numerator < 0 && (-1)*f.numerator < f.denominator)
    {
      fraction tmp(f.numerator, f.denominator);
      out <<  tmp.numerator << "/" << tmp.denominator;
    }
  else if (f.numerator > f.denominator && f.numerator > 0)
    {
      int tmpreduce = f.numerator/f.denominator;
      out << tmpreduce << " " << (f.numerator%f.denominator) << "/" << f.denominator;
    }
  else if (f.numerator < 0 && (-1)*f.numerator > f.denominator)
    {
      int tmpreduce = f.numerator/f.denominator;

      out << tmpreduce << " " << ((-1)*f.numerator%f.denominator) << "/" << f.denominator;
    }

  return out;
}

/**************************************************
FRIEND FUNCTION: Overload input stream >> operator.
PARAMETERS: istream in and one fraction type.
RETURN: In.
DESCRIPTION: Read in fraction input from user in the form
numerator/denominator and store it in the fraction "f".
Return in.
 *************************************************/
istream& operator>>(istream& in, fraction& f)
{
  char slash;

  in >> f.numerator >> slash >> f.denominator;

  return in;
}

/******************************************************
FRIEND FUNCTION: Overload + operator between int on LHS
and fraction on RHS.
PARAMETERS: LHS int and RHS fraction.
RETURN: Fraction.
DESCRIPTION: Multiply lhs by RHS denominator, then add
this to the RHS numerator. Return fraction.
 *****************************************************/
fraction operator+(int lhs, const fraction& rhs)
{
  fraction tmp(rhs.numerator, rhs.denominator);

  tmp.numerator = tmp.numerator + (lhs*tmp.denominator);

  int a = tmp.numerator;
  int b = tmp.denominator;
  int GCD = gcd(a, b);  

  if (GCD < 0)
    GCD = (-1)*GCD;
  
  if (GCD != 0)
    {
      tmp.numerator = tmp.numerator/GCD;
      tmp.denominator = tmp.denominator/GCD;
    }
  
  return tmp;
}

/*****************************************************
FUNCTION: Overload + operator between double and fraction.
PARAMETERS: LHS double and RHS fraction.
RETURN: Double.
DESCRIPTION: Convert fraction to decimal values, add
the LHS and RHS decimal values, and return double decimal.
 ****************************************************/
double operator+(double lhs, const fraction& rhs)
{
  fraction tmp(rhs.numerator, rhs.denominator);
  double numerator = tmp.numerator;
  double denominator = tmp.denominator;
  double decimal = numerator/denominator;

  decimal = lhs + decimal;

  return decimal;

}

/*****************************************************
FUNCTION: Overload - operator between int and fraction.
PARAMETERS: LHS int and RHS fraction.
RETURN: Fraction.
DESCRIPTION: Multiplty integer by fraction's denominator,
and subtract fraction numerator from new integer.
Return numerator and denominator fraction.
 ****************************************************/
fraction operator-(int lhs, const fraction& rhs)
{
  fraction tmp(rhs.numerator, rhs.denominator);

  tmp.numerator = (lhs*tmp.denominator) - tmp.numerator;

  int a = tmp.numerator;
  int b = tmp.denominator;
  int GCD = gcd(a, b);

  if (GCD < 0)
    GCD = (-1)*GCD;
  
  if (GCD != 0)
    {
      tmp.numerator = tmp.numerator/GCD;
      tmp.denominator = tmp.denominator/GCD;
    }
  
  return tmp;
}

/*******************************************************
FUNCTION: Overload - operator between double and fraction.
PARAMETERS: LHS double and RHS fraction.
RETURN: Double.
DESCRIPTION: Convert fraction to double, and calculate
difference between LHS double and RHS decimal value, return
the resulting decimal value.
 ******************************************************/
double operator-(double lhs, const fraction& rhs)
{
  fraction tmp(rhs.numerator, rhs.denominator);
  double numerator = tmp.numerator;
  double denominator = tmp.denominator;
  double decimal = numerator/denominator;

  decimal = lhs - decimal;

  return decimal;

}


