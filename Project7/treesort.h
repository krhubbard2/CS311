// treesort.h
// Kelby Hubbard, Rose Peters, and Yali Wang
// Started: 2020-11-09
// Updated: 2020-11-15

// For CS 311 Fall 2020
// Header for function template treesort
// There is no associated source file.

// CREDIT:
// This file is based off of the skeleton file treesort.h
// written by Glenn G. Chappell which can be found at
// https://github.com/ggchappell/cs311-2020-03

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <iterator>
// For std::iterator_traits
#include <algorithm>
// For std::move
#include <iterator>
// For std::distance, std::iterator_traits
#include <memory>


// Struct BSTNode -- Binary Search Tree Node
// Pre:
//     _left is left node or a nullptr
//     _right is right node or a nullptr
//     _data = data
// Requirements on Types:
//     ValType must have a copy constructor
//     ValType must have a < operator
template <typename ValType>
struct BSTNode {

    ValType                           _data;        // Data for this node
    std::unique_ptr<BSTNode<ValType>> _left;        // left node or nullptr
    std::unique_ptr<BSTNode<ValType>> _right;       // right node or nullptr


    // 1- & 2-param ctor
    // _data is set to data (given). _next is set to next, if given, or
    // nullptr if not.
    // No-Throw Guarantee
    explicit BSTNode(const ValType& data,
        std::unique_ptr<BSTNode<ValType>> left = nullptr,
        std::unique_ptr<BSTNode<ValType>> right = nullptr)
        : _data(data)
          
    {
        _left = std::move(left);
        _right= std::move(right);
    }

    // dctor
    // Iterative: avoid recursive destruction.
    // No-Throw Guarantee
    ~BSTNode() = default;

};

// insert
// Pre:
//     Smart pointer for a binary tree and item
// Requirements on Types:
//     ValType must have a copy constructor
//     ValType must have a < operator
// Exception safety guarantee:
// Strong Guarantee
template<typename ValType>
void insert(std::unique_ptr<BSTNode<ValType>> & head, const ValType & item)
{
    if (head == nullptr)
    {
        head = std::make_unique<BSTNode<ValType>>(item);
        return;
    }
    if (item < head->_data) 
    {
        insert(head->_left, item);
    }
    else {
        insert(head->_right, item);
    }
}


// traverse
// Pre:
//     iter is a valid forward iterator pointing to first item
// Requirements on Types:
//     ValType must have a copy constructor
//     ValType must have a < operator
//     FDIter must be a forward iterator
// Exception safety guarantee:
// No-Throw Guarantee
template<typename ValType, typename FDIter>
void traverse(std::unique_ptr<BSTNode<ValType>> & head, FDIter &iter) 
{
    if (head == nullptr) 
    {
        return;
    }
    traverse(head->_left, iter);
    *iter++ = head->_data;
    traverse(head->_right, iter);
}


// treesort
// Sort a given range using Treesort.
// Pre:
//     (first, last) is a valid range
// Requirements on Types:
//     ValType must have a copy constructor
//     ValType must have a < operator
//     FDIter must be a valid forward iterator
// Exception safety guarantee:
//     Strong Guarantee
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;
 
    if (std::distance(first, last) == 0)
    {
      return;
    }

    std::unique_ptr<BSTNode<Value>> head = std::make_unique<BSTNode<Value>>(*first);
    FDIter temp = first;

    while (std::distance(temp, last) != 1) 
    {
        std::advance(temp, 1);
        insert(head, *temp);
    }

    traverse(head, first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED