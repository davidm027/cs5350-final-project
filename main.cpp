#include <iostream>

#include "sudoku.hpp"

int main() {
    Sudoku s;
    s.set_space(0, 0, 1);
    s.set_space(0, 1, 2);
    s.set_space(0, 2, 3);
    s.set_space(1, 0, 4);
    s.set_space(1, 1, 5);
    s.set_space(1, 2, 6);
    s.set_space(2, 0, 7);
    s.set_space(2, 1, 8);
    s.set_space(2, 2, 9);
    s.print();

    // auto square = s.get_square(0);
    // auto row = s.get_row(0);
    // for (auto i : row) {
    //     std::cout << i << "\n";
    // }
    // auto column = s.get_column(0);
    // for (auto i : column) {
    //     std::cout << i << "\n";
    // }
    return 0;
}
