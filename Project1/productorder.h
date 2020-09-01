// productorder.h
// Kelby Hubbard
// Started: 2020-08-31
// Updated: 2020-08-31

// For CS 311 Fall 2020
// Header for class ProductOrder
// Product Order: product name, number of items ordered

#ifndef FILE_PRODUCTORDER_H_INCLUDED
#define FILE_PRODUCTORDER_H_INCLUDED

#include <string>
using std::string;

// *********************************************************************
// class ProductOrder - Class definition
// *********************************************************************

// Product Order: product name, number of items ordered
// Invariants:
// 0 <= _numb

class ProductOrder {

// ***** ProductOrder: Constructors, destructors, op= *****
public:

    // Default constructor
    // Set name to "UNSPECIFIED" and number to "0"
    ProductOrder(){}

    // Constructor from name and quanity
    // Set name and quantity to given values
    // Pre: numb >= 0
    ProductOrder(string name, int inventory){}

    // Big 5: Automatically generated versions
    ~ProductOrder() = default;
    ProductOrder(const ProductOrder & other) = default;
    ProductOrder(ProductOrder && other) = default;
    ProductOrder & operator=(const ProductOrder & other) = default;
    ProductOrder & operator=(ProductOrder && other) = default;

// ***** ProductOrder: General public operators *****
public:

  // op++ [pre]
  // Increase quantity by one
  ProductOrder & operator++()
  {
    ++_numb;
    return *this;
  }

  // op++ [post]
  // Increase quantity by one
  ProductOrder operator++(int dummy)
  {
    auto save = *this;
    ++(*this);
    return save;
  }

  // op-- [pre]
  // Reduce order quantity by one
  ProductOrder & operator--()
  {
    --_numb;
    if (_numb < 0)
    {
      _numb = 0;
    }
    return *this;
  }

  // op-- [post]
  // Reduce order quantity by one
  ProductOrder operator--(int dummy)
  {
    auto save = *this;
    --(*this);
    return save;
  }

  // ***** ProductOrder: General public functions *****
public:

  // getName
  // Return product name
  void getName(string & name) const;

  // setName
  // Sets name of product
  void setName(string name);

  // getNumber
  // Return order quantity
  void getNumber(int & inventory) const;

  // setNumber
  // Sets order quantity
  void setNumber(int inventory);





// ***** ProductOrder: Data members *****
private:

  int _numb; // Order quantity (range 0 .. infinit)
  string _name; // Product name

}; // End class ProductOrder



#endif
