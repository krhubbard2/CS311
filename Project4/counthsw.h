// counthsw.h
// Kelby Hubbard
// Started: 2020-09-28
// Updated: 2020-09-28

// For CS 311 Fall 2020
// Header for Project 4

// "Consider a rectangle divided into squares, like a checkerboard or chessboard. 
// One square is marked as the hole. Another square is marked start, and a third square is marked finish. 
// We will call the result a board. 

// Place a spider on the start square. The spider can step to an adjacent square on the board: north, south,
// east, west, or any of the four diagonal directions. It does this repeatedly until it reaches the finish square.
// A way of doing this that does not step on the hole, and steps on each other square exactly once, 
// is a holey spider walk." (Glenn G. Chappell)

#ifndef FILE_COUNTHSW_H_INCLUDED
#define FILE_COUNTHSW_H_INCLUDED

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
int countHSW(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y);


#endif // #ifndef FILE_COUNTHSW_H_INCLUDED
