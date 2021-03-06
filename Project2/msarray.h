// msarray.h
// Kelby Hubbard
// Started: 2020-09-08
// Updated: 2020-09-16

// For CS 311 Fall 2020
// Header for class MSArray
// Class template that manages and allows access to a fixed-size array
// There is no associated source file.

// CREDIT:
// All code below is written by me (Kelby Hubbard)
// This code was built off of code written and styled by
// Glenn G. Chappell from intarray.h which can be
// seen at https://github.com/ggchappell/cs311-2020-03

#ifndef FILE_MSARRAY_H_INCLUDED
#define FILE_MSARRAY_H_INCLUDED

#include <cstddef>   // For std::size_t
#include <iterator>  // For std::swap
#include <algorithm> // For std::lexicographical_compare and std::equal

// *********************************************************************
// class MSArray - Class definition
// *********************************************************************

// class MSArray
// A "Moderately Smart Array Class"
// Invariants:
//             size_type must be >= 0.

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
    :_arrayptr(new value_type[8]), _size(8)
  {}

  // 1 Parameter Constructor
  // Creates an array size of value given
  // Pre:
  //     size >= 0
  MSArray(size_type size)
    :_arrayptr(new value_type[size]), _size(size)
  {}

  // 2 Parameter Constructor
  // 1st parameter is number of items in array
  // 2nd parameter is item of the value type
  // each item in array will be set to this value
  // Pre:
  //      size >= 0
  MSArray(size_type size, const value_type& value)
    :_arrayptr(new value_type[size]), _size(size)
  {
    for (std::size_t i=0; i < size; ++i)
        _arrayptr[i] = value;
  }

  // Destructor
  ~MSArray()
  {
    delete [] _arrayptr;
  }

  // Move Constructor
  // Pre:
  //      A valid MSArray object
  MSArray(MSArray && oldMSArray) noexcept
    : _arrayptr(oldMSArray._arrayptr), _size(oldMSArray.size())
  {
    oldMSArray._arrayptr = nullptr;
    oldMSArray._size = 0;
  }

  // Copy Constructor
  // Pre:
  //      A valid MSArray object
  MSArray(const MSArray & original)
    : _arrayptr(new value_type[original.size()]), _size(original.size())
  {
    for (std::size_t i=0; i < _size; ++i)
        _arrayptr[i] = original[i];
  }

  // Move Assignment Op
  // Pre:
  //      A valid MSArray object
  MSArray & operator=(MSArray && original) noexcept
  {
    std::swap(_size, original._size);
    std::swap(_arrayptr, original._arrayptr);
    return *this;
  }

  // Copy Assignment Op
  // Pre:
  //      A valid MSArray object
  MSArray & operator=(const MSArray & original)
  {
    MSArray old(original);
    std::swap(_size, old._size);
    std::swap(_arrayptr, old._arrayptr);
    return *this;
  }

// ***** MSArray: General public operators *****
public:

  // op[] (const and non-const)
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


// ***** MSArray: General public functions *****
  // MSArray::size
  // Returns number of items in array
  std::size_t size() const
  {
    return _size;
  }

  // MSArray::begin (const and non-const)
  // Returns the address of item 0
  value_type * begin()
  {
    return _arrayptr;
  }
  const value_type * begin() const
  {
    return _arrayptr;
  }

  // MSArray::end (const and non-const)
  // Returns the address of the item one-past the end of the array
  value_type * end()
  {
    return _arrayptr + _size;
  }
  const value_type * end() const
  {
    return _arrayptr + _size;
  }


// ***** MSArray: Data members *****
private:

  value_type * _arrayptr;  // Pointer to array
  size_type _size;         // size

}; // End class MSArray


// *********************************************************************
// Global Operators
// *********************************************************************

// Equality Op==
// Returns true if two MSArray objects have same size and all items are equal
// Pre:
//      Both MSArray objects must be the same type
template <typename T>
bool operator==(const MSArray<T> & left, const MSArray<T> & right)
{
  return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

// Inequality op!=
// Returns true if two MSArray objects are different sizes
// or have a different element
// Pre:
//      Both MSArray objects must be the same type
template <typename T>
bool operator!=(const MSArray<T> & left, const MSArray<T> & right)
{
  return !(left==right);
}

// Less than op<
// Takes two MSArray objects of the same type and compares the first element.
// If the first MSArray element is lower than the first element of the second
// MSArray then it returns true. If the elements are the same it looks at the
// next element and compares again.
// Pre:
//      Both MSArray objects must be the same type
template <typename T>
bool operator<(const MSArray<T> & left, const MSArray<T> & right)
{
  return std::lexicographical_compare(left.begin(), left.end(),
                                     right.begin(), right.end());
}

// Less than or equal to op<=
// Takes two MSArray objects of the same type and compares the first element.
// If the first MSArray element is lower than or equal to the first element of
// the second MSArray then it returns true. If the elements
// are the same it looks at the next element and compares again.
// Pre:
//      Both MSArray objects must be the same type
template <typename T>
bool operator<=(const MSArray<T> & left, const MSArray<T> & right)
{
  return !(right < left);
}

// Greater than op>
// Takes two MSArray objects of the same type and compares the first element.
// If the first MSArray element is greater than the first element of the second
// MSArray then it returns true. If the elements are the same it looks at the
// next element and compares again.
// Pre:
//      Both MSArray objects must be the same type
template <typename T>
bool operator>(const MSArray<T> & left, const MSArray<T> & right)
{
  return right < left;
}

// Greater than or equal to op>=
// Takes two MSArray objects of the same type and compares the first element.
// If the first MSArray element is greater than or equal to the first element
// of the second MSArray then it returns true. If the elements are the
// same it looks at the next element and compares again.
// Pre:
//      Both MSArray objects must be the same type
template <typename T>
bool operator>=(const MSArray<T> & left, const MSArray<T> & right)
{
  return !(left < right);
}

#endif //#ifndef FILE_MSARRAY_H_INCLUDED
