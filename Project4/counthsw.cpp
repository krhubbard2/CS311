// counthsw.cpp
// Kelby Hubbard
// Started: 2020-09-28
// Updated: 2020-10-02

// For CS 311 Fall 2020
// Source file for Project 4

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

#include "counthsw.h"

// countHSW -- See header for documentation
int countHSW(const int &dim_x, const int &dim_y,
             const int &hole_x, const int &hole_y,
             const int &start_x, const int &start_y,
             const int &finish_x, const int &finish_y)
{
  // Create board of correct size -- all values set to 0
  BoardType board(dim_x, vector<int>(dim_y, 0));
	
  int squaresLeft = dim_x * dim_y;
	
  // set hole to 1
  board[hole_x][hole_y] = 1;
  --squaresLeft;
	
  // set start to 1
  board[start_x][start_y] = 1;
  --squaresLeft;
	
  int curr_x = start_x;
  int curr_y = start_y;
	
  return countHSW_recurse(board, dim_x,dim_y, finish_x,finish_y, curr_x,curr_y, squaresLeft);
}

int countHSW_recurse(BoardType &board, 
		     const int &dim_x, const int &dim_y, 
		     const int &finish_x, const int &finish_y, 
		     int &curr_x, int &curr_y, 
		     int &squaresLeft)
{
  // BASE CASE
  if (squaresLeft == 0 && curr_x == finish_x && curr_y == finish_y)
  {
    return 1;	// We have a full solution
  }
	
  // RECURSIVE CASE
  int total = 0;  //Running total of full solutions

  // Check surrounding squares (x dimensions)
  for (int i = -1; i < 2; ++i)
  {
    // Check surrounding squares (y dimensions)
    for (int j = -1; j < 2; ++j)
    {
      // Current space -- skip
      if (i == 0 && j == 0)
      {
	continue;
      } 
      // Space not on board -- skip
      // This includes negative dimensions and dimensions past the highest x and y dimension
      if (curr_x + i < 0 || curr_x + i > (dim_x - 1) || curr_y + j < 0 || curr_y + j > (dim_y - 1))
      {
        continue;
      }			
		
      // If the square lies on the board and has not yet been visited.	
      if (board[curr_x + i][curr_y + j] == 0)
      {
        // Move current spider position
        curr_x += i;
        curr_y += j;
	
        // Mark new square as visited
        board[curr_x][curr_y] = 1;
		
        // Decrement number of squares left
        --squaresLeft;
			
        // Recrusive call & Add return value to total
        total += countHSW_recurse(board, dim_x,dim_y, finish_x,finish_y, curr_x,curr_y, squaresLeft);
			
        // Restore all changes, except change to total
        board[curr_x][curr_y] = 0;
        curr_x -= i;
        curr_y -= j;
        ++squaresLeft;
		
      }
    }  
  }
  // Return all the ones we've added up so far
  return total;
}



