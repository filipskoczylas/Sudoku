#include "Sudoku.h"

using std::cout;
using std::endl;

Sudoku::Sudoku()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			grid[i][j] = 0;
}

void Sudoku::Display_grid()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			cout << ' ';
			for (int j = 0; j < 25; j++)
			{
				cout << '-';
			}
			cout << endl;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)cout << " |";
			cout << " " << grid[i][j];
			if (j == 8)cout << " |";
		}
		cout << endl;
		if (i == 8)
		{
			cout << ' ';
			for (int j = 0; j < 25; j++)
			{
				cout << '-';
			}
		}
	}
}

bool Sudoku::Can_put(int number, int row, int column)
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[row][i] == number) return false;
		if (grid[i][column] == number) return false;
	}
	int row_number = (row / 3)*3;
	int column_number = (column / 3)*3;
	for (int i = row_number; i < row_number + 3; i++)
	{
		for (int j = column_number; j < column_number + 3; j++)
		{
			if (grid[i][j] == number)return false;
		}
	}
	return true;
}