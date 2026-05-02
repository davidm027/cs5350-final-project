#include <iostream>
#include <ostream>

#include "sudoku.hpp"
#include <omp.h>

#include "vector"

#include <chrono>



bool regular_brute_force(Sudoku & input, int row, int col){
    if (row == 9 )
        return true;

    if (col == 9) {
        return regular_brute_force(input, row + 1, 0);
    }

    if (input.get_space(row, col)!= 0) {
        return regular_brute_force(input, row, col + 1);
    }

    for (int c = 0; c < 9; c++) {
        if (input.is_choice_valid(row, col, c)) {
            input.set_space(row, col, c);
            if (regular_brute_force(input, row, col + 1) )
                return true;
            input.set_space(row, col, 0);
        }
    }
    return false;
}

bool advanced_serial(Sudoku & input, int row, int col){
    if (row == 9 )
        return true;

    if (col == 9) {
        return regular_brute_force(input, row + 1, 0);
    }

    if (input.get_space(row, col)!= 0) {
        return regular_brute_force(input, row, col + 1);
    }

    for (int c = 0; c < 9; c++) {
        if (input.is_choice_valid(row, col, c)) {
            input.set_space(row, col, c);
            if (regular_brute_force(input, row, col + 1) )
                return true;
            input.set_space(row, col, 0);
        }
    }
    return false;
}


bool omp_brute_force(Sudoku & input, int row, int col){
    if (row == 9 )
        return true;

    if (col == 9) {
        return regular_brute_force(input, row + 1, 0);
    }

    if (input.get_space(row, col)!= 0) {
        return regular_brute_force(input, row, col + 1);
    }
    omp_set_num_threads(9);

    for (int c = 0; c < 9; c++) {
        if (input.is_choice_valid(row, col, c)) {
            input.set_space(row, col, c);
            if (regular_brute_force(input, row, col + 1) )
                return true;
            input.set_space(row, col, 0);
        }
    }
    return false;
}

bool set_up_function(Sudoku & input, int row, int col) {

    if (row == 9 )
        return true;

    if (col == 9) {
        return regular_brute_force(input, row + 1, 0);
    }

    if (input.get_space(row, col)!= 0) {
        return regular_brute_force(input, row, col + 1);
    }

    // std::vector<Sudoku> squares(9, input);

    bool found = false;
    Sudoku s;

    #pragma omp parallel for shared(found, s)
    for (int c = 0; c < 9; c++) {
        bool local_found;
        #pragma omp atomic read
        local_found = found;
        if (local_found) continue;
        if ( input.is_choice_valid(row, col, c)) {
            Sudoku current = input;
            current.set_space(row, col, c);

            if (regular_brute_force(current, row, col + 1) )
                #pragma omp  critical
                {
                    if (!found) {
                        found = true;
                        s = current;
                    }
                }
            current.set_space(row, col, 0);
        }
    }
    if (found) input = s;
    return found;
}


template <typename Func>
void time_function(Func f, Sudoku & input, int row, int col) {
    auto start = std::chrono::steady_clock::now();
    ten_times(f, input, row, col);
    auto end =  std::chrono::steady_clock::now();
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout<<"time elapse is : " << ns.count() /1000<< std::endl;
}

template <typename Func>
void ten_times(Func f, Sudoku & input, int row, int col) {
    for (int i = 0; i < 1000; i++) {
        auto h = f(input, row, col);
    }
}

// sudoku_test.cpp
int main() {
    Sudoku s;
    omp_set_num_threads(9);

    std::vector<std::vector<int>> squares{
            {1, 2, 6, 5, 9, 8, 7, 4, 3}, {7, 5, 8, 1, 4, 3, 9, 6, 2}, {9, 3, 4, 6, 7, 2, 8, 5, 1},
            {3, 1, 4, 2, 6, 9, 8, 7, 5}, {2, 9, 5, 8, 7, 4, 3, 1, 6}, {7, 6, 8, 5, 1, 3, 4, 2, 9},
            {9, 5, 7, 6, 3, 1, 4, 8, 2}, {4, 2, 1, 5, 8, 9, 6, 3, 7}, {3, 8, 6, 2, 4, 7, 1, 9, 5}};

    s.set_grid(squares);

    time_function(set_up_function, s, 0, 0);
    s.print();
}