// dp6.h
// Kelby Hubbard, Rose Peters, and Yali Wang
// Started: 2020-10-30
// Updated: 2020-10-30

// For CS 311 Fall 2020
// Header for Project 6 functions


// CREDIT:
//
//
//

#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"	
#include <memory>		// for std::unique_ptr

// reverseList
// Efficient reversing function for a Linked List of LLNode2
// Pre:
//	Valid LLNode2 unique pointer
// ??? Guarantee
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head)
{
	std::unique_ptr<LLNode2<ValType>> newHead(nullptr);
	std::unique_ptr<LLNode2<ValType>> currentHead(nullptr);

	while(head != nullptr)
	{
		currentHead = head->_next;
		head->_next = newHead;
		newHead = head;
		head = currentHead;
	}
	
	head = newHead;
}

// **********************************************************************
// class LLMap - Class definition
// **********************************************************************
// class LLMap
// Templated linked list map
// Invariants:
//		???
// Type requirements:
//		???
template <typename Key, typename Data>
class LLMap {



}; // End class LLMap

#endif // FILE_DP6_H_INCLUDED