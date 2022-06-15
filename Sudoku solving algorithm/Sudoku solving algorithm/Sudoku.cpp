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