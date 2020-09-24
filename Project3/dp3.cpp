// dp3.cpp
// Kelby Hubbard
// Started: 2020-09-18
// Updated: 2020-09-24

// For CS 311 Fall 2020
// Header for Project 3 functions

// CREDIT:
// All code below is written by me (Kelby Hubbard)
// This code was built off of the skeleton code written and styled by
// Glenn G. Chappell from dp3.cpp which can be
// seen at https://github.com/ggchappell/cs311-2020-03

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;

// void didItThrow
// See dp3.h for function information
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

// int gcd
// See dp3.h for function information
int gcd(int a,
        int b)
{
  if (a == 0) return b;
  else if (a > b)
  {
    return gcd(b, a);
  }
  else{
    return gcd(b % a, a);
  }
}
