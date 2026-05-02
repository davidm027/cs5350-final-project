#include "sudoku.hpp"




void regular_brute_force(Sudoku inout) {

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            for (int c = 0; c < 9; c++) {






            }
        }
    }
}



// sudoku_test.cpp
int main() {
    Sudoku s;
    std::vector<std::vector<int>> squares{
            {1, 2, 6, 5, 9, 8, 7, 4, 3}, {7, 5, 8, 1, 4, 3, 9, 6, 2}, {9, 3, 4, 6, 7, 2, 8, 5, 1},
            {3, 1, 4, 2, 6, 9, 8, 7, 5}, {2, 9, 5, 8, 7, 4, 3, 1, 6}, {7, 6, 8, 5, 1, 3, 4, 2, 9},
            {9, 5, 7, 6, 3, 1, 4, 8, 2}, {4, 2, 1, 5, 8, 9, 6, 3, 7}, {3, 8, 6, 2, 4, 7, 1, 9, 5}};

    s.set_grid(squares);

    regular_brute_force(s);
}