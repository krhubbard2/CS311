// productorder.cpp
// Kelby Hubbard
// Started: 2020-08-31
// Updated: 2020-08-31

// For CS 311 Fall 2020
// Source for class ProductOrder
// Product Order: product name, number of items ordered

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
  if (_numb == 0){
    return true;
  }
  else{
    return false;
  }
}

// ProductOrder::toString
// (See header for docs.)
string ProductOrder::toString() const
{
  string final = _name + " (" + std::to_string(_numb) + ")";
  return final;
}

// ProductOrder::op==
// (See header for docs.)
bool ProductOrder::operator==(const ProductOrder &p) const
{
  if (getName() == p.getName() && getNumber() == p.getNumber()){
    return true;
  }
  else{
    return false;
  }
}

// ProductOrder::op!=
// (See header for docs.)
bool ProductOrder::operator!=(const ProductOrder &p) const
{
  if (getName() == p.getName() && getNumber() == p.getNumber()){
    return false;
  }
  else{
    return true;
  }
}

// ProductOrder::op<< (ostream,ProductOrder)
// (See header for docs.)
std::ostream & operator<<(std::ostream & out,
                     const ProductOrder & p)
{
  out << p.toString();
  return out;
}
