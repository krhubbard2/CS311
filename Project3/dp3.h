// dp3.h
// Kelby Hubbard
// Started: 2020-09-18
// Updated: 2020-09-24

// For CS 311 Fall 2020
// Header for Project 3 functions

// CREDIT:
// All code below is written by me (Kelby Hubbard)
// This code was built off of the skeleton code written and styled by
// Glenn G. Chappell from dp3.h which can be
// seen at https://github.com/ggchappell/cs311-2020-03

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range

// Looks through a Singly Linked List
// Throws an error exception (out_of_range) if incorrect entry is inputted.
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
  while(true)
  {
    if(head == nullptr)
    {
      throw std::out_of_range("Inproper entry. "
                              "Index cannot be negative or bigger than size.");
    }
    else if (index == 0)
    {
      return head->_data;
    }
    head = head->_next;
    --index;
  }
}


// Implementation in source file
// Pass a function pointer or object that acts like a function
// If the function throws, sets parameter threw to true and passes
// the exception on to the caller. If function doesn't throw, sets
// parameter threw to false and returns normally
void didItThrow(const std::function<void()> & ff,
                bool & threw);

// Takes iterators as paramters and processes a range of data
// Returns true if data is sorted in ascending order. Returns false otherwise.
template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
  if (first == last) return true;
  FDIter nextItem = first;
  while (++nextItem != last)
  {
    if (*nextItem < *first) return false;
    ++first;
  }
  return true;
}


// Implementation in source file
// Returns the GCD of two nonnegative integers using recursive methods.
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED
