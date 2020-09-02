// productorder.cpp
// Kelby Hubbard
// Started: 2020-08-31
// Updated: 2020-09-02

// For CS 311 Fall 2020
// Source for class ProductOrder
// Product Order: product name, number of items ordered

// CREDIT:
// While all code below was written by me (Kelby Hubbard)
// styling and formatting (code neatness) was based off of
// Professor Glenn G. Chappell from timeofday.cpp and timeofday.h
// which can be seen at https://github.com/ggchappell/cs311-2020-03

#include "productorder.h" // For class ProductOrder


// *********************************************************************
// class ProductOrder - Definitions of member functions
// *********************************************************************

// ProductOrder::getName
// (See header for docs.)
string ProductOrder::getName() const
{
  return _name;
}

// ProductOrder::setName
// (See header for docs.)
void ProductOrder::setName(string name)
{
  _name = name;
}

// ProductOrder::getNumber
// (See header for docs.)
int ProductOrder::getNumber() const
{
  return _numb;
}

// ProductOrder::setNumber
// (See header for docs.)
void ProductOrder::setNumber(int inventory)
{
  _numb = inventory;
}

// ProductOrder::empty
// (See header for docs.)
bool ProductOrder::empty() const
{
  return (_numb == 0);
}

// ProductOrder::toString
// (See header for docs.)
string ProductOrder::toString() const
{
  return (_name + " (" + std::to_string(_numb) + ")");
}

// ProductOrder::op<< (ostream,ProductOrder)
// (See header for docs.)
std::ostream & operator<<(std::ostream & out,
                     const ProductOrder & p)
{
  out << p.toString();
  return out;
}
