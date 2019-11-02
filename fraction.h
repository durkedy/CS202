//Header file for fraction class
#include <iostream>

//"fraction" class definition
class fraction
{
 public:
  fraction();
  fraction(int);
  fraction(int, int);

  fraction operator+ (const fraction&) const;
  fraction operator+ (int) const;
  double operator+ (double) const;

  fraction operator-() const;

  fraction operator- (const fraction&) const;
  fraction operator- (int) const;
  double operator- (double) const;

  fraction operator^ (int) const;
  
  bool operator== (const fraction&) const;
  bool operator== (int) const;

  friend std::ostream& operator<< (std::ostream&, const fraction&);
  friend std::istream& operator>> (std::istream&, fraction&);

  friend fraction operator+ (int, const fraction&);
  friend double operator+ (double, const fraction&);

  friend fraction operator- (int, const fraction&);
  friend double operator- (double, const fraction&);

 private:
  int numerator;
  int denominator;
};

