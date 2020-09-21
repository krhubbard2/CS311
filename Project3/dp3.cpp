// dp3.cpp  SKELETON
// Glenn G. Chappell
// 2020-09-17
//
// For CS 311 Fall 2020
// Source for Project 3 functions

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;


void didItThrow(const function<void()> & ff,
                bool & threw)
{
    try
    {
      ff();
    }
    catch(...)
    {
      threw = true;
      throw;
    }

    threw = false;
    return;
}


int gcd(int a,
        int b)
{
  if (a == 0) return b;
  else if (a > b)
  {
    gcd(b, a);
  }
  else{
    gcd(b % a, a);
  }
}
