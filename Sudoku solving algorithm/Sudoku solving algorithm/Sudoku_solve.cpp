#include "Sudoku.h"
#include <iostream>

bool Sudoku::Solve(int current_row, int current_column)
{
	int i = 1;
	if (current_row == 8 && current_column == 8)
	{
		std::cout << "tu";
	}
	if (current_row == 9)
	{
		return true;
	}
	else if (grid[current_row][current_column] == 0)
	{
		while (i < 10)
		{
			if (Sudoku::Can_put(i, current_row, current_column))
			{
				grid[current_row][current_column] = i;
				if (current_column == 8 && current_row == 8) return true;
				else if (current_column < 8)
				{
					if (!Sudoku::Solve(current_row, current_column + 1))
					{
						grid[current_row][current_column] = 0;
					}
				}
				else
				{
					if (current_row == 8)return true;
					else if (Sudoku::Solve(current_row + 1, 0))
					{
						grid[current_row][current_column] = 0;
					}
				}
			}
			i++;
		}
		return false;
	}
	else
	{
		if (current_column < 9)current_column++;
		else
		{
			current_column = 0;
			current_row++;
		}
	}
}