#include <iostream>

#include "Sudoku.h"

int main()
{
    Sudoku app;
    app.Display_grid();
    std::cout << std::endl;
    if(app.Solve(0,0))
    app.Display_grid();
    return 0;
}
