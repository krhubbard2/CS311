// productorder.h
// Kelby Hubbard
// Started: 2020-08-31
// Updated: 2020-09-02

// For CS 311 Fall 2020
// Header for class ProductOrder
// Product Order: product name, number of items ordered

// CREDIT:
// While all code below was written by me (Kelby Hubbard)
// styling and formatting (code neatness) was based off of
// Professor Glenn G. Chappell from timeofday.cpp and timeofday.h
// which can be seen at https://github.com/ggchappell/cs311-2020-03

#ifndef FILE_PRODUCTORDER_H_INCLUDED
#define FILE_PRODUCTORDER_H_INCLUDED

#include <iostream> // For std::cout
#include <string>   // For std::string
using std::string;
#include <ostream>  // For std::ostream

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
    ProductOrder()
    {
      setName("UNSPECIFIED");
      setNumber(0);
    }

    // Constructor from name and quanity
    // Set name and quantity to given values
    // Pre: numb >= 0
    ProductOrder(string name, int inventory)
    {
      setName(name);

      //If invalid quanitity (< 0) is passed, give error and set quantity to 0
      if (inventory < 0){
        std::cout << "Error invalid quantity. Setting quantity to '0'.\n";
        setNumber(0);
      }

      else{
        setNumber(inventory);
      }

    }

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
  // If quantity goes below 0 (breaking invariant) set quantity to 0
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
  // If quantity goes below 0 (breaking invariant) set quantity to 0
  ProductOrder operator--(int dummy)
  {
    auto save = *this;
    --(*this);
    return save;
  }

  // op==
  // If both product name AND order quantity are equal return true
  bool operator==(const ProductOrder &p) const
  {
    return (getName() == p.getName() && getNumber() == p.getNumber());
  }

  // op!=
  // If product name OR order quantity are not equal return true
  bool operator!=(const ProductOrder &p) const
  {
    return (getName() != p.getName() || getNumber() != p.getNumber());
  }


  // ***** ProductOrder: General public functions *****
public:

  // getName
  // Return product name as a string
  string getName() const;

  // setName
  // Sets name of product
  void setName(string name);

  // getNumber
  // Return order quantity as an int
  int getNumber() const;

  // setNumber
  // Sets order quantity
  void setNumber(int inventory);

  // empty
  // Returns true if order quantity = 0, false otherwise
  bool empty() const;

  // toString
  // Returns product name and order quantity as a string
  // Format: "Productname (quantity)"
  string toString() const;



// ***** ProductOrder: Data members *****
private:

  int _numb; // Order quantity (range 0 .. infinit)
  string _name; // Product name

}; // End class ProductOrder


// ProductOrder::op<< (ostream,ProductOrder)
// Prints results of ProductOrder::toString() -- See toString() for docs.
std::ostream & operator<<(std::ostream & out,
                          const ProductOrder & p);

#endif // #ifndef FILE_PRODUCTORDER_H_INCLUDED
