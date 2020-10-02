// counthsw.cpp
// Kelby Hubbard
// Started: 2020-09-28
// Updated: 2020-09-28

// For CS 311 Fall 2020
// Source file for Project 4

// "Consider a rectangle divided into squares, like a checkerboard or chessboard. 
// One square is marked as the hole. Another square is marked start, and a third square is marked finish. 
// We will call the result a board. 

// Place a spider on the start square. The spider can step to an adjacent square on the board: north, south,
// east, west, or any of the four diagonal directions. It does this repeatedly until it reaches the finish square.
// A way of doing this that does not step on the hole, and steps on each other square exactly once, 
// is a holey spider walk." (Glenn G. Chappell)

#include "counthsw.h"
#include "vector"



int countHSW(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y)
{
	vector<vector<int>> board(dim_x, vector<int>(dim_y, 0));
  return 1;
}

int countHSW_recurse(vector<vector<int>> board, 
										 int dim_x, int dim_y, 
										 int finish_x, int finish_y, 
										 int curr_x, int curr_y, 
										 int squaresLeft)
{
	if (squaresLeft == 0 && curr_x == finish_x && curr_y == finish_y)
	{
		return 1;	// We have a full solution
	}
}
