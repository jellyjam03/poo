#include <cstring>
#include <cstdio>
#include <iostream>

class Number

{

   char *v;
   int lg, baza;

public:

   Number(const char * value, int base); // where base is between 2 and 16

   ~Number();

   Number(const int x);

   // add operators and copy/move constructor

   Number(const Number& x);///copy constructor

   Number(Number&& x);///move constructor

   ///operatori de atribuire si indexare
   Number& operator= (const Number& a);
   Number& operator= (const int x);
   Number& operator= (const char* const p);
   char operator[] (int poz);

   ///adunare si scadere
   friend Number& operator+ (const Number& a, const Number& b);
   friend Number& operator- (const Number& a, const Number& b);
   friend Number& operator+= (Number& a, const Number& b);
   friend Number& operator-= (Number& a, const Number& b);
   Number& operator-- (); ///postfixat
   Number& operator-- (int val);///prefixat

   ///operatori relationali
   friend bool operator> (const Number& a, const Number& b);
   friend bool operator>= (const Number& a, const Number& b);
   friend bool operator< (const Number& a, const Number& b);
   friend bool operator<= (const Number& a, const Number& b);
   friend bool operator== (const Number& a, const Number& b);
   friend bool operator!= (const Number& a, const Number& b);




   void SwitchBase(int newBase);

   void Print();

   int  GetDigitsCount(); // returns the number of digits for the current number

   int  GetBase(); // returns the current base

};
