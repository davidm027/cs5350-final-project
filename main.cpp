#include <iostream>
#include <vector>

// #include "solvers.cpp"
#include "solvers_tests.cpp"
#include "sudoku.hpp"
#include "sudoku_tests.cpp"

int main()
{
    run_class_tests();
    run_solver_tests();
    return 0;
}
