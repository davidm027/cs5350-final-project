#include <iostream>

#include "sudoku.hpp"

int main() {
    Sudoku s;
    s.set_square(0, 0, 1);
    s.print();
    return 0;
}
