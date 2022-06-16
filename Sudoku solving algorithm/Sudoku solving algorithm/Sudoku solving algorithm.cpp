#include <iostream>

#include "Sudoku.h"


int main()
{
    Sudoku app;
    app.Load("Sud.txt");
    app.Display_grid();
    std::cout << std::endl;
    app.Solve(0, 0);
    app.Display_grid();
    return 0;
}
