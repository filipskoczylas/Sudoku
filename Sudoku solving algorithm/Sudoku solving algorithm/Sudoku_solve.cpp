#include "Sudoku.h"

bool Sudoku::Solve(int current_row, int current_column)
{
	int i = 1;
	while (i < 10)
	{
		if (finished)
			return true;
		if (current_column > 8)
		{
			current_column = 0;
			current_row++;
		}
		while (grid[current_row][current_column] != 0)
		{
			if (current_column < 8)current_column++;
			else
			{
				current_column = 0;
				current_row++;
			}
		}
		if (grid[current_row][current_column] == 0)
		{
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
						if (!finished)grid[current_row][current_column] = 0;
					}
				}
				else
				{
					if (current_column == 8 && current_row == 8) return true;
					else if (!Sudoku::Solve(current_row + 1, 0))
					{
						if (!finished)grid[current_row][current_column] = 0;
					}
				}
			}
		}
		i++;
		if (i == 10) return false;
	}
}
