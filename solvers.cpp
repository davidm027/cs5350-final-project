#include <iostream>
#include <ostream>

#include "sudoku.hpp"
#include <omp.h>





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

    #pragma omp parallel
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



// sudoku_test.cpp
int main() {
    Sudoku s;
    std::vector<std::vector<int>> squares{
            {1, 2, 6, 5, 9, 8, 7, 4, 3}, {7, 5, 8, 1, 4, 3, 9, 6, 2}, {9, 3, 4, 6, 7, 2, 8, 5, 1},
            {3, 1, 4, 2, 6, 9, 8, 7, 5}, {2, 9, 5, 8, 7, 4, 3, 1, 6}, {7, 6, 8, 5, 1, 3, 4, 2, 9},
            {9, 5, 7, 6, 3, 1, 4, 8, 2}, {4, 2, 1, 5, 8, 9, 6, 3, 7}, {3, 8, 6, 2, 4, 7, 1, 9, 5}};

    s.set_grid(squares);

    bool h = omp_brute_force(s, 0, 0);
    s.print();
}