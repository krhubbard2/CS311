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
void ProductOrder::getName(string & name) const
{
  name = _name;
}

// ProductOrder::setName
// (See header for docs.)
void ProductOrder::setName(string name)
{
  _name = name;
}

// ProductOrder::getNumber
// (See header for docs.)
void ProductOrder::getNumber(int & inventory) const
{
  inventory = _numb;
}

// ProductOrder::setNumber
// (See header for docs.)
void ProductOrder::setNumber(int inventory)
{
  _numb = inventory;
}
