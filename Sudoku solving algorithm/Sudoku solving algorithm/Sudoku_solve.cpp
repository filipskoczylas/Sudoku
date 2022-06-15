#include "Sudoku.h"
#include <iostream>

bool Sudoku::Solve(int current_row, int current_column)
{
	int i = 1;
	if (finished)
		return true;
	while (grid[current_row][current_column] != 0)
	{
		if (current_column < 9)current_column++;
		else
		{
			current_column = 0;
			current_row++;
		}
	}
	if (grid[current_row][current_column] == 0)
	{
		while (i < 10)
		{
			if (finished)
				return true;
			if (Sudoku::Can_put(i, current_row, current_column))
			{
				grid[current_row][current_column] = i;
				if (current_column == 8 && current_row == 8)
				{
					finished = true;
					return true;
				}
				else if (current_column < 8)
				{
					if (!Sudoku::Solve(current_row, current_column + 1))
					{
						grid[current_row][current_column] = 0;
					}
				}
				else
				{
					if (current_column == 8 && current_row == 8) return true;
					else if (!Sudoku::Solve(current_row + 1, 0))
					{
						grid[current_row][current_column] = 0;
					}
				}
			}
			i++;
		}
		if (finished)
			return true;
		return false;
	}
	else if (current_column == 8 and current_row == 8)
	{
		finished = true;
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				if (grid[j][k] == 0) finished = false;
		return finished;
	}
}