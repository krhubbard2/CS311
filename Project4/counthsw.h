// counthsw.h
// Kelby Hubbard
// Started: 2020-09-28
// Updated: 2020-10-05

// For CS 311 Fall 2020
// Header for Project 4

// "Consider a rectangle divided into squares, like a checkerboard or chessboard. 
// One square is marked as the hole. Another square is marked start, and a third square is marked finish. 
// We will call the result a board. 

// Place a spider on the start square. The spider can step to an adjacent square on the board: north, south,
// east, west, or any of the four diagonal directions. It does this repeatedly until it reaches the finish square.
// A way of doing this that does not step on the hole, and steps on each other square exactly once, 
// is a holey spider walk." (Glenn G. Chappell)

// CREDIT:
// All code below is written by me (Kelby Hubbard)
// This code was built off of the code written and styled by
// Glenn G. Chappell from nqueencount.cpp which can be
// seen at https://github.com/ggchappell/cs311-2020-03


#ifndef FILE_COUNTHSW_H_INCLUDED
#define FILE_COUNTHSW_H_INCLUDED

#include <vector> // for std::vector
using std::vector;

using BoardType = vector<vector<int>>; // Holds board layout. To lookup item i,j: board[i][j]

// Counts and returns the amount of holey spider walks on a given board
// Pre -
//	0 <= hole_x < dim_x
//	0 <= hole_y < dim_y
//	0 <= start_x < dim_x
//	0 <= start_y < dim_y
//	0 <= finish_x < dim_x
//	0 <= finish_y < dim_y
//	(hole_x, hole_y) != (start_x, start_y)
//	(hole_x, hole_y) != (finish_x, finish_y)
int countHSW(const int &dim_x, const int &dim_y,
             const int &hole_x, const int &hole_y,
             const int &start_x, const int &start_y,
             const int &finish_x, const int &finish_y);
             
// Does most of the computational work for countHSW. Implements recursive backtracking. 
// Pre -
// 	All countHSW preconditions must be met             
int countHSW_recurse(BoardType &board, 
		     const int &dim_x, const int &dim_y, 
		     const int &finish_x, const int &finish_y, 
		     int &curr_x, int &curr_y, 
		     int &squaresLeft);


#endif // #ifndef FILE_COUNTHSW_H_INCLUDED
