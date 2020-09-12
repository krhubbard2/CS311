// msarray.h
// Kelby Hubbard
// Started: 2020-09-08
// Updated: 2020-09-09

// For CS 311 Fall 2020
// Header for class MSArray
// Class template that manages and allows access to a fixed-size array
// There is no associated source file.

#ifndef FILE_MSARRAY_H_INCLUDED
#define FILE_MSARRAY_H_INCLUDED

#include <cstddef> // For std::size_t

// *********************************************************************
// class MSArray - Class definition
// *********************************************************************

// class MSArray
// A "Moderately Smart Array Class"
// Invariants:
//

template <typename T>
class MSArray{

// ***** MSArray: Types *****
public:
  using size_type = std::size_t; // Unsigned type for size of the array
  using value_type = T;          // Type of item in the container

// ***** MSArray: Constructors, Destructors *****
public:

  // Default Constructor
  // Creates an array of size 8
  MSArray()
    :_arrayptr(new value_type[8])
  {}

  // 1 Parameter Constructor
  // Creates an array size of value given
  // Pre:
  //     size >= 0
  MSArray(size_type size)
    :_arrayptr(new value_type[size])
  {}

  // 2 Parameter Constructor
  // 1st parameter is number of items in array
  // 2nd parameter is item of the value type
  // each item in array will be set to this value
  // Pre:
  //      size >= 0
  MSArray(size_type size, const value_type& item)
  {
    _arrayptr = new value_type[size];

    for (std::size_t i=0; i < size; ++i)
        _arrayptr[i] = item;
  }

  // Destructor
  ~MSArray()
  {
    delete [] _arrayptr;
  }

// ***** MSArray: General public operators *****
public:

  // op[]
  // Pre:
  //     0 <= index < (size of array)
  value_type & operator[](size_type index)
  {
    return _arrayptr[index];
  }
  const value_type & operator[](size_type index) const
  {
    return _arrayptr[index];
  }

  // op==
  //
  bool operator==(const MSArray & p) const
  {
    return true;
  }

  // op!=
  //
  bool operator!=(const MSArray & p) const
  {
    return true;
  }

  // op<
  //
  bool operator<(const MSArray & p) const
  {
    return true;
  }

  // op<=
  //
  bool operator<=(const MSArray & p) const
  {
    return true;
  }

  // op>
  //
  bool operator>(const MSArray & p) const
  {
    return true;
  }

  // op>=
  //
  bool operator>=(const MSArray & p) const
  {
    return true;
  }


// ***** MSArray: General public functions *****
  // MSArray::size
  // Returns number of items in array
  value_type size()
  {
    value_type arrSize = *(&_arrayptr + 1) - _arrayptr;
    return arrSize;
  }
  value_type size() const
  {
    value_type arrSize = *(&_arrayptr + 1) - _arrayptr;
    return arrSize;
  }

  // MSArray::begin
  // Returns the address of item 0
  value_type begin()
  {
    return _arrayptr[0];
  }
  value_type begin() const
  {
    return _arrayptr[0];
  }

  // MSArray::end
  // Returns the address of the item one-past the end of the array
  value_type end()
  {
    return _arrayptr[+1];
  }
  value_type end() const
  {
    return _arrayptr[+1];
  }


// ***** MSArray: Data members *****
private:

  value_type * _arrayptr;  // Pointer to array

}; // End class MSArray


#endif //#ifnded FILE_MSARRAY_H_INCLUDED
