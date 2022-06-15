#pragma once
#include <iostream>

class Sudoku
{
public: 
	Sudoku();
	void Display_grid();
	bool Solve(int, int);
private: 
	int r;
	int c;
	bool finished;
	bool Can_put(int, int, int);
	int grid[9][9];
};

