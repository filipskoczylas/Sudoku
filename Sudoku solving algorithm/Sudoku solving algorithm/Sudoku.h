#pragma once
#include <iostream>

class Sudoku
{
public: 
	Sudoku();
	void Display_grid();
	bool Solve();
private: 
	bool Can_put(int);
	int grid[9][9];
};

