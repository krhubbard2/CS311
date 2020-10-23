// tfsarray.h
// Kelby Hubbard
// Started: 2020-10-22
// Updated: 2020-10-22

// For CS 311 Fall 2020
// Header for class TFSArray
// Class template that acts as a "smart array".
// There is no associated source file.

// CREDIT:
// All code below is written by me (Kelby Hubbard)
// This code was built off of code written and styled by
// Glenn G. Chappell from fsarray.h which can be
// seen at https://github.com/ggchappell/cs311-2020-03

#ifndef FILE_TFSARRAY_H_INCLUDED
#define FILE_TFSARRAY_H_INCLUDED

#include <cstddef>	// For std::size_t
#include <algorithm>	// For std::max

// *********************************************************************
// class TFSArray - Class definition
// *********************************************************************

template <typename T>
class TFSArray{

// ***** TFSArray: Types *****
public:

  // value_type: type of data items
  using value_type = T;
  
  // size_type: type of sizes & indices
  using size_type = std::size_t; 
  
  // iterator, const_iterator: random-access iterator types
  using iterator = value_type *; 
  using const_iterator = const value_type *;
  
// ***** TFSArray: Internal-Use Constants *****
private:

  // Capacity of default-constructed object
  enum { DEFAULT_CAP = 16 };

// ***** TFSArray: Constructors, Destructors, op= *****
public:

  // Default constructor and constructor from size
  // Strong Guarantee
  explicit TFSArray(size_type size=0)
  	:_capacity(std::max(size, size_type(DEFAULT_CAP))),
  	  // _capacity must be declared before _data
  	_size(size),
  	_data(_cpacity == 0 ? nullptr : new value_type[_capacity])
  {}



  // Deconstructor
  // No-Throw Guarantee
  ~TFSArray()
  {
    delete [] _data;
  }
  
// ***** TFSArray: Data Members *****
private:
  
  size_type    _capacity;  // Size of our allocated array
  size_type    _size;	   // Size of client's data
  value_type * _data;      // Pointer to our array

}; // End class TFSArray

#endif // #ifndef FILE_TFSARRAY_H_INCLUDED
