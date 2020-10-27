// tfsarray.h
// Kelby Hubbard
// Started: 2020-10-22
// Updated: 2020-10-26

// For CS 311 Fall 2020
// Header for class TFSArray
// Class template that acts as a "smart array".
// There is no associated source file.

// CREDIT:
// All code below is written by me (Kelby Hubbard)
// This code was built off of code written and styled by
// Glenn G. Chappell from fsarray.h and fsarray.cpp which can be
// seen at https://github.com/ggchappell/cs311-2020-03

#ifndef FILE_TFSARRAY_H_INCLUDED
#define FILE_TFSARRAY_H_INCLUDED

#include <cstddef>		// For std::size_t
#include <algorithm>	// For std::max

// *********************************************************************
// class TFSArray - Class definition
// *********************************************************************

// class TFSArray
// Templated Frightfully Smart Array.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//		0 <= _size <= _capacity
//		_data points to an array of value_type, allocated with new [],
//		owned by *this, holding _capacity value_type values -- UNLESS
//		_capacity == 0, in which case _data may be nullptr.
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
  	_data(_capacity == 0 ? nullptr : new value_type[_capacity])
  {}

  // Copy constructor
  // Strong Guarantee
  // Pre:
  //	  A valid TFSArray object to copy
  TFSArray(const TFSArray & other):
  			_size(other.size()),
  			_data(new value_type[other._capacity]),
  			_capacity(other._capacity)
  {
    try
    {
      std::copy(other.begin(), other.end(), begin());
    }
    catch(...)
    {
      this->~TFSArray();
      throw;
    }
  }
  
  // Move constructor
  // No-Throw Guarantee
  // Pre:
  //	A valid TFSArray object to move
  TFSArray(TFSArray && other) noexcept: _size(other.size()), _data(other._data)
  {
    other._size = 0;
    other._data = nullptr;
  }

  // Copy assignment
  // Strong Guarantee
  // Pre:
  //	A valid TFSArray object to copy
  TFSArray & operator=(const TFSArray & other)
  {
    TFSArray old(other);
    swap(old);
    return *this;
  }
  
  // Move assignment
  // No-Throw Guarantee
  // Pre:
  //	A valid TFSArray object to move
  TFSArray & operator=(TFSArray && other) noexcept
  {
    if (this == &other)
    {
      return *this;
    }
    swap(other);
    return *this;
  }

  // Deconstructor
  // No-Throw Guarantee
  ~TFSArray()
  {
    delete [] _data;
  }
 
// ***** TFSarray: General Public Operators *****
public:

  // operator[] - non-const & const
  // Pre:
  //	 0 >= index <= _size
  // No-Throw Guarantee
  value_type & operator[](size_type index) noexcept
  {
    return _data[index];
  }
  const value_type & operator[](size_type index) const noexcept
  {
    return _data[index];
  }
  
// ***** TFSArray: General Public Functions *****
public:

  // size
  // No-Throw Guarantee 
  size_type size() const noexcept
  {
    return _size;
  }
  
  // empty
  // No-Throw Guarantee
  bool empty() const noexcept
  {
    return size() == 0;
  }
  
  // begin - non-const & const
  // No-Throw Guarantee
  iterator begin() noexcept
  {
    return _data;
  }
  const_iterator begin() const noexcept
  {
    return _data;
  }

  // end - non-const & const
  // No-Throw Guarantee
  iterator end() noexcept
  {
    return begin() + size();
  }
  const_iterator end() const noexcept
  {
    return begin() + size();
  }

  // resize
  // Strong Guarantee
  // Pre:
  //	newsize >= 0
  void resize(size_type newsize)
  {
    if (newsize <= _capacity)
    {
      _size = newsize;
    }
    else
    {
      size_type newCapacity = std::max(2*_capacity, newsize);
      value_type * temp = new value_type[newCapacity];
      try
      {
        std::copy(begin(), end(), temp);
      }
      catch(...)
      {
        delete[] temp;
        throw;
      }
      delete[] _data;

      std::swap(_capacity, newCapacity);
   	  std::swap(_size, newsize);
   	  std::swap(_data, temp);
    }
  }

  // insert
  // Basic Guarantee
  // Pre:
  //	Position is within TFSArray size
  //	Item is of correct value_type
  iterator insert(iterator pos,
                  const value_type & item)
  {
  	size_type index = pos - begin();
  	resize(_size + 1);
  	iterator it1 = begin() + index;
  	_data[_size - 1] = item;

  	try
  	{
  		std::rotate(it1, begin() + _size - 1, end());
  	}
  	catch (...)
  	{
  		resize(_size - 1);
  		throw;
  	}
    
    return it1;
  }

  // erase
  // Strong Guarantee
  // Pre:
  // 	Position is within TFSArray size
  iterator erase(iterator pos)
  {
    std::rotate(pos, pos+1, end());
    resize(_size - 1);
    return pos;
  }

  // push_back
  // Strong Guarantee
  // Pre:
  //	Item is of correct value_type
  void push_back(const value_type & item)
  {
    insert(end(), item);
  }

  // pop_back
  // Strong Guarantee
  void pop_back()
  {
    erase(end()-1);
  }

  // swap
  // No-Throw Guarantee
  // Pre:
  //	A TFSArray of the same value type
  void swap(TFSArray & other) noexcept
  {
    std::swap(_capacity, other._capacity);
    std::swap(_size, other._size);
    std::swap(_data, other._data);
  }
  
// ***** TFSArray: Data Members *****
private:
  
  size_type    _capacity;  // Size of our allocated array
  size_type    _size;	   // Size of client's data
  value_type * _data;      // Pointer to our array

}; // End class TFSArray

#endif // #ifndef FILE_TFSARRAY_H_INCLUDED
