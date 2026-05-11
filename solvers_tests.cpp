#include <cassert>
#include <iostream>

#include "sudoku.hpp"

Sudoku setup_puzzle()
{
    Sudoku s;
    std::vector<std::vector<int>> rows{
        {0, 3, 9, 5, 0, 0, 0, 0, 0}, {0, 0, 0, 8, 0, 0, 0, 7, 0}, {0, 0, 0, 0, 1, 0, 9, 0, 4},
        {1, 0, 0, 4, 0, 0, 0, 0, 3}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 7, 0, 0, 0, 8, 6, 0},
        {0, 0, 6, 7, 0, 8, 2, 0, 0}, {0, 1, 0, 0, 9, 0, 0, 0, 5}, {0, 0, 0, 0, 0, 1, 0, 0, 8}};

    s.set_grid_by_rows(rows);

    // s.print();

    return s;
}

Sudoku setup_solution()
{
    Sudoku s;
    std::vector<std::vector<int>> rows{
        {6, 3, 9, 5, 7, 4, 1, 8, 2}, {5, 4, 1, 8, 2, 9, 3, 7, 6}, {7, 8, 2, 6, 1, 3, 9, 5, 4},
        {1, 9, 8, 4, 6, 7, 5, 2, 3}, {3, 6, 5, 9, 8, 2, 4, 1, 7}, {4, 2, 7, 1, 3, 5, 8, 6, 9},
        {9, 5, 6, 7, 4, 8, 2, 3, 1}, {8, 1, 3, 2, 9, 6, 7, 4, 5}, {2, 7, 4, 3, 5, 1, 6, 9, 8}};

    s.set_grid_by_rows(rows);

    // s.print();

    return s;
}

void test_brute_force()
{
    std::cout << "Testing brute-force algorithm...\n";

    Sudoku puzzle = setup_puzzle();
    Sudoku solution = setup_solution();
    auto result = puzzle == solution;
    assert(puzzle == solution && "Brute-force algorithm did not return a correct solution.");

    std::cout << "Completed brute-force algorithm tests.\n";
}

void test_advanced()
{
    std::cout << "Testing advanced algorithm...\n";

    Sudoku puzzle = setup_puzzle();
    Sudoku solution = setup_solution();
    auto result = puzzle == solution;
    assert(puzzle == solution && "Advanced algorithm did not return a correct solution.");

    std::cout << "Completed advanced algorithm tests.\n";
}

void run_solver_tests()
{
    // setup_puzzle();
    // setup_solution();
    test_brute_force();
    test_advanced();
    Sudoku puzzle = setup_puzzle();
    Sudoku solution = setup_solution();
    auto res = puzzle == solution;
    std::cout << std::boolalpha << "res: " << res << "\n";
}