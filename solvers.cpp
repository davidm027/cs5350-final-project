#include "solvers.hpp"

#include <omp.h>

#include <vector>

namespace
{
bool regular_brute_force(Sudoku& input, int row, int col)
{
    if (row == 9)
        return true;

    if (col == 9)
        return regular_brute_force(input, row + 1, 0);

    if (input.get_space(row, col) != 0)
        return regular_brute_force(input, row, col + 1);

    for (int choice = 1; choice <= 9; choice++)
    {
        if (input.is_choice_valid(row, col, choice))
        {
            input.set_space(row, col, choice);

            if (regular_brute_force(input, row, col + 1))
                return true;

            input.set_space(row, col, 0);
        }
    }

    return false;
}

bool find_first_empty(Sudoku input, int& row, int& col)
{
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (input.get_space(r, c) == 0)
            {
                row = r;
                col = c;
                return true;
            }
        }
    }

    return false;
}

bool openmp_brute_force(Sudoku& input)
{
    int row = 0;
    int col = 0;

    if (!find_first_empty(input, row, col))
        return true;

    std::vector<Sudoku> solutions(10, input);
    std::vector<bool> found(10, false);

    #pragma omp parallel for
    for (int choice = 1; choice <= 9; choice++)
    {
        if (input.is_choice_valid(row, col, choice))
        {
            Sudoku current = input;
            current.set_space(row, col, choice);

            if (regular_brute_force(current, row, col + 1))
            {
                solutions[choice] = current;
                found[choice] = true;
            }
        }
    }

    for (int choice = 1; choice <= 9; choice++)
    {
        if (found[choice])
        {
            input = solutions[choice];
            return true;
        }
    }

    return false;
}

bool find_best_empty_mrv(Sudoku input, int& best_row, int& best_col)
{
    int best_count = 10;
    bool has_empty = false;

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (input.get_space(row, col) == 0)
            {
                has_empty = true;
                int count = 0;

                for (int choice = 1; choice <= 9; choice++)
                {
                    if (input.is_choice_valid(row, col, choice))
                        count++;
                }

                if (count < best_count)
                {
                    best_count = count;
                    best_row = row;
                    best_col = col;
                }

                if (best_count == 1)
                    return true;
            }
        }
    }

    return has_empty;
}

bool advanced_serial(Sudoku& input)
{
    int row = 0;
    int col = 0;

    if (!find_best_empty_mrv(input, row, col))
        return true;

    for (int choice = 1; choice <= 9; choice++)
    {
        if (input.is_choice_valid(row, col, choice))
        {
            input.set_space(row, col, choice);

            if (advanced_serial(input))
                return true;

            input.set_space(row, col, 0);
        }
    }

    return false;
}
} // namespace

namespace solvers
{
Sudoku brute_force(Sudoku puzzle)
{
    openmp_brute_force(puzzle);
    return puzzle;
}

Sudoku advanced(Sudoku puzzle)
{
    advanced_serial(puzzle);
    return puzzle;
}
} // namespace solvers
