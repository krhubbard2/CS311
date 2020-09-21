// dp3.h
// Kelby Hubbard
// Started: 2020-09-18
// Updated: 2020-09-21

// For CS 311 Fall 2020
// Header for Project 3 functions

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range


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
void didItThrow(const std::function<void()> & ff,
                bool & threw);


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
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED
